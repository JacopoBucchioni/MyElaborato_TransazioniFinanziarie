#ifndef PRELIEVOCONTROLLER_H
#define PRELIEVOCONTROLLER_H

#include <QDialog>
#include "saldo.h"
#include "transazioni.h"
#include "Model.h"
#include "pinmanager.h"

namespace Ui {
class PrelievoController;
}

class PrelievoController : public QDialog, public Model
{
    Q_OBJECT

public:
    explicit PrelievoController(Saldo* s, Transazioni* t, QWidget *parent = nullptr);
    ~PrelievoController();

private slots:
    void on_pushButton_ok_clicked();
    void on_pushButton_cancel_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::PrelievoController *ui;
    Saldo* saldo;
    Transazioni* transazioni; //serve singleton per i subject oppure gli si passa nel cotruttore
    PinManager* pinManager;

};

#endif // PRELIEVOCONTROLLER_H
