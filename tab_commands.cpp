/* @brief  Файл tab_commands.cpp содержит методы, реализующие функционирование
 * закладки КОМАНДЫ
 */

#include "train_imitator.h"
#include "ui_train_imitator.h"

/* @brief  Метод слота на нажатие кнопки "Задать параметры"
 * @detail По нажатию кнопки происходит считывание в 3-и tx-массива
 *  всех системных настроек и битов команд.
 * @param  None
 * @retval None
 */
void train_imitator::tab_commands(void)
{
    sys_date_retr();        // считывание системной даты
    sys_time_retr();        // считывание системного времени
    post_date_retr();       // считывание даты отложенного старта
    post_time_retr();       // считывание времени отложенного старта
    valid_pwr_400();        // считывание допустимой мощности сети 400 В

    // счит. темп. наруж. воздуха
    // счит. смещ. темп. уставки

    // метод считывания битов команд




}

/* @brief  Метод считывания в массив tx_time[8] системной даты
 * @param  None
 * @retval None
 */
void train_imitator::sys_date_retr(void)
{
    // **********  считываем дату (день, месяц, год)  *****************************
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
         ui->label_2->setText("неправильный формат числа, месяца или года системной даты");
         ui->label_2->setStyleSheet("QLabel{color: rgb(255, 10, 0); }");  // делаем текст красным
     }
     else
     {  // если прошли проверку
         tx_time[AH] = (year>>8);
         tx_time[AL] = year;
         tx_time[BH] = month;
         tx_time[BL] = day;

         ui->label_2->setText("");  // удаляем аварийную надпись
         ui->label_2->setStyleSheet("QLabel{color: rgb(0, 0, 0); }");  // делаем текст чёрным
     }
//        ui->label_2->setText(QString::number(date));
}


/* @brief  Метод считывания в массив tx_time[8] системного времени
 * @param  None
 * @retval None
 */
void train_imitator::sys_time_retr(void)
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
         ui->label_2->setText("неправильный формат часов, мин., сек. или сот. долей сек. системного времени");
         ui->label_2->setStyleSheet("QLabel{color: rgb(255, 10, 0); }");  // делаем текст красным
     }
     else
     {  // если прошли проверку
         tx_time[CH] = min;
         tx_time[CL] = hour;
         tx_time[DH] = h_of_sec;
         tx_time[DL] = sec;

         ui->label_2->setText("");  // удаляем аварийную надпись
         ui->label_2->setStyleSheet("QLabel{color: rgb(0, 0, 0); }");  // делаем текст чёрным
     }
}

/* @brief  Метод считывания в массив tx_post_start[8] даты отложенного старта
 * @param  None
 * @retval None
 */
void train_imitator::post_date_retr(void)
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
         ui->label_2->setText("неправильный формат числа, месяца или года системной даты");
         ui->label_2->setStyleSheet("QLabel{color: rgb(255, 10, 0); }");  // делаем текст красным
     }
     else
     {  // если прошли проверку
         tx_post_start[AH] = (year>>8);
         tx_post_start[AL] = year;
         tx_post_start[BH] = month;
         tx_post_start[BL] = day;

         ui->label_2->setText("");  // удаляем аварийную надпись
         ui->label_2->setStyleSheet("QLabel{color: rgb(0, 0, 0); }");  // делаем текст чёрным
     }
}

/* @brief  Метод считывания в массив tx_post_start[8] времени отложенного старта
 * @param  None
 * @retval None
 */
void train_imitator::post_time_retr(void)
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
         ui->label_2->setText("неправильный формат часов, мин., сек. или сот. долей сек. системного времени");
         ui->label_2->setStyleSheet("QLabel{color: rgb(255, 10, 0); }");  // делаем текст красным
     }
     else
     {  // если прошли проверку
         tx_post_start[CH] = min;
         tx_post_start[CL] = hour;
         tx_post_start[DH] = h_of_sec;
         tx_post_start[DL] = sec;

         ui->label_2->setText("");  // удаляем аварийную надпись
         ui->label_2->setStyleSheet("QLabel{color: rgb(0, 0, 0); }");  // делаем текст чёрным
     }
}

/* @brief  Метод считывания в массив tx_commands[8] допустимой мощности сети 400 В
 * @param  None
 * @retval None
 */
void train_imitator::valid_pwr_400(void)
{
    // **********  считываем мощность  *****************************
    QString str = ui->lineEdit_15->text();    // забираем текст из строки
    uint8_t pwr = str.toInt(&str_error, 10);  // переводим в int

     // проверяем данные на адекватность
     if((pwr == 0) || (pwr > 254))
     {
         tx_commands[BH] = tx_commands[BL] = 0; // обуляем все данные
         ui->label_2->setText("неправильный формат числа, месяца или года системной даты");
         ui->label_2->setStyleSheet("QLabel{color: rgb(255, 10, 0); }");  // делаем текст красным
     }
     else
     {  // если прошли проверку
         tx_commands[BH] = pwr;

         ui->label_2->setText("");  // удаляем аварийную надпись
         ui->label_2->setStyleSheet("QLabel{color: rgb(0, 0, 0); }");  // делаем текст чёрным
     }
}









