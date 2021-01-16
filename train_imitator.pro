QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    can.cpp \
    diag_data.cpp \
    failuries_data.cpp \
    main.cpp \
    service_info.cpp \
    tab_commands.cpp \
    train_imitator.cpp

HEADERS += \
    bits.h \
    chai.h \
    train_imitator.h

FORMS += \
    train_imitator.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32: LIBS += -L$$PWD/./ -lchai

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
