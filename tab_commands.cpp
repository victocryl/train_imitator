/* @brief  Файл tab_commands.cpp содержит методы, реализующие функционирование
 * закладки КОМАНДЫ
 */

#include "train_imitator.h"
#include "ui_train_imitator.h"
#include "bits.h"

/* ***************************************************************************************
 *  МЕТОДЫ
 * ***************************************************************************************
 */

/* @brief  Метод считывания в массив tx_time[8] системной даты
 * @param  None
 * @retval None
 */
uint8_t train_imitator::sys_date_retr(void)
{
    // считываем дату (день, месяц, год)
    QString str = ui->lineEdit_5->text();     // забираем текст из строки день
    uint8_t day = str.toInt(&str_error, 10);  // переводим в int
    str = ui->lineEdit_6->text();             // забираем месяц
    uint8_t month = str.toInt(&str_error, 10);
    str = ui->lineEdit_7->text();             // забираем год
    uint16_t year = str.toInt(&str_error, 10);

     // проверяем данные на адекватность
     if((day == 0) || (day > 31) || (month == 0) || (month > 12) || (year == 0) || (year < 2021) || (year > 2100))
     {
         tx_time[AH] = tx_time[AL] = tx_time[BH] = tx_time[BL] = 0; // обуляем все данные
         return ER_SYS_DATA;
     }
     else
     {  // если прошли проверку
         tx_time[AH] = (year>>8);
         tx_time[AL] = year;
         tx_time[BH] = month;
         tx_time[BL] = day;

         // помещаем данные в окно в шапке интерфейса
         ui->label_36->setText(QString::number(day)+"."+QString::number(month)+"."+QString::number(year));

         return NO_INPUT_ERRORS;
     }
     return NO_INPUT_ERRORS;
}


/* @brief  Метод считывания в массив tx_time[8] системного времени
 * @param  None
 * @retval None
 */
uint8_t train_imitator::sys_time_retr(void)
{
    // **********  считываем время (часы, мин., сек., сотые доли сек.)  *****************************
    QString str = ui->lineEdit->text();     // забираем текст из строки час
    uint8_t hour = str.toInt(&str_error, 10);  // переводим в int
    str = ui->lineEdit_2->text();             // забираем минуты
    uint8_t min = str.toInt(&str_error, 10);
    str = ui->lineEdit_3->text();             // забираем секунды
    uint16_t sec = str.toInt(&str_error, 10);
    str = ui->lineEdit_4->text();             // забираем сот. доли секунды
    uint16_t h_of_sec = str.toInt(&str_error, 10);

     // проверяем данные на адекватность
     if((hour > 23) || (min == 0) || (min > 59) || (sec == 0) || (sec > 59) || (h_of_sec == 0) || (h_of_sec > 99))
     {
         tx_time[CH] = tx_time[CL] = tx_time[DH] = tx_time[DL] = 0; // обуляем все данные        
         return  ER_SYS_TIME;
     }
     else
     {  // если прошли проверку
         tx_time[CH] = min;
         tx_time[CL] = hour;
         tx_time[DH] = h_of_sec;
         tx_time[DL] = sec;

         // помещаем данные в окно в шапке интерфейса
         ui->label_9->setText(QString::number(hour)+":"+QString::number(min)+":"+QString::number(sec)+":"+QString::number(h_of_sec));

         return NO_INPUT_ERRORS;
     }
     return NO_INPUT_ERRORS;
}

/* @brief  Метод считывания в массив tx_post_start[8] даты отложенного старта
 * @param  None
 * @retval None
 */
