#include "train_imitator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    train_imitator w;
    w.show();
    return a.exec();
}
