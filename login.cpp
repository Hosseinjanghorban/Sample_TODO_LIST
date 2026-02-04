#include "login.h"
#include "ui_login.h"
#include <QString>
#include <iostream>
#include <QMessageBox>
#include "common.h"
using namespace std;
login::login(vector<user>& listuser,int i,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->listuser=listuser;
    this->i=i;
    extern QString username;
}

login::~login()
{
    delete ui;
}
user* userr= new user;
void login::on_pushButton_login_clicked()
{
   username= ui->lineEdit_username->text();
   QString password= ui->lineEdit_pass->text();
   if(username=="" || password==""){
    ui->label_eror->setText("Please fill in both fields");
    return;
   }
    int k; bool con=true;
     for (k=0; k<listuser.size(); k++) {
         if(listuser[k].username==username && listuser[k].password==password){
             QMessageBox::information(this,"login!","welcom!!");
             con=false;
             static welcom*page=new welcom(listuser,k);
             page->show();
             this->hide();
         }

    }
     if(k==listuser.size() && con==true){
         QMessageBox::warning(this,"login!","username or password is false!!");
     }

}
void writefile(vector<user>& listuser)
{
    ofstream outFile("C:\\Users\\Admin\\Desktop\\todolist\\data.txt");
           for (unsigned int k = 0; k <listuser.size() ; ++k) {
               string usernam=listuser[k].username.toStdString();
               string pass=listuser[k].password.toStdString();
               outFile << usernam << endl;
               outFile << pass<< endl;
           }
           outFile.close();
}
void login::on_pushButton_2_clicked()
{
   username= ui->lineEdit_username->text();
    QString password= ui->lineEdit_pass->text();
    if(username=="" || password==""){
     ui->label_eror->setText("Please fill in both fields");
     return;
    }
    userr->username=username;
    userr->password=password;
    listuser.push_back(*userr);    
    writefile(listuser);
    QMessageBox::information(this,"signup!","signup sucessfully!!");   
    static welcom*page=new welcom(listuser,i);
    page->show();
    this->hide();

}


