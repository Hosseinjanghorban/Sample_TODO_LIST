#include "welcom.h"
#include "ui_welcom.h"
#include "common.h"
#include "listworks.h"
#include <fstream>
#include <vector>
#include "listworks.h"
using namespace std;
QString list_name;
welcom::welcom(vector<user>& listuser,int counter,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::welcom)
{
    ui->setupUi(this);    
    extern QString username;
    ui->label_welcom->setText("welcome "+username);
  this->counter=counter;
  this->listuser=listuser;
}
welcom::~welcom()
{
    delete ui;
}

void fillwork(vector<user>& listuser)
{    work* twork; int con=0;
    string tmp1;
    vector<work> listwork;
    QString workname,workdef,starwork,workdate,dowork;
    int i=-1,j=1;
   ifstream inFile("C:\\Users\\Admin\\Desktop\\todolist\\listwork.txt");
   while (getline(inFile, tmp1)) {
       if(tmp1=="--"){
            //firstname listworks
           getline(inFile, tmp1);
           if(tmp1!="##"){
               list_name = QString::fromUtf8(tmp1.c_str());
           }
       }
        if(tmp1=="***"){
            //new work
                        //workfill

             getline(inFile, tmp1);
              workname = QString::fromUtf8(tmp1.c_str());
            getline(inFile, tmp1);
             workdef = QString::fromUtf8(tmp1.c_str());
           getline(inFile, tmp1);
              starwork = QString::fromUtf8(tmp1.c_str());
            getline(inFile, tmp1);
               workdate = QString::fromUtf8(tmp1.c_str());
            getline(inFile, tmp1);
                dowork = QString::fromUtf8(tmp1.c_str());
                twork=new work;
                twork->workname=workname;
                twork->workdef=workdef;
                twork->date=workdate;
                twork->namelist=list_name;
                if(starwork=="true"){
                    twork->star=true;
                }
                else{
                    twork->star=false;
                }
                if(dowork=="true"){
                    twork->dowork=true;
                }
                else{
                    twork->dowork=false;
                }

            listwork.push_back(*twork);
        }
        if(tmp1=="----" && con==0){
             con++;
             //name listworks
            getline(inFile, tmp1);
            list_name = QString::fromUtf8(tmp1.c_str());
        }
        else if(tmp1=="----"){
             //name listworks
            getline(inFile, tmp1);
            list_name = QString::fromUtf8(tmp1.c_str());
            listuser[i].list_works.push_back(listwork);
            listwork.clear();
            j++;
        }

        if(tmp1=="##"){
             //next user
            if(listwork.size()!=0){
                listuser[i].list_works.push_back(listwork);
                listwork.clear();
            }
            i++;
            con=0;
        }

       }
    if(listwork.size()!=0){
        listuser[i].list_works.push_back(listwork);
        listwork.clear();
        }
    inFile.close();
}


void welcom::on_pushButton_clicked()
{    fillwork(listuser);
    listworks* list=new listworks(listuser,counter);
    list->show();
    this->hide();
}
