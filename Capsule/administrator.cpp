#include "administrator.h"
#include "ui_administrator.h"

#include <QtGui>
#include <QSqlQueryModel>

administrator::administrator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrator)
{
    ui->setupUi(this);
    db = QSqlDatabase :: database("database");
    qry = QSqlQuery(db);
    qry.prepare("SELECT interval, header, footer,device FROM settings WHERE id=1");
        if(!qry.exec())
            qDebug("Error at prefer");
        else
        {
            qry.first();
            if( qry.value(0).toInt() == 2 )
                ui->radiobutton2secs->setChecked(1);
            else if( qry.value(0).toInt() == 3 )
                ui->radiobutton3secs->setChecked(1);
            else if( qry.value(0).toInt() == 4 )
                ui->radiobutton4secs->setChecked(1);

            ui->devicecombobox->setCurrentIndex(qry.value(3).toInt());
            ui->header->setText(qry.value(1).toString());
            ui->footer->setText(qry.value(2).toString());
        }

}

administrator::~administrator()
{
    delete ui;
}

void administrator::on_okbutton_clicked()
{
    int flag=0;
    qry.prepare( "SELECT * FROM admin WHERE username = :user" );
    qry.bindValue(":user", ui->operatorusername->text());
    if( !qry.exec() )
          qDebug() << qry.lastError();
    else
    {
        while (qry.next())
        {
            flag = 1;
        }
        if(flag == 1)
        {
            ui->resetpasswordgroup->setEnabled(1);
            ui->deletegroup->setEnabled(1);
        }
        else
        {
            QMessageBox::critical(this, "Invalid User", " Invalid Username !!");
        }
    }/*
    ui->resetpasswordgroup->setEnabled(1);
    ui->deletegroup->setEnabled(1);*/
}

void administrator::on_cancelbutton_clicked()
{
        qry.prepare("SELECT interval, header, footer FROM settings WHERE id=1");
            if(!qry.exec())
                qDebug("Error at prefer");
            else
            {
                qry.first();
                if( qry.value(0).toInt() == 2 )
                    ui->radiobutton2secs->setChecked(1);
                else if( qry.value(0).toInt() == 3 )
                    ui->radiobutton3secs->setChecked(1);
                else if( qry.value(0).toInt() == 4 )
                    ui->radiobutton4secs->setChecked(1);

                ui->header->setText(qry.value(1).toString());
                ui->footer->setText(qry.value(2).toString());
            }
}

void administrator::on_passokbutton_clicked()
{
    QString word;
    qry.prepare("SELECT password FROM settings WHERE id=1");
        if(!qry.exec())
            qDebug("Error at prefer");
        else
        {
            qry.first();
            word = qry.value(0).toString();
            if(ui->oldpassedit->text() == word )
            {
                qDebug("Old password correct");
                ui->newpassedit->setEnabled(1);
                ui->newpasswordlabel->setEnabled(1);
                ui->changebutton->setEnabled(1);
                ui->passcancelbutton->setEnabled(1);
            }
            else
            {
                QMessageBox::critical(this, "Login Failed", "Password Incorrect !!");
                ui->oldpassedit->clear();
            }
        }
}

void administrator::on_changebutton_clicked()
{
    qry.prepare( "UPDATE settings SET password =:pass WHERE id = 1" );
    qry.bindValue(":pass", ui->newpassedit->text());
    if( !qry.exec() )
         qDebug() << qry.lastError();
    else
     {
         qDebug( "Updated!" );
         QMessageBox::information(this, "Successful", "Password changed successfuly");
         ui->oldpassedit->clear();
         ui->newpassedit->clear();
     }
}

void administrator::on_passcancelbutton_clicked()
{
    ui->newpassedit->clear();
    ui->oldpassedit->clear();
    ui->newpassedit->setDisabled(1);
    ui->newpasswordlabel->setDisabled(1);
    ui->changebutton->setDisabled(1);
    ui->passcancelbutton->setDisabled(1);
}

void administrator::on_savebutton_clicked()
{
    qry.prepare( "UPDATE settings SET interval =:inter, header =:head, footer=:foot,device=:dev WHERE id = 1" );

    if( ui->radiobutton2secs->isChecked())
        qry.bindValue(":inter", 2);
    else if( ui->radiobutton3secs->isChecked())
        qry.bindValue(":inter", 3);
    else if( ui->radiobutton4secs->isChecked())
        qry.bindValue(":inter", 4);

    qry.bindValue(":head", ui->header->text());
    qry.bindValue(":foor", ui->footer->text());
    qry.bindValue(":dev",ui->devicecombobox->currentIndex());

    if( !qry.exec() )
         qDebug() << qry.lastError();
    else
     {
         qDebug( "Interval Updated" );
         QMessageBox::information(this, "Restart","Restart application to make changes in effect");
     }
}

