#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include "conto.h"

namespace Ui {
  class LoginWindow;
}

class LoginWindow : public QDialog
{
  Q_OBJECT

public:
  explicit LoginWindow(Conto* c, QWidget *parent = nullptr);
  ~LoginWindow();

private slots:
  void on_pushButton_clicked();
  void on_checkBox_stateChanged(int arg1);

private:
  Ui::LoginWindow *ui;
  Conto* conto;
  unsigned short int count_u,count_p;
};

#endif // LOGINWINDOW_H
