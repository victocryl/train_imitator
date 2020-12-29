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
    Ui::train_imitator *ui;
};
#endif // TRAIN_IMITATOR_H
