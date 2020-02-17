#include "accaunt.h"
#include <exception>
#include "NullPointException.h"
#include <QtSerialPort/QSerialPort>

void Accaunt::setName(std::string name)
{
    _name = new std::string(name);
}

std::string Accaunt::getName()
{
    if (_name == nullptr)
        throw NullPointException("NullPointerException");
    return *_name;
}

//Accaunt::~Accaunt()
//{
//    if(_name != nullptr)
//        delete _name;
//    return;
//}
