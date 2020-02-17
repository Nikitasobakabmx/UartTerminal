#ifndef UARTSETTING_H
#define UARTSETTING_H

#include <string>
#include <QtSerialPort/QSerialPort>


class Accaunt : public QSerialPort
{
    private:
        std::string *_name;
    public:
        Accaunt(const std::string name):_name(new std::string(name)){}
        void setName(std::string name);
        std::string getName();
        //~Accaunt();
};

#endif // UARTSETTING_H
