#include "spesaController.h"
#include "ui_spesaController.h"

SpesaController::SpesaController(Conto* c,QWidget *parent) :
  QDialog(parent),
  ui(new Ui::SpesaController),
  conto(c)
{
  ui->setupUi(this);
  ui->dateEdit->setDate(QDate::currentDate());
  ui->comboBox->addItem("Shopping");
  ui->comboBox->addItem("Viaggio");
  ui->comboBox->addItem("Ristoranti");
  ui->comboBox->addItem("Bancomat");
  ui->comboBox->addItem("Bonifico");
  ui->comboBox->addItem("Assegno");
}

SpesaController::~SpesaController()
{
  delete ui;
}


void SpesaController::on_pushButton_ok_clicked()
{
  if(ui->dateEdit->date() <= QDate::currentDate()){
      QDate data = ui->dateEdit->date();

      float v = (ui->lineEdit_prelievo->text()).toFloat();
      if(v>0){
          if(!conto->isInRosso()){
              string causale =ui->comboBox->currentText().toStdString();
              Transazione newUscita = Transazione(data, v, causale, false);
              conto->addTransazione(newUscita);
              hide();

            }else {
              ui->label_errori->setStyleSheet("color: red");
              ui->label_errori->setText("Importo non disponibile");
            }
        }else{
          ui->label_errori->setStyleSheet("color: red");
          ui->label_errori->setText("Importo Errato");
        }
    }else {
      ui->label_errori->setStyleSheet("color: red");
      ui->label_errori->setText("La Data supera quella odierna");
    }
}

void SpesaController::on_pushButton_cancel_clicked()
{
  hide();
}
