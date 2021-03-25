/* @brief  can.cpp содержит методы и слоты, реализующие настройку CAN
 * каналов и корреспонденцию по сети CAN
 */

#include "train_imitator.h"
#include "ui_train_imitator.h"
#include "bits.h"

/* ***************************************************************************************
 *  МЕТОДЫ
 * ***************************************************************************************
 */

/* @brief  Метод, реализующий обработку ошибок по can
 * @param  er_code - номер кода ошибки
 * @retval None
 */
void train_imitator::can_error_handler(_s16 er_code)
{
    qDebug() << er_code;
}

/* @brief  Метод, определяющий подключенный адаптер и получающий данные о нём
 * @param  None
 * @retval код ошибки can
 */
_s16 train_imitator::board_info(void)
{
    _s16 ret;               // код, возвращаемый ф-ией CiBoardInfo(&binfo)
    canboard_t binfo;       // объект структуры инфы об адаптере
    uint8_t chan_cnt = 0;   // кол-во доступных каналов

    binfo.brdnum = 0;           // задаём порядковый номер проверяемого адаптера
    ret = CiBoardInfo(&binfo);  // проверяем подключенный адаптер

    if (ret < 0)
    {
        ui->label_2->setText("АДАПТЕР НЕ ПОДКЛЮЧЕН!   ПОДКЛЮЧИТЕ АДАПТЕР И ПЕРЕЗАПУСТИТЕ ПРИЛОЖЕНИЕ.");
        ui->label_2->setStyleSheet("QLabel{color: rgb(255, 10, 0); }");  // делаем текст красным
        return ret;
    }
    else
    {
        // здесь мы заполняем массив номеров каналов номерами каналов
        for (uint8_t j = 0; j < 4; j++)
        {if (binfo.chip[j] >= 0){chan_cnt++;}}

        brd_name = binfo.name;      // считываем наименование адаптера
        brd_manuf = binfo.manufact; // считываем производителя адаптера

        ui->label_2->setText("Подключен адаптер " + brd_name+", " + brd_manuf +", кол-во доступных каналов: " + QString::number(chan_cnt));
        ui->label_2->setStyleSheet("QLabel{color: rgb(0, 0, 0); }");  // делаем текст чёрным
    }
    return 0;
}




/* ***************************************************************************************
 *  СЛОТЫ
 * ***************************************************************************************
 */

/* @brief  Метод слота реакции на нажатие кнопки "подключить"
 * @param  None
 * @retval None
 */
void train_imitator::on_btn_connect(void)
{
    _u16 trqcnt = 0;    // вспом. перем. для хранения кол-ва стёртых посылок
    _u16 * ptr_trqcnt = &trqcnt;

    if(can_stat == OFF)
    {
        can_error_handler(board_info());            // счит. инфо об адаптере (проверяем его наличие)
        can_error_handler(CiOpen(0, CIO_CAN11));    // открываем канал 0
        can_error_handler(CiSetBaud(0, BCI_250K));  // кофигурируем канал (устанавливаем скорость)
        can_error_handler(CiRcQueResize(0, 3));     // кофигурируем канал (размер очереди приёма)
        CiTrCancel(0, ptr_trqcnt);                  // стираем содержимое очереди приёма
        can_error_handler(CiStart(0));              // запускаем канал
        ui->pushButton_5->setText("отключить х");
        can_stat = ON;
    }
    else
    {
        can_error_handler(CiStop(0));               // останавливаем канал
        can_error_handler(CiClose(0));              // закрываем канал 0
        ui->pushButton_5->setText("подключить->");
        ui->label_2->setText("Адаптер отключен");
        ui->label_2->setStyleSheet("QLabel{color: rgb(0, 0, 0); }");  // делаем текст чёрным
        can_stat = OFF;
    }
}


void train_imitator::on_btn_receive(void)
{
    canmsg_t rx_data;
    qDebug() << "CiRead" << CiRead(0, &rx_data, 1);
    qDebug() << "ID" << rx_data.id;


    for(uint8_t i=0; i<8; i++)
    {
        qDebug() << "data" << i <<rx_data.data[i];
    }
}

/* @brief  Метод слота на достижение счёта счётчика timer_sys_time
 * @param  None
 * @retval None
 */
void train_imitator::send_sys_time(void)
{
    uint8_t tmp_id = 0; //  временная переменная для выбора основного или резервного id

    if(use_id == NORMAL){tmp_id = ID_TIME;}
    else{tmp_id = ID_TIME_RES;}

    time_retr();    // получаем время, загружаем в массив и выводим в окно интерфейса
    date_retr();    // считываем дату, загружаем в массив tx_time и выводим в шапку интерфейса

    // передаём посылку
    if(can_stat)    // если адаптер подключен
    {
        canmsg_t tx_data;
        tx_data.id = tmp_id;
        memcpy(tx_data.data, tx_time, 8);
        tx_data.len = 8;
        CiTransmit(0, &tx_data);
    }
}

/* @brief  Метод слота на достижение счёта счётчика timer_post_start
 * @param  None
 * @retval None
 */
void train_imitator::send_post_start(void)
{
    uint8_t tmp_id = 0; //  временная переменная для выбора основного или резервного id

    if(use_id == NORMAL){tmp_id = ID_POST_START;}
    else{tmp_id = ID_POST_START_RES;}

    if(can_stat)    // если адаптер подключен
    {
        canmsg_t tx_data;
        tx_data.id = tmp_id;
        memcpy(tx_data.data, tx_post_start, 8);
        tx_data.len = 8;
        CiTransmit(0, &tx_data);
    }
}

