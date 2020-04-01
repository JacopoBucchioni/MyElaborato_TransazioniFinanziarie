#ifndef PRELIEVO_H
#define PRELIEVO_H
#include "transazione.h"

class Prelievo : public Transazione
{
public:
  Prelievo(unsigned int id, QDate d, float i, string c);
  virtual ~Prelievo()override;
  virtual void setImporto(float value)override;
  virtual float getImporto() const override;
};

#endif // PRELIEVO_H
