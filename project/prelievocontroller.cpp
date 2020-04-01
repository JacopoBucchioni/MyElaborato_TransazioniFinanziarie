#include "prelievocontroller.h"
#include "ui_prelievocontroller.h"
#include "IdCounter.h"

PrelievoController::PrelievoController(Conto* c,QWidget *parent) :
  QDialog(parent),
  ui(new Ui::PrelievoController),
  conto(c)
{
  ui->setupUi(this);
  ui->lineEdit_pin->setEchoMode(QLineEdit::Password);
  ui->dateEdit->setDate(QDate::currentDate());
  ui->comboBox->addItem("Shopping");
  ui->comboBox->addItem("Viaggio");
  ui->comboBox->addItem("Ristoranti");
  ui->comboBox->addItem("Bancomat");
  ui->comboBox->addItem("Bonifico");
  ui->comboBox->addItem("Assegno");
}

PrelievoController::~PrelievoController()
{
  delete ui;
}


void PrelievoController::on_pushButton_ok_clicked()
{
  if(ui->dateEdit->date() <= QDate::currentDate()){
      QDate data = ui->dateEdit->date();
      QString s_pin = ui->lineEdit_pin->text();

      if(s_pin.length()==4){
          unsigned short int pin =s_pin.toUShort();
          if(conto->getPin()->isCorret(pin)){

              float v = (ui->lineEdit_prelievo->text()).toFloat();
              if(v>0){
                  if(!conto->isInRosso()){
                      string causale =ui->comboBox->currentText().toStdString();
                      Prelievo* newPrelievo = new Prelievo(IdCounter::getId(), data, v, causale);
                      conto->addTransazione(newPrelievo);
                      hide();

                    }else {
                      ui->label_errori->setStyleSheet("color: red");
                      ui->label_errori->setText("Importo non disponibile");
                    }
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

void PrelievoController::on_pushButton_cancel_clicked()
{
  hide();
}

void PrelievoController::on_checkBox_stateChanged(int arg1)
{
  if(arg1)
    ui->lineEdit_pin->setEchoMode(QLineEdit::Normal);
  else
    ui->lineEdit_pin->setEchoMode(QLineEdit::Password);
}
