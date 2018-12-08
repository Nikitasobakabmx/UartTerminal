#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include <QSerialPortInfo>
#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QtSerialPort/QSerialPort>

struct settingPort
{
  QString name;
  qint32 baudrate;
  QSerialPort::DataBits databits;
  QSerialPort::Parity parity;
  QSerialPort::StopBits stopBits;
  QSerialPort::FlowControl flowControl;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    void windowCreate(int x, int y);
    void setSetting(QString name,
                     QSerialPort::BaudRate baudrate,
                     QSerialPort::DataBits databits,
                     QSerialPort::Parity parity,
                     QSerialPort::StopBits stopBits,
                     QSerialPort::FlowControl flowControl);
    void connectUART();
    void disconect();
    void writeToPort();
    void readPort();
    void TranslateBox();
    ~MainWindow();
public slots:
    void ConnectHandle();
    void sendHandle();
    void reqest();

private:

    Ui::MainWindow *ui;
    QWidget *window;
    QHBoxLayout *hBox;
    QHBoxLayout *buttonBox;
    QHBoxLayout *headLayot;
    QHBoxLayout *textBox;
    QLabel *name;
    QLabel *setOfPort;
    QTextEdit *comPort;
    QPushButton *conectButton;
    QPushButton *sendButton;
    QLabel *status;
    QLabel *sendText;
    QLabel *getText;
    QTextEdit *sendTextBox;
    QTextEdit *getTextBox;
    QVBoxLayout *layout;

    settingPort setting;
    QSerialPort *port = nullptr;
};

#endif // MAINWINDOW_H
