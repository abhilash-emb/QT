#include "startweighing.h"
#include "ui_startweighing.h"

#include "weighing.h"
#include <QtGui>

startweighing::startweighing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::startweighing)
{
    ui->setupUi(this);
    db = QSqlDatabase :: database("database");
    qry = QSqlQuery(db);
}

startweighing::~startweighing()
{
    delete ui;
}

void startweighing::on_cancelbutton_clicked()
{
    QDialog::reject();
}

void startweighing::on_okbutton_clicked()
{
    int uflag=0,pflag=0;
    QString word;
    qry.prepare( "SELECT password FROM admin WHERE username = :user" );
    qry.bindValue(":user", ui->usernameedit->text());
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
            ui->usernameedit->clear();
            ui->passwordedit->clear();
        }
        else if( uflag == 1 && pflag == 0)
        {
            QMessageBox::critical(this, "Login Failed", "Wrong Password !!");
            ui->passwordedit->clear();
        }
        else if( uflag == 1 && pflag == 1)
        {
            QDialog::reject();
            weighing weigh(this,ui->usernameedit->text());
            weigh.setModal(true);
            weigh.exec();
        }
    }
}
