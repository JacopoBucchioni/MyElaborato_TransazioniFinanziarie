#include "saldo.h"

#include<QTextStream>
#include<iostream>

Saldo::Saldo()
{
    saldotxt = new QFile("saldo.txt");
    if(!((*saldotxt).exists("saldo.txt"))){

        (*saldotxt).open(QIODevice::ReadWrite | QFile::Text);
        QTextStream stream(saldotxt);


        saldo = 0;//SET SALDO INIZIALE DI DEFAULT A 0
        QString text=QString::number(saldo);
        stream<<text;

    }else {
        (*saldotxt).open(QIODevice::ReadWrite | QFile::Text);
        QTextStream stream(saldotxt);
        QString v = stream.readAll();
        saldo = v.toDouble();
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
    QString text=QString::number(saldo);
    out<<text;
    (*saldotxt).flush();
    (*saldotxt).close();
}

Saldo::~Saldo(){
    delete saldotxt;
}
