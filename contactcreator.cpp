#include "contactcreator.h"
#include "ui_contactcreator.h"

contactCreator::contactCreator(QWidget *parent,QString ID) :
    QDialog(parent),
    ui(new Ui::contactCreator)
{
    ui->setupUi(this);
    current_ID= ID;
}

contactCreator::~contactCreator()
{
    delete ui;
}

void contactCreator::on_savet_Button_clicked()
{
    this->close();
}


void contactCreator::on_pushButton_2_clicked()
{
    QDate date = ui->dateEdit->date();
    QString gender = ui->gender_combo->currentText();
    QString tele = ui->tel_edit->text();
    QString email = ui->mail_edit->text();
    QString address = ui->add_edit->text();
    QString qq=ui->qq_edit->text();
    QString genre = ui->sort_combo->currentText();
    QString name = ui->name_edit->text();
    QString note = ui->note_textedit->toPlainText();

    //添加到contacts表
    QSqlQuery query;
    QString add_contact = QString("INSERT INTO contacts(belonging,con_name,con_tel,con_mail,con_qq,alias,con_gender,con_year,con_month,con_day,"
                                  "con_addr,con_note)"
                                " VALUES(:belonging,:con_name,:con_tel,:con_mail,:con_qq,:alias,:con_gender,:con_year,:con_month,:con_day,"

                                  ":con_addr,:con_note)");
    query.prepare(add_contact);

    query.bindValue(":belonging",current_ID);
    query.bindValue(":con_name",name);
    query.bindValue(":con_tel",tele);
    query.bindValue("con_mail",email);
    query.bindValue(":con_qq",qq);
    query.bindValue(":alias",genre);
    query.bindValue(":con_gender",gender);
    query.bindValue(":con_year",date.year());
    query.bindValue(":con_month",date.month());
    query.bindValue(":con_day",date.day());
    query.bindValue(":con_addr",address);
    query.bindValue(":con_note",note);

    if(query.exec()==false){
        qDebug()<< "contact添加失败";
        QMessageBox::critical(this,"严重错误","账号创建失败：该联系人已存在");
    }else{
          qDebug()<< "contact添加成功";
          QMessageBox::information(this,"成功","添加成功");
          this->close();
    }

}