/* @brief  Метод слота на достижение счёта счётчика timer_commands
 * @param  None
 * @retval None
 */
void train_imitator::send_commands(void)
{
    uint8_t tmp_id = 0; //  временная переменная для выбора основного или резервного id

    if(use_id == NORMAL){tmp_id = ID_COMMANDS;}
    else{tmp_id = ID_COMMANDS_RES;}

    if(can_stat)    // если адаптер подключен
    {
        canmsg_t tx_data;
        tx_data.id = tmp_id;
        memcpy(tx_data.data, tx_commands, 8);
        tx_data.len = 8;
        CiTransmit(0, &tx_data);
    }
}

/* @brief  Метод слота на достижение счёта счётчика timer_diag_data
 * (происходит считывание очереди принятых посылок)
 * @param  None
 * @retval None
 */
void train_imitator::receive_all_msgs(void)
{
    if(can_stat)    // если адаптер подключен
    {
        CiRead(0, rx_buffer, 2);    // считываем 3-и посылки из очереди

        // обрабатываем 0-й элемент
        switch(rx_buffer[0].id)
        {
        // основные id-шники
        case ID_DIAG:
            memcpy(rx_diag_data, rx_buffer[0].data, 8);
            gui_diag();                                 // обновляем gui диагн. данными
            break;
        case ID_FAILS:
            memcpy(rx_failuries, rx_buffer[0].data, 8);
            gui_failuries();                            // обновляем gui данными неиспр.
            break;
        case ID_SERVICE:
            memcpy(rx_service_info, rx_buffer[0].data, 8);
            gui_service();                                 // обновляем gui данными сервиса
            break;

        // резервные id-шники
        case ID_DIAG_RES:
            memcpy(rx_diag_data, rx_buffer[0].data, 8);
            gui_diag();                                 // обновляем gui диагн. данными
            break;
        case ID_FAILS_RES:
            memcpy(rx_failuries, rx_buffer[0].data, 8);
            gui_failuries();                            // обновляем gui данными неиспр.
            break;
        case ID_SERVICE_RES:
            memcpy(rx_service_info, rx_buffer[0].data, 8);
            gui_service();                                 // обновляем gui данными сервиса
            break;

        default: break;
        }

        // обрабатываем 1-й элемент
        switch(rx_buffer[1].id)
        {
        // основные id-шники
        case ID_DIAG:
            memcpy(rx_diag_data, rx_buffer[1].data, 8);
            gui_diag();                                 // обновляем gui диагн. данными
            break;
        case ID_FAILS:
            memcpy(rx_failuries, rx_buffer[1].data, 8);
            gui_failuries();                            // обновляем gui данными неиспр.
            break;
        case ID_SERVICE:
            memcpy(rx_service_info, rx_buffer[1].data, 8);
            gui_service();                                 // обновляем gui данными сервиса
            break;

        // резервные id-шники
        case ID_DIAG_RES:
            memcpy(rx_diag_data, rx_buffer[1].data, 8);
            gui_diag();                                 // обновляем gui диагн. данными
            break;
        case ID_FAILS_RES:
            memcpy(rx_failuries, rx_buffer[1].data, 8);
            gui_failuries();                            // обновляем gui данными неиспр.
            break;
        case ID_SERVICE_RES:
            memcpy(rx_service_info, rx_buffer[1].data, 8);
            gui_service();                                 // обновляем gui данными сервиса
            break;

        default: break;
        }

        // обрабатываем 2-й элемент
        switch(rx_buffer[2].id)
        {
        // основные id-шники
        case ID_DIAG:
            memcpy(rx_diag_data, rx_buffer[2].data, 8);
            gui_diag();                                 // обновляем gui диагн. данными
            break;
        case ID_FAILS:
            memcpy(rx_failuries, rx_buffer[2].data, 8);
            gui_failuries();                            // обновляем gui данными неиспр.
            break;
        case ID_SERVICE:
            memcpy(rx_service_info, rx_buffer[2].data, 8);
            gui_service();                                 // обновляем gui данными сервиса
            break;

        // резервные id-шники
        case ID_DIAG_RES:
            memcpy(rx_diag_data, rx_buffer[2].data, 8);
            gui_diag();                                 // обновляем gui диагн. данными
            break;
        case ID_FAILS_RES:
            memcpy(rx_failuries, rx_buffer[2].data, 8);
            gui_failuries();                            // обновляем gui данными неиспр.
            break;
        case ID_SERVICE_RES:
            memcpy(rx_service_info, rx_buffer[2].data, 8);
            gui_service();                                 // обновляем gui данными сервиса
            break;

        default: break;
        }
    }
}

/* @brief  Метод считывания системного времени, загрузки данных в tx_time и вывод в шапку интерфейса
 * @param  None
 * @retval None
 */
void train_imitator::time_retr(void)
{
    c_time = QTime::currentTime(); // текущее время
    minute  = c_time.minute();
    hour    = c_time.hour();
    sec_100 = c_time.msec()/10;
    sec     = c_time.second();

    // загружаем в массив tx_time
    tx_time[CH] = minute;
    tx_time[CL] = hour;
    tx_time[DH] = sec_100;
    tx_time[DL] = sec;

    // помещаем данные в окно в шапке интерфейса
    ui->label_9->setText(QString::number(hour)+":"+QString::number(minute)+":"+QString::number(sec));
}
