
#include "homepage.h"
#include "ui_homepage.h"
#include <iostream>
#include <fstream>
#include <QMessageBox>
#include <QFileDialog>
#include <QtCore>
#include <QPdfWriter>
#include <QPainter>
#include <QPrinter>
#include <QPrintDialog>
using namespace std ;
// Function to get the current date and time
tm getCurrentTime() {
    time_t now = time(nullptr);
    return *localtime(&now);
}

int getYear(const tm& date) {
    return date.tm_year + 1900;
}

int getMonth(const tm& date) {
    return date.tm_mon + 1;
}
int getDay(const tm& date) {
    return date.tm_mday;
}


work* twork=new work;
homepage::homepage(QString listname,int numlist,int counter,vector<user>& listuser,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::homepage)
{
    ui->setupUi(this);
    this->listuser=listuser;
    this->counter=counter;
    this->numlist=numlist;
    this->listname=listname;
    if(listuser[counter].list_works[numlist].size() >=1){
        ui->label_5->setText(listuser[counter].list_works[numlist][0].workname);
    }
    if(listuser[counter].list_works[numlist].size() >=2){
        ui->label_6->setText(listuser[counter].list_works[numlist][1].workname);
    }
    if(listuser[counter].list_works[numlist].size() >=3){
        ui->label_7->setText(listuser[counter].list_works[numlist][2].workname);
    }
    if(listuser[counter].list_works[numlist].size() >=4){
        ui->label_8->setText(listuser[counter].list_works[numlist][3].workname);
    }
    if(listuser[counter].list_works[numlist].size() >=5){
        ui->label_9->setText(listuser[counter].list_works[numlist][4].workname);
    }
    ui->label_listname->setText(listname);
//    ui->label_3->setPalette(c);
}

homepage::~homepage()
{
    delete ui;
}


void writelist(vector<user>& listuser){
           int z=0;
        string list_name, workname,workdef,workdate,starwork,dowork;
    ofstream outFile("C:\\Users\\Admin\\Desktop\\todolist\\listwork.txt");
            outFile << "--" << endl;
           for (unsigned int k = 0; k <listuser.size() ; ++k) {
               outFile <<"##" << endl;
               //write name list
               for(int j=0;j<=listuser[k].list_works.size();j++){
                   if(listuser[k].list_works.size()==0){
                       continue;
                   }
                   if(listuser[k].list_works.size()==j){
                       continue;
                   }
                   if(listuser[k].list_works[j].size()==0){
                       continue;
                   }

                    outFile << "----" << endl;


                    z=0;
                   list_name=listuser[k].list_works[j][z].namelist.toStdString();
                   outFile << list_name << endl;
                   //write works in a list
                   for(z=0;z<listuser[k].list_works[j].size();z++){
                       outFile << "***"<<endl;

               workname=listuser[k].list_works[j][z].workname.toStdString();
               workdef=listuser[k].list_works[j][z].workdef.toStdString();
                workdate=listuser[k].list_works[j][z].date.toStdString();
                if(listuser[k].list_works[j][z].star==true){
                     starwork="true";
                }
               else
                    starwork="false";
                if(listuser[k].list_works[j][z].dowork==true){
                     dowork="true";
                }
               else{
                    dowork="false";
                }

               outFile << workname << endl;
               outFile << workdef<< endl;
               outFile << starwork << endl;
               outFile << workdate<< endl;
               outFile << dowork << endl;
                   }
               }
           }
           outFile.close();
}

void homepage::on_pushButton_addtime_clicked()
{
   twork->date= ui->dateEdit->text();
}


void homepage::on_pushButton_more4_clicked()
{
    QString detail=listuser[counter].list_works[numlist][3].workdef +"  "+ listuser[counter].list_works[numlist][3].date ;
       QMessageBox::information(this,"details!",detail);
}

void homepage::on_pushButton_more3_clicked()
{
    QString detail=listuser[counter].list_works[numlist][2].workdef +"  "+ listuser[counter].list_works[numlist][2].date ;
       QMessageBox::information(this,"details!",detail);
}

void homepage::on_pushButton_more2_clicked()
{
    QString detail=listuser[counter].list_works[numlist][1].workdef +"  "+ listuser[counter].list_works[numlist][1].date ;
       QMessageBox::information(this,"details!",detail);
}