void administrator::on_newpassokbutton_clicked()
{

    if(!ui->newusernameedit->text().isEmpty())
    {
        qry.prepare("INSERT INTO admin ( username ,password ) VALUES (:user,'password')");
        qry.bindValue(":user",ui->newusernameedit->text());
        if( !qry.exec() )
        {
               qDebug() << qry.lastError();
               QMessageBox::critical(this, "Failed","'"+ ui->newusernameedit->text() + "' already exists !!");
               qDebug("Insert admin fail");
        }
        else
        {
            qDebug() << "Insert to table admin pass";
            qry.prepare( "CREATE TABLE IF NOT EXISTS "+ ui->newusernameedit->text() +" ( batchid varchar(30) primary key, stat1 integer, para1 varchar(10), value1 varchar(10),"
                         " stat2 integer, para2 varchar(10), value2 varchar(10), stat3 integer, para3 varchar(10), value3 varchar(10), stat4 integer, para4 varchar(10), value4 varchar(10),"
                         " stat5 integer, para5 varchar(10), value5 varchar(10), stat6 integer, para6 varchar(10), value6 varchar(10), stat7 integer, para7 varchar(10), value7 varchar(10),"
                         " stat8 integer, para8 varchar(10), value8 varchar(10), stat9 integer, para9 varchar(10), value9 varchar(10), stat10 integer, para10 varchar(10), value10 varchar(10),"
                         " fillweight float(3,3),tareweight float(3,3), T1 integer, T2 integer,T3 integer, id integer )");
            if( !qry.exec() )
            {
                 qDebug() << qry.lastError();
                 QMessageBox::information(this, "Success","Table creation failed");
            }
            else
            {
                 qDebug() << "Table with name username created!";
                 QMessageBox::information(this, "Success","New Operator Created successfuly..\nUsername : "+ ui->newusernameedit->text() +"\nPassword : password");
                 ui->newusernameedit->clear();
            }

            /*

            */
        }
    }
    else
        QMessageBox::information(this, "Info","New Operator Username field empty");
}

void administrator::on_newpasscancelbutton_clicked()
{
    ui->newusernameedit->clear();
}

void administrator::on_opusercancelbutton_clicked()
{
    ui->operatorusername->clear();
    ui->newpassword->clear();
    ui->resetpasswordgroup->setDisabled(1);
    ui->deletegroup->setDisabled(1);
    ui->operatorusername->clear();
}

void administrator::on_resetbutton_clicked()
{
    qry.prepare( "UPDATE admin SET password =:pass WHERE username = :user" );
    qry.bindValue(":pass", ui->newpassword->text());
    qry.bindValue(":user", ui->operatorusername->text());
    if( !qry.exec() )
         qDebug() << qry.lastError();
    else
    {
         qDebug( "Updated!" );
         QMessageBox::information(this, "Successful", "Password changed successfuly");
         ui->newpassword->clear();
         ui->resetpasswordgroup->setDisabled(1);
    }
}

void administrator::on_deletebutton_clicked()
{
    qry.prepare( "DELETE FROM admin WHERE username = :user" );
    qry.bindValue(":user",ui->operatorusername->text());
    if( !qry.exec() )
    {
        qDebug() << qry.lastError();
        QMessageBox::critical(this, "Invalid User", " Invalid Username !!");
    }
    else
    {
        qDebug( "Deleted!" );
        /*###############################################################

        'delete from' command must be replaced with another best suitable
        because delete from is not fare.

        #################################################################*/

        if( !qry.exec("delete from "+ ui->operatorusername->text()) )
        {
            qDebug() << qry.lastError();
        }
        else
            QMessageBox::information(this, "Successful", "User '"+ui->operatorusername->text()+"' deleted successfuly");
    }

    /*
    qry.prepare( "DROP TABLE if exists "+ ui->operatorusername->text());
    if( !qry.exec()
    {
        qDebug() << qry.lastError();
    }
    else
        QMessageBox::information(this, "Successful", "User '"+ui->operatorusername->text()+"' deleted successfuly");

    qry.prepare( "DROP TABLE if exists "+ui->operatorusername->text());
    if( !qry.exec() )
    {
        qDebug() << qry.lastError();
    }
    else
        QMessageBox::information(this, "Successful", "User '"+ui->operatorusername->text()+"' deleted successfuly");
        */

}
