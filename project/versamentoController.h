#ifndef RICARICACONTROLLER_H
#define RICARICACONTROLLER_H

#include <QDialog>
#include "conto.h"
#include "transazione.h"

namespace Ui {
  class VersamentoController;
}

class VersamentoController : public QDialog
{
  Q_OBJECT

public:
  explicit VersamentoController(Conto* c, QWidget *parent = nullptr);
  ~VersamentoController();

private slots:
  void on_pushButton_ok_clicked();
  void on_pushButton_cancel_clicked();

private:
  Ui::VersamentoController *ui;
  Conto* conto;
};

#endif // RICARICACONTROLLER_H
