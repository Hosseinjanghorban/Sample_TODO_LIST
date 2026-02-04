#include "login.h"
#include <QApplication>
#include "welcom.h"
#include "homepage.h"
#include <vector>
#include "work.h"
#include "user.h"
#include <fstream>

using namespace std;
int i=0;
void fill(vector<user>& listuser)
{
    string tmp;
    QString tmpuser;
    QString tmppass;

   ifstream inFile("C:\\Users\\Admin\\Desktop\\todolist\\data.txt");
   while (getline(inFile, tmp)) {
       tmpuser = QString::fromUtf8(tmp.c_str());
           getline(inFile, tmp);
           tmppass = QString::fromUtf8(tmp.c_str());
           user* usert=new user;
           usert->username=tmpuser;
           usert->password=tmppass;
           listuser.push_back(*usert);
           i++;
       }
   inFile.close();
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    vector<user> listuser;    
    fill(listuser);
    login w(listuser,i);
    w.show();


    return a.exec();
}
