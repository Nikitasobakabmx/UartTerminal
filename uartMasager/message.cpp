#include "message.h"
#include <ctime>

Message::Message(std::string msg)
{
    _message = new std::string(msg);
    _time_stamp = time(nullptr);
}
std::string Message::getContent()
{
    return *_message;
}
unsigned int Message::getTime()
{
    return _time_stamp;
}
void Message::editContext(std::string msg)
{
    delete _message;
    _message = new std::string(msg);
}

Message::~Message()
{
    if(_message != nullptr)
        delete _message;
}
