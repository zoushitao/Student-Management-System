#include "logindialog.h"
#include "ui_logindialog.h"
#include "help.h"

int i=0;

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->m_message->clear();


}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QRect rect = ui->frame->frameRect();
    rect.translate(ui->frame->pos());
    QImage image(":/images/login.JPG");
    painter.drawImage(rect,image);
    i=(i+1)%3;

}


void LoginDialog::on_login_button_clicked()
{
    //添加数据库驱动库
    db = QSqlDatabase::addDatabase("QSQLITE");
    //设置名字
    db.setDatabaseName(DATABASE_NAME);
     //打开数据库
    if(db.open()){
        qDebug()<<"打开数据库成功";
    }else{
        qDebug()<<"打开数据库失败";
    }
    //建立





    //获取输入的用户名和密码
    QString identity;
    identity= ui->m_identity_combo->currentText();
    qDebug()<<identity;
    QString username = ui->m_username_edit->text();
    qDebug()<<username;
    QString passwd = ui->m_password_edit->text();
    qDebug()<<passwd;


    /*******管理员登录*******/
    if(identity == QString("管理员")){

        //查询admins表
        QSqlQuery query;
        if(query.exec("SELECT * FROM admins")){
            qDebug()<<"查询成功！！！";
        }
        int idNum = query.record().indexOf("id");
        int pswNum = query.record().indexOf("password");


        while(query.next()){
             qDebug()<<"可以";
            QString stored_username = query.value(idNum).toString();
            QString stored_passwd = query.value(pswNum).toString();
            qDebug()<<stored_username ;

            if(stored_username==username and stored_passwd==passwd){
                qDebug()<<"管理员登录成功！！！";

                adminview *adv=new adminview(nullptr);
                adv->show();


                this->close();
                return;

            }

        }
        QMessageBox::information(this,"失败","账号或者密码错误");

    }

    /*******学生登录*******/
    if(identity == QString("学生")){
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

            if(stored_username==username and stored_passwd==passwd){
                qDebug()<<"登录成功！！！";
                studentView *stv=new studentView(nullptr,stored_username);
                stv->show();
                this->close();

            }

        }
        QMessageBox::information(this,"失败","账号或者密码错误");
    }

}


void LoginDialog::on_quit_button_clicked()
{
    if(QMessageBox::question(this,"退出","确定要退出吗???",QMessageBox::Yes|QMessageBox::No)
            ==QMessageBox::Yes)
    this->close();

}


void LoginDialog::on_create_account_clicked()
{
    studentCreator *st=new studentCreator;
    st->show();

}


void LoginDialog::on_help_clicked()
{
    auto help_view = new help(this);
    help_view->show();

}


void LoginDialog::on_find_passwd_clicked()
{
    find_pswd *find= new find_pswd(this);
    find->show();
}

