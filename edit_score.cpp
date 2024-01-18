#include "edit_score.h"
#include "ui_edit_score.h"

edit_score::edit_score(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_score)
{
    ui->setupUi(this);
}

edit_score::~edit_score()
{
    delete ui;
}

void edit_score::on_buttonBox_accepted()
{
    bool flag=true;
    QString id =ui->id_edit->text();
    /*检查学号是否存在*/
    QSqlQuery query_sc;
    if(query_sc.exec("SELECT * FROM scores")){
        qDebug()<<"查询成功！！！";
    }
    int idNum = query_sc.record().indexOf("id");



    while(query_sc.next()){
         qDebug()<<"可以";
        QString stored_id = query_sc.value(idNum).toString();

        qDebug()<<stored_id ;

        if(stored_id==id){
            qDebug()<<"成绩查询成功！！！";
            flag=true;

        }else{
            flag=false;
        }

    }
    if(!flag){
        QMessageBox::information(this,"严重的错误","找不到该学号");
        return;
    }
    /*************8删除操作*********/
    QSqlQuery query_del;
    QString de = QString("DELETE FROM scores WHERE id= ")
            +id;
    if(query_del.exec(de)){
        qDebug()<<"删除成功！！！";


    }else{
     qDebug()<<"删除失败！！！";
    }


    /********写入操作***********/

        double chinese = ui->chinese_edit->text().toDouble(&flag);
        double english = ui->english_edit->text().toDouble(&flag);
        double math =ui->math_edit->text().toDouble(&flag);
        double mutual =ui->mutual_edit->text().toDouble(&flag);
        double quality = ui->quality_edit->text().toDouble(&flag);
        double teacher = ui->quality_edit->text().toDouble(&flag);
        if(!flag){
            QMessageBox::information(this,"严重的错误","输入的不是数字");
            return;
        }
        if(chinese<0 or chinese>100)flag =false;
        if(english<0 or english>100)flag =false;
        if(math<0 or math>100)flag =false;
        if(mutual<0 or mutual>100)flag =false;
        if(quality<0 or quality>100)flag =false;
        if(teacher<0 or teacher>100)flag =false;
        if(!flag){
            QMessageBox::information(this,"严重的错误","输入成绩不合法:0-100");
            return;
        }
        //计算平均成绩
        double test_avg = (math+chinese+english)/3;
        double avg = test_avg*0.6+mutual*0.1+teacher*0.2+quality*0.1;

        //查询students表
        QSqlQuery query2;
        if(query2.exec("SELECT * FROM students")){
            qDebug()<<"查询成功！！！";
        }






        //添加到scores表
        QSqlQuery query;
        QString add = QString("INSERT INTO scores(id,sum,math,chinese,english,mutual,quality,teacher,test_avg)  "
                                    " VALUES(:myid,:mysum,:mymath,:mychinese,:myenglish,:mymutual,"
                                      ":myquality,:myteacher,:mytest_avg)");
        query.prepare(add);

        query.bindValue(":myid",id);
        query.bindValue(":mysum",avg);
        query.bindValue(":mymath",math);
        query.bindValue(":mychinese",chinese);
        query.bindValue(":myenglish",english);
        query.bindValue(":mymutual",mutual);
        query.bindValue(":myquality",quality);
        query.bindValue(":myteacher",teacher);
        query.bindValue(":mytest_avg",test_avg);




        if(query.exec()==false){
            qDebug()<< "score添加失败";
            QMessageBox::information(this,"严重错误","成绩创建失败：该学生的成绩已存在");
        }else{
              qDebug()<< "score添加成功";
              QMessageBox::information(this,"成功","添加成功");
              this->close();
        }
}

