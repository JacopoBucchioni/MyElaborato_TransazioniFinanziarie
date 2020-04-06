#include "transazione.h"
#include "IdCounter.h"

Transazione::Transazione(QDate data, float importo, string causale, bool entrata) : ID(IdCounter::getId()), data(data), importo(importo), causale(causale), entrata(entrata) {}

Transazione::~Transazione(){}

float Transazione::getImporto() const{return importo;}
void Transazione::setImporto(float value) {importo=value;}

unsigned int Transazione::getId() const{return ID;}

string Transazione::getCausale() const{return causale;}
void Transazione::setCausale(string c){causale=c;}

QDate Transazione::getDate() const{return data;}
void Transazione::setDate(QDate d) {data=d;}

string Transazione::getTipo() const{
  if(entrata)
    return "VERSAMENTO";
  else
    return "SPESA";
}
