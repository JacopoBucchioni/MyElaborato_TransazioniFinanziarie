#ifndef TRANSAZIONIMANAGER_H
#define TRANSAZIONIMANAGER_H

#include <QDialog>
#include "conto.h"

namespace Ui {
  class TransazioniManager;
}

class TransazioniManager : public QDialog
{
  Q_OBJECT

public:
  explicit TransazioniManager(Conto* c, QWidget *parent = nullptr);
  ~TransazioniManager();

private slots:
  void on_salvaSuFile_pushButton_clicked();
  void on_filtra_pushButton_clicked();
  void on_elimina_pushButton_clicked();
  void on_indietro_pushButton_clicked();

  void on_entrate_checkBox_stateChanged(int arg1);
  void on_uscite_checkBox_stateChanged(int arg1);

private:
  Ui::TransazioniManager *ui;
  Conto* conto;
};

#endif // TRANSAZIONIMANAGER_H
