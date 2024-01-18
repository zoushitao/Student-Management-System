#include "delete_score.h"
#include "ui_delete_score.h"

delete_score::delete_score(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::delete_score)
{
    ui->setupUi(this);
}

delete_score::~delete_score()
{
    delete ui;
}

void delete_score::on_buttonBox_accepted()
{
    if(QMessageBox::question(this,"删除","确定要删除吗???这个操作无法撤销哦",
                             QMessageBox::Yes|QMessageBox::No) !=QMessageBox::Yes){
        return;

    }
    current_name = this->ui->id_edit->text();
    qDebug()<<current_name;
    QSqlQuery query;
    QString search=QString("SELECT * FROM scores WHERE id= ") +current_name;
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
        QString de = QString("DELETE FROM scores WHERE id= ")
                +current_name;
        if(query.exec(de)){
            qDebug()<<"删除成功！！！";
            QMessageBox::information(this,"成功","删除成功了");

        }else{
         qDebug()<<"删除失败！！！";
        }

        this->close();

    }else{
        QMessageBox::critical(this,"严重错误","找不到这个学生，确认ID输入无误");
    }
}

