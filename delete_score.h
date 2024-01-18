#ifndef DELETE_SCORE_H
#define DELETE_SCORE_H

#include <QDialog>
#include "globals.h"
namespace Ui {
class delete_score;
}

class delete_score : public QDialog
{
    Q_OBJECT

public:
    explicit delete_score(QWidget *parent = nullptr);
    ~delete_score();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::delete_score *ui;

    QString current_ID;
    QString current_name;
    //数据库操作
    QSqlDatabase db;
    QSqlQueryModel model;
};

#endif // DELETE_SCORE_H
