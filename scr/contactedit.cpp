#include "contactedit.h"
#include "ui_contactedit.h"

contactedit::contactedit(QWidget *parent,QString ID,QString name) :
    QDialog(parent),
    ui(new Ui::contactedit)
{
    ui->setupUi(this);
    current_ID =ID;
    current_name =name;

    //查询stuents表
    QSqlQuery query;
    if(query.exec(QString("SELECT * FROM contacts WHERE belonging=%1 AND con_name='%2'")
                  .arg(current_ID).arg(current_name))){
        qDebug()<<"查询成功！！！";
    }

    if(query.next()){
        qDebug()<<"现实成功！！！";
    }

    QString stored_gender = query.value(query.record().indexOf("con_gender")).toString();
    QString stored_address = query.value(query.record().indexOf("con_addr")).toString();
    QString stored_email =query.value(query.record().indexOf("con_mail")).toString();
    QString stored_year =query.value(query.record().indexOf("year")).toString();
    QString stored_month =query.value(query.record().indexOf("month")).toString();
    QString stored_day =query.value(query.record().indexOf("day")).toString();
    QString stored_telephone =query.value(query.record().indexOf("con_tel")).toString();
    QString stored_note = query.value(query.record().indexOf("con_note")).toString();
    QString stored_alias = query.value(query.record().indexOf("alias")).toString();
    QString stored_qq = query.value(query.record().indexOf("con_qq")).toString();
    QString stored_name = query.value(query.record().indexOf("con_name")).toString();

    //设置基本信息
    ui->tel_edit->setText(stored_telephone);
    ui->add_edit->setText(stored_address);
    ui->gender_combo->setCurrentText(stored_gender);
    ui->mail_edit->setText(stored_email);
    ui->dateEdit->setDate(QDate(stored_year.toInt(),stored_month.toInt(),stored_day.toInt()));
    ui->sort_combo->setCurrentText(stored_alias);
    ui->qq_edit->setText(stored_qq);
    ui->note_textedit->setText(stored_note);
    ui->name_edit->setText(stored_name);

}

contactedit::~contactedit()
{
    delete ui;
}

void contactedit::on_pushButton_2_clicked()
{
    QDate date = ui->dateEdit->date();
    QString gender = ui->gender_combo->currentText();
    QString tele = ui->tel_edit->text();
    QString email = ui->mail_edit->text();
    QString address = ui->add_edit->text();
    QString qq=ui->qq_edit->text();
    QString genre = ui->sort_combo->currentText();

    QString note = ui->note_textedit->toPlainText();

    //update contacts表
    QSqlQuery query;

    QString update_contact = QString("UPDATE contacts "
                                     "SET belonging=:belonging,"
                                     "con_tel=:con_tel,"
                                     "con_mail=:con_mail,"
                                     "con_qq=:con_qq,"
                                     "alias=:alias,"
                                     "con_gender=:con_gender,"
                                     "con_year = :con_year,"
                                     "con_month = :con_month,"
                                     "con_day = :con_day,"
                                     "con_addr=:con_addr,"
                                     "con_note=:con_note"
                                     " WHERE con_name=:con_name"
                                     );
    query.prepare(update_contact);

    query.bindValue(":belonging",current_ID);
    query.bindValue(":con_name",current_name);
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
          QMessageBox::information(this,"成功","修改成功");
          this->close();
    }

}

