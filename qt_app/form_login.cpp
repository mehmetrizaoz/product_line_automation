#include "form_login.h"
#include "ui_form_login.h"
#include "database.h"
#include <QGridLayout>
#include <QDesktopWidget>
#include <QStyle>

Form_Login::Form_Login(QWidget *parent) : QWidget(parent), ui(new Ui::Form_Login){
    ui->setupUi(this);
    this->setFixedSize(278,194);
    this->setWindowTitle("Login");
    setStyleSheet("background-color: rgb(224,243,176)");
    myDB = database();
    window()->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,window()->size(),qApp->desktop()->availableGeometry()));
    //used to send connection status to main window
    connect(ui->connect, SIGNAL(clicked()), this, SIGNAL(loginClicked()));
}

Form_Login::~Form_Login(){
    delete ui;
}

void Form_Login::on_connect_clicked(){
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QString hostname = ui->lineEdit_3->text();
    QString database = ui->lineEdit_4->text();

    if(myDB.connect(hostname, database, username, password) == true){
       qDebug() << "connected";
       isConnected = true;
       this->close();
    }
    else{ //todo: use messagebox
       isConnected = false;
       qDebug() << "cant connect to database server";
    }
}

