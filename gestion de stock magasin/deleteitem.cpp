#include "deleteitem.h"
#include "ui_deleteitem.h"
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
deleteitem::deleteitem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteitem)
{
    ui->setupUi(this);


}

deleteitem::~deleteitem()
{
    delete ui;
}

void deleteitem::on_pushButton_delete_clicked()
{
    Login conn;
    Item item;
    item.name = ui->lineEdit_sName->text();   //only need a unique variable, find whole row and delete

    if(!conn.connOpen()){
        qDebug() <<"Failed to open the database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;

    qry.prepare("Delete from items where Name='"+item.name+"'");
    qDebug()<<qry.executedQuery();

    if(qry.exec()) {
        QMessageBox::information(this,tr("Delete"),tr("Data Deleted!"));
        conn.connClose();
    }else{
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }
}


void deleteitem::on_pushButton_loadInfo_clicked()
{
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


void deleteitem::on_pushButton_quit_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"My Title","Are you sure to quit the login page? ", QMessageBox::Yes| QMessageBox::No);
    if(reply == QMessageBox::Yes){
        QApplication::quit();
    }else{
        qDebug() << "Answer 'NO' Button is clicked";
    }
}


void deleteitem::on_comboBox_currentIndexChanged(const QString &arg1)
{
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


void deleteitem::on_tableView_activated(const QModelIndex &index)
{
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

