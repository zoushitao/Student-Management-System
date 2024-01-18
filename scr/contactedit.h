#ifndef CONTACTEDIT_H
#define CONTACTEDIT_H

#include <QDialog>
#include "globals.h"
namespace Ui {
class contactedit;
}

class contactedit : public QDialog
{
    Q_OBJECT

public:
    explicit contactedit(QWidget *parent = nullptr,QString ID="",QString name="");
    ~contactedit();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::contactedit *ui;
    QString current_ID;
    QString current_name;
    //数据库操作
    QSqlDatabase db;
    QSqlQueryModel model;
};

#endif // CONTACTEDIT_H
