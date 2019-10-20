#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "viewsaldo.h"
#include "viewtransazioni.h"
#include "AbstractView.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public AbstractView
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void update();

private slots:
    void on_prelieva_Button_clicked();
    void on_ricarica_Button_clicked();
    void on_pin_Button_clicked();
    void on_logout_Button_clicked();

private:
    Ui::MainWindow *ui;
    ViewSaldo* saldoView;
    ViewTransazioni* transazioniView;
};

#endif // MAINWINDOW_H
