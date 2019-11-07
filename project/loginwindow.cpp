#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"


LoginWindow::LoginWindow(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::LoginWindow)
{
  ui->setupUi(this);
  pinManager = new PinManager;
  ui->lineEdit_pin->setEchoMode(QLineEdit::Password);
  count_u = 0;
  count_p = 0;
}

LoginWindow::~LoginWindow()
{
  delete ui;
  delete pinManager;
}

void LoginWindow::on_pushButton_clicked()
{
    QString user = ui->lineEdit_user->text();
    QString s_pin = ui->lineEdit_pin->text();

    if(user=="jacopo"){
        if(s_pin.length()==4){
            unsigned short int pin = s_pin.toUShort();

            if(pinManager->isCorret(pin)){

                this->parentWidget()->show();
                hide();
            }

        }else {
            if(count_p<3){
                ui->label_errori->setStyleSheet("color: red");
                ui->label_errori->setText("PIN errato");
                count_p++;
            }else {
                ui->label_errori->setStyleSheet("color: blue");
                ui->label_errori->setText("Il PIN di default PIN è 0000");
                count_p=0;
            }
        }
    }else {
        if(count_u<3){
            ui->label_errori->setStyleSheet("color: red");
            ui->label_errori->setText("Nome Utente errato");
            count_u++;
        }else {
            ui->label_errori->setStyleSheet("color: blue");
            ui->label_errori->setText("suggerimento: Nome Utente = jacopo");
            count_u=0;
        }
    }
}

void LoginWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_pin->setEchoMode(QLineEdit::Normal);
    }
    else{
        ui->lineEdit_pin->setEchoMode(QLineEdit::Password);
    }
}
