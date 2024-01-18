#include "adminview.h"
#include "ui_adminview.h"
#include <iostream>
#include "delete_score.h"
#include"edit_score.h""
//相关窗口
#include "add_new_score.h"
adminview::adminview(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminview)
{
    ui->setupUi(this);

    //初始化操作
    initScore();
    initStudents();
    mtimer=startTimer(100);
}

int stu_count =0;
adminview::~adminview()
{
    delete ui;
}


void adminview::initScore(){
    QString item,order;
    if(this->ui->item_combo->currentText()==QString("学号"))item="sc.id";
    if(this->ui->item_combo->currentText()=="综合成绩")item="sc.sum";
    if(this->ui->item_combo->currentText()=="语文")item="sc.chinese";
    if(this->ui->item_combo->currentText()=="数学")item="sc.math";
    if(this->ui->item_combo->currentText()=="英语")item="sc.english";
    if(this->ui->item_combo->currentText()=="同学互评")item="sc.mutual";
    if(this->ui->item_combo->currentText()=="任课老师评分")item="sc.teacher";
    if(this->ui->item_combo->currentText()=="品德思想")item="sc.quality";
    if(this->ui->item_combo->currentText()=="考试平均成绩")item="sc.test_avg ";

    if(this->ui->order_comBox->currentText()=="升序")order=" ASC";
    if(this->ui->order_comBox->currentText()=="降序")order=" DESC";



    QString select = QString("SELECT sc.id as 学号,"
                             "stu.name 姓名,"
                             "sc.sum as 综合成绩,"
                             "ROW_NUMBER() OVER (ORDER BY sc.sum DESC) as 排名,"
                             "sc.chinese as 语文,sc.english as 英语,"
                             "sc.math as 数学,"
                             "sc.test_avg as 考试平均成绩,"
                             "sc.mutual as 同学互评 ,"
                             "sc.teacher as 任课老师评分,"
                             "sc.quality as 品德思想 "
                             " FROM scores as sc INNER JOIN students as stu on sc.id = stu.id "
                             " ORDER BY  "
                             )+item+order;

    model.setQuery(select);


    ui->score_table->setModel(&model);

}

//自动刷新
void adminview::timerEvent(QTimerEvent*){
    initScore();
    this->ui->lcdNumber->display(stu_count++);

}

void adminview::on_add_score_button_clicked()
{
    add_new_score *ans = new add_new_score(this);
    ans->show();
}


void adminview::on_pushButton_clicked()
{
    auto username = ui->id_search_edit->text();
    //查询admins表
    QSqlQuery query;
    if(query.exec("SELECT * FROM students")){
        qDebug()<<"查询成功！！！";
    }
    int idNum = query.record().indexOf("id");
    int pswNum = query.record().indexOf("password");


    while(query.next()){
         qDebug()<<"可以";
        QString stored_username = query.value(idNum).toString();
        QString stored_passwd = query.value(pswNum).toString();
        qDebug()<<stored_username ;

        if(stored_username==username ){
            qDebug()<<"登录成功！！！";
            studentView *stv=new studentView(nullptr,stored_username);
            stv->show();
            this->close();

        }

    }
    QMessageBox::information(this,"笑死","找不到该学生");
}

void adminview::initStudents(){
    QString select = QString("SELECT id as 学号,name as 姓名,gender as 性别,year as 出生年份"
                             " FROM students");

    model2.setQuery(select);

    ui->studenttableView->setModel(&model2);
}

void adminview::on_pushButton_2_clicked()
{
  auto view = new delete_score(this);
  view->show();

}


void adminview::on_edit_score_clicked()
{
    auto view = new edit_score(this);
    view->show();
}


void adminview::on_help_button_clicked()
{
    auto help_view = new help(this);
    help_view->show();
}

