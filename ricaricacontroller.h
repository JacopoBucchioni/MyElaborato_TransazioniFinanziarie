#ifndef RICARICACONTROLLER_H
#define RICARICACONTROLLER_H

#include <QDialog>
#include "Model.h"
#include "saldo.h"
#include "transazioni.h"
#include "pinmanager.h"

namespace Ui {
class RicaricaController;
}

class RicaricaController : public QDialog, public Model
{
    Q_OBJECT

public:
    explicit RicaricaController(Saldo* s, Transazioni* t, QWidget *parent = nullptr);
    ~RicaricaController();

private slots:
    void on_pushButton_ok_clicked();
    void on_pushButton_cancel_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::RicaricaController *ui;
    Saldo* saldo;
    Transazioni* transazioni;
    PinManager* pinManager;

};

#endif // RICARICACONTROLLER_H