uint8_t train_imitator::post_date_retr(void)
{
    // **********  считываем дату (день, месяц, год)  *****************************
    QString str = ui->lineEdit_8->text();     // забираем текст из строки день
    uint8_t day = str.toInt(&str_error, 10);  // переводим в int
    str = ui->lineEdit_9->text();             // забираем месяц
    uint8_t month = str.toInt(&str_error, 10);
    str = ui->lineEdit_10->text();             // забираем год
    uint16_t year = str.toInt(&str_error, 10);

     // проверяем данные на адекватность
     if((day == 0) || (day > 31) || (month == 0) || (month > 12) || (year == 0) || (year < 2021) || (year > 2100))
     {
         tx_post_start[AH] = tx_post_start[AL] = tx_post_start[BH] = tx_post_start[BL] = 0; // обуляем все данные
         return ER_POST_DATA;
     }
     else
     {  // если прошли проверку
         tx_post_start[AH] = (year>>8);
         tx_post_start[AL] = year;
         tx_post_start[BH] = month;
         tx_post_start[BL] = day;

         // помещаем данные в окно в шапке интерфейса
         ui->label_44->setText(QString::number(day)+"."+QString::number(month)+"."+QString::number(year));

         return NO_INPUT_ERRORS;
     }
     return NO_INPUT_ERRORS;
}

/* @brief  Метод считывания в массив tx_post_start[8] времени отложенного старта
 * @param  None
 * @retval None
 */
uint8_t train_imitator::post_time_retr(void)
{
    // **********  считываем время (часы, мин., сек., сотые доли сек.)  *****************************
    QString str = ui->lineEdit_11->text();     // забираем текст из строки час
    uint8_t hour = str.toInt(&str_error, 10);  // переводим в int
    str = ui->lineEdit_12->text();             // забираем минуты
    uint8_t min = str.toInt(&str_error, 10);
    str = ui->lineEdit_13->text();             // забираем секунды
    uint16_t sec = str.toInt(&str_error, 10);
    str = ui->lineEdit_14->text();             // забираем сот. доли секунды
    uint16_t h_of_sec = str.toInt(&str_error, 10);

     // проверяем данные на адекватность
     if((hour > 23) || (min == 0) || (min > 59) || (sec == 0) || (sec > 59) || (h_of_sec == 0) || (h_of_sec > 99))
     {
         tx_post_start[CH] = tx_post_start[CL] = tx_post_start[DH] = tx_post_start[DL] = 0; // обуляем все данные
         return ER_POST_TIME;
     }
     else
     {  // если прошли проверку
         tx_post_start[CH] = min;
         tx_post_start[CL] = hour;
         tx_post_start[DH] = h_of_sec;
         tx_post_start[DL] = sec;

         // помещаем данные в окно в шапке интерфейса
         ui->label_65->setText(QString::number(hour)+":"+QString::number(min)+":"+QString::number(sec)+":"+QString::number(h_of_sec));

         return NO_INPUT_ERRORS;
     }
     return NO_INPUT_ERRORS;
}

/* @brief  Метод считывания в массив tx_commands[8] допустимой мощности сети 400 В
 * @param  None
 * @retval None
 */
uint8_t train_imitator::valid_pwr_400_retr(void)
{
    // **********  считываем мощность  *****************************
    QString str = ui->lineEdit_15->text();    // забираем текст из строки
    uint8_t pwr = str.toInt(&str_error, 10);  // переводим в int

     // проверяем данные на адекватность
     if((pwr == 0) || (pwr > 254))
     {
         tx_commands[BH] = tx_commands[BL] = 0; // обуляем все данные
         return ER_PWR_400;
     }
     else
     {  // если прошли проверку
         tx_commands[BH] = pwr;

         // помещаем данные в окно в шапке интерфейса
         ui->label_20->setText(QString::number(pwr)+"кВт");

         return NO_INPUT_ERRORS;
     }
     return NO_INPUT_ERRORS;
}

/* @brief  Метод считывания в массив tx_commands[8] температуры окружающей среды
 * @param  None
 * @retval None
 */
uint8_t train_imitator::ambient_temp_retr(void)
{
    // **********  считываем температуру  *****************************
    QString str = ui->lineEdit_16->text();    // забираем текст из строки
    uint16_t t = str.toInt(&str_error, 10);  // переводим в int

     // проверяем данные на адекватность
     if((t == 0) || (t > 850))
     {
         tx_commands[CH] = tx_commands[CL] = 0; // обуляем все данные
         return ER_AIR_TEMP;
     }
     else
     {  // если прошли проверку
         tx_commands[CH] = t>>8;
         tx_commands[CL] = t;

         // помещаем данные в окно в шапке интерфейса
         ui->label_13->setText(QString::number(t));

         return NO_INPUT_ERRORS;
     }
    return NO_INPUT_ERRORS;
}

