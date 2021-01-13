/* @brief  Файл failuries_data.cpp содержит методы обработки посылки с отказами rx_failuries[8]
 */

#include "train_imitator.h"
#include "ui_train_imitator.h"
#include "bits.h"


/* ***************************************************************************************
 *  СЛОТЫ
 * ***************************************************************************************
 */

/* @brief  Метод слота реализации битов отказов, полученных
 * в посылке rx_failuries[8] 0x1F5/0x201 - проставление галочек в чекбоксах.
 * @param  None
 * @retval None
 */
void train_imitator::failuries(void)
{
    // rx_failuries[AH]
    if(rx_failuries[AH] & BIT_3000_V_OTSUT){ui->checkBox_73->setCheckState(Qt::Checked);}
    else{ui->checkBox_73->setCheckState(Qt::Unchecked);}
    if(rx_failuries[AH] & BIT_400_V_OTSUT){ui->checkBox_76->setCheckState(Qt::Checked);}
    else{ui->checkBox_76->setCheckState(Qt::Unchecked);}
    if(rx_failuries[AH] & BIT_OTKAZ_VENT_PRIT_1){ui->checkBox_78->setCheckState(Qt::Checked);}
    else{ui->checkBox_78->setCheckState(Qt::Unchecked);}
    if(rx_failuries[AH] & BIT_OTKAZ_VENT_PRIT_2){ui->checkBox_74->setCheckState(Qt::Checked);}
    else{ui->checkBox_74->setCheckState(Qt::Unchecked);}
    if(rx_failuries[AH] & BIT_OTKAZ_VENT_OTR_VOZD){ui->checkBox_81->setCheckState(Qt::Checked);}
    else{ui->checkBox_81->setCheckState(Qt::Unchecked);}
    if(rx_failuries[AH] & BIT_OTKAZ_KLAP_NAR_VOZD_1){ui->checkBox_79->setCheckState(Qt::Checked);}
    else{ui->checkBox_79->setCheckState(Qt::Unchecked);}
    if(rx_failuries[AH] & BIT_OTKAZ_KLAP_NAR_VOZD_2){ui->checkBox_72->setCheckState(Qt::Checked);}
    else{ui->checkBox_72->setCheckState(Qt::Unchecked);}
    if(rx_failuries[AH] & BIT_OTKAZ_KLAP_REC_VOZD_1){ui->checkBox_82->setCheckState(Qt::Checked);}
    else{ui->checkBox_82->setCheckState(Qt::Unchecked);}

    // rx_failuries[AL]
    if(rx_failuries[AL] & BIT_OTKAZ_KLAP_REC_VOZD_2){ui->checkBox_70->setCheckState(Qt::Checked);}
    else{ui->checkBox_70->setCheckState(Qt::Unchecked);}
    if(rx_failuries[AL] & BIT_OTKAZ_RASPR_KL_OT_OKHL){ui->checkBox_71->setCheckState(Qt::Checked);}
    else{ui->checkBox_71->setCheckState(Qt::Unchecked);}
    if(rx_failuries[AL] & BIT_OTKAZ_POZHARN_KLAP){ui->checkBox_75->setCheckState(Qt::Checked);}
    else{ui->checkBox_75->setCheckState(Qt::Unchecked);}

    // rx_failuries[BH]
    if(rx_failuries[BH] & BIT_OTKAZ_DAT_TEMP_NAR_VOZD){ui->checkBox_80->setCheckState(Qt::Checked);}
    else{ui->checkBox_80->setCheckState(Qt::Unchecked);}
    if(rx_failuries[BH] & BIT_OTKAZ_DAT_TEMP_PRIT_VOZD){ui->checkBox_69->setCheckState(Qt::Checked);}
    else{ui->checkBox_69->setCheckState(Qt::Unchecked);}
    if(rx_failuries[BH] & BIT_OTKAZ_DAT_TEMP_REC_VOZD){ui->checkBox_77->setCheckState(Qt::Checked);}
    else{ui->checkBox_77->setCheckState(Qt::Unchecked);}
    if(rx_failuries[BH] & BIT_OTKAZ_DAT_TEMP_SAL_1){ui->checkBox_83->setCheckState(Qt::Checked);}
    else{ui->checkBox_83->setCheckState(Qt::Unchecked);}
    if(rx_failuries[BH] & BIT_OTKAZ_DAT_TEMP_SAL_2){ui->checkBox_84->setCheckState(Qt::Checked);}
    else{ui->checkBox_84->setCheckState(Qt::Unchecked);}
    if(rx_failuries[BH] & BIT_OTKAZ_DAT_CO2){ui->checkBox_2->setCheckState(Qt::Checked);}
    else{ui->checkBox_2->setCheckState(Qt::Unchecked);}
    if(rx_failuries[BH] & BIT_OTKAZ_LAMP_OBEZZARAZH_1){ui->checkBox_41->setCheckState(Qt::Checked);}
    else{ui->checkBox_41->setCheckState(Qt::Unchecked);}
    if(rx_failuries[BH] & BIT_OTKAZ_LAMP_OBEZZARAZH_2){ui->checkBox_42->setCheckState(Qt::Checked);}
    else{ui->checkBox_42->setCheckState(Qt::Unchecked);}

    // rx_failuries[BL]
    if(rx_failuries[BL] & BIT_OTKAZ_LAMP_OBEZZARAZH_3){ui->checkBox_43->setCheckState(Qt::Checked);}
    else{ui->checkBox_43->setCheckState(Qt::Unchecked);}
    if(rx_failuries[BL] & BIT_OTKAZ_LAMP_OBEZZARAZH_4){ui->checkBox_44->setCheckState(Qt::Checked);}
    else{ui->checkBox_44->setCheckState(Qt::Unchecked);}
    if(rx_failuries[BL] & BIT_OTKAZ_LAMP_OBEZZARAZH_5){ui->checkBox_45->setCheckState(Qt::Checked);}
    else{ui->checkBox_45->setCheckState(Qt::Unchecked);}
    if(rx_failuries[BL] & BIT_OTKAZ_LAMP_OBEZZARAZH_6){ui->checkBox_46->setCheckState(Qt::Checked);}
    else{ui->checkBox_46->setCheckState(Qt::Unchecked);}

    // rx_failuries[CH]
    if(rx_failuries[CH] & BIT_OTKAZ_OTOP_3000_SEC_1){ui->checkBox_47->setCheckState(Qt::Checked);}
    else{ui->checkBox_47->setCheckState(Qt::Unchecked);}
    if(rx_failuries[CH] & BIT_OTKAZ_OTOP_3000_SEC_2){ui->checkBox_48->setCheckState(Qt::Checked);}
    else{ui->checkBox_48->setCheckState(Qt::Unchecked);}
    if(rx_failuries[CH] & BIT_OTKAZ_OTOP_400_V){ui->checkBox_49->setCheckState(Qt::Checked);}
    else{ui->checkBox_49->setCheckState(Qt::Unchecked);}
    if(rx_failuries[CH] & BIT_OTKAZ_RECIRC_NAGR_SAL){ui->checkBox_50->setCheckState(Qt::Checked);}
    else{ui->checkBox_50->setCheckState(Qt::Unchecked);}
    if(rx_failuries[CH] & BIT_OTKAZ_KOMPRESSOR_1){ui->checkBox_51->setCheckState(Qt::Checked);}
    else{ui->checkBox_51->setCheckState(Qt::Unchecked);}
    if(rx_failuries[CH] & BIT_OTKAZ_KOMPRESSOR_2){ui->checkBox_52->setCheckState(Qt::Checked);}
    else{ui->checkBox_52->setCheckState(Qt::Unchecked);}
    if(rx_failuries[CH] & BIT_OTKAZ_DAT_DAVL_COND_1){ui->checkBox_53->setCheckState(Qt::Checked);}
    else{ui->checkBox_53->setCheckState(Qt::Unchecked);}
    if(rx_failuries[CH] & BIT_OTKAZ_DAT_DAVL_COND_2){ui->checkBox_54->setCheckState(Qt::Checked);}
    else{ui->checkBox_54->setCheckState(Qt::Unchecked);}

    // rx_failuries[DH] критические отказы
        if(rx_failuries[DH] & BIT_OTKAZ_VSEKH_VENT_PRIT){ui->checkBox_57->setCheckState(Qt::Checked);}
        else{ui->checkBox_57->setCheckState(Qt::Unchecked);}
        if(rx_failuries[DH] & BIT_OTKAZ_VSEKH_SEC_OTOP){ui->checkBox_58->setCheckState(Qt::Checked);}
        else{ui->checkBox_58->setCheckState(Qt::Unchecked);}
        if(rx_failuries[DH] & BIT_OTKAZ_VSEKH_KOMPRESS){ui->checkBox_59->setCheckState(Qt::Checked);}
        else{ui->checkBox_59->setCheckState(Qt::Unchecked);}
        if(rx_failuries[DH] & BIT_OTKAZ_VENT_KONDENSAT){ui->checkBox_60->setCheckState(Qt::Checked);}
        else{ui->checkBox_60->setCheckState(Qt::Unchecked);}
        if(rx_failuries[DH] & BIT_OTKAZ_UOV_VSEKH_LAMP){ui->checkBox_61->setCheckState(Qt::Checked);}
        else{ui->checkBox_61->setCheckState(Qt::Unchecked);}
        if(rx_failuries[DH] & BIT_POZHAR){ui->checkBox_62->setCheckState(Qt::Checked);}
        else{ui->checkBox_62->setCheckState(Qt::Unchecked);}
}



