#include <QtTest>
#include <QString>
#include <QDate>
#include "conto.h"
#include "transazione.h"
#include "persona.h"
#include "ricarica.h"
#include "prelievo.h"


class UnitTest:public QObject{
  Q_OBJECT

public:
  UnitTest();

  private Q_SLOTS:
  void Test_IdTransazione();
  void Test_calcolaSaldo();
  void Test_SaldoInRosso();
  void Test_aggiungiTransazione();
  void Test_eliminaTransazione();
  void Test_filtraTransazioni();

};


UnitTest::UnitTest(){}


void UnitTest::Test_calcolaSaldo(){
  Persona* intestatario = new Persona("nome","cognome","CF","nome.cognome@mail.com");
  float saldoIniziale = 0;
  Conto* conto = new Conto(intestatario,saldoIniziale);
  Ricarica* r1 = new Ricarica(QDate::currentDate(),100,"prova ricarica");
  conto->addTransazione(r1);
  Prelievo* p1 = new Prelievo(QDate::currentDate(),50,"prova prelievo");
  conto->addTransazione(p1);
  float newSaldo = conto->getSaldo();
  QCOMPARE(newSaldo,float(50));
  conto->addTransazione(p1);
  float newSaldo2 = conto->getSaldo();
  QCOMPARE(newSaldo2,float(50));
}

void UnitTest::Test_SaldoInRosso(){
  Persona* intestatario = new Persona("nome","cognome","CF","nome.cognome@mail.com");
  float saldoIniziale = 100;
  Conto* conto = new Conto(intestatario,saldoIniziale);
  Prelievo* p1 = new Prelievo(QDate::currentDate(),150,"prova prelievo");
  conto->addTransazione(p1);
  QCOMPARE(conto->isInRosso(),true);
}

void UnitTest::Test_aggiungiTransazione(){
  Persona* intestatario = new Persona("nome","cognome","CF","nome.cognome@mail.com");
  float saldoIniziale = 0;
  Conto* conto = new Conto(intestatario,saldoIniziale);
  Ricarica* r1 = new Ricarica(QDate::currentDate(),100,"prova ricarica");
  conto->addTransazione(r1);
  Transazione* t = conto->getUltimaTransazione();
  int n = conto->getNumeroTransazioni();
  QCOMPARE(t,r1);
  QCOMPARE(n,1);
  conto->addTransazione(r1);
  int n1 = conto->getNumeroTransazioni();
  QCOMPARE(n1,1);
}

void UnitTest::Test_eliminaTransazione(){
  Persona* intestatario = new Persona("nome","cognome","CF","nome.cognome@mail.com");
  float saldoIniziale = 0;
  Conto* conto = new Conto(intestatario,saldoIniziale);
  Ricarica* r1 = new Ricarica(QDate::currentDate(),100,"prova ricarica");
  conto->addTransazione(r1);
  Prelievo* p1 = new Prelievo(QDate::currentDate(),50,"prova prelievo");
  conto->addTransazione(p1);
  int n1 = conto->getNumeroTransazioni();
  QCOMPARE(n1,2);
  conto->eliminaTransazione(r1->getId());
  int n2 = conto->getNumeroTransazioni();
  QCOMPARE(n2,1);
  conto->eliminaTransazione(p1->getId());
  n2 = conto->getNumeroTransazioni();
  QCOMPARE(n2,0);
}

void UnitTest::Test_filtraTransazioni(){

}

void UnitTest::Test_IdTransazione(){
  Ricarica* r1 = new Ricarica(QDate::currentDate(),100,"prova");
  Ricarica* r2 = new Ricarica(QDate::currentDate(),100,"prova");
  Prelievo* p1 = new Prelievo(QDate::currentDate(),100,"prova");
  Prelievo* p2 = new Prelievo(QDate::currentDate(),100,"prova");
  Ricarica* r3 = new Ricarica(QDate::currentDate(),100,"prova");
  QCOMPARE(int(r1->getId()),1);
  QCOMPARE(int(r2->getId()),2);
  QCOMPARE(int(p1->getId()),3);
  QCOMPARE(int(p2->getId()),4);
  QCOMPARE(int(r3->getId()),5);
}


QTEST_APPLESS_MAIN(UnitTest)

#include "unitTest.moc"
