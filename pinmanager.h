#ifndef PINMANAGER_H
#define PINMANAGER_H

#include <QFile>

class PinManager
{
public:
    PinManager();
    ~PinManager();
    bool isCorret(unsigned short int const p) const;
    bool changePin(unsigned short int const pin,const unsigned short newPin) const;

private:
    QFile* pintxt;
    bool isEqual(const unsigned short p) const;
    void setPin(unsigned short int const p) const;

};


#endif // PINMANAGER_H
