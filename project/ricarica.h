#ifndef RICARICA_H
#define RICARICA_H
#include "transazione.h"

class Ricarica : public Transazione
{
public:
  Ricarica(unsigned int id, QDate d, float i, string c);
  virtual ~Ricarica();
};

#endif // RICARICA_H
