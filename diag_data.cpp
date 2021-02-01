/* @brief  Файл diag_data.cpp содержит метод(ы), реализующие реакцию на
 * получение can посылки 0x1F4/0x200 с диагностическими данными и обратной связью
 * по командам (на закладке "КОМАНДЫ"). Происходит простановка галочек в чекбоксах.
 */

#include "train_imitator.h"
#include "ui_train_imitator.h"
#include "bits.h"


/* ***************************************************************************************
 *  МЕТОДЫ
 * ***************************************************************************************
 */

/* @brief  Метод слота реализации диагностических битов, полученных
 * в посылке diag (0x1F4/0x200) - проставление галочек в чекбоксах.
 * @param  None
 * @retval None
 */
void train_imitator::gui_diag(void)
{
    uint16_t tmp_ambient_temp = 0;   // температура наружного воздуха
    uint16_t tmp_cab_temp = 0;       // температура в салоне
    uint16_t version_maj = 0;        // версия ПО мажорная
    uint16_t version_min = 0;        // версия ПО минорная

    // rx_diag_data[AH]
    if((rx_diag_data[AH] & DIAG_MASK) == BIT_REZH_OFF){ui->checkBox_29->setCheckState(Qt::Checked);}
    else{ui->checkBox_29->setCheckState(Qt::Unchecked);}
    if((rx_diag_data[AH] & DIAG_MASK) == BIT_REZH_ON){ui->checkBox_20->setCheckState(Qt::Checked);}
    else{ui->checkBox_20->setCheckState(Qt::Unchecked);}
    if((rx_diag_data[AH] & DIAG_MASK) == BIT_REZH_OTSTOY){ui->checkBox_8->setCheckState(Qt::Checked);}
    else{ui->checkBox_8->setCheckState(Qt::Unchecked);}
    if((rx_diag_data[AH] & DIAG_MASK) == BIT_REZH_MOYKA){ui->checkBox_21->setCheckState(Qt::Checked);}
    else{ui->checkBox_21->setCheckState(Qt::Unchecked);}
    if((rx_diag_data[AH] & DIAG_MASK) == BIT_REZH_AVAR_VENT){ui->checkBox_26->setCheckState(Qt::Checked);}
    else{ui->checkBox_26->setCheckState(Qt::Unchecked);}
    if((rx_diag_data[AH] & DIAG_MASK) == BIT_REZH_AVAR_OTOP){ui->checkBox_27->setCheckState(Qt::Checked);}
    else{ui->checkBox_27->setCheckState(Qt::Unchecked);}
    if(rx_diag_data[AH] & BIT_REZH_STATION){ui->checkBox_22->setCheckState(Qt::Checked);}
    else{ui->checkBox_22->setCheckState(Qt::Unchecked);}
    if(rx_diag_data[AH] & BIT_REZH_TONNEL){ui->checkBox_23->setCheckState(Qt::Checked);}
    else{ui->checkBox_23->setCheckState(Qt::Unchecked);}
    if(rx_diag_data[AH] & BIT_REZH_OBOGREV){ui->checkBox_24->setCheckState(Qt::Checked);}
    else{ui->checkBox_24->setCheckState(Qt::Unchecked);}
    if(rx_diag_data[AH] & BIT_REZH_OKHLAZHD){ui->checkBox_25->setCheckState(Qt::Checked);}
    else{ui->checkBox_25->setCheckState(Qt::Unchecked);}

    // rx_diag_data[AL]
    if(rx_diag_data[AL] & BIT_NAGR_3000_V_VKL){ui->checkBox_28->setCheckState(Qt::Checked);}
    else{ui->checkBox_28->setCheckState(Qt::Unchecked);}

    // rx_diag_data[BH] и rx_diag_data[BL] - наружная температура
    tmp_ambient_temp = (rx_diag_data[BH] << 8);
    tmp_ambient_temp |= rx_diag_data[BL];
    ui->label_13->setText(QString::number(tmp_ambient_temp/10)+" °C");

    // rx_diag_data[СH] и rx_diag_data[CL] - температура в салоне
    tmp_cab_temp = (rx_diag_data[CH] << 8);
    tmp_cab_temp |= rx_diag_data[CL];
    ui->label_15->setText(QString::number(tmp_cab_temp/10)+" °C");

    // rx_diag_data[СH] и rx_diag_data[CL] - версия ПО
    version_maj = rx_diag_data[DH];
    version_min = rx_diag_data[DL];
    ui->label_7->setText(QString::number(version_maj)+"."+QString::number(version_min));
}

/* ***************************************************************************************
 *  ТЕСТЫ
 * ***************************************************************************************
 */

// тестирование - заполнение массива rx_diag_data[8] для целей тестирования
void train_imitator::diag_simulate(void)
{
// ***************** rx_diag_data[AH]
//    rx_diag_data[AH] &= 0xF0; rx_diag_data[AH] |= BIT_REZH_OFF;
//    rx_diag_data[AH] &= 0xF0; rx_diag_data[AH] |= BIT_REZH_ON;
//    rx_diag_data[AH] &= 0xF0; rx_diag_data[AH] |= BIT_REZH_OTSTOY;
//    rx_diag_data[AH] &= 0xF0; rx_diag_data[AH] |= BIT_REZH_MOYKA;
    rx_diag_data[AH] &= 0xF0; rx_diag_data[AH] |= BIT_REZH_AVAR_VENT;
//    rx_diag_data[AH] &= 0xF0; rx_diag_data[AH] |= BIT_REZH_AVAR_OTOP;

//    rx_diag_data[AH] |= BIT_REZH_STATION;
//    rx_diag_data[AH] |= BIT_REZH_TONNEL;
//    rx_diag_data[AH] |= BIT_REZH_OBOGREV;
//    rx_diag_data[AH] |= BIT_REZH_OKHLAZHD;

// ***************** rx_diag_data[AL]
    rx_diag_data[AL] |= BIT_NAGR_3000_V_VKL;

// ***************** rx_diag_data[BH] и rx_diag_data[BL]
    rx_diag_data[BH] = 0x01;
    rx_diag_data[BL] = 0x7C; //  в сборе 380 будет (38 град)

// ***************** rx_diag_data[CH] и rx_diag_data[CL]
    rx_diag_data[CH] = 0x00;
    rx_diag_data[CL] = 0xDC; //  в сборе 220 будет (22 град)

// ***************** rx_diag_data[DH] и rx_diag_data[DL]
    rx_diag_data[DH] = 14;
    rx_diag_data[DL] = 15; //  версия ПО
}
