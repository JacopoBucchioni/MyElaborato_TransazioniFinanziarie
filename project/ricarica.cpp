#include "ricarica.h"

Ricarica::Ricarica(QDate d, float i, string c) : Transazione(d,i,"RICARICA",c) {}

Ricarica::~Ricarica(){}
