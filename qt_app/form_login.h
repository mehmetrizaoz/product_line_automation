#ifndef FORM_LOGIN_H
#define FORM_LOGIN_H

#include <QWidget>
#include "database.h"

namespace Ui {
class Form_Login;
}

class Form_Login : public QWidget
{
    Q_OBJECT

public:
    explicit Form_Login(QWidget *parent = nullptr);
    ~Form_Login();
    bool isConnected=false;
    database myDB;
private slots:
    void on_connect_clicked();

private:
    Ui::Form_Login *ui;

signals:
    void loginClicked();
};

#endif // FORM_LOGIN_H
