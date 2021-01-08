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
    sys_date_retr();    // считывание системной даты
    sys_time_retr();    // считывание системного времени

    // ф-ия считывания даты отл. старта
    // ф-ия считывания времени отл. старта
    // считывания мощности 400В
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
         tx_time[BL] = day;
         tx_time[BH] = month;
         tx_time[AL] = year;
         tx_time[AH] = (year>>8);

         ui->label_2->setText("");  // удаляем аварийную надпись
         ui->label_2->setStyleSheet("QLabel{color: rgb(0, 0, 0); }");  // делаем текст чёрным
     }
//        ui->label_2->setText(QString::number(date));
}


/* @brief  Метод считывания в массив tx_time[8] системной даты
 * @param  None
 * @retval None
 */
void train_imitator::sys_time_retr(void)
{

}







