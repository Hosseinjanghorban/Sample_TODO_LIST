#include "listworks.h"
#include "ui_listworks.h"
#include <QFont>
#include <QFontDialog>
#include <QColor>
#include <QColorDialog>
#include "homepage.h"
#include "common.h"
#include <QMessageBox>
QString username="";
QString listname="";
int zero=0,one=1,two=2,three=3;
listworks::listworks(vector<user>& listuser,int counter,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::listworks)
{
    ui->setupUi(this);     
    ui->label_5->setText(username);
    this->counter=counter;
    this->listuser=listuser;
    if(listuser[counter].list_works.size()>=1){
        ui->pushButton_list1->setText(listuser[counter].list_works[0][0].namelist);
    }
    if(listuser[counter].list_works.size()>=2){
        ui->pushButton_list2->setText(listuser[counter].list_works[1][0].namelist);
    }
    if(listuser[counter].list_works.size()>=3){
       ui->pushButton_list3->setText(listuser[counter].list_works[2][0].namelist);
    }
    if(listuser[counter].list_works.size()>=4){
       ui->pushButton_list4->setText(listuser[counter].list_works[3][0].namelist);
    }
}

listworks::~listworks()
{
    delete ui;
}


void listworks::on_pushButton_list1_clicked()
{   listname=ui->pushButton_list1->text();
    homepage* home=new homepage(listname,zero,counter,listuser);
    home->show();
    this->hide();
}

void listworks::on_pushButton_list2_clicked()
{   listname=ui->pushButton_list2->text();
    homepage* home=new homepage(listname,one,counter,listuser);
    home->show();
    this->hide();
}

void listworks::on_pushButton_list3_clicked()
{   listname=ui->pushButton_list3->text();
    homepage* home=new homepage(listname,two,counter,listuser);
    home->show();
    this->hide();
}

void listworks::on_pushButton_list4_clicked()
{   listname=ui->pushButton_list4->text();
    homepage* home=new homepage(listname,three,counter,listuser);
    home->show();
    this->hide();
}

void listworks::on_pushButton_addlist_clicked()
{

   listname= ui->lineEdit_listname->text();
   vector<work> list_work;
   listuser[counter].list_works.push_back(list_work);

   if(listuser[counter].list_works.size()==1){
       ui->pushButton_list1->setText(listname);
   }
   else if(listuser[counter].list_works.size()==2){
       ui->pushButton_list2->setText(listname);
   }
   else if(listuser[counter].list_works.size()==3){
       ui->pushButton_list3->setText(listname);
   }
   else if(listuser[counter].list_works.size()==4){
       ui->pushButton_list4->setText(listname);
   }
   else if(listuser[counter].list_works.size()>4){
         ui->label_eror->setText("you cant create more list!!");
   }
}

void listworks::on_pushButton_starlist_clicked()
{       QString message="";
    for(int i=0;i<listuser[counter].list_works.size();i++){
        for(int j=0;j<listuser[counter].list_works[i].size();j++){
            if(listuser[counter].list_works[i][j].star==true){
                message+=listuser[counter].list_works[i][j].workname +" * ";
            }
        }
    }
         QMessageBox::information(this,"star works!",message);
}

void listworks::on_pushButton_sendtask_clicked()
{       int taskuser;
    QString tusername=ui->lineEdit_username->text();
    QString tnamework=ui->lineEdit_workname->text();

    for(int i=0;i<listuser.size();i++){
            if(listuser[i].username==tusername){
                work twork;
                twork.workname=tnamework;
                twork.workdef="sended by " +username;
              taskuser=i;
              int numberlist;
                numberlist=listuser[taskuser].list_works.size();
                if(numberlist==0){
                    QMessageBox::warning(this,"send task!","member must creat a list at first!!");
                    return;
                }
                else{
                  listuser[taskuser].list_works[0].push_back(twork);
                  listuser[counter].list_assigned_work.push_back(twork);
                  QMessageBox::information(this,"send task!","sucssesful!!");

                  return;
                }

              QMessageBox::information(this,"send task!","sucssesful!!");
              return;
            }            

        }
          QMessageBox::warning(this,"not found!!!","user not found!!");
    }


void listworks::on_pushButton_assigned_clicked()
{   QString message="";
   for(int i=0;i<listuser[counter].list_assigned_work.size();i++){
    message+=listuser[counter].list_assigned_work[i].workname + " * ";
   }
    QMessageBox::information(this,"sendtask list!",message);

}

void listworks::on_pushButton_color_clicked()
{
    QColor color=QColorDialog::getColor(Qt::white,this,"Choose color");
    if(color.isValid()){

            ui->lineEdit_listname->setStyleSheet("color:red;");
    }
}

void listworks::on_pushButton_font_clicked()
{
    bool ok;
    QFont font=QFontDialog::getFont(&ok,this);
    if(ok)
       ui->lineEdit_listname->setFont(font);
}
