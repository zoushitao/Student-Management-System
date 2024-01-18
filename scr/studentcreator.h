#ifndef STUDENTCREATOR_H
#define STUDENTCREATOR_H

#include <QDialog>
//数据库
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlError>
#include <QDebug>
#include <QSqlRecord>
#include <QMessageBox>
#include <globals.h>








namespace Ui {
class studentCreator;
}

class studentCreator : public QDialog
{
    Q_OBJECT

public:
    explicit studentCreator(QWidget *parent = nullptr);
    ~studentCreator();



private slots:
    void on_save_button_clicked();

private:
    Ui::studentCreator *ui;


    //数据库操作
    QSqlDatabase db;
    QSqlQueryModel model;
};

#endif // STUDENTCREATOR_H
