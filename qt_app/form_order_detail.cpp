#include "form_order_detail.h"
#include "ui_form_order_detail.h"
#include <QVBoxLayout>
#include <QMainWindow>
#include <QDesktopWidget>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QtSql>
#include <QSqlError>
#include <QSqlQuery>

Form_Order_Detail::Form_Order_Detail(QWidget *parent) : QDialog(parent), ui(new Ui::Form_Order_Detail){
    ui->setupUi(this);
    this->setWindowTitle("Order Detail");
    myDB = database();
    window()->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,window()->size(),qApp->desktop()->availableGeometry()));
    setStyleSheet("background-color: rgb(224,243,176)");

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(ui->label,0,0);
    layout->addWidget(ui->comboBox,0,1);
    layout->addWidget(ui->label_2,1,0);
    layout->addWidget(ui->comboBox_2,1,1);
    layout->addWidget(ui->label_3,2,0);
    layout->addWidget(ui->lineEdit,2,1);
    layout->addWidget(ui->label_4,3,0);
    layout->addWidget(ui->lineEdit_2,3,1);
    layout->addWidget(ui->label_5,4,0);
    layout->addWidget(ui->lineEdit_3,4,1);
    layout->addWidget(ui->process_order_detail_record,5,0,1,0);
    this->setLayout(layout);
}

void Form_Order_Detail::populate_window(){
    ui->comboBox->setCurrentText(qr.value(0).toString() + " ");
    ui->comboBox_2->setCurrentText(qr.value(1).toString() + " ");
    ui->lineEdit->setText(qr.value(2).toString());
    ui->lineEdit_2->setText(qr.value(3).toString());
    ui->lineEdit_3->setText(qr.value(4).toString());
}

void Form_Order_Detail::keyPressEvent(QKeyEvent *event){

}

QString Form_Order_Detail::get_mode(int m){
    if(m == ADD) { return "Add"; }
    else if(m == UPDATE) { return "Update"; }
    else if(m == DELETE) { return "Delete"; }
    return "";
}

void Form_Order_Detail::clear_form(){
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
}

void Form_Order_Detail::refresh_query(){

}

void Form_Order_Detail::fill_combo_orders_combo_box(){
    QSqlQuery qr2 = myDB.executeQuery("SELECT * FROM orders");
    vector<int> cols{0};
    int row = 1;
    ui->comboBox->clear();
    for(int i=1; i<=qr2.size(); i++){
        QString nn = myDB.getCells(qr2, row, cols);
        ui->comboBox->addItem(nn);
    }
}

void Form_Order_Detail::fill_combo_products_combo_box(){
    QSqlQuery qr2 = myDB.executeQuery("SELECT * FROM products");
    vector<int> cols{0};
    int row = 1;
    row = 1;
    ui->comboBox_2->clear();
    for(int i=1; i<=qr2.size(); i++){
        QString man = myDB.getCells(qr2, row, cols);
        ui->comboBox_2->addItem(man);
    }
}

void Form_Order_Detail::on_show(){        
    ui->process_order_detail_record->setText(get_mode(mode));
    clear_form();
    fill_combo_orders_combo_box();
    fill_combo_products_combo_box();

    if(mode == UPDATE || mode == DELETE){
        qr = myDB.executeQuery("select * from orderdetails");
        qr.next();
        populate_window();
    }
}

Form_Order_Detail::~Form_Order_Detail(){
    delete ui;
}

void Form_Order_Detail::on_process_order_detail_record_clicked()
{

}