/* ***************************************************************************************
 *  ТЕСТЫ
 * ***************************************************************************************
 */

// тестирование - заполнение массива rx_failuries[8] для целей тестирования
void train_imitator::failuries_simulate(void)
{
// ***************** rx_diag_data[AH]
    rx_failuries[AH] |= BIT_3000_V_OTSUT;
    rx_failuries[AH] |= BIT_400_V_OTSUT;
    rx_failuries[AH] |= BIT_OTKAZ_VENT_PRIT_1;
    rx_failuries[AH] |= BIT_OTKAZ_VENT_PRIT_2;
    rx_failuries[AH] |= BIT_OTKAZ_VENT_OTR_VOZD;
    rx_failuries[AH] |= BIT_OTKAZ_KLAP_NAR_VOZD_1;
    rx_failuries[AH] |= BIT_OTKAZ_KLAP_NAR_VOZD_2;
    rx_failuries[AH] |= BIT_OTKAZ_KLAP_REC_VOZD_1;

// ***************** rx_diag_data[AL]
    rx_failuries[AL] |= BIT_OTKAZ_KLAP_REC_VOZD_2;
    rx_failuries[AL] |= BIT_OTKAZ_RASPR_KL_OT_OKHL;
    rx_failuries[AL] |= BIT_OTKAZ_POZHARN_KLAP;

// ***************** rx_diag_data[BH]
    rx_failuries[BH] |= BIT_OTKAZ_DAT_TEMP_NAR_VOZD;
    rx_failuries[BH] |= BIT_OTKAZ_DAT_TEMP_PRIT_VOZD;
    rx_failuries[BH] |= BIT_OTKAZ_DAT_TEMP_REC_VOZD;
    rx_failuries[BH] |= BIT_OTKAZ_DAT_TEMP_SAL_1;
    rx_failuries[BH] |= BIT_OTKAZ_DAT_TEMP_SAL_2;
    rx_failuries[BH] |= BIT_OTKAZ_DAT_CO2;
    rx_failuries[BH] |= BIT_OTKAZ_LAMP_OBEZZARAZH_1;
    rx_failuries[BH] |= BIT_OTKAZ_LAMP_OBEZZARAZH_2;

// ***************** rx_diag_data[BL]
    rx_failuries[BL] |= BIT_OTKAZ_LAMP_OBEZZARAZH_3;
    rx_failuries[BL] |= BIT_OTKAZ_LAMP_OBEZZARAZH_4;
    rx_failuries[BL] |= BIT_OTKAZ_LAMP_OBEZZARAZH_5;
    rx_failuries[BL] |= BIT_OTKAZ_LAMP_OBEZZARAZH_6;

// ***************** rx_diag_data[CH]
    rx_failuries[CH] |= BIT_OTKAZ_OTOP_3000_SEC_1;
    rx_failuries[CH] |= BIT_OTKAZ_OTOP_3000_SEC_2;
    rx_failuries[CH] |= BIT_OTKAZ_OTOP_400_V;
    rx_failuries[CH] |= BIT_OTKAZ_RECIRC_NAGR_SAL;
    rx_failuries[CH] |= BIT_OTKAZ_KOMPRESSOR_1;
    rx_failuries[CH] |= BIT_OTKAZ_KOMPRESSOR_2;
    rx_failuries[CH] |= BIT_OTKAZ_DAT_DAVL_COND_1;
    rx_failuries[CH] |= BIT_OTKAZ_DAT_DAVL_COND_2;

// ***************** rx_diag_data[DH]
    rx_failuries[DH] |= BIT_OTKAZ_VSEKH_VENT_PRIT;
    rx_failuries[DH] |= BIT_OTKAZ_VSEKH_SEC_OTOP;
    rx_failuries[DH] |= BIT_OTKAZ_VSEKH_KOMPRESS;
    rx_failuries[DH] |= BIT_OTKAZ_VENT_KONDENSAT;
    rx_failuries[DH] |= BIT_OTKAZ_UOV_VSEKH_LAMP;
    rx_failuries[DH] |= BIT_POZHAR;





}
