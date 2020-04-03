#include "transazione.h"
#include "IdCounter.h"
unsigned int IdCounter::Id=0;

Transazione::Transazione(QDate d, float i, string t, string c) : ID(IdCounter::getId()), data(d), importo(i), tipoTransazione(t), causale(c) {}

Transazione::~Transazione(){}

float Transazione::getImporto() const{return importo;}
void Transazione::setImporto(float value) {importo=value;}

unsigned int Transazione::getId() const{return ID;}

string Transazione::getCausale() const{return causale;}
void Transazione::setCausale(string c){causale=c;}

QDate Transazione::getDate() const{return data;}
void Transazione::setDate(QDate d) {data=d;}

string Transazione::getTipo() const{return tipoTransazione;}
