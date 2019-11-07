#include "pinmanager.h"
#include <QTextStream>
#include"lib/simplecrypt.h"


PinManager::PinManager()
{
    pintxt = new QFile("pin.txt");
    SimpleCrypt crypto(Q_UINT64_C(0x0be919fe8c95bc14)); //some random number
    if(!((*pintxt).exists("pin.txt"))){

        (*pintxt).open(QIODevice::ReadWrite | QFile::Text);
        QTextStream stream(pintxt);
        unsigned short int p = 0000; //DEFAULT PIN
        QString pin_crypted = crypto.encryptToString(QString::number(p));
        stream<<pin_crypted;
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
    SimpleCrypt crypto(Q_UINT64_C(0x0be919fe8c95bc14)); //some random number
    QString pin_decrypted = crypto.decryptToString(stream.readAll());
    if(p == pin_decrypted.toUShort()){
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
    SimpleCrypt crypto(Q_UINT64_C(0x0be919fe8c95bc14)); //some random number
    QString pin_crypted = crypto.encryptToString(QString::number(newPin));
    stream<<pin_crypted;
    (*pintxt).flush();
    (*pintxt).close();
}
