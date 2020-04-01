#ifndef PRELIEVOCONTROLLER_H
#define PRELIEVOCONTROLLER_H

#include <QDialog>
#include "pinmanager.h"
#include "conto.h"
#include "prelievo.h"

namespace Ui {
  class PrelievoController;
}

class PrelievoController : public QDialog
{
  Q_OBJECT

public:
  explicit PrelievoController(Conto* c, QWidget *parent = nullptr);
  ~PrelievoController();

private slots:
  void on_pushButton_ok_clicked();
  void on_pushButton_cancel_clicked();

  void on_checkBox_stateChanged(int arg1);

private:
  Ui::PrelievoController *ui;
  Conto* conto;
};

#endif // PRELIEVOCONTROLLER_H
