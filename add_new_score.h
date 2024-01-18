#ifndef ADD_NEW_SCORE_H
#define ADD_NEW_SCORE_H

#include <QDialog>
#include "globals.h"

namespace Ui {
class add_new_score;
}

class add_new_score : public QDialog
{
    Q_OBJECT

public:
    explicit add_new_score(QWidget *parent = nullptr);
    ~add_new_score();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::add_new_score *ui;

    //数据库操作
    QSqlDatabase db;
    QSqlQueryModel model;
    QString current_ID;
};

#endif // ADD_NEW_SCORE_H
