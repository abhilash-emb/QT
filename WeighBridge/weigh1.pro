#-------------------------------------------------
#
# Project created by QtCreator 2012-09-07T15:08:18
#
#-------------------------------------------------

QT       += core gui

TARGET = WeighBridge
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dsettings.cpp \
    dreports.cpp \
    dviewticket.cpp \
    dsecondweight.cpp \
    dfirstweight.cpp \
    tabset.cpp \
    master.cpp

HEADERS  += mainwindow.h \
    dsettings.h \
    dreports.h \
    dviewticket.h \
    dsecondweight.h \
    dfirstweight.h \
    tabset.h \
    master.h \
    Header.h

FORMS    += mainwindow.ui \
    dsettings.ui \
    dreports.ui \
    dviewticket.ui \
    dsecondweight.ui \
    dfirstweight.ui

RESOURCES += \
    resources.qrc

RC_FILE = appicon.rc

QT += sql

include(qext/qextserialport-1.2beta2/src/qextserialport.pri)
