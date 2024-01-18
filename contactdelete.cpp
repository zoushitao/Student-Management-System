#include "contactdelete.h"
#include "ui_contactdelete.h"

contactDelete::contactDelete(QWidget *parent,QString ID) :
    QDialog(parent),
    ui(new Ui::contactDelete)
{
    ui->setupUi(this);
    current_ID=ID;
}

contactDelete::~contactDelete()
{
    delete ui;
}

void contactDelete::on_quit_clicked()
{
    this->close();
}


void contactDelete::on_ok_clicked()
{
    if(QMessageBox::question(this,"删除","确定要删除吗???这个操作无法撤销哦",
                             QMessageBox::Yes|QMessageBox::No) !=QMessageBox::Yes){
        return;

    }
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
        //do something....

        qDebug()<<"现实成功！！！";
        //删除操作
        QString de = QString("DELETE FROM contacts WHERE belonging=%1 AND con_name='%2'")
                .arg(current_ID).arg(current_name);
        if(query.exec(de)){
            qDebug()<<"删除成功！！！";
            QMessageBox::information(this,"成功","删除成功了");

        }else{
         qDebug()<<"删除失败！！！";
        }

        this->close();

    }else{
        QMessageBox::critical(this,"严重错误","找不到这个人，确认名字输入无误");
    }
}

