#include <QtTest>
#include <QString>
#include <QDate>
#include "conto.h"
#include "transazione.h"
#include "persona.h"
#include "ricarica.h"
#include "prelievo.h"

Persona* const intestatario = new Persona("nome","cognome");
const float saldoIniziale = 0;

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
  float saldoIniziale = 100;
  Conto* conto = new Conto(intestatario,saldoIniziale);
  Prelievo* p1 = new Prelievo(QDate::currentDate(),150,"prova prelievo");
  conto->addTransazione(p1);
  QCOMPARE(conto->isInRosso(),true);
}

void UnitTest::Test_aggiungiTransazione(){
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
  Conto* conto = new Conto(intestatario,saldoIniziale);
  Ricarica* r1 = new Ricarica(QDate(2019,12,10),200,"ricarica 1");
  conto->addTransazione(r1);
  Ricarica* r2 = new Ricarica(QDate(2019,12,31),100,"ricarica 2");
  conto->addTransazione(r2);
  Prelievo* p1 = new Prelievo(QDate(2020,1,10),50,"prelievo 1");
  conto->addTransazione(p1);
  Prelievo* p2 = new Prelievo(QDate(2020,2,10),30,"prelievo 2");
  conto->addTransazione(p2);
  Ricarica* r3 = new Ricarica(QDate(2020,3,10),300,"ricarica 3");
  conto->addTransazione(r3);
  Prelievo* p3 = new Prelievo(QDate::currentDate(),150,"prelievo 3");
  conto->addTransazione(p3);
  Prelievo* p4 = new Prelievo(QDate::currentDate(),250,"prelievo 4");
  conto->addTransazione(p4);

  //Filtro transazioni solo sulle date: cerco transazioni effetuate solo nel 2019
  list<Transazione*> s1 = conto->selezionaTransazioni(QDate(2019,1,1),QDate(2019,12,31));
  for(Transazione* t : s1)
    QCOMPARE(((*t).getTipo()),string("RICARICA"));

  //Filtro transazioni solo sul tipo di transazione: cerco tutti i prelievi
  list<Transazione*> s2 = conto->selezionaTransazioni(QDate(2019,1,1),QDate::currentDate(),"","PRELIEVO");
  for(Transazione* t : s2)
    QCOMPARE(((*t).getTipo()),string("PRELIEVO"));

  //Filtro transazioni solo sulla causale: cerco la transazione con causale "prelievo 2"
  list<Transazione*> s3 = conto->selezionaTransazioni(QDate(2019,1,1),QDate::currentDate(),"prelievo 2");
  for(Transazione* t : s3)
    QCOMPARE(((*t).getCausale()),string("prelievo 2"));

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
