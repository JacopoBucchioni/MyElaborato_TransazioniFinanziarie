#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "pinmanager.h"

namespace Ui {
class Dialog;
}

class LogInWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LogInWindow(QWidget *parent = nullptr);
    ~LogInWindow();

private slots:
    void on_pushButton_clicked();
    void on_checkBox_stateChanged(int arg1);

private:
    Ui::Dialog *ui;
    PinManager* pinManager;

    unsigned short int count_u,count_p;
};

#endif // DIALOG_H
