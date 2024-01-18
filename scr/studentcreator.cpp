#include "studentcreator.h"
#include "ui_studentcreator.h"

studentCreator::studentCreator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentCreator)
{
    ui->setupUi(this);
}

studentCreator::~studentCreator()
{
    delete ui;
}




void studentCreator::on_save_button_clicked()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    //设置名字
    db.setDatabaseName(DATABASE_NAME);
     //打开数据库
    if(db.open()){
        qDebug()<<"打开数据库成功";
    }else{
        qDebug()<<"打开数据库失败";
    }


    //从对话框中获取信息
    QDate date = ui->dateEdit->date();
    QString name = ui->name_edit->text();
    QString gender = ui->gender_combo->currentText();
    QString email = ui->email_edit->text();
    QString address = ui->adress->text();
    QString password = ui->pwd_edit->text();
    QString tel = ui->telephone_edit->text();
    QString id=ui->id_edit->text();

    //添加学生账户
    QSqlQuery query;
    QString add_student = QString("INSERT INTO students(id,name,gender,telephone,email,year,month,day,address,age,password)"
                                " VALUES(:id,:name,:gender,:telephone,:email,:year,:month,:day,:address,:age,:password)");

    query.prepare(add_student);
    query.bindValue(":id",id);
    query.bindValue(":name",name);
    query.bindValue(":gender",gender);
    query.bindValue(":telephone",tel);
    query.bindValue(":email",email);
    query.bindValue(":year",date.year());
    query.bindValue(":month",date.month());
    query.bindValue(":day",date.day());
    query.bindValue(":address",address);
    query.bindValue(":age",18);//!!!!!!j记得修改
    query.bindValue(":password",password);

    qDebug()<<address;
    if(query.exec()==false){
        qDebug()<< "student添加失败";
        QMessageBox::critical(this,"严重错误","账号创建失败：学号重复");
    }else{
          qDebug()<< "student添加成功";
          QMessageBox::information(this,"可以","创建成功，记得保存密码");
          this->close();
    }



};

