#include "dashboard.h"
#include "ui_dashboard.h"
#include "AdminDialog1.h"
#include "updateitem.h"
#include "deleteitem.h"
#include "finditem.h"
#include "Login.h"
#include "QPixmap"

Dashboard::Dashboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    int w = ui->label->width();
    int h = ui->label->height();
    QPixmap pic1(":/img/vaccinePic1.png");
    ui->label->setPixmap(pic1.scaled(w,h,Qt::KeepAspectRatio));


}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::on_pushButton_clicked()
{
   AdminDialog1 AdminDialog1;
   AdminDialog1.setModal(true);
   AdminDialog1.exec();
}


void Dashboard::on_pushButton_2_clicked()
{
    updateItem updateItem;
    updateItem.setModal(true);
    updateItem.exec();
}


void Dashboard::on_pushButton_3_clicked()
{
     deleteitem deleteitem ;
     deleteitem.setModal(true);
     deleteitem.exec();
}


void Dashboard::on_pushButton_4_clicked()
{
    finditem finditem ;
    finditem.setModal(true);
    finditem.exec();
}

