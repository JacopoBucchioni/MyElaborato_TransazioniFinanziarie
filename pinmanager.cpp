#include "pinmanager.h"
#include <QTextStream>

PinManager::PinManager()
{
    pintxt = new QFile("pin.txt");
    if(!((*pintxt).exists("pin.txt"))){

        (*pintxt).open(QIODevice::ReadWrite | QFile::Text);
        QTextStream stream(pintxt);
        unsigned short int p = 0000; //DEFAULT PIN
        QString ps = QString::number(p);
        stream<<ps;
        (*pintxt).flush();
        (*pintxt).close();
    }
}

PinManager::~PinManager(){
    delete pintxt;
}


bool PinManager::isCorret(const unsigned short p) const{
    return isEqual(p);
}

bool PinManager::changePin(const unsigned short pin, const unsigned short newPin) const{
    if(isEqual(pin)){
        setPin(newPin);
        return true;
    }
    else {
        return false;
    }
}


bool PinManager::isEqual(const unsigned short p) const{
    (*pintxt).open(QIODevice::ReadOnly | QFile::Text);
    QTextStream stream(pintxt);
    if(p == (stream.readAll()).toUShort()){
        (*pintxt).flush();
        (*pintxt).close();
        return true;
    }
    else{
        (*pintxt).flush();
        (*pintxt).close();
        return false;
    }
}

void PinManager::setPin(const unsigned short newPin) const{
    (*pintxt).open(QIODevice::ReadWrite | QFile::Text);
    QTextStream stream(pintxt);
    QString ps = QString::number(newPin);
    stream<<ps;
    (*pintxt).flush();
    (*pintxt).close();
}
