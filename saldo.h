#ifndef SALDO_H
#define SALDO_H

#include"Model.h"
#include <QFile>

class Saldo : public Model
{
private:
    double saldo;
    QFile* saldotxt;
public:
    Saldo();
    double getSaldo() const;
    void setSaldo(const double v);
    ~Saldo();
};

#endif // SALDO_H
