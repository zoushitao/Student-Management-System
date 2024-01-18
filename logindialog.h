#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QPainter>
#include <QImage>

//其他界面弹出

#include "studentcreator.h"
#include "studentview.h"
#include "adminview.h"
#include "find_pswd.h"
//数据库

#include <globals.h>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots:


    void on_login_button_clicked();

    void on_quit_button_clicked();

    void on_create_account_clicked();

    void on_help_clicked();

    void on_find_passwd_clicked();

private:
    Ui::LoginDialog *ui;
    //插入图片
    void paintEvent(QPaintEvent *)override;

    //数据库操作
    QSqlDatabase db;
    QSqlQueryModel model;

};

#endif // LOGINDIALOG_H
