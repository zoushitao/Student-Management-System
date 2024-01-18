
#include "logindialog.h"
#include <QApplication>

#include "globals.h"
//数据库
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlError>

QSqlDatabase db;

void setupDatabase(){
    //添加数据库驱动库
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    //设置名字
    db.setDatabaseName(DATABASE_NAME);
     //打开数据库
    if(db.open()){
        qDebug()<<"打开数据库成功";
    }else{
        qDebug()<<"打开数据库失败";
    }
    /****************创建学生表**************/

    QSqlQuery query;

    QString creat_students_table = QString("CREATE TABLE students ("
                                          "id INT PRIMARY KEY NOT NULL,"
                                           "name TEXT NOT NULL,"
                                           "gender TEXT NOT NULL,"
                                           "telephone TEXT,"
                                           "email TEXT,"
                                           "year INT,"
                                           "month INT,"
                                           "day INT,"
                                           "address TEXT,"
                                           "age INT,"
                                           "password TEXT NOT NULL)");
    if(query.exec(creat_students_table)==false){
        qDebug()<< "学生表创建失败";
    }else{
          qDebug()<< "学生表创建成功";
    }


    /****************创建管理员表**************/
    QString creat_admin_table = QString("CREATE TABLE admins ("
                                          "id INT PRIMARY KEY NOT NULL,"
                                           "password TEXT NOT NULL)");
    if(query.exec(creat_admin_table)==false){
        qDebug()<< "admins表创建失败";
    }else{
          qDebug()<< "admins表创建成功";
    }
    //添加管理员账户
    QString add_admin = QString("INSERT INTO admins(id,password)"
                                "VALUES(:id,:password)");
    query.prepare(add_admin);
    query.bindValue(":id",1);
    query.bindValue(":password","1");


    if(query.exec()==false){
        qDebug()<< "admins添加失败";
    }else{
          qDebug()<< "admins添加成功";
    }

    //建立contacts数据库
    QString creat_contacts_table = QString("CREATE TABLE contacts ("
                                          "belonging INT NOT NULL,"
                                           "con_name TEXT NOT NULL UNIQUE,"
                                           "con_tel TEXT,"
                                           "con_mail TEXT,"
                                           "con_qq TEXT,"
                                           "alias TEXT ,"
                                           "con_gender TEXT,"
                                           "con_year INT,"
                                           "con_month INT,"
                                           "con_day INT,"
                                          "con_addr TEXT,"
                                           "con_note TEXT)");
    if(query.exec(creat_contacts_table)==false){
        qDebug()<< "联系人表创建失败";
    }else{
          qDebug()<< "联系人表创建成功";
    }

    //建立scores数据库
    QString creat_scores_table = QString("CREATE TABLE scores ("
                                          "id INT PRIMARY KEY NOT NULL,"
                                         "sum DOUBLE NOT NULL,"
                                         "math DOUBLE NOT NULL,"
                                         "chinese DOUBLE NOT NULL,"
                                         "english DOUBLE NOT NULL,"
                                         "mutual DOUBLE NOT NULL,"
                                         "teacher DOUBLE NOT NULL,"
                                         "test_avg DOUBLE NOT NULL,"
                                         "quality DOUBLE NOT NULL"
                                         ")");
    if(query.exec(creat_scores_table)==false){
        qDebug()<< "scores数据库创建失败";
    }else{
          qDebug()<< "scores数据库创建成功";
    }

}



#include "studentview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    setupDatabase();
    LoginDialog lg;
    lg.show();


    return a.exec();
}
