#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;
#include <QObject>
#include <QString>
#include "work.h"
#include <vector>
class user
{
public:
    QString username;
    QString password;
   vector<vector<work>> list_works;
   vector <work> list_assigned_work;
    user();
};

#endif // USER_H
