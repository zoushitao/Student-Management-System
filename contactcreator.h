#ifndef CONTACTCREATOR_H
#define CONTACTCREATOR_H

#include <QDialog>
#include "globals.h"
namespace Ui {
class contactCreator;
}

class contactCreator : public QDialog
{
    Q_OBJECT

public:
    explicit contactCreator(QWidget *parent = nullptr,QString ID="");
    ~contactCreator();

private slots:
    void on_savet_Button_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::contactCreator *ui;
    QString current_ID;
    //数据库操作
    QSqlDatabase db;
    QSqlQueryModel model;
};

#endif // CONTACTCREATOR_H
