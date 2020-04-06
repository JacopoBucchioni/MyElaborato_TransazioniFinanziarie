#ifndef PRELIEVOCONTROLLER_H
#define PRELIEVOCONTROLLER_H

#include <QDialog>
#include "conto.h"
#include "transazione.h"

namespace Ui {
  class SpesaController;
}

class SpesaController : public QDialog
{
  Q_OBJECT

public:
  explicit SpesaController(Conto* c, QWidget *parent = nullptr);
  ~SpesaController();

private slots:
  void on_pushButton_ok_clicked();
  void on_pushButton_cancel_clicked();


private:
  Ui::SpesaController *ui;
  Conto* conto;
};

#endif // PRELIEVOCONTROLLER_H
