#ifndef MAINDIALOGWINDOW_H
#define MAINDIALOGWINDOW_H

#include <QDialog>

#include "viewsaldo.h"
#include "viewtransazioni.h"
#include "AbstractView.h"

namespace Ui {
class MainDialogWindow;
}

class MainDialogWindow : public QDialog, public AbstractView
{
    Q_OBJECT

public:
    explicit MainDialogWindow(QWidget *parent = nullptr);
    ~MainDialogWindow();
    virtual void update();

private slots:
    void on_prelieva_Button_clicked();
    void on_ricarica_Button_clicked();
    void on_pin_Button_clicked();
    void on_logout_Button_clicked();

private:
    Ui::MainDialogWindow *ui;
    ViewSaldo* saldoView;
    ViewTransazioni* transazioniView;
};

#endif // MAINDIALOGWINDOW_H
