#include "pindialog.h"
#include "ui_pindialog.h"

PinDialog::PinDialog(Conto* c, QWidget *parent) :
  QDialog(parent),
  ui(new Ui::PinDialog),
  conto(c)
{
  ui->setupUi(this);
  ui->lineEdit_pin->setEchoMode(QLineEdit::Password);
  ui->lineEdit_newPin->setEchoMode(QLineEdit::Password);
  ui->lineEdit_newPin_repeat->setEchoMode(QLineEdit::Password);
}

PinDialog::~PinDialog()
{
  delete ui;
}

void PinDialog::on_pushButton_ok_clicked()
{
  QString s_pin = ui->lineEdit_pin->text();
  QString s_newPin = ui->lineEdit_newPin->text();
  QString s_newPin_2 = ui->lineEdit_newPin_repeat->text();

  if(s_pin.length()==4){

      if(s_newPin.length()==4 && s_newPin_2.length()==4){
          unsigned short int pin = s_pin.toUShort();
          unsigned short int newPin = s_newPin.toUShort();
          unsigned short int newPin_2 = s_newPin_2.toUShort();

          if(newPin == newPin_2){
              if(conto->getPin()->changePin(pin, newPin)){
                  ui->label_errori->setText("PIN modificato correttamente");
                  hide();

                }else {
                  ui->label_errori->setStyleSheet("color: red");
                  ui->label_errori->setText("PIN errato");
                }
            }else {
              ui->label_errori->setStyleSheet("color: red");
              ui->label_errori->setText("I due PIN non corrispondono");
            }

        }else {
          ui->label_errori->setStyleSheet("color: red");
          ui->label_errori->setText("Il PIN deve essere di 4 cifre");
        }
    }else {
      ui->label_errori->setStyleSheet("color: red");
      ui->label_errori->setText("PIN errato");
    }
}

void PinDialog::on_pushButton_cancel_clicked()
{
  hide();
}

void PinDialog::on_checkBox_stateChanged(int arg1)
{
  if(arg1){
      ui->lineEdit_pin->setEchoMode(QLineEdit::Normal);
      ui->lineEdit_newPin->setEchoMode(QLineEdit::Normal);
      ui->lineEdit_newPin_repeat->setEchoMode(QLineEdit::Normal);
    }
  else{
      ui->lineEdit_pin->setEchoMode(QLineEdit::Password);
      ui->lineEdit_newPin->setEchoMode(QLineEdit::Password);
      ui->lineEdit_newPin_repeat->setEchoMode(QLineEdit::Password);
    }

}
