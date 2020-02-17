#pragma once

#include <string>


class Message
{
private:
    std::string *_message = nullptr;
    unsigned int _time_stamp = 0;
public:
    Message(std::string msg);
    std::string getContent();
    unsigned int getTime();
    void editContext(std::string msg);
    ~Message();
};

