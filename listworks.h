#ifndef LISTWORKS_H
#define LISTWORKS_H

#include <QMainWindow>
#include "user.h"
namespace Ui {
class listworks;
}

class listworks : public QMainWindow
{
    Q_OBJECT
    vector<user> listuser;
    int counter;

public:

    explicit listworks(vector<user>& listuser,int counter,QWidget *parent = 0);
    ~listworks();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_list1_clicked();

    void on_pushButton_list2_clicked();

    void on_pushButton_list3_clicked();

    void on_pushButton_list4_clicked();

    void on_pushButton_addlist_clicked();

    void on_pushButton_starlist_clicked();

    void on_pushButton_sendtask_clicked();

    void on_pushButton_assigned_clicked();

    void on_pushButton_color_clicked();

    void on_pushButton_font_clicked();

private:
    Ui::listworks *ui;
};

#endif // LISTWORKS_H
