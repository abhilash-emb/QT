#-------------------------------------------------
#
# Project created by QtCreator 2013-08-28T14:11:48
#
#-------------------------------------------------

QT       += core gui

TARGET = Printer++
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    adminlogin.cpp \
    settings.cpp

HEADERS  += mainwindow.h \
    adminlogin.h \
    settings.h

FORMS    += mainwindow.ui \
    adminlogin.ui \
    settings.ui

QT += sql

include(qextserialport/src/qextserialport.pri)

RESOURCES += \
    images.qrc

RC_FILE = appicon.rc
