#include "NullPointException.h"

char const* NullPointException::what() const noexcept
{
    return _message->c_str();
}

NullPointException::~NullPointException()
{
    if(_message != nullptr)
        delete _message;
}
