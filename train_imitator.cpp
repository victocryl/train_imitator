#include "train_imitator.h"
#include "ui_train_imitator.h"

train_imitator::train_imitator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::train_imitator)
{
    ui->setupUi(this);

    can_arrays_init();  // инициализируем нулями массивы can




}

train_imitator::~train_imitator()
{
    delete ui;
}

/* @brief  Метод инициализации массивов can нулями
 * @param  None
 * @retval None
 */
void train_imitator::can_arrays_init(void)
{
    uint8_t init_array[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    memcpy(tx_time, init_array, 8);
    memcpy(tx_post_start, init_array, 8);
    memcpy(tx_commands, init_array, 8);
    memcpy(rx_diag_data, init_array, 8);
    memcpy(rx_failuries, init_array, 8);
    memcpy(rx_service_info, init_array, 8);
}
