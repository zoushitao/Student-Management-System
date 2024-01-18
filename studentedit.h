#ifndef STUDENTEDIT_H
#define STUDENTEDIT_H

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
class studentedit;
}

class studentedit : public QDialog
{
    Q_OBJECT

public:
    explicit studentedit(QWidget *parent = nullptr,QString ID="");
    ~studentedit();

private slots:
    void on_quit_button_clicked();

    void on_save_button_clicked();

private:
    Ui::studentedit *ui;

    //数据库操作
    QSqlDatabase db;
    QSqlQueryModel model;
    QString current_ID;

    //初始化操作
    void initializeBasicInfo();
};

#endif // STUDENTEDIT_H
