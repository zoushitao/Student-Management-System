#ifndef FIND_PSWD_H
#define FIND_PSWD_H

#include <QDialog>

namespace Ui {
class find_pswd;
}

class find_pswd : public QDialog
{
    Q_OBJECT

public:
    explicit find_pswd(QWidget *parent = nullptr);
    ~find_pswd();

private slots:
    void on_pushButton_clicked();

private:
    Ui::find_pswd *ui;
};

#endif // FIND_PSWD_H
