#include <QtTest>
#include <QString>
#include <QDate>
#include "../project/conto.h"
#include "../project/transazione.h"
#include "../project/persona.h"
#include "../project/ricarica.h"
#include "../project/prelievo.h"
#include "../project/IdCounter.h"
unsigned int IdCounter::Id=0;

class UnitTest:public QObject{
  Q_OBJECT

public:
  UnitTest();

  private Q_SLOTS:

  void Test_calcolaSaldo();
  void Test_SaldoInRosso();
  void Test_aggiungiTransazione();
  void Test_eliminaTransazione();
  void Test_filtraTransazioni();

  void Test_IdTransazione();
};


UnitTest::UnitTest(){}

void UnitTest::Test_calcolaSaldo(){
  Persona* intestatario = new Persona("nome","cognome","CF","nome.cognome@mail.com");
  float saldoIniziale = 0;
  Conto* conto = new Conto(intestatario,saldoIniziale);
  Ricarica* r1 = new Ricarica(IdCounter::getId(),QDate::currentDate(),100,"prova ricarica");
  conto->addTransazione(r1);
  Prelievo* p1 = new Prelievo(IdCounter::getId(),QDate::currentDate(),50,"prova prelievo");
  conto->addTransazione(p1);
  float newSaldo = conto->getSaldo();
  QCOMPARE(newSaldo,float(50));
}

void UnitTest::Test_SaldoInRosso(){
  Persona* intestatario = new Persona("nome","cognome","CF","nome.cognome@mail.com");
  float saldoIniziale = 100;
  Conto* conto = new Conto(intestatario,saldoIniziale);
  Prelievo* p1 = new Prelievo(IdCounter::getId(),QDate::currentDate(),150,"prova prelievo");
  conto->addTransazione(p1);
  QCOMPARE(conto->isInRosso(),true);
}

void UnitTest::Test_aggiungiTransazione(){
  Persona* intestatario = new Persona("nome","cognome","CF","nome.cognome@mail.com");
  float saldoIniziale = 0;
  Conto* conto = new Conto(intestatario,saldoIniziale);
  Ricarica* r1 = new Ricarica(IdCounter::getId(),QDate::currentDate(),100,"prova ricarica");
  conto->addTransazione(r1);
  Transazione* t = conto->getUltimaTransazione();
  QCOMPARE(t,r1);

}

void UnitTest::Test_eliminaTransazione(){
  Persona* intestatario = new Persona("nome","cognome","CF","nome.cognome@mail.com");
  float saldoIniziale = 0;
  Conto* conto = new Conto(intestatario,saldoIniziale);
  Ricarica* r1 = new Ricarica(IdCounter::getId(),QDate::currentDate(),100,"prova ricarica");
  conto->addTransazione(r1);
  Prelievo* p1 = new Prelievo(IdCounter::getId(),QDate::currentDate(),50,"prova prelievo");
  conto->addTransazione(p1);
  int n1 = conto->getNumeroTransazioni();
  QCOMPARE(n1,2);
  conto->eliminaTransazione(r1->getId());
  int n2 = conto->getNumeroTransazioni();
  QCOMPARE(n2,1);
}

void UnitTest::Test_filtraTransazioni(){

}

void UnitTest::Test_IdTransazione(){

}


QTEST_APPLESS_MAIN(UnitTest)

#include "unitTest.moc"
