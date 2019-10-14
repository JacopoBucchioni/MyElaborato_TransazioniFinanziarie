#include "prelievocontroller.h"
#include "ui_prelievocontroller.h"

PrelievoController::PrelievoController(Saldo* s, Transazioni* t,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrelievoController),
    saldo(s),
    transazioni(t)
{
    ui->setupUi(this);
    pinManager = new PinManager;
    ui->lineEdit_pin->setEchoMode(QLineEdit::Password);
}

PrelievoController::~PrelievoController()
{
    delete ui;
    delete pinManager;
}


void PrelievoController::on_pushButton_ok_clicked()
{
    double v = (ui->lineEdit_prelievo->text()).toDouble();
    if(v>0){
        double s = saldo->getSaldo();
        if(v <= s){
            QString s_pin = ui->lineEdit_pin->text();
            if(s_pin.length()==4){
                unsigned short int pin =s_pin.toUShort();
                if(pinManager->isCorret(pin)){
                    saldo->setSaldo((s-v));
                    transazioni->addTransizione("Prelievo di "+QString::number(v)+" euro -> saldo: "+QString::number(s-v));
                    Notify();
                    hide();
                }
            }else {
                ui->label_errori->setStyleSheet("color: red");
                ui->label_errori->setText("PIN errato");
            }
        }else {
            ui->label_errori->setStyleSheet("color: red");
            ui->label_errori->setText("Importo non disponibile");
        }
    }else{
        ui->label_errori->setStyleSheet("color: red");
        ui->label_errori->setText("Importo errato");
    }

}

void PrelievoController::on_pushButton_cancel_clicked()
{
    hide();
}

void PrelievoController::on_checkBox_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_pin->setEchoMode(QLineEdit::Normal);
    }
    else{
        ui->lineEdit_pin->setEchoMode(QLineEdit::Password);
    }
}
