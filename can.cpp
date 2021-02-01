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
    if(can_stat == OFF)
    {
        can_error_handler(board_info());            // счит. инфо об адаптере (проверяем его наличие)
        can_error_handler(CiOpen(0, CIO_CAN11));    // открываем канал 0
        can_error_handler(CiSetBaud(0, BCI_250K));  // кофигурируем канал
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
    if(can_stat)    // если адаптер подключен
    {
        canmsg_t tx_data;
        tx_data.id = 0x161;
        memcpy(tx_data.data, tx_time, 8);
        tx_data.len = 8;
        qDebug() << "send_sys_time(void)";
        qDebug() << "CiTransmit error " <<CiTransmit(0, &tx_data);
    }
}

/* @brief  Метод слота на достижение счёта счётчика timer_diag_data
 * (происходит считывание очереди принятых посылок)
 * @param  None
 * @retval None
 */
void train_imitator::receive_diag_data(void)
{
    if(can_stat)    // если адаптер подключен
    {
        qDebug() << "receive_diag_data(void)";
//        canmsg_t rx_data;
//        qDebug() << "CiRead" << CiRead(0, &rx_data, 1);
//        qDebug() << "ID" << rx_data.id;
//        qDebug() << "zdczsdfsd";
//        for(uint8_t i=0; i<8; i++)
//        {
//            qDebug() << "data" << i <<rx_data.data[i];
//        }
    }
}
