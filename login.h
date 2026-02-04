#ifndef LOGIN_H
#define LOGIN_H
#include <QMainWindow>
#include "user.h"
#include "work.h"
#include "welcom.h"
#include "user.h"
#include <vector>
#include <fstream>
namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT
    vector<user> listuser;
    int i;
public:
    explicit login(vector<user>&,int i,QWidget *parent = 0);
    ~login();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