void homepage::on_pushButton_more1_clicked()
{
    QString detail=listuser[counter].list_works[numlist][0].workdef +"  "+ listuser[counter].list_works[numlist][0].date ;
       QMessageBox::information(this,"details!",detail);
}

void homepage::on_pushButton_more5_clicked()
{
    QString detail=listuser[counter].list_works[numlist][4].workdef +"  "+ listuser[counter].list_works[numlist][4].date ;
       QMessageBox::information(this,"details!",detail);
}

void homepage::on_pushButton_addwork_clicked()
{
    twork->workname=ui->lineEdit->text();
    twork->workdef=ui->textEdit->toPlainText();
    twork->namelist=this->listname;
    if(ui->checkbox_star->isChecked()){
        twork->star=true;
    }
    twork->dowork=false;

    listuser[counter].list_works[numlist].push_back(*twork);
    if(ui->label_5->text()=="...."){
        ui->label_5->setText(twork->workname);
    }
    else if(ui->label_6->text()=="...."){
        ui->label_6->setText(twork->workname);
    }
    else if(ui->label_7->text()=="...."){
        ui->label_7->setText(twork->workname);
    }
    else if(ui->label_8->text()=="...."){
        ui->label_8->setText(twork->workname);
    }
   else  if(ui->label_9->text()=="...."){
        ui->label_9->setText(twork->workname);
    }
    twork->date="";
}

void homepage::on_pushButton_save_clicked(){
    //remove do worked from vector
            for(auto it=listuser[counter].list_works[numlist].begin(); it!=listuser[counter].list_works[numlist].end() ; it++){
            if(it->dowork==true){
                 listuser[counter].list_works[numlist].erase(it);
                 break;
                }
            }

    writelist(listuser);
     QMessageBox::information(this,"save!","sucssesful!!");
}

void homepage::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked()){

          ui->label_5->setStyleSheet("text-decoration: line-through;");
          listuser[counter].list_works[numlist][0].dowork=true;
      }
      else{
        listuser[counter].list_works[numlist][0].dowork=false;
        ui->label_5->setStyleSheet("color: rgb(255, 255, 255);");
        }
}

void homepage::on_checkBox_2_clicked()
{
    if(ui->checkBox_2->isChecked()){

           ui->label_6->setStyleSheet("text-decoration: line-through;");
           listuser[counter].list_works[numlist][1].dowork=true;
       }
    else{
      listuser[counter].list_works[numlist][1].dowork=false;
      ui->label_6->setStyleSheet("color: rgb(255, 255, 255);");
      }
}

void homepage::on_checkBox_3_clicked()
{
    if(ui->checkBox_3->isChecked()){

           ui->label_7->setStyleSheet("text-decoration: line-through;");
           listuser[counter].list_works[numlist][2].dowork=true;
       }
    else{
      listuser[counter].list_works[numlist][2].dowork=false;
      ui->label_7->setStyleSheet("color: rgb(255, 255, 255);");

      }
}

void homepage::on_checkBox_4_clicked()
{
    if(ui->checkBox_4->isChecked()){

           ui->label_8->setStyleSheet("text-decoration: line-through;");
           listuser[counter].list_works[numlist][3].dowork=true;
       }
    else{
      listuser[counter].list_works[numlist][3].dowork=false;
      ui->label_8->setStyleSheet("color: rgb(255, 255, 255);");

      }
}

void homepage::on_checkBox_5_clicked()
{
    if(ui->checkBox_5->isChecked()){

           ui->label_9->setStyleSheet("text-decoration: line-through;");
           listuser[counter].list_works[numlist][4].dowork=true;
       }
    else{
      listuser[counter].list_works[numlist][4].dowork=false;
      ui->label_9->setStyleSheet("color: rgb(255, 255, 255);");
      }
}
QString currDate()
{
    QDate date = QDate::currentDate();
    return date.toString("d/M/yyyy");
}
void homepage::on_pushButton_Today_clicked()
{   QString currentdate=currDate();
    QString date,message="";
       for(int i=0; i<listuser[counter].list_works[numlist].size(); i++){
           date=listuser[counter].list_works[numlist][i].date;
                   if(currentdate==date){
                 message+=listuser[counter].list_works[numlist][i].workname + " * ";
       }
       }
        QMessageBox::information(this,"today!",message);
}

void homepage::on_pushButton_print_clicked()
{
    QPrinter printer;
    printer.setPrinterName("printer name");
    QPrintDialog dialog(&printer,this);
    ui->textEdit->print(&printer);
}
