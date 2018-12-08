#include "mainwindow.h"
#include <QApplication>

void setdMassage();
void getMassage();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow start;
    start.windowCreate(500, 300);
    /*start.setSetting("COM6",
                        QSerialPort::Baud9600,
                        QSerialPort::Data8,
                        QSerialPort:: NoParity,
                        QSerialPort::TwoStop,
                        QSerialPort::NoFlowControl);*/
    return a.exec();
}


