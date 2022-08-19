#include "master.h"
#include "ui_master.h"

#include <QtGui>

master::master(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::master)
{
    ui->setupUi(this);
    db = QSqlDatabase :: database("settingsdb");
    qry = QSqlQuery(db);
}

master::~master()
{
    delete ui;
}

void master::on_okbutton_clicked()
{

    qry.prepare("SELECT pass FROM settings WHERE id=1");
    if( !qry.exec() )
    {
      qDebug() << qry.lastError();
      qDebug()<<"Status";
    }
    else
    {
        qry.first();
        if(ui->passedit->text()== qry.value(0).toString())
        QMessageBox::information(this, "Confidential", "Password is : "+qry.value(0).toString());
        else
        QMessageBox::warning(this, "Wrong", "Password is Incorrect");
    }
}