/* @brief  Метод считывания в массив tx_commands[8] сдвига уставки температуры
 * @param  None
 * @retval None
 */
uint8_t train_imitator::temp_offset_retr(void)
{
    // **********  считываем сдвиг  *****************************
    QString str = ui->lineEdit_17->text();        // забираем текст из строки
    uint8_t offset = str.toInt(&str_error, 10);  // переводим в int

     // проверяем данные на адекватность
     if((offset == 0) || (offset > 254))
     {
         tx_commands[DH] = tx_commands[DL] = 0; // обуляем все данные
         return ER_SET_OFFSET;
     }
     else
     {  // если прошли проверку
         tx_commands[DH] = offset;

         return NO_INPUT_ERRORS;
     }
    return NO_INPUT_ERRORS;
}


/* @brief  Метод считывания из чекбоксов галочек команд в массив tx_commands[8]
 * @param  None
 * @retval None
 */
uint8_t train_imitator::cmd_check_boxes_retr(void)
{
    uint8_t ch_b_cnt = 0;   // счётчик кликнутых чекбоксов

    tx_commands[AH] &= CMD_RESET;   // сбрасываем все предыдущие команды

    // проверяем чекбоксы главных 4-х режимов
    if(ui->checkBox_30->checkState() == Qt::Checked)
    {
        tx_commands[AH] |= CMD_OFF;
        ch_b_cnt++;
    }
    if(ui->checkBox_19->checkState() == Qt::Checked)
    {
        tx_commands[AH] |= CMD_ON;
        ch_b_cnt++;
    }
    if(ui->checkBox_7->checkState() == Qt::Checked)
    {
        tx_commands[AH] |= CMD_OTSTOY;
        ch_b_cnt++;
    }
    if(ui->checkBox_16->checkState() == Qt::Checked)
    {
        tx_commands[AH] |= CMD_MOYKA;
        ch_b_cnt++;
    }

    // проверяем чекбоксы доп. статусов (Станция и Тоннель)
    if(ui->checkBox_17->checkState() == Qt::Checked){tx_commands[AH] |= BIT_STATION;}
    else{tx_commands[AH] &= ~BIT_STATION;}
    if(ui->checkBox_18->checkState() == Qt::Checked){tx_commands[AH] |= BIT_TONNEL;}
    else{tx_commands[AH] &= ~BIT_TONNEL;}

    // если кликнуто более 1 чекбокса из 4-х основных режимов - возвращаем ошибку
    if(ch_b_cnt > 1){return ER_CHECK_BOX;}
    else{return NO_INPUT_ERRORS;}
}

/* @brief  Метод считывания статусов из чекбоксов раздела "ЗАДАТЬ СТАТУСЫ"
 * @param  None
 * @retval None
 */
void train_imitator::stat_check_boxes_retr(void)
{
    if(ui->checkBox_33->checkState() == Qt::Checked){tx_commands[AH] |= BIT_OTKR_DVER;}
    else{tx_commands[AH] &= ~BIT_OTKR_DVER;}
    if(ui->checkBox_11->checkState() == Qt::Checked){tx_commands[AH] |= BIT_3000_V;}
    else{tx_commands[AH] &= ~BIT_3000_V;}
    if(ui->checkBox_34->checkState() == Qt::Checked){tx_commands[AL] |= BIT_400_V;}
    else{tx_commands[AL] &= ~BIT_400_V;}
    if(ui->checkBox_34->checkState() == Qt::Checked){tx_commands[AL] |= BIT_400_V;}
    else{tx_commands[AL] &= ~BIT_400_V;}
    if(ui->checkBox_35->checkState() == Qt::Checked){tx_commands[AL] |= BIT_REZH_OGR_MOSCHN;}
    else{tx_commands[AL] &= ~BIT_REZH_OGR_MOSCHN;}
    if(ui->checkBox_36->checkState() == Qt::Checked){tx_commands[AL] |= BIT_VKL_COMPR_RAZR;}
    else{tx_commands[AL] &= ~BIT_VKL_COMPR_RAZR;}
    if(ui->checkBox_37->checkState() == Qt::Checked){tx_commands[AL] |= BIT_VKL_REC_NAGR;}
    else{tx_commands[AL] &= ~BIT_VKL_REC_NAGR;}
    if(ui->checkBox_38->checkState() == Qt::Checked){tx_commands[AL] |= BIT_SBR_ACTIV_SERV_SOOB;}
    else{tx_commands[AL] &= ~BIT_SBR_ACTIV_SERV_SOOB;}
}



