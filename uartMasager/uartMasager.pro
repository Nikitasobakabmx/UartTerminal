#-------------------------------------------------
#
# Project created by QtCreator 2019-11-20T14:35:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = uartMasager
TEMPLATE = app


SOURCES += main.cpp\
    NullPointException.cpp \
    addaccauntwindow.cpp \
    connectionexception.cpp \
    mainwindow.cpp \
    message.cpp \
    accaunt.cpp \
    comunication.cpp

HEADERS  += \
    NullPointException.h \
    accaunt.h \
    addaccauntwindow.h \
    comunication.h \
    connectionexception.h \
    mainwindow.h \
    message.h

FORMS    += window.ui
