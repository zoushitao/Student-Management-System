#include "contactedit_search.h"
#include "ui_contactedit_search.h"

contactedit_search::contactedit_search(QWidget *parent,QString ID) :
    QDialog(parent),
    ui(new Ui::contactedit_search)
{
    ui->setupUi(this);
    current_ID =ID;
}

contactedit_search::~contactedit_search()
{
    delete ui;
}

void contactedit_search::on_pushButton_clicked()
{
    this->close();
}


void contactedit_search::on_pushButton_2_clicked()
{
    current_name = ui->name_edit->text();
    QSqlQuery query;
    QString search=QString("SELECT * FROM contacts WHERE belonging=%1 AND con_name='%2'")
            .arg(current_ID).arg(current_name);
    qDebug()<<search;
    if(query.exec(search)){
        qDebug()<<"查询成功！！！";
    }else{
     qDebug()<<"查询失败！！！";
    }

    if(query.next()){
        contactedit *cd = new contactedit(nullptr,current_ID,current_name);

        qDebug()<<"现实成功！！！";
        cd->show();
        this->close();

    }else{
        QMessageBox::critical(this,"严重错误","找不到这个人，确认名字输入无误");
    }

}