/* @brief  Метод обработки ошибок ввода данных
 * @param  None
 * @retval None
 */
void train_imitator::errors_printing(void)
{
    ui->label_2->setText("");  // удаляем любую надпись
    ui->label_2->setStyleSheet("QLabel{color: rgb(0, 0, 0); }");  // делаем текст чёрным

    if(input_errors[0])
    {
        ui->label_2->setText("неправильный формат числа, месяца или года системной даты");
        ui->label_2->setStyleSheet("QLabel{color: rgb(255, 10, 0); }");  // делаем текст красным
    }

    if(input_errors[1])
    {
        ui->label_2->setText("неправильный формат данных системного времени");
        ui->label_2->setStyleSheet("QLabel{color: rgb(255, 10, 0); }");  // делаем текст красным
    }

    if(input_errors[2])
    {
        ui->label_2->setText("неправильный формат числа, месяца или года отложенного старта");
        ui->label_2->setStyleSheet("QLabel{color: rgb(255, 10, 0); }");  // делаем текст красным
    }

    if(input_errors[3])
    {
        ui->label_2->setText("неправильный формат времени отдложенного старта");
        ui->label_2->setStyleSheet("QLabel{color: rgb(255, 10, 0); }");  // делаем текст красным
    }

    if(input_errors[4])
    {
        ui->label_2->setText("неправильный формат данных потребляемой мощности");
        ui->label_2->setStyleSheet("QLabel{color: rgb(255, 10, 0); }");  // делаем текст красным
    }

    if(input_errors[5])
    {
        ui->label_2->setText("неправильный формат данных температуры наружного воздуха");
        ui->label_2->setStyleSheet("QLabel{color: rgb(255, 10, 0); }");  // делаем текст красным
    }

    if(input_errors[6])
    {
        ui->label_2->setText("неправильный формат данных смещения температурной уставки");
        ui->label_2->setStyleSheet("QLabel{color: rgb(255, 10, 0); }");  // делаем текст красным
    }

    if(input_errors[7])
    {
        ui->label_2->setText("может быть выбран только 1 из 4-х режимов: Отключение, Включение, Отстой или Мойка");
        ui->label_2->setStyleSheet("QLabel{color: rgb(255, 10, 0); }");  // делаем текст красным
    }

    memcpy(input_errors, init_array, 8);   // обнуляем массив ошибок
}





/* ***************************************************************************************
 *  СЛОТЫ
 * ***************************************************************************************
 */


/* @brief  Метод слота на нажатие кнопки "Задать параметры"
 * @detail По нажатию кнопки происходит считывание в 3-и tx-массива
 *  всех системных настроек и битов команд.
 * @param  None
 * @retval None
 */
void train_imitator::tab_commands(void)
{
    input_errors[0] = sys_date_retr();        // считывание системной даты
    input_errors[1] = sys_time_retr();        // считывание системного времени
    input_errors[2] = post_date_retr();       // считывание даты отложенного старта
    input_errors[3] = post_time_retr();       // считывание времени отложенного старта
    input_errors[4] = valid_pwr_400_retr();   // считывание допустимой мощности сети 400 В
    input_errors[5] = ambient_temp_retr();    // считывание температуры наружного воздуха
    input_errors[6] = temp_offset_retr();     // считывание сдвига уставки температуры
    input_errors[7] = cmd_check_boxes_retr(); // считывание команд из чекбоксов

    stat_check_boxes_retr(); // считывание команд из чекбоксов

    errors_printing();      // печать ошибок в строку Служебной информации
}




