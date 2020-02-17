#include "connectionexception.h"

const char* ConnectionException::what() const noexcept
{
    return _message->c_str();
}

ConnectionException::~ConnectionException()
{
    if(_message != nullptr)
        delete _message;
}
