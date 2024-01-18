#ifndef CONTACTEDIT_SEARCH_H
#define CONTACTEDIT_SEARCH_H

#include <QDialog>
#include "globals.h"
#include "contactedit.h"



namespace Ui {
class contactedit_search;
}

class contactedit_search : public QDialog
{
    Q_OBJECT

public:
    explicit contactedit_search(QWidget *parent = nullptr,QString ID="");
    ~contactedit_search();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::contactedit_search *ui;
    QString current_ID;
    QString current_name;
    //数据库操作
    QSqlDatabase db;
    QSqlQueryModel model;
};

#endif // CONTACTEDIT_SEARCH_H
