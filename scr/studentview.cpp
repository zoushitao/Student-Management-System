#include "studentview.h"
#include "ui_studentview.h"

studentView::studentView(QWidget *parent,QString ID) :
    QMainWindow(parent),
    ui(new Ui::studentView)
{
    ui->setupUi(this);

    ui->welcome_banal_label->clear();

    ui->welcome_banal_label->setText(QString("你好，"));

    current_ID =ID;
    //初始化界面
    initializeBasicInfo();
    initializeContacts();
    mtimer=startTimer(100);






}

studentView::~studentView()
{
    killTimer(mtimer);
    delete ui;
}

void studentView::initializeBasicInfo(){



    //查询stuents表
    QSqlQuery query;
    if(query.exec(QString("SELECT * FROM students WHERE id=")+current_ID)){

    }

    if(query.next()){

    }
    QString stored_name = query.value(query.record().indexOf("name")).toString();
    QString stored_gender = query.value(query.record().indexOf("gender")).toString();
    QString stored_address = query.value(query.record().indexOf("address")).toString();
    QString stored_email =query.value(query.record().indexOf("email")).toString();
    QString stored_year =query.value(query.record().indexOf("year")).toString();
    QString stored_month =query.value(query.record().indexOf("month")).toString();
    QString stored_day =query.value(query.record().indexOf("day")).toString();
    QString stored_telephone =query.value(query.record().indexOf("telephone")).toString();
    //设置基本信息
    ui->name_edit->setText(stored_name);
    ui->birthday_edit->setText(stored_year+QString("年")+stored_month+QString("月")+stored_day+QString("日"));
    ui->gender_edit->setText(stored_gender);
    ui->tel_edit->setText(stored_telephone);
   ui->email_edit->setText(stored_email);
    ui->id_edit->setText(current_ID);
    ui->adress->setText(stored_address);

}


void studentView::on_eidt_info_clicked()
{
    studentedit *ed = new studentedit(nullptr,current_ID);
    ed->show();
}





void studentView::on_create_contact_Button_clicked()
{
    contactCreator *cc = new contactCreator(nullptr,current_ID);
    cc->show();
}

//自动刷新
void studentView::timerEvent(QTimerEvent*){
    initializeBasicInfo();
    initializeContacts();
    initializeScore();
}

void studentView::initializeContacts(){
    QString select = QString("SELECT con_name as 名字,con_tel as 电话,con_mail as Email,"
                             "con_qq as QQ,alias as 分组,con_gender as 性别,con_year as 出生年份,"
                             "con_month as 出生月份,con_day as 出生日,con_addr as 联系地址,con_note as 备注"
                             " FROM contacts WHERE belonging=%1").arg(current_ID);

    model.setQuery(select);

    ui->contact_tableView->setModel(&model);

}

void studentView::on_edit_contact_button_clicked()
{
    contactedit_search *cs = new contactedit_search(this,current_ID);
    cs->show();


}


void studentView::on_delete_contact_button_clicked()
{
    contactDelete *cd=new  contactDelete(this,current_ID);
    cd->show();

}


void studentView::on_pushButton_clicked()
{
    QMessageBox::information(this,"傻逼","好好学习吧");
}

void studentView::initializeScore(){




    QString select = QString("SELECT "
                             ""
                             "sum as 综合成绩,"
                             "ROW_NUMBER() OVER (ORDER BY sum DESC) as 排名,"
                             "chinese as 语文,english as 英语,"
                             "math as 数学,"
                             "test_avg as 考试平均成绩,"
                             "mutual as 同学互评 ,"
                             "teacher as 任课老师评分,"
                             "quality as 品德思想 "
                             " FROM scores WHERE id = "+this->current_ID
                             );
    qDebug()<<select;
    model2.setQuery(select);


    this->ui->scores_tableView->setModel(&model2);
}

void studentView::on_help_button_clicked()
{
    auto help_view = new help(this);
    help_view->show();
}


void studentView::on_exitbutton_clicked()
{

}

