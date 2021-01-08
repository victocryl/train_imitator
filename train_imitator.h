#ifndef TRAIN_IMITATOR_H
#define TRAIN_IMITATOR_H

#include <QWidget>

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

/*******  массивы rx, tx can-посылок *************/
    uint8_t tx_time[8];
    uint8_t tx_post_start[8];
    uint8_t tx_commands[8];
    uint8_t rx_diag_data[8];
    uint8_t rx_failuries[8];
    uint8_t rx_service_info[8];
    uint8_t init_array[8];

    void can_arrays_init(void);



    Ui::train_imitator *ui;
};
#endif // TRAIN_IMITATOR_H
