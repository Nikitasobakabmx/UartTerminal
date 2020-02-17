#include <list>
#include <string>
#include <bitset>
#include <QByteArray>

#include "message.h"
#include "comunication.h"
#include "connectionexception.h"
#include "NullPointException.h"


/*
 * in this we connect to uart port? that will be used for sending
 *
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 *              Accaunt should be located in a heap
 *              accaunt can't copy, you give an object
 *              Comunication by himself delete Accaunt, dont touch it!!!!
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 *
*/
Comunication::Comunication(Accaunt* companion)
{
    _companion =companion;
    //callback
    QObject::connect(_companion, SIGNAL(dataTerminalReadyChanged(bool set)), this, SLOT(getMsgSlot()));
}

void Comunication::send(std::string msg)
{
    if(_sendMessageStory == nullptr)
        _sendMessageStory = new std::list<Message*>();
    _sendMessageStory->push_back(new Message(msg));
    //may bee this work
    // this may be doesnt work, because i send str, but need biset or qbitearray
    if(!_companion->isOpen())
        throw new ConnectionException("conection is falled");
    QByteArray tmp(msg.c_str(), (int)msg.length());
    _companion->write(tmp);
}

/*
 * callback triggered on getting massage
*/
void Comunication::getMsgSlot()
{
    if(!_companion->isOpen())
        throw new ConnectionException("conection is falled");
    QByteArray tmp = _companion->readAll();
    //look like a crutch, it's expensive, need edit
    Message *tmpPtr = new Message(*(new std::string(tmp.constData(), (int)tmp.length())));
    _getMessageStory->push_back(tmpPtr);
}
std::list<Message*>* Comunication::getStory()
{
    if(_sendMessageStory == nullptr)
        throw new NullPointException("Story is empty¯\\_(ツ)_/¯");
    return _sendMessageStory;
}
std::list<Message*>* Comunication::getEnemyStory()
{
    if(_getMessageStory == nullptr)
        throw new NullPointException("Story is empty¯\\_(ツ)_/¯");
    return _getMessageStory;
}

Comunication::~Comunication()
{
    if (_sendMessageStory != nullptr)
        delete _sendMessageStory;
    if(_getMessageStory != nullptr)
        delete _getMessageStory;
    if(_companion != nullptr)
        delete _companion;
}





















