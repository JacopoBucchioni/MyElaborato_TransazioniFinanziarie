#include "versamentoController.h"
#include "ui_versamentoController.h"

VersamentoController::VersamentoController(Conto* c, QWidget *parent) :
  QDialog(parent),
  ui(new Ui::VersamentoController),
  conto(c)
{
  ui->setupUi(this);
  ui->dateEdit->setDate(QDate::currentDate());
  ui->comboBox->addItem("Stipendio");
  ui->comboBox->addItem("Assegno");
  ui->comboBox->addItem("Rimborso");
  ui->comboBox->addItem("Bonifico");
  ui->comboBox->addItem("Ricarica Generica");
}

VersamentoController::~VersamentoController()
{
  delete ui;
}


void VersamentoController::on_pushButton_ok_clicked()
{
  if(ui->dateEdit->date() <= QDate::currentDate()){
      QDate data = ui->dateEdit->date();

      float v = (ui->lineEdit_ricarica->text()).toFloat();
      if(v>0){
          string causale =ui->comboBox->currentText().toStdString();
          Transazione newEntrata = Transazione(data, v, causale, true);
          conto->addTransazione(newEntrata);
          hide();

        }else{
          ui->label_errori->setStyleSheet("color: red");
          ui->label_errori->setText("Importo Errato");
        }
    }else {
      ui->label_errori->setStyleSheet("color: red");
      ui->label_errori->setText("La Data supera quella odierna");
    }
}


void VersamentoController::on_pushButton_cancel_clicked()
{
  hide();
}
