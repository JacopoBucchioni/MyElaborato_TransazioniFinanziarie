#include "transazionimanager.h"
#include "ui_transazionimanager.h"
#include <QTextStream>
#include <QMessageBox>

TransazioniManager::TransazioniManager(Conto* c, QWidget *parent) :
  QDialog(parent),
  ui(new Ui::TransazioniManager),
  conto(c)
{
  ui->setupUi(this);
  ui->plainTextEdit->setReadOnly(true);
  ui->fine_dateEdit->setDate(QDate::currentDate());
  ui->inizio_dateEdit->setDate(QDate::currentDate().addMonths(-1));
  ui->categoria_comboBox->addItem("");
  ui->categoria_comboBox->addItem("Shopping");
  ui->categoria_comboBox->addItem("Viaggio");
  ui->categoria_comboBox->addItem("Ristoranti");
  ui->categoria_comboBox->addItem("Bancomat");
  ui->categoria_comboBox->addItem("Bonifico");
  ui->categoria_comboBox->addItem("Assegno");
  ui->categoria_comboBox->addItem("Stipendio");
  ui->categoria_comboBox->addItem("Rimborso");
  ui->categoria_comboBox->addItem("Ricarica Generica");
}

TransazioniManager::~TransazioniManager()
{
  delete ui;
}

void TransazioniManager::on_salvaSuFile_pushButton_clicked()
{
  QString text=ui->plainTextEdit->toPlainText();
  QByteArray textFormatted = text.toUtf8();

  QFile* transazionitxt = new QFile("C:/Users/Jacopo/Desktop/transazioni.txt");
  if(!((*transazionitxt).exists("C:/Users/Jacopo/Desktop/transazioni.txt"))){
      (*transazionitxt).open(QFile::WriteOnly | QFile::Text);
      (*transazionitxt).seek(0);
      (*transazionitxt).write(textFormatted);
      (*transazionitxt).flush();
      (*transazionitxt).close();
    }
  (*transazionitxt).open(QFile::WriteOnly | QFile::Text);
  (*transazionitxt).seek(0);
  (*transazionitxt).write(textFormatted);
  (*transazionitxt).flush();
  (*transazionitxt).close();
}


void TransazioniManager::on_filtra_pushButton_clicked()
{
  ui->error_label->clear();
  ui->errori_label_2->clear();
  if(ui->inizio_dateEdit->date() <= ui->fine_dateEdit->date()){
      ui->plainTextEdit->clear();

      if(ui->fine_dateEdit->date() > QDate::currentDate()){
          ui->error_label->setStyleSheet("color: blue");
          ui->error_label->setText("La Data di Fine superava la data odierna");
          ui->fine_dateEdit->setDate(QDate::currentDate());
        }
      QDate inizio = ui->inizio_dateEdit->date();
      QDate fine = ui->fine_dateEdit->date();
      string categoria = ui->categoria_comboBox->currentText().toStdString();
      list<Transazione*> result;

      if(ui->entrate_checkBox->checkState())
        result = conto->selezionaTransazioni(inizio,fine,categoria,"RICARICA");
      else {
          if(ui->uscite_checkBox->checkState())
            result = conto->selezionaTransazioni(inizio,fine,categoria,"PRELIEVO");
          else
            result = conto->selezionaTransazioni(inizio,fine,categoria);
        }
      QString text="";
      for(auto itr=result.begin(); itr!=result.end(); itr++){
          if((*itr)!=nullptr)
            text +="[ID="+QString::number((*itr)->getId())+"] "+QString::fromStdString((*itr)->getTipo())+" di "+QString::number((*itr)->getImporto())+"€ per ''"+QString::fromStdString((*itr)->getCausale())+"'' in Data: "+(*itr)->getDate().toString("dd/MM/yyyy")+"\n";
        }
      ui->plainTextEdit->setPlainText(text);


    }else {
      ui->error_label->setStyleSheet("color: red");
      ui->error_label->setText("La Data di Inizio supera quella di Fine");
    }
}


void TransazioniManager::on_elimina_pushButton_clicked()
{
  ui->error_label->clear();
  ui->errori_label_2->clear();
  int id = ui->ID_lineEdit->text().toInt();
  if(id>0)
    if(conto->eliminaTransazione(id)){
        ui->errori_label_2->setStyleSheet("color: green");
        ui->errori_label_2->setText("Eliminazione avvenuta con successo");
        ui->ID_lineEdit->clear();
      }
    else {
        ui->errori_label_2->setStyleSheet("color: black");
        ui->errori_label_2->setText("La Transazione selezionata non esiste");
        ui->ID_lineEdit->clear();
      }

  else {
      ui->errori_label_2->setStyleSheet("color: red");
      ui->errori_label_2->setText("Mettere un ID valido");
      ui->ID_lineEdit->clear();
    }
}

void TransazioniManager::on_indietro_pushButton_clicked()
{
  this->parentWidget()->show();
  hide();
}

void TransazioniManager::on_entrate_checkBox_stateChanged(int arg1)
{
  ui->error_label->clear();
  ui->errori_label_2->clear();
  if(arg1){
      if(ui->uscite_checkBox->checkState())
        ui->uscite_checkBox->click();
    }
}

void TransazioniManager::on_uscite_checkBox_stateChanged(int arg1)
{
  ui->error_label->clear();
  ui->errori_label_2->clear();
  if(arg1){
      if(ui->entrate_checkBox->checkState())
        ui->entrate_checkBox->click();
    }
}
