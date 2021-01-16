#ifndef TRAIN_IMITATOR_H
#define TRAIN_IMITATOR_H

#include <QWidget>
#include <QDebug>
#include <chai.h>

#define ID_TIME         0x10   // посылка даты и времени (для линии В 0x60)
#define ID_POST_START   0x50   // посылка отложенного старта (для линии В 0x90)
#define ID_COMMANDS     0x51   // посылка с командами для УКВ (для линии В 0x91)
#define ID_DIAG         0x1F4  // посылка с диагностическими статусами (для линии В 0x200)
#define ID_FAILS        0x1F5  // посылка с ошибками УКВ (для линии В 0x201)
#define ID_SERVICE      0x1F6  // посылка с сервисной информацией (для линии В 0x202)

QT_BEGIN_NAMESPACE
namespace Ui { class train_imitator; }
QT_END_NAMESPACE

class train_imitator : public QWidget
{
    Q_OBJECT

public:
    train_imitator(QWidget *parent = nullptr);
    ~train_imitator();

private:

Ui::train_imitator *ui;

/*******  вспомогательные переменные *************/
    bool str_error;
    QString brd_name;       // наименование платы адаптера
    QString brd_manuf;      // производитель платы

/*******  рабочие переменные *************/


/*******  массивы rx, tx can-посылок *************/
    uint8_t tx_time[8];             // 0x10 посылка даты и времени (для линии В 0x60)
    uint8_t tx_post_start[8];       // 0x50 посылка отложенного старта (для линии В 0x90)
    uint8_t tx_commands[8];         // 0x51 посылка с командами для УКВ (для линии В 0x91)
    uint8_t rx_diag_data[8];        // 0x1F4 посылка с диагностическими статусами (для линии В 0x200)
    uint8_t rx_failuries[8];        // 0x1F5 посылка с ошибками УКВ (для линии В 0x201)
    uint8_t rx_service_info[8];     // 0x1F6 посылка с сервисной информацией (для линии В 0x202)
    uint8_t init_array[8];

    uint8_t input_errors[8];    // массив ошибок ввода данных

/*******  enum байтов посылок Can *************/
    typedef enum canbytes
    {
        AH,
        AL,
        BH,
        BL,
        CH,
        CL,
        DH,
        DL,
        DATA_NUM
    }TE_canbytes;

/*******  enum кодов ошибок ввода данных *************/
    typedef enum input_errors
    {
        NO_INPUT_ERRORS,
        ER_SYS_DATA,
        ER_SYS_TIME,
        ER_POST_DATA,
        ER_POST_TIME,
        ER_PWR_400,
        ER_AIR_TEMP,
        ER_SET_OFFSET,
        ER_CHECK_BOX
    }TE_input_errors;

/*******  методы ******************************/
    // первичная инициализация
    void interface_init(void);      // первичная инициализация интерфейса
    void can_arrays_init(void);     // инициализация can массивов нулями

    void diag_simulate(void);       // для тестов - симуляция посылки rx_diag_data
    void failuries_simulate(void);  // для тестов - симуляция посылки rx_failuries
    void service_simulate(void);    // для тестов - симуляция посылки rx_service_info

    void can_error_handler(_s16 er_code);   // обработчик ошибок can
    _s16 board_info(void);                  // сбор инфо об адаптере

    // считывание данных и команд
    uint8_t sys_date_retr(void);       // считывание системной даты
    uint8_t sys_time_retr(void);       // считывание системного времени
    uint8_t post_date_retr(void);      // считывание даты отложенного старта
    uint8_t post_time_retr(void);      // считывание времени отложенного старта
    uint8_t valid_pwr_400_retr(void);  // считывание допустимой мощности сети 400 В
    uint8_t ambient_temp_retr(void);   // считывание температуры наружного воздуха
    uint8_t temp_offset_retr(void);    // считывание сдвига уставки температуры
    uint8_t cmd_check_boxes_retr(void);// считывание команд из чекбоксов
    void stat_check_boxes_retr(void);  // считывание статусов из чекбоксов

    void errors_printing(void);        // вывод ошибок в Служ. Информацию

/*******  слоты *******************************/
private slots:
    void tab_commands(void);
    void diag(void);
    void failuries(void);
    void service(void);

    void on_btn_connect(void);
    void on_btn_receive(void);




};
#endif // TRAIN_IMITATOR_H
