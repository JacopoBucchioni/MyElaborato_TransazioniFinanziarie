#ifndef TRANSAZIONE_H
#define TRANSAZIONE_H

#include <string>
#include <QDate>
using namespace std;

class Transazione
{
public:
  Transazione(QDate data, float importo, string causale, bool entrata);
  ~Transazione();

  float getImporto() const;
  void setImporto(float value);
  string getCausale() const;
  void setCausale(string c);
  unsigned int getId() const;
  QDate getDate() const;
  void setDate(QDate d);
  string getTipo() const;

protected:
  unsigned int ID;
  QDate data;
  float importo;
  string causale;
  bool entrata;
};

#endif // TRANSAZIONE_H
