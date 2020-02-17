#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <accaunt.h>

namespace Ui {
class MainWindow;
}

/*
    start window with messaging
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui = nullptr;
    QPushButton *_sendButton = nullptr;
    QPushButton *_settingButton = nullptr;
    QTextEdit *_textBox = nullptr;
};

#endif // WINDOW_H
