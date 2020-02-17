#pragma once

#include <exception>
#include <string>


class ConnectionException : public std::exception
{
    std::string *_message = nullptr;
public:
    ConnectionException(const char* msg):_message(new std::string(msg)){}
    virtual const char * what() const noexcept;
    ~ConnectionException();
};

