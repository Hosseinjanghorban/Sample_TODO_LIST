#ifndef WELCOM_H
#define WELCOM_H

#include <QWidget>
#include "user.h"
#include "work.h"
namespace Ui {
class welcom;
}

class welcom : public QWidget
{
    Q_OBJECT
    int counter;
    vector<user> listuser;
public:
    explicit welcom(vector<user>& listuser,int i,QWidget *parent = 0);
    ~welcom();

private slots:
    void on_label_welcom_linkActivated(const QString &link);

    void on_pushButton_clicked();

private:
    Ui::welcom *ui;
};

#endif // WELCOM_H
