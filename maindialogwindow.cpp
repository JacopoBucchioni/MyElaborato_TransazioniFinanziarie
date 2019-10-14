#include "maindialogwindow.h"
#include "ui_maindialogwindow.h"

#include "prelievocontroller.h"
#include "ricaricacontroller.h"
#include "pindialog.h"
#include "loginwindow.h"

MainDialogWindow::MainDialogWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialogWindow)
{
    ui->setupUi(this);

    saldoView = new ViewSaldo(new Saldo);
    transazioniView = new ViewTransazioni(new Transazioni);
    ui->labelSaldo->setText(QString::number(saldoView->getState()) + " € ");
    ui->transazioni_plainTextEdit->setPlainText(transazioniView->getTransazioni());

}

MainDialogWindow::~MainDialogWindow()
{
    delete ui;

    delete saldoView;
    delete transazioniView;
}



void MainDialogWindow::on_prelieva_Button_clicked()
{
    PrelievoController popupPrelievo(saldoView->getSubject(), transazioniView->getSubject());
    popupPrelievo.attach(this);
    popupPrelievo.setModal(true);
    popupPrelievo.exec();
}

void MainDialogWindow::update(){
    ui->labelSaldo->setText(QString::number(saldoView->getState()) + " € ");

    ui->transazioni_plainTextEdit->moveCursor(QTextCursor::Up);
    ui->transazioni_plainTextEdit->insertPlainText(transazioniView->getTransazioni()+"\n");
}

void MainDialogWindow::on_ricarica_Button_clicked()
{
    RicaricaController popupRicarica(saldoView->getSubject(), transazioniView->getSubject());
    popupRicarica.attach(this);
    popupRicarica.setModal(true);
    popupRicarica.exec();
}

void MainDialogWindow::on_logout_Button_clicked()
{
    this->parentWidget()->show();
    hide();


}

void MainDialogWindow::on_pin_Button_clicked()
{
    PinDialog popupPin;
    popupPin.setModal(true);
    popupPin.exec();

}
