#include "ricaricacontroller.h"
#include "ui_ricaricacontroller.h"

RicaricaController::RicaricaController(Saldo* s, Transazioni* t, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RicaricaController),
    saldo(s),
    transazioni(t)
{
    ui->setupUi(this);
    pinManager = new PinManager;
    ui->lineEdit_pin->setEchoMode(QLineEdit::Password);

}

RicaricaController::~RicaricaController()
{
    delete ui;
    delete pinManager;
}

void RicaricaController::on_pushButton_ok_clicked()
{
    double v = (ui->lineEdit_ricarica->text()).toDouble();
    if(v>0){
        QString s_pin = ui->lineEdit_pin->text();
        if(s_pin.length()==4){
            unsigned short int pin =s_pin.toUShort();
            if(pinManager->isCorret(pin)){
                double s = saldo->getSaldo();
                saldo->setSaldo((v+s));
                transazioni->addTransizione("Ricarica di "+QString::number(v)+" euro -> saldo: "+QString::number(v+s));
                Notify();
                hide();
            }
        }
        else {
            ui->label_errori->setStyleSheet("color: red");
            ui->label_errori->setText("PIN errato");
        }
    }else{
        ui->label_errori->setStyleSheet("color: red");
        ui->label_errori->setText("Importo errato");
    }
}

void RicaricaController::on_pushButton_cancel_clicked()
{
    hide();
}

void RicaricaController::on_checkBox_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_pin->setEchoMode(QLineEdit::Normal);
    }
    else{
        ui->lineEdit_pin->setEchoMode(QLineEdit::Password);
    }
}
