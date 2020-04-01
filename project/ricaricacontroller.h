#ifndef RICARICACONTROLLER_H
#define RICARICACONTROLLER_H

#include <QDialog>
#include "pinmanager.h"
#include "conto.h"
#include "ricarica.h"

namespace Ui {
  class RicaricaController;
}

class RicaricaController : public QDialog
{
  Q_OBJECT

public:
  explicit RicaricaController(Conto* c, QWidget *parent = nullptr);
  ~RicaricaController();

private slots:
  void on_pushButton_ok_clicked();
  void on_pushButton_cancel_clicked();

  void on_checkBox_stateChanged(int arg1);

private:
  Ui::RicaricaController *ui;
  Conto* conto;
};

#endif // RICARICACONTROLLER_H
