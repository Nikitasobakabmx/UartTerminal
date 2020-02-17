#ifndef COMUNICATION_H
#define COMUNICATION_H

#include <list>
#include <string>
#include <QObject>

#include "accaunt.h"
#include "message.h"


class Comunication : public QObject
{
    public:
        Comunication(Accaunt* companion);
        void send(std::string msg);
        void getMsgSlot();
        std::list<Message*>* getStory();
        std::list<Message*>* getEnemyStory();
        ~Comunication();
    private:
        std::list<Message*> *_sendMessageStory = nullptr;
        std::list<Message*> *_getMessageStory = nullptr;
        Accaunt *_companion = nullptr;
};

#endif // COMUNICATION_H
