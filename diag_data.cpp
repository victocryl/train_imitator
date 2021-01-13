/* @brief  Файл diag_data.cpp содержит метод(ы), реализующие реакцию на
 * получение can посылки 0x1F4/0x200 с диагностическими данными и обратной связью
 * по командам (на закладке "КОМАНДЫ"). Происходит простановка галочек в чекбоксах.
 */

#include "train_imitator.h"
#include "ui_train_imitator.h"
#include "bits.h"


/* ***************************************************************************************
 *  СЛОТЫ
 * ***************************************************************************************
 */

/* @brief  Метод слота реализации диагностических битов, полученных
 * в посылке diag (0x1F4/0x200) - проставление галочек в чекбоксах.
 * @param  None
 * @retval None
 */
void train_imitator::diag(void)
{


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

}
