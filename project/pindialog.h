#ifndef PINDIALOG_H
#define PINDIALOG_H

#include <QDialog>
#include "pinmanager.h"

namespace Ui {
class PinDialog;
}

class PinDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PinDialog(QWidget *parent = nullptr);
    ~PinDialog();

private slots:
    void on_pushButton_ok_clicked();
    void on_pushButton_cancel_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::PinDialog *ui;
    PinManager* pinManager;
};

#endif // PINDIALOG_H
