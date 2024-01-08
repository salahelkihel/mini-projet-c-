#include "Login.h"
#include "ui_Login.h"
#include "UserDialog1.h"
#include <QMessageBox>
#include "userMain.h"
#include "user.h"
#include "user.cpp"
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QException>
#include "QPixmap"


Login::Login(QWidget *parent): QMainWindow(parent), ui(new Ui::Login){  
    ui->setupUi(this);

    QPixmap pic3("C:/Users/user/Desktop/VaccineS/img/login.png");
    ui->label_2->setPixmap(pic3);
    if(!connOpen()){
        ui->label->setText("Failed to open the database!");
        qDebug()<<"The database Not connected ";
    }else{
        ui->label->setText("Connected database........");
        qDebug()<<"The database connected ";
    }
}

Login::~Login(){
    delete ui;
}

// for action admin register....(admin_username,admin_password,admin_code)
void Login::on_pushButton_adminRegister_clicked(){   
    Login conn;
    QString adminUsername, adminPassword, adminCode;

    adminUsername = ui->lineEdit_adminUsername->text();
    adminPassword = ui->lineEdit_adminPW->text();

    if(!connOpen()){
        qDebug() <<"Failed to open the database";
        return;
    }
    connOpen();   // open the database function
    QSqlQuery qry;
    qry.prepare("insert into admin (admin_username,admin_password,admin_code) values ('"+adminUsername+"','"+adminPassword+"','"+adminCode+"')" );

    qDebug()<<qry.executedQuery();
    if(qry.exec()) {
        QMessageBox::information(this,tr("Save"),tr("Admin Data Saved!"));
        conn.connClose();
    }else{
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }
}

// for action admin login select 3 columns from database
void Login::on_pushButton_adminLogin_clicked(){  
    int count = 0;
    //.........................................................Exception.....................................//
    try {
        QString adminUsername = ui ->lineEdit_adminUsername->text();   // login and get the text of username and password form user input.
        QString adminPassword = ui->lineEdit_adminPW->text();
        connOpen();
        QSqlQuery qry;
        qry.prepare("select* from admin where admin_username='"+adminUsername + "'and admin_password = '"+adminPassword+"'");

        if(qry.exec()) {
            while(qry.next()){
                count++;
            }

            qDebug() << count;
            if(count==1){
                connClose();    // close the database before open next window
                this->hide();
                dash = new Dashboard(this);
                dash->show();
            }else{
                throw("Error");
            }
        }
    }
    catch (...) {
        ui->label ->setText("Username or password or work code is NOT correct.");
        qDebug() << "Catch Error： Username or password or work code is NOT correct. ";
    }

}

// for action  user login select 2 columns
void Login::on_pushButton_userLogin_clicked(){  
    int count = 0;
    //.........................................................Exception.....................................//
    try {

        connOpen();                                                    // open the database function, there are debug in the function.
        QSqlQuery qry;

        if(qry.exec()) {
            while(qry.next()){
                count++;
            }
            qDebug() << count;
            if(count==1){
                ui->label ->setText("Username and password is correct.");
                connClose();
                this->hide();
                userP1 = new UserDialog1(this);


                qDebug() << userP1->user_name + " has logged in";
                userP1->show();
            }
            else if (count == 0) {
                throw("Error");
            }
        }
    }
    catch (...) {
        ui->label ->setText("Username or password is NOT correct.");
        qDebug() << "Catch Error： Username or password is NOT correct. ";
    }
}


void Login::on_pushButton_userRegister_clicked(){
    Login conn;
    User curUser;


    if(!connOpen()){
        qDebug() <<"Failed to open the database";
        return;
    }
    connOpen();
    QSqlQuery qry;
    qry.prepare("insert into userInfo (username,password) values ('"+curUser.username+"','"+curUser.password+"')" );
    qDebug()<<qry.executedQuery();

    if(qry.exec()) {
        QMessageBox::information(this,tr("Save"),tr("User Data Saved!"));
        conn.connClose();
    }else{
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }
}


void Login::on_pushButton_loginQuit_clicked(){
    QMessageBox::StandardButton reply = QMessageBox::question(this,"My Title","Are you sure to quit the login page? ", QMessageBox::Yes| QMessageBox::No);
    if(reply == QMessageBox::Yes){
        QApplication::quit();
    }else{
        qDebug() << "Answer 'NO' Button is clicked";
    }
}
