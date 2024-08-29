#-------------------------------------------------
#
# Project created by QtCreator 2019-11-15T08:26:36
#
#-------------------------------------------------

QT       += core gui network serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = app-arm
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    logindialog.cpp \
    monitorwindow.cpp \
    monitorarea.cpp \
    settingwindow.cpp \
    keyboardwindow.cpp

HEADERS += \
        mainwindow.h \
    logindialog.h \
    protocol.h \
    monitorwindow.h \
    monitorarea.h \
    settingwindow.h \
    keyboardwindow.h

FORMS += \
        mainwindow.ui \
    logindialog.ui \
    monitorwindow.ui \
    monitorarea.ui \
    settingwindow.ui \
    keyboardwindow.ui

RESOURCES += \
    res.qrc
