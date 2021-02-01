/* @brief  Файл service_info.cpp содержит методы обработки посылки сервисных сообщений rx_service_info[8]
 */

#include "train_imitator.h"
#include "ui_train_imitator.h"
#include "bits.h"


/* ***************************************************************************************
 *  МЕТОДЫ
 * ***************************************************************************************
 */

/* @brief  Метод слота реализации сервисных битов, полученных
 * в посылке rx_service_info[8] 0x1F6/0x202 - проставление галочек в чекбоксах.
 * @param  None
 * @retval None
 */
void train_imitator::gui_service(void)
{
    uint16_t tmp_life_cnt = 0;  // счётчик жизни

    // rx_service_info[AH]
    if(rx_service_info[AH] & BIT_VOZD_FILTR_ZASOR){ui->checkBox_40->setCheckState(Qt::Checked);}
    else{ui->checkBox_40->setCheckState(Qt::Unchecked);}
    if(rx_service_info[AH] & BIT_RESURS_LAMP_UOV_ZAKON){ui->checkBox_55->setCheckState(Qt::Checked);}
    else{ui->checkBox_55->setCheckState(Qt::Unchecked);}
    if(rx_service_info[AH] & BIT_RESURS_VENT_PRIT_ZAKON){ui->checkBox_56->setCheckState(Qt::Checked);}
    else{ui->checkBox_56->setCheckState(Qt::Unchecked);}
    if(rx_service_info[AH] & BIT_RESURS_VENT_OTRAB_ZAKON){ui->checkBox_63->setCheckState(Qt::Checked);}
    else{ui->checkBox_63->setCheckState(Qt::Unchecked);}
    if(rx_service_info[AH] & BIT_RESURS_OTOP_3000_ZAKON){ui->checkBox_64->setCheckState(Qt::Checked);}
    else{ui->checkBox_64->setCheckState(Qt::Unchecked);}
    if(rx_service_info[AH] & BIT_RESURS_OTOP_400_ZAKON){ui->checkBox_65->setCheckState(Qt::Checked);}
    else{ui->checkBox_65->setCheckState(Qt::Unchecked);}
    if(rx_service_info[AH] & BIT_RESURS_KOMPR1_ZAKON){ui->checkBox_66->setCheckState(Qt::Checked);}
    else{ui->checkBox_66->setCheckState(Qt::Unchecked);}
    if(rx_service_info[AH] & BIT_RESURS_KOMPR2_ZAKON){ui->checkBox_67->setCheckState(Qt::Checked);}
    else{ui->checkBox_67->setCheckState(Qt::Unchecked);}

    // rx_service_info[AL]
    if(rx_service_info[AL] & BIT_RESURS_VENT_COND_ZAKON){ui->checkBox_68->setCheckState(Qt::Checked);}
    else{ui->checkBox_68->setCheckState(Qt::Unchecked);}

    // rx_service_info[BH] и rx_service_info[BL] - счётчик жизни
    tmp_life_cnt = (rx_service_info[BH] << 8);
    tmp_life_cnt |= rx_service_info[BL];
    ui->label_85->setText(QString::number(tmp_life_cnt));
}



/* ***************************************************************************************
 *  ТЕСТЫ
 * ***************************************************************************************
 */

// тестирование - заполнение массива rx_service_info[8] для целей тестирования
void train_imitator::service_simulate(void)
{
// ***************** rx_service_info[AH]
    rx_service_info[AH] |= BIT_VOZD_FILTR_ZASOR;
    rx_service_info[AH] |= BIT_RESURS_LAMP_UOV_ZAKON;
    rx_service_info[AH] |= BIT_RESURS_VENT_PRIT_ZAKON;
    rx_service_info[AH] |= BIT_RESURS_VENT_OTRAB_ZAKON;
    rx_service_info[AH] |= BIT_RESURS_OTOP_3000_ZAKON;
    rx_service_info[AH] |= BIT_RESURS_OTOP_400_ZAKON;
    rx_service_info[AH] |= BIT_RESURS_KOMPR1_ZAKON;
    rx_service_info[AH] |= BIT_RESURS_KOMPR2_ZAKON;

// ***************** rx_service_info[AL]
    rx_service_info[AL] |= BIT_RESURS_VENT_COND_ZAKON;


// ***************** rx_service_info[BH] и rx_service_info[BL] - счётчик жизни
    rx_service_info[BH] = 0x00;
    rx_service_info[BL] = 0xCD; //  пусть будет 205

}
