#include "prelievo.h"

Prelievo::Prelievo(QDate d, float i, string c) : Transazione(d,-i,"PRELIEVO",c) {}

Prelievo::~Prelievo(){}

void Prelievo::setImporto(float value){
  importo=-value;
}

float Prelievo::getImporto() const{
  return -importo;
}

