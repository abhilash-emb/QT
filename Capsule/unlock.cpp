#include "unlock.h"
#include "ui_unlock.h"

#include <QtGui>

unlock::unlock(QWidget *parent, QString user) :
    QDialog(parent),
    ui(new Ui::unlock)
{
    db = QSqlDatabase :: database("database");
    qry = QSqlQuery(db);
    ui->setupUi(this);
    ui->username->setText(user);
}

unlock::~unlock()
{
    delete ui;
}

void unlock::on_passwordedit_returnPressed()
{
    int uflag=0,pflag=0;
    QString word;
    qry.prepare( "SELECT password FROM admin WHERE username = :user" );
    qry.bindValue(":user", ui->username->text());
    if( !qry.exec() )
          qDebug() << qry.lastError();
    else
    {
        while (qry.next())
        {
            uflag = 1;
            word = qry.value(0).toString();
            if( word == ui->passwordedit->text())
                pflag = 1;

        }
        if( uflag == 0 )
        {
            QMessageBox::critical(this, "Login Failed", " Wrong  Username or Password!!");
            ui->passwordedit->clear();
        }
        else if( uflag == 1 && pflag == 0)
        {
            QMessageBox::critical(this, "Login Failed", "Wrong Password !!");
            ui->passwordedit->clear();
        }
        else if( uflag == 1 && pflag == 1)
        {
            QDialog::done(1);
            //QDialog::reject();
        }
    }
}
