#include "train_imitator.h"
#include "ui_train_imitator.h"

train_imitator::train_imitator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::train_imitator)
{
    ui->setupUi(this);
}

train_imitator::~train_imitator()
{
    delete ui;
}

