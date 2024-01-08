#include "finditem.h"
#include "ui_finditem.h"
#include "items.h"
#include <QString>
#include "Login.h"

finditem::finditem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::finditem)
{
    ui->setupUi(this);
}

finditem::~finditem()
{
    delete ui;
}

void finditem::on_btnFind_clicked()
{
    Login conn;
    Item item;
    QString sValue = ui->txtValue->text();
    QString sCriteriaColum = "";

    if(ui->rdoId->isChecked())
        sCriteriaColum="Id";
    else if (ui->rdoName->isChecked())
        sCriteriaColum="Name";
    else if (ui->rdoQuantity->isChecked())
        sCriteriaColum="Quantity";
    else if (ui->rdoSellingPrice->isChecked())
        sCriteriaColum = "SellingPrice";
    else
        sCriteriaColum = "Name";

    conn.connOpen();
    QSqlQuery qry;

    QSqlQueryModel * model = new QSqlQueryModel(this);

    qry.prepare("select * from items where " +sCriteriaColum+" like '%" + sValue + "%'");
    qry.exec();
    model->setQuery(qry);
    ui->tableView->setModel(model);
    ui->tableView->show();

}

