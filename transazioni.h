#ifndef TRANSAZIONI_H
#define TRANSAZIONI_H
#include "Model.h"
#include <QFile>

class Transazioni : public Model
{
public:
    Transazioni();
    ~Transazioni();
    QString getUltimaTransizione() const;
    void addTransizione(const QString t);
private:
    QString ultimaTransazione;
    QFile* transazionitxt;

};

#endif // TRANSAZIONI_H
