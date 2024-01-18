#include "find_pswd.h"
#include "ui_find_pswd.h"
#include"globals.h"

find_pswd::find_pswd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::find_pswd)
{
    ui->setupUi(this);
}

find_pswd::~find_pswd()
{
    delete ui;
}

void find_pswd::on_pushButton_clicked()
{
    QMessageBox::information(this,"l","验证信息失败");
}

