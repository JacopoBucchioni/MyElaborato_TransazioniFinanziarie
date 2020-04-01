#include "ricaricacontroller.h"
#include "ui_ricaricacontroller.h"
#include "IdCounter.h"

RicaricaController::RicaricaController(Conto* c, QWidget *parent) :
  QDialog(parent),
  ui(new Ui::RicaricaController),
  conto(c)
{
  ui->setupUi(this);
  ui->lineEdit_pin->setEchoMode(QLineEdit::Password);
  ui->dateEdit->setDate(QDate::currentDate());
  ui->comboBox->addItem("Stipendio");
  ui->comboBox->addItem("Assegno");
  ui->comboBox->addItem("Rimborso");
  ui->comboBox->addItem("Bonifico");
  ui->comboBox->addItem("Ricarica Generica");
}

RicaricaController::~RicaricaController()
{
  delete ui;
}


void RicaricaController::on_pushButton_ok_clicked()
{
  if(ui->dateEdit->date() <= QDate::currentDate()){
      QDate data = ui->dateEdit->date();
      QString s_pin = ui->lineEdit_pin->text();

      if(s_pin.length()==4){
          unsigned short int pin =s_pin.toUShort();
          if(conto->getPin()->isCorret(pin)){

              float v = (ui->lineEdit_ricarica->text()).toFloat();
              if(v>0){
                  string causale =ui->comboBox->currentText().toStdString();
                  Ricarica* newRicarica = new Ricarica(IdCounter::getId(), data, v, causale);
                  conto->addTransazione(newRicarica);
                  hide();

                }else{
                  ui->label_errori->setStyleSheet("color: red");
                  ui->label_errori->setText("L'Importo deve essere >0");
                }
            }else {
              ui->label_errori->setStyleSheet("color: red");
              ui->label_errori->setText("PIN errato");
            }
        }else {
          ui->label_errori->setStyleSheet("color: red");
          ui->label_errori->setText("PIN errato");
        }
    }else {
      ui->label_errori->setStyleSheet("color: red");
      ui->label_errori->setText("La Data supera quella odierna");
    }
}


void RicaricaController::on_pushButton_cancel_clicked()
{
  hide();
}

void RicaricaController::on_checkBox_stateChanged(int arg1)
{
  if(arg1)
    ui->lineEdit_pin->setEchoMode(QLineEdit::Normal);
  else
    ui->lineEdit_pin->setEchoMode(QLineEdit::Password);
}
