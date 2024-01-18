#include "studentedit.h"
#include "ui_studentedit.h"

studentedit::studentedit(QWidget *parent,QString ID) :
    QDialog(parent),
    ui(new Ui::studentedit)
{
    ui->setupUi(this);
    current_ID =ID;
    initializeBasicInfo();
}

studentedit::~studentedit()
{
    delete ui;
}

void studentedit::initializeBasicInfo(){
    //查询stuents表
    QSqlQuery query;
    if(query.exec(QString("SELECT * FROM students WHERE id=")+current_ID)){
        qDebug()<<"查询成功！！！";
    }

    if(query.next()){
        qDebug()<<"现实成功！！！";
    }

    QString stored_gender = query.value(query.record().indexOf("gender")).toString();
    QString stored_address = query.value(query.record().indexOf("address")).toString();
    QString stored_email =query.value(query.record().indexOf("email")).toString();
    QString stored_year =query.value(query.record().indexOf("year")).toString();
    QString stored_month =query.value(query.record().indexOf("month")).toString();
    QString stored_day =query.value(query.record().indexOf("day")).toString();
    QString stored_telephone =query.value(query.record().indexOf("telephone")).toString();
    //设置基本信息
    ui->telephone_edit->setText(stored_telephone);
    ui->adress->setText(stored_address);
    ui->gender_combo->setCurrentText(stored_gender);
    ui->email_edit->setText(stored_email);
    ui->dateEdit->setDate(QDate(stored_year.toInt(),stored_month.toInt(),stored_day.toInt()));

}

void studentedit::on_quit_button_clicked()
{
    this->close();
}


void studentedit::on_save_button_clicked()
{
    //从对话框中获取信息
    QDate date = ui->dateEdit->date();
    QString gender = ui->gender_combo->currentText();
    QString email = ui->email_edit->text();
    QString address = ui->adress->text();;
    QString tel = ui->telephone_edit->text();

    //修改学生账户
    QSqlQuery query;

    QString update_student = QString("UPDATE students "
                                     "SET gender=:gender,"
                                     "telephone=:telephone,"
                                     "email=:email,"
                                     "year=:year,"
                                     "month=:month,"
                                     "day=:day,"
                                     "address=:address,"
                                     "age = age"
                                     " WHERE id=:id"
                                     );



    qDebug()<<update_student;
    qDebug()<<address;
    query.prepare(update_student);

     query.bindValue(":address",address);
    query.bindValue(":gender",gender);
   query.bindValue(":telephone",tel);
    query.bindValue(":email",email);
   query.bindValue(":month",date.month());
   query.bindValue(":year",date.year());
    query.bindValue(":day",date.day());


     qDebug()<<address;
   query.bindValue(":age",18);//!!!!!!j记得
   query.bindValue(":id",current_ID);

    qDebug()<<query.lastQuery();

    if(query.exec()==false){
        qDebug()<< "student修改失败";
        QMessageBox::critical(this,"严重错误","学生信息修改失败");

        qDebug()<<query.executedQuery();

    }else{
          qDebug()<< "student修改成功";
          QMessageBox::information(this,"提示","修改成功");
          qDebug()<<query.lastError();
          this->close();

    }



}

