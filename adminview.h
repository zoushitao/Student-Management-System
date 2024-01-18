#ifndef ADMINVIEW_H
#define ADMINVIEW_H

#include <QMainWindow>

//数据库

#include <globals.h>

#include "studentview.h"

namespace Ui {
class adminview;
}

class adminview : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminview(QWidget *parent = nullptr);
    ~adminview();

private slots:
    void on_add_score_button_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_edit_score_clicked();

    void on_help_button_clicked();

private:
    Ui::adminview *ui;
    void initScore();
    void initStudents();
    //数据库操作
    QSqlDatabase db;
    QSqlQueryModel model,model2;
    QString current_ID;

    //定时器刷新
    void timerEvent(QTimerEvent*)override;
    int mtimer;

};

#endif // ADMINVIEW_H
