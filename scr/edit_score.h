#ifndef EDIT_SCORE_H
#define EDIT_SCORE_H

#include <QDialog>
#include "globals.h"
namespace Ui {
class edit_score;
}

class edit_score : public QDialog
{
    Q_OBJECT

public:
    explicit edit_score(QWidget *parent = nullptr);
    ~edit_score();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::edit_score *ui;
    //数据库操作
    QSqlDatabase db;
    QSqlQueryModel model;
};

#endif // EDIT_SCORE_H
