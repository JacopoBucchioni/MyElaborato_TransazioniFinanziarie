#ifndef TRANSAZIONE_H
#define TRANSAZIONE_H

#include <string>
#include <QDate>
using namespace std;

class Transazione
{
public:
  Transazione(unsigned int id, QDate d, float i, string t, string c);
  virtual ~Transazione()=0;

  virtual float getImporto() const;
  virtual void setImporto(float value);
  string getCausale() const;
  void setCausale(string c);
  unsigned int getId() const;
  void setId(unsigned int id);
  QDate getDate() const;
  void setDate(QDate d);
  string getTipo() const;

protected:
  unsigned int ID;
  QDate data;
  float importo;
  string tipoTransazione;
  string causale;
};

#endif // TRANSAZIONE_H
