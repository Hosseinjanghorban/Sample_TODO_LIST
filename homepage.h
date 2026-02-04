#ifndef HOMEPAGE_H
#define HOMEPAGE_H
#include <QtWidgets>
#include <QtPrintSupport/QPrinter>
#include <QWidget>
#include <vector>
#include "user.h"
#include "work.h"
#include<vector>
#include <time.h>
namespace Ui {
class homepage;
}

class homepage : public QWidget
{
    Q_OBJECT
     vector<user> listuser;
    int counter;
    int numlist;
    QString listname;
public:
    explicit homepage(QString listname,int numlist,int counter,vector<user>&,QWidget *parent = 0);
    ~homepage();

private slots:
    void on_checkBox_6_clicked();

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_checkBox_4_clicked();

    void on_checkBox_5_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_addwork_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_addtime_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_more4_clicked();

    void on_pushButton_more3_clicked();

    void on_pushButton_more2_clicked();

    void on_pushButton_more1_clicked();

    void on_pushButton_more5_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_today_clicked();

    void on_pushButton_Today_clicked();

    void on_pushButton_print_clicked();

private:
    Ui::homepage *ui;
};

#endif // HOMEPAGE_H
