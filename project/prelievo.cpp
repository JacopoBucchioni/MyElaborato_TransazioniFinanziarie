#include "prelievo.h"

Prelievo::Prelievo(unsigned int id, QDate d, float i, string c) : Transazione(id,d,-i,"PRELIEVO",c) {}

Prelievo::~Prelievo(){}

void Prelievo::setImporto(float value){
  importo=-value;
}

float Prelievo::getImporto() const{
  return -importo;
}

