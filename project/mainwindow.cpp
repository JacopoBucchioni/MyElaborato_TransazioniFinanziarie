#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "prelievocontroller.h"
#include "ricaricacontroller.h"
#include "pindialog.h"
#include "loginwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    LoginWindow loginWindow(this);
    loginWindow.setModal(true);
    loginWindow.exec();
    //hide();

    saldoView = new ViewSaldo(new Saldo);
    transazioniView = new ViewTransazioni(new Transazioni);
    ui->labelSaldo->setText(QString::number(saldoView->getState()) + " € ");
    ui->transazioni_plainTextEdit->setPlainText(transazioniView->getTransazioni());
}

MainWindow::~MainWindow()
{
    delete ui;
    delete saldoView;
    delete transazioniView;
}

void MainWindow::update(){
    ui->labelSaldo->setText(QString::number(saldoView->getState()) + " € ");

    ui->transazioni_plainTextEdit->moveCursor(QTextCursor::Up);
    ui->transazioni_plainTextEdit->insertPlainText(transazioniView->getTransazioni()+"\n");
}


void MainWindow::on_prelieva_Button_clicked()
{
    PrelievoController popupPrelievo(saldoView->getSubject(), transazioniView->getSubject());
    popupPrelievo.attach(this);
    popupPrelievo.setModal(true);
    popupPrelievo.exec();
}

void MainWindow::on_ricarica_Button_clicked()
{
    RicaricaController popupRicarica(saldoView->getSubject(), transazioniView->getSubject());
    popupRicarica.attach(this);
    popupRicarica.setModal(true);
    popupRicarica.exec();
}


void MainWindow::on_pin_Button_clicked()
{
    PinDialog popupPin;
    popupPin.setModal(true);
    popupPin.exec();
}

void MainWindow::on_logout_Button_clicked()
{
    //this->parentWidget()->show();
    LoginWindow loginWindow(this);
    loginWindow.setModal(true);
    hide();
    loginWindow.exec();

}


