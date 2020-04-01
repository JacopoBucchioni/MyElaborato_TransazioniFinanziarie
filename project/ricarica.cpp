#include "ricarica.h"

Ricarica::Ricarica(unsigned int id, QDate d, float i, string c) : Transazione(id,d,i,"RICARICA",c) {}

Ricarica::~Ricarica(){}
