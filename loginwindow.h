#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "pinmanager.h"

namespace Ui {
class LogInWindow;
}

class LogInWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LogInWindow(QWidget *parent = nullptr);
    ~LogInWindow();

private slots:
    void on_pushButton_clicked();
    void on_checkBox_stateChanged(int arg1);

private:
    Ui::LogInWindow *ui;
    PinManager* pinManager;

    unsigned short int count_u,count_p;
};

#endif // LOGINWINDOW_H
