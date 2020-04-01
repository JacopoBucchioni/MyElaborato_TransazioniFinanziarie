#ifndef CONTO_H
#define CONTO_H

#include "Model.h"
#include "AbstractView.h"
#include "transazione.h"
#include <list>
#include "persona.h"
#include "pinmanager.h"
using namespace std;


class Conto : public Model
{
public:
  Conto(Persona* p, float s);
  virtual ~Conto();

  void calcolaSaldo();
  void addTransazione(Transazione* t);
  bool eliminaTransazione(unsigned int id);
  list<Transazione*> selezionaTransazioni(QDate inizio, QDate fine, string categoria, string tipoTransazione="");

  Transazione* getUltimaTransazione() const;
  list<Transazione*> getTransazioni()const;
  float getSaldo() const;
  bool isInRosso();
  Persona* getIntestario()const;
  PinManager* getPin() const;

  virtual void attach(AbstractView* o);
  virtual void detach(AbstractView* o);
  virtual void Notify();


private:
  list<Transazione*> transazioni;
  Persona* intestatario;
  float saldo;
  bool inRosso;
  float saldoIniziale;
  PinManager* pin;
  list<AbstractView*> observers;
};

#endif // CONTO_H
