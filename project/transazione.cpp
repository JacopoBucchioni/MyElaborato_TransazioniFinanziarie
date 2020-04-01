#include "transazione.h"

Transazione::Transazione(unsigned int id, QDate d, float i, string t, string c) : ID(id), data(d), importo(i), tipoTransazione(t), causale(c) {}

Transazione::~Transazione(){}

float Transazione::getImporto() const{return importo;}
void Transazione::setImporto(float value) {importo=value;}

unsigned int Transazione::getId() const{return ID;}
void Transazione::setId(unsigned int id) {ID=id;}

string Transazione::getCausale() const{return causale;}
void Transazione::setCausale(string c){causale=c;}

QDate Transazione::getDate() const{return data;}
void Transazione::setDate(QDate d) {data=d;}

string Transazione::getTipo() const{return tipoTransazione;}
