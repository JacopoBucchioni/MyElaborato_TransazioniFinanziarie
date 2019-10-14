#include "transazioni.h"
#include <QTextStream>
#include <QDateTime>
#include "viewsaldo.h"

Transazioni::Transazioni(){
    transazionitxt = new QFile("transazioni.txt");

    if(!((*transazionitxt).exists("transazioni.txt"))){
        (*transazionitxt).open(QFile::ReadWrite | QFile::Text);
        QTextStream stream(transazionitxt);
        ultimaTransazione = "";
        stream<<ultimaTransazione;
        //(*transazionitxt).flush();
    }else{
        (*transazionitxt).open(QIODevice::ReadWrite | QFile::Text);
        QTextStream stream(transazionitxt);
        ultimaTransazione = stream.readAll();
    }
    (*transazionitxt).flush();
    (*transazionitxt).close();
}


Transazioni::~Transazioni(){
    delete transazionitxt;
}

QString Transazioni::getUltimaTransizione() const {return ultimaTransazione;}

void Transazioni::addTransizione(const QString t){
    QString currentDate = (QDateTime::currentDateTime()).toString("dd.MM.yyyy hh:mm:ss");
    QString line = currentDate+": "+t;

    ultimaTransazione = line;
    Notify();

    (*transazionitxt).open(QIODevice::ReadWrite | QFile::Text);
    QTextStream out(transazionitxt);
    QString temp = out.readAll();
    line += "\n"+temp;
    QByteArray lineFormatted = line.toUtf8();
    (*transazionitxt).seek(0);
    (*transazionitxt).write(lineFormatted);
    (*transazionitxt).flush();
    (*transazionitxt).close();


}

