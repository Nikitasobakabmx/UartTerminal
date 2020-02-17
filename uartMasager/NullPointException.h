#ifndef EVERYEXCEPTION_H
#define EVERYEXCEPTION_H

#include <exception>
#include <string>


class NullPointException : public std::exception
{
private:
    std::string *_message = nullptr;
public:
    explicit NullPointException(const char* mess):_message(new std::string(mess)){}
    virtual char const* what() const noexcept;
    ~NullPointException();
};

#endif // EVERYEXCEPTION_H
