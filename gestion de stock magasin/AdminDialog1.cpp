#include "AdminDialog1.h"
#include "ui_AdminDialog1.h"
#include "Login.h"
#include <QString>
#include <QMessageBox>
#include <QPixmap>
#include <QTableView>
#include <QListView>
#include <QLineEdit>
#include <QSqlTableModel>
#include <QComboBox>

#include "items.h"


AdminDialog1::AdminDialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminDialog1){
    ui->setupUi(this);
}

AdminDialog1::~AdminDialog1(){
    delete ui;
}

void AdminDialog1::on_pushButton_loadInfo_clicked(){
    Login conn;
    QSqlQueryModel * modal = new QSqlQueryModel();  // create model
    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select Name, Quantity, Status, DOP, DOS, SellingPrice, PurchasePrice from items");
    qry->exec();
    modal->setQuery(*qry);

    ui->listView->setModel(modal);
    ui->comboBox->setModel(modal);

    ui->tableView->setModel(modal);

    conn.connClose();
    qDebug()<<(modal->rowCount());

}

void AdminDialog1::on_comboBox_currentIndexChanged(const QString &arg1){   
    QString Name = ui->comboBox->currentText();
    Login conn;
    if(!conn.connOpen()){
        qDebug() <<"Failed to open the database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;

    qry.prepare("select * from items where Name='"+Name+"'");
    qDebug()<<qry.executedQuery();

    if(qry.exec()) {
        while(qry.next()){
            ui->lineEdit_sName->setText(qry.value(1).toString());
            ui->lineEdit_sQuantity->setText(qry.value(2).toString());
            ui->lineEdit_sStatus->setText(qry.value(3).toString());
            ui->lineEdit_sDOP->setText(qry.value(4).toString());
            ui->lineEdit_sDOS->setText(qry.value(5).toString());
            ui->lineEdit_sSellingPrice->setText(qry.value(6).toString());
            ui->lineEdit_sPurchasePrice->setText(qry.value(7).toString());

        }
        conn.connClose();
    }else{
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }
}


void AdminDialog1::on_tableView_activated(const QModelIndex &index){

    QString val = ui->tableView->model()->data(index).toString();
    Login conn;
    if(!conn.connOpen()){
        qDebug() <<"Failed to open the database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("select * from items where Name='"+val+"' or Quantity='"+val+"' or Status='"+val+"' or DOP='"+val+"' or dos='"+val+"'"
             " or SellingPrice='"+val+"' or purchasePrice='"+val+"'  ");

    qDebug()<<qry.executedQuery();
    if(qry.exec()) {

        while(qry.next()){
            ui->lineEdit_sName->setText(qry.value(1).toString());
            ui->lineEdit_sQuantity->setText(qry.value(2).toString());
            ui->lineEdit_sStatus->setText(qry.value(3).toString());
            ui->lineEdit_sDOP->setText(qry.value(4).toString());
            ui->lineEdit_sDOS->setText(qry.value(5).toString());
            ui->lineEdit_sSellingPrice->setText(qry.value(6).toString());
            ui->lineEdit_sPurchasePrice->setText(qry.value(7).toString());

        }
        conn.connClose();
    }else{
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }
}


void AdminDialog1::on_listView_activated(const QModelIndex &index){

    QString val = ui->listView->model()->data(index).toString();
    Login conn;

    if(!conn.connOpen()){
        qDebug() <<"Failed to open the database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;

    qry.prepare("select * from items where Name='"+val+"' ");

    qDebug()<<qry.executedQuery();
    if(qry.exec()) {
        while(qry.next()){
            ui->lineEdit_sName->setText(qry.value(1).toString());
            ui->lineEdit_sQuantity->setText(qry.value(2).toString());
            ui->lineEdit_sStatus->setText(qry.value(3).toString());
            ui->lineEdit_sDOP->setText(qry.value(4).toString());
            ui->lineEdit_sDOS->setText(qry.value(5).toString());
            ui->lineEdit_sSellingPrice->setText(qry.value(6).toString());
            ui->lineEdit_sPurchasePrice->setText(qry.value(7).toString());

        }
        conn.connClose();
    }else{
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }
}

void AdminDialog1::on_pushButton_save_clicked(){  // insert
    Login conn;
    Item item;
    item.name = ui->lineEdit_sName->text();
    item.quantity = ui->lineEdit_sQuantity->text();
    item.status = ui->lineEdit_sStatus->text();
    item.dop = ui->lineEdit_sDOP->text();
    item.dos = ui->lineEdit_sDOS->text();
    item.sellingPrice = ui->lineEdit_sSellingPrice->text();
    item.purchasePrice= ui->lineEdit_sPurchasePrice->text();

    if(!conn.connOpen()){
        qDebug() <<"Failed to open the database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("INSERT INTO items (Name, Quantity, Status, DOP, DOS, SellingPrice, PurchasePrice)"
     "values ('"+item.name+"','"+item.quantity+"','"+item.status+"','"+item.dop+"','"+item.dos+"','"+item.sellingPrice+"','"+item.purchasePrice+"' )" );

    qDebug()<<qry.executedQuery();

    if(qry.exec()) {
        QMessageBox::information(this,tr("Save"),tr("Data Saved!"));
        conn.connClose();
    }else{
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }
}


void AdminDialog1::on_pushButton_update_clicked(){  // update
    Login conn;
    Item item;
    item.name = ui->lineEdit_sName->text();
    item.quantity = ui->lineEdit_sQuantity->text();
    item.status = ui->lineEdit_sStatus->text();
    item.dop = ui->lineEdit_sDOP->text();
    item.dos = ui->lineEdit_sDOS->text();
    item.sellingPrice = ui->lineEdit_sSellingPrice->text();
    item.purchasePrice= ui->lineEdit_sPurchasePrice->text();


    if(!conn.connOpen()){
        qDebug() <<"Failed to open the database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;

    qry.prepare("update items set Name='"+item.name+"',Quantity='"+item.quantity+"',Status='"+item.status+"',DOP='"+item.dop+"',DOS='"+item.dos+"'"
             ",SellingPrice='"+item.sellingPrice+"',PurchasePrice='"+item.purchasePrice+"' where Name='"+item.name+"'" );

    qDebug()<<qry.executedQuery();

    if(qry.exec()) {
        QMessageBox::information(this,tr("Edit"),tr("Data Updated!"));
        conn.connClose();
    }else{
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }


}


void AdminDialog1::on_pushButton_delete_clicked(){ // delete
    Login conn;
    Item item;
    item.name = ui->lineEdit_sName->text();   //only need a unique variable, find whole row and delete

    if(!conn.connOpen()){
        qDebug() <<"Failed to open the database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;

    qry.prepare("Delete from items where username='"+item.name+"'");
    qDebug()<<qry.executedQuery();

    if(qry.exec()) {
        QMessageBox::information(this,tr("Delete"),tr("Data Deleted!"));
        conn.connClose();
    }else{
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }


}

void AdminDialog1::on_pushButton_quit_clicked(){
    QMessageBox::StandardButton reply = QMessageBox::question(this,"My Title","Are you sure to quit the  page? ", QMessageBox::Yes| QMessageBox::No);
    if(reply == QMessageBox::Yes){
        QApplication::quit();
    }else{
        qDebug() << "Answer 'NO' Button is clicked";
    }
}
