#include "train_imitator.h"
#include "ui_train_imitator.h"
#include "bits.h"

train_imitator::train_imitator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::train_imitator)
{
    ui->setupUi(this);

    CiInit();           // инициализируем библиотеку CHAI для can адаптера
    interface_init();   // первичная инициализации интерфейса
    can_arrays_init();  // инициализируем нулями массивы can
    memcpy(input_errors, init_array, 8);   // хранит ошибки ввода данных
    timers_init();     // инициализация и запуск таймеров


    ui->label_9->setText(QTime::currentTime().toString("hh:mm:ss"));  // текущее время

    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(tab_commands())); // кнопка "задать параметры"

    // коннект на нажате кнопки "подключиться"
    connect(ui->pushButton_5, SIGNAL(clicked(bool)), this, SLOT(on_btn_connect()));

    // группа слотов таймеров для регулярных отправок посылок can
    connect(timer_sys_time, SIGNAL(timeout()), this, SLOT(send_sys_time()));
    connect(timer_post_start, SIGNAL(timeout()), this, SLOT(send_post_start()));
    connect(timer_commands, SIGNAL(timeout()), this, SLOT(send_commands()));
    connect(timer_rx_data, SIGNAL(timeout()), this, SLOT(receive_all_msgs()));


}

train_imitator::~train_imitator()
{
    delete ui;
}

/* @brief  Метод первичной инициализации интерфейса
 * @param  None
 * @retval None
 */
void train_imitator::interface_init(void)
{
    ui->checkBox_30->setCheckState(Qt::Checked);    // ставим галочку напротив "Отключение"

    // первичное заполнение lineEdit-ов для целей отладки
    ui->lineEdit_5->setText("5");
    ui->lineEdit_6->setText("5");
    ui->lineEdit_7->setText("2021");

    ui->lineEdit->setText("5");
    ui->lineEdit_2->setText("5");
    ui->lineEdit_3->setText("5");
    ui->lineEdit_4->setText("5");

    ui->lineEdit_8->setText("5");
    ui->lineEdit_9->setText("5");
    ui->lineEdit_10->setText("2021");

    ui->lineEdit_11->setText("5");
    ui->lineEdit_12->setText("5");
    ui->lineEdit_13->setText("5");
    ui->lineEdit_14->setText("5");

    ui->lineEdit_15->setText("5");
    ui->lineEdit_16->setText("5");
    ui->lineEdit_17->setText("5");

}

/* @brief  Метод инициализации массивов can нулями
 * @param  None
 * @retval None
 */
void train_imitator::can_arrays_init(void)
{
    can_stat = OFF;   // статус адаптера - откл.

    uint8_t init_array[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    memcpy(tx_time, init_array, 8);
    memcpy(tx_post_start, init_array, 8);
    memcpy(tx_commands, init_array, 8);
    memcpy(rx_diag_data, init_array, 8);
    memcpy(rx_failuries, init_array, 8);
    memcpy(rx_service_info, init_array, 8);

    // методы для тестирования
//    diag_simulate();
//    failuries_simulate();
//    service_simulate();

}

void train_imitator::timers_init(void)
{
    // создаём объекты таймеров
    timer_sys_time = new QTimer();   // объект таймера системного времени
    timer_post_start = new QTimer(); // объект таймера отлож. старта
    timer_commands = new QTimer();   // объект таймера команд
    timer_rx_data = new QTimer();    // объект таймера для принятия посылок

    // и запускаем их каждый со своим периодом
    timer_sys_time->start(50);      // 50
    timer_post_start->start(1000);  // 1000
    timer_commands->start(100);     // 100
    timer_rx_data->start(200);      // 3 посылки с интервалом 100 мс
}






