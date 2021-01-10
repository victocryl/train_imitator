#ifndef TRAIN_IMITATOR_H
#define TRAIN_IMITATOR_H

#include <QWidget>

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

/*******  массивы rx, tx can-посылок *************/
    uint8_t tx_time[8];
    uint8_t tx_post_start[8];
    uint8_t tx_commands[8];
    uint8_t rx_diag_data[8];
    uint8_t rx_failuries[8];
    uint8_t rx_service_info[8];
    uint8_t init_array[8];

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

/*******  методы ******************************/
    // первичная инициализация
    void interface_init(void);      // первичная инициализация интерфейса
    void can_arrays_init(void);     // инициализация can массивов нулями

    // считывание данных и команд
    void sys_date_retr(void);       // считывание системной даты
    void sys_time_retr(void);       // считывание системного времени
    void post_date_retr(void);      // считывание даты отложенного старта
    void post_time_retr(void);      // считывание времени отложенного старта
    void valid_pwr_400_retr(void);  // считывание допустимой мощности сети 400 В
    void ambient_temp_retr(void);   // считывание температуры наружного воздуха
    void temp_offset_retr(void);    // считывание сдвига уставки температуры
    void check_boxes_retr(void);    // считывание команд из чекбоксов

/*******  слоты *******************************/
private slots:
    void tab_commands(void);



};
#endif // TRAIN_IMITATOR_H
