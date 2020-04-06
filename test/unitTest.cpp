#include <QtTest>
#include <QString>
#include <QDate>
#include "conto.h"
#include "transazione.h"
#include "persona.h"

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
  Transazione v1 = Transazione(QDate::currentDate(),100,"versamento di prova",true);
  conto->addTransazione(v1);
  Transazione s1 = Transazione(QDate::currentDate(),50,"spesa di prova",false);
  conto->addTransazione(v1);
  float newSaldo = conto->getSaldo();
  QCOMPARE(newSaldo,float(100));
  conto->addTransazione(s1);
  float newSaldo2 = conto->getSaldo();
  QCOMPARE(newSaldo2,float(50));
}

void UnitTest::Test_SaldoInRosso(){
  float saldoIniziale = 100;
  Conto* conto = new Conto(intestatario,saldoIniziale);
  Transazione s1 = Transazione(QDate::currentDate(),150,"spesa di prova",false);
  conto->addTransazione(s1);
  bool rosso = conto->isInRosso();
  QCOMPARE(rosso,true);
}

void UnitTest::Test_aggiungiTransazione(){
  Conto* conto = new Conto(intestatario,saldoIniziale);
  Transazione v1 = Transazione(QDate::currentDate(),100,"versamento di prova",true);
  conto->addTransazione(v1);
  Transazione s1 = Transazione(QDate::currentDate(),100,"spesa di prova",false);
  conto->addTransazione(s1);
  Transazione t = conto->getUltimaTransazione();
  int n1 = conto->getNumeroTransazioni();
  QCOMPARE(t.getId(),s1.getId());
  QCOMPARE(n1,2);
  conto->addTransazione(v1);
  int n2 = conto->getNumeroTransazioni();
  QCOMPARE(n2,2);
}

void UnitTest::Test_eliminaTransazione(){
  Conto* conto = new Conto(intestatario,saldoIniziale);
  Transazione v1 = Transazione(QDate::currentDate(),100,"versamento di prova",true);
  conto->addTransazione(v1);
  Transazione s1 = Transazione(QDate::currentDate(),50,"spesa di prova",false);
  conto->addTransazione(s1);
  int n1 = conto->getNumeroTransazioni();
  QCOMPARE(n1,2);
  conto->eliminaTransazione(v1.getId());
  int n2 = conto->getNumeroTransazioni();
  QCOMPARE(n2,1);
  conto->eliminaTransazione(s1.getId());
  int n3 = conto->getNumeroTransazioni();
  QCOMPARE(n3,0);
}

void UnitTest::Test_filtraTransazioni(){
  Conto* conto = new Conto(intestatario,saldoIniziale);
  Transazione r1 = Transazione(QDate(2019,12,10),200,"versamento 1",true);
  conto->addTransazione(r1);
  Transazione r2 = Transazione(QDate(2019,12,31),100,"versamento 2",true);
  conto->addTransazione(r2);
  Transazione p1 = Transazione(QDate(2020,1,10),50,"spesa 1",false);
  conto->addTransazione(p1);
  Transazione p2 = Transazione(QDate(2020,2,10),30,"spesa 2",false);
  conto->addTransazione(p2);
  Transazione r3 = Transazione(QDate(2020,3,10),300,"versamento 3",true);
  conto->addTransazione(r3);
  Transazione p3 = Transazione(QDate::currentDate(),150,"spesa 3",false);
  conto->addTransazione(p3);
  Transazione p4 = Transazione(QDate::currentDate(),250,"spesa 4",false);
  conto->addTransazione(p4);

  //Filtro transazioni solo sulle date: cerco transazioni effetuate solo nel 2019
  list<Transazione*> l1 = conto->selezionaTransazioni(QDate(2019,1,1),QDate(2019,12,31));
  for(Transazione* t : l1)
    QCOMPARE(((*t).getTipo()),string("VERSAMENTO"));

  //Filtro transazioni solo sul tipo di transazione: cerco tutte le spese
  list<Transazione*> l2 = conto->selezionaTransazioni(QDate(2019,1,1),QDate::currentDate(),"","SPESA");
  for(Transazione* t : l2)
    QCOMPARE(((*t).getTipo()),string("SPESA"));

  //Filtro transazioni solo sulla causale: cerco la transazione con causale "spesa 2"
  list<Transazione*> l3 = conto->selezionaTransazioni(QDate(2019,1,1),QDate::currentDate(),"spesa 2");
  for(Transazione* t : l3)
    QCOMPARE(((*t).getCausale()),string("spesa 2"));

  //Filtro transazioni sulla date e sul tipo di transazione: cerco le transazioni avvenute tra il 10/1 e il 10/3 che sono solo spese
  list<Transazione*> l4 = conto->selezionaTransazioni(QDate(2020,1,10),QDate(2020,3,10),"","SPESA");
  bool verify = false;
  for(Transazione* t : l4){
    QCOMPARE((*t).getTipo(),string("SPESA"));
    if((*t).getDate()<QDate(2020,1,10) || (*t).getDate()>QDate(2020,3,10))
      verify = true;
    QCOMPARE(verify,false);
    }
}

void UnitTest::Test_IdTransazione(){
  Transazione t1 = Transazione(QDate::currentDate(),100,"prova",true);
  Transazione t2 = Transazione(QDate::currentDate(),100,"prova",true);
  Transazione t3 = Transazione(QDate::currentDate(),100,"prova",false);
  Transazione t4 = Transazione(QDate::currentDate(),100,"prova",false);
  Transazione t5 = Transazione(QDate::currentDate(),100,"prova",true);
  QCOMPARE(int(t1.getId()),1);
  QCOMPARE(int(t2.getId()),2);
  QCOMPARE(int(t3.getId()),3);
  QCOMPARE(int(t4.getId()),4);
  QCOMPARE(int(t5.getId()),5);
}


QTEST_APPLESS_MAIN(UnitTest)

#include "unitTest.moc"
