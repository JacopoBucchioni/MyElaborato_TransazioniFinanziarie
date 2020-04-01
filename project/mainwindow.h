#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "AbstractView.h"
#include "conto.h"

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
  void salvaSaldoSuFile();

private slots:
  void on_prelieva_Button_clicked();
  void on_ricarica_Button_clicked();
  void on_pin_Button_clicked();
  void on_logout_Button_clicked();
  void on_transazioni_Button_clicked();

private:
  Ui::MainWindow *ui;
  Conto* conto;
  QFile* saldotxt;
};

#endif // MAINWINDOW_H
