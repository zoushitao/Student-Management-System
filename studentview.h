#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H

#include <QMainWindow>

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

//相关窗口
#include "studentedit.h"//编辑学生信息
#include "contactcreator.h"
#include "contactedit_search.h"
#include "contactdelete.h"



namespace Ui {
class studentView;
}

class studentView : public QMainWindow
{
    Q_OBJECT

public:
    explicit studentView(QWidget *parent = nullptr,QString id = "");

    ~studentView();



private slots:
    void on_eidt_info_clicked();



    void on_create_contact_Button_clicked();

    void on_edit_contact_button_clicked();

    void on_delete_contact_button_clicked();

    void on_pushButton_clicked();

    void on_help_button_clicked();

    void on_exitbutton_clicked();

private:
    Ui::studentView *ui;
    //数据库操作
    QSqlDatabase db;
    QSqlQueryModel model,model2;
    QString current_ID;

    //初始化操作
    void initializeBasicInfo();
    void initializeContacts();
    void initializeScore();

    //定时器刷新
    void timerEvent(QTimerEvent*)override;
    int mtimer;
};

#endif // STUDENTVIEW_H
