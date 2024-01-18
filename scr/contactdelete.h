#ifndef CONTACTDELETE_H
#define CONTACTDELETE_H

#include <QDialog>
#include "globals.h"
namespace Ui {
class contactDelete;
}

class contactDelete : public QDialog
{
    Q_OBJECT

public:
    explicit contactDelete(QWidget *parent = nullptr,QString ID="");
    ~contactDelete();

private slots:
    void on_quit_clicked();

    void on_ok_clicked();

private:
    Ui::contactDelete *ui;
    QString current_ID;
    QString current_name;
    //数据库操作
    QSqlDatabase db;
    QSqlQueryModel model;
};

#endif // CONTACTDELETE_H
