#include "saldo.h"

#include<QTextStream>
#include<iostream>
#include"lib/simplecrypt.h"

Saldo::Saldo()
{
    saldotxt = new QFile("saldo.txt");
    SimpleCrypt crypto(Q_UINT64_C(0x0c2ad4a4acb9f023)); //some random number
    if(!((*saldotxt).exists("saldo.txt"))){

        (*saldotxt).open(QIODevice::ReadWrite | QFile::Text);
        QTextStream stream(saldotxt);


        saldo = 0;//SET SALDO INIZIALE DI DEFAULT A 0
        QString crypted=crypto.encryptToString(QString::number(saldo));
        stream<<crypted;

    }else {
        (*saldotxt).open(QIODevice::ReadWrite | QFile::Text);
        QTextStream stream(saldotxt);
        QString v = stream.readAll();
        QString decrypted = crypto.decryptToString(v);
        saldo = decrypted.toDouble();
    }
    (*saldotxt).flush();
    (*saldotxt).close();



}
double Saldo::getSaldo() const {
    return saldo;
}
void Saldo::setSaldo(const double v){
    saldo=v;
    Notify();

    (*saldotxt).open(QFile::WriteOnly | QFile::Text);
    QTextStream out(saldotxt);
    SimpleCrypt crypto(Q_UINT64_C(0x0c2ad4a4acb9f023)); //some random number
    QString crypted=crypto.encryptToString(QString::number(saldo));
    out<<crypted;
    (*saldotxt).flush();
    (*saldotxt).close();
}

Saldo::~Saldo(){
    delete saldotxt;
}
