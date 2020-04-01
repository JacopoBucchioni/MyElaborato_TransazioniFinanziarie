#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "prelievocontroller.h"
#include "ricaricacontroller.h"
#include "pindialog.h"
#include "loginwindow.h"
#include "transazionimanager.h"
#include "lib/simplecrypt.h"
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  float saldoIniziale;
  saldotxt = new QFile("saldo.txt");
  SimpleCrypt crypto(Q_UINT64_C(0x0c2ad4a4acb9f023)); //some random number
  if(!((*saldotxt).exists("saldo.txt"))){
      (*saldotxt).open(QIODevice::ReadWrite | QFile::Text);
      QTextStream stream(saldotxt);
      saldoIniziale = 0; //SET SALDO INIZIALE DI DEFAULT A 0
      QString crypted=crypto.encryptToString(QString::number(saldoIniziale));
      stream<<crypted;
    }else {
      (*saldotxt).open(QIODevice::ReadOnly | QFile::Text);
      QTextStream stream(saldotxt);
      QString v = stream.readAll();
      QString decrypted = crypto.decryptToString(v);
      saldoIniziale = decrypted.toFloat();
    }
  (*saldotxt).flush();
  (*saldotxt).close();

  conto = new Conto(new Persona("jacopo","bucchioni"),saldoIniziale);
  conto->attach(this);

  LoginWindow loginWindow(conto, this);
  loginWindow.setModal(true);
  loginWindow.exec();
  //hide();

  ui->saldo_lineEdit->setReadOnly(true);
  ui->transazioni_plainTextEdit->setReadOnly(true);

  if(conto->isInRosso())
    ui->saldo_lineEdit->setStyleSheet("color: red");
  else
    ui->saldo_lineEdit->setStyleSheet("color: black");

  ui->saldo_lineEdit->setText(QString::number(conto->getSaldo()) + " € ");

}

MainWindow::~MainWindow()
{
  delete ui;
}


void MainWindow::update(){
  if(conto->isInRosso())
    ui->saldo_lineEdit->setStyleSheet("color: red");
  else
    ui->saldo_lineEdit->setStyleSheet("color: black");
  ui->saldo_lineEdit->setText(QString::number(conto->getSaldo()) + " € ");
  salvaSaldoSuFile();

  ui->transazioni_plainTextEdit->clear();
  list<Transazione*> t = conto->getTransazioni();
  QString text = "";
  for(auto itr = t.rbegin(); itr!=t.rend(); itr++)
    if((*itr)!=nullptr)
      text +="[ID="+QString::number((*itr)->getId())+"] "+QString::fromStdString((*itr)->getTipo())+" di "+QString::number((*itr)->getImporto())+"€ per ''"+QString::fromStdString((*itr)->getCausale())+"'' in Data: "+(*itr)->getDate().toString("dd/MM/yyyy")+"\n";
  ui->transazioni_plainTextEdit->setPlainText(text);
}

void MainWindow::salvaSaldoSuFile() {
    (*saldotxt).open(QFile::WriteOnly | QFile::Text);
    QTextStream out(saldotxt);
    SimpleCrypt crypto(Q_UINT64_C(0x0c2ad4a4acb9f023)); //some random number
    QString crypted=crypto.encryptToString(QString::number(conto->getSaldo()));
    out<<crypted;
    (*saldotxt).flush();
    (*saldotxt).close();
}


void MainWindow::on_transazioni_Button_clicked()
{
  TransazioniManager gestoreTransazioni(conto,this);
  gestoreTransazioni.setModal(true);
  hide();
  gestoreTransazioni.exec();
}

void MainWindow::on_prelieva_Button_clicked()
{
  PrelievoController popupPrelievo(conto);
  popupPrelievo.setModal(true);
  popupPrelievo.exec();
}

void MainWindow::on_ricarica_Button_clicked()
{
  RicaricaController popupRicarica(conto);
  popupRicarica.setModal(true);
  popupRicarica.exec();
}


void MainWindow::on_pin_Button_clicked()
{
  PinDialog popupPin(conto);
  popupPin.setModal(true);
  popupPin.exec();
}

void MainWindow::on_logout_Button_clicked()
{
  LoginWindow loginWindow(conto, this);
  loginWindow.setModal(true);
  hide();
  loginWindow.exec();
}
