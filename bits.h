/* Данный хедер содержит биты команд, аварий и сервисных статусов,
 * передаваемых по can-шине между УКВ и СУ верхнего уровня поезда.
*/
#ifndef BITS_H
#define BITS_H

/********** Биты команд закладки Команды, посылки 0x51 \ 0x91 *********/
// AH
#define CMD_RESET                   0xF0
#define CMD_OFF                     0x00
#define CMD_ON                      0x01
#define CMD_OTSTOY                  0x02
#define CMD_MOYKA                   0x03
#define BIT_STATION                 (1<<4)
#define BIT_TONNEL                  (1<<5)
#define BIT_OTKR_DVER               (1<<6)
#define BIT_3000_V                  (1<<7)
// AL
#define BIT_400_V                   (1<<0)
#define BIT_REZH_OGR_MOSCHN         (1<<1)
#define BIT_VKL_COMPR_RAZR          (1<<2)
#define BIT_VKL_REC_NAGR            (1<<3)
#define BIT_SBR_ACTIV_SERV_SOOB     (1<<4)

/********** Биты обратной связи (диагностические), посылки 0x1F4 \ 0x200 *********/
// AH
#define DIAG_MASK                        0x0f
#define BIT_REZH_OFF                     0x00
#define BIT_REZH_ON                      0x01
#define BIT_REZH_OTSTOY                  0x02
#define BIT_REZH_MOYKA                   0x03
#define BIT_REZH_AVAR_VENT               0x04
#define BIT_REZH_AVAR_OTOP               0x05
#define BIT_REZH_STATION                 (1<<4)
#define BIT_REZH_TONNEL                  (1<<5)
#define BIT_REZH_OBOGREV                 (1<<6)
#define BIT_REZH_OKHLAZHD                (1<<7)
// AL
#define BIT_NAGR_3000_V_VKL              (1<<0)

/********** Биты сообщений об отказах УК, посылки 0x1F5 \ 0x201 *********/
// AH
#define BIT_SET_3000_V_OTSUT        (1<<0)
#define BIT_SET_400_V_OTSUT         (1<<1)
#define BIT_OTKAZ_VENT_PRIT_1       (1<<2)
#define BIT_OTKAZ_VENT_PRIT_2       (1<<3)
#define BIT_OTKAZ_VENT_OTR_VOZD     (1<<4)
#define BIT_OTKAZ_KLAP_NAR_VOZD_1   (1<<5)
#define BIT_OTKAZ_KLAP_NAR_VOZD_2   (1<<6)
#define BIT_OTKAZ_KLAP_REC_VOZD_1   (1<<7)
// AL
#define BIT_OTKAZ_KLAP_REC_VOZD_2   (1<<0)
#define BIT_OTKAZ_RASPR_KL_OT_OKHL  (1<<1)
#define BIT_OTKAZ_POZHARN_KLAP      (1<<2)
// BH
#define BIT_OTKAZ_DAT_TEMP_NAR_VOZD     (1<<0)
#define BIT_OTKAZ_DAT_TEMP_PRIT_VOZD    (1<<1)
#define BIT_OTKAZ_DAT_TEMP_REC_VOZD     (1<<2)
#define BIT_OTKAZ_DAT_TEMP_SAL_1        (1<<3)
#define BIT_OTKAZ_DAT_TEMP_SAL_2        (1<<4)
#define BIT_OTKAZ_DAT_CO2               (1<<5)
#define BIT_OTKAZ_LAMP_OBEZZARAZH_1     (1<<6)
#define BIT_OTKAZ_LAMP_OBEZZARAZH_2     (1<<7)
// BL
#define BIT_OTKAZ_LAMP_OBEZZARAZH_3     (1<<0)
#define BIT_OTKAZ_LAMP_OBEZZARAZH_4     (1<<1)
#define BIT_OTKAZ_LAMP_OBEZZARAZH_5     (1<<2)
#define BIT_OTKAZ_LAMP_OBEZZARAZH_6     (1<<3)
// СH
#define BIT_OTKAZ_OTOP_3000_SEC_1   (1<<0)
#define BIT_OTKAZ_OTOP_3000_SEC_2   (1<<1)
#define BIT_OTKAZ_OTOP_400_V        (1<<2)
#define BIT_OTKAZ_RECIRC_NAGR_SAL   (1<<3)
#define BIT_OTKAZ_KOMPRESSOR_1      (1<<4)
#define BIT_OTKAZ_KOMPRESSOR_2      (1<<5)
#define BIT_OTKAZ_DAT_DAVL_COND_1   (1<<6)
#define BIT_OTKAZ_DAT_DAVL_COND_2   (1<<7)
// DH
#define BIT_OTKAZ_VSEKH_VENT_PRIT   (1<<0)
#define BIT_OTKAZ_VSEKH_SEC_OTOP    (1<<1)
#define BIT_OTKAZ_VSEKH_KOMPRESS    (1<<2)
#define BIT_OTKAZ_VENT_KONDENSAT    (1<<3)
#define BIT_OTKAZ_UOV_VSEKH_LAMP    (1<<4)
#define BIT_POZHAR                  (1<<5)

/********** Биты сообщений о сервисном обслуживании УК, посылки 0x1F6 \ 0x202 *********/
// AH
#define BIT_VOZD_FILTR_ZASOR            (1<<0)
#define BIT_RESURS_LAMP_UOV_ZAKON       (1<<1)
#define BIT_RESURS_VENT_PRIT_ZAKON      (1<<2)
#define BIT_RESURS_VENT_OTRAB_ZAKON     (1<<3)
#define BIT_RESURS_OTOP_3000_ZAKON      (1<<4)
#define BIT_RESURS_OTOP_400_ZAKON       (1<<5)
#define BIT_RESURS_KOMPR1_ZAKON         (1<<6)
#define BIT_RESURS_KOMPR2_ZAKON         (1<<7)
// AL
#define BIT_RESURS_VENT_COND_ZAKON      (1<<0)


#endif // BITS_H
