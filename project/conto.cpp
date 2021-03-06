#include "conto.h"

Conto::Conto(Persona* p, float s) : intestatario(p), saldoIniziale(s)
{
  saldo = saldoIniziale;
  pin = new PinManager();
  isInRosso();
}

Conto::~Conto(){
  observers.erase(observers.begin(),observers.end());

  transazioni.erase(transazioni.begin(), transazioni.end());

  delete intestatario;
  delete pin;
}


void Conto::calcolaSaldo(){
  float s=saldoIniziale;
  for(auto itr=transazioni.begin(); itr!=transazioni.end(); itr++){
      if(itr->getTipo()=="SPESA")
        s -= itr->getImporto();
      if(itr->getTipo()=="VERSAMENTO")
        s += itr->getImporto();
    }
  saldo = s;
  isInRosso();
}

void Conto::addTransazione(Transazione t){
  for(auto itr=transazioni.begin(); itr!=transazioni.end(); itr++)
    if(itr->getId()==t.getId())
      return;
  transazioni.push_back(t);
  calcolaSaldo();
  Notify();
}

bool Conto::eliminaTransazione(unsigned int id){
  for(auto itr=transazioni.begin(); itr!=transazioni.end(); itr++){
      if(itr->getId()==id){
          transazioni.erase(itr);
          calcolaSaldo();
          Notify();
          return true;
        }
    }
  return false;
}

list<Transazione*> Conto::selezionaTransazioni(QDate inizio, QDate fine, string categoria, string tipoTransazione){
  list<Transazione*> r;
  if(inizio<=fine){
      if(fine>QDate::currentDate())
        fine=QDate::currentDate();

      for(auto itr=transazioni.begin(); itr!=transazioni.end(); itr++)
        if(itr->getDate()>=inizio && itr->getDate()<=fine)
          r.push_back(&(*itr));

      if(categoria!="")
        for(auto itr=r.begin(); itr!=r.end(); itr++)
          if((*itr)->getCausale()!=categoria)
            r.remove(*itr);

      if(tipoTransazione!="")
        for(auto itr=r.begin(); itr!=r.end(); itr++)
          if((*itr)->getTipo()!=tipoTransazione)
            r.remove(*itr);
    }
  return r;
}


Transazione Conto::getUltimaTransazione() const {return transazioni.back();}

list<Transazione> Conto::getTransazioni() const {return transazioni;}

int Conto::getNumeroTransazioni() const {return transazioni.size();}

float Conto::getSaldo() const {return saldo;}

bool Conto::isInRosso(){
  if(saldo<0){
      inRosso=true;
    }
  else {
      inRosso=false;
    }
  return inRosso;
}

Persona* Conto::getIntestario() const { return intestatario;}

PinManager* Conto::getPin() const {return pin;}

void  Conto::attach(AbstractView* o){observers.push_back(o);}

void Conto::detach(AbstractView* o){observers.remove(o);}

void Conto::Notify()
{
  for(list<AbstractView*>::iterator itr=observers.begin(); itr!=observers.end(); itr++)
    (*itr)->update();
}

