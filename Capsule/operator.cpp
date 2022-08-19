#include "operator.h"
#include "ui_operator.h"

#include <QtGui>

Operator::Operator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Operator)
{
    ui->setupUi(this);
    ui->operatorgroup->setDisabled(1);
    db = QSqlDatabase :: database("database");
    qry = QSqlQuery(db);
}

Operator::~Operator()
{
    delete ui;
}

void Operator::on_loginbutton_clicked()
{
    int uflag=0,pflag=0,itemflag=0;
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
            ui->loginbutton->setDisabled(1);
            ui->logoutbutton->setEnabled(1);
            ui->usernameedit->setDisabled(1);
            ui->passwordedit->setDisabled(1);
            ui->passwordchangegroup->setEnabled(1);
            ui->newpasslabel->setDisabled(1);
            ui->newpassedit->setDisabled(1);
            ui->changebutton->setDisabled(1);
            ui->operatorgroup->setEnabled(1);
            ui->batcheditgroup->setDisabled(1);
            ui->savebutton->setDisabled(1);
            ui->resetbutton->setDisabled(1);
            ui->currentoperatorlabel->setText(ui->usernameedit->text());
            //ui->usernameedit->clear();
            //ui->passwordedit->clear();
            ui->loggedintime->setText( QTime::currentTime().toString("h:mm:ss ap"));

            // Stopped here, Continue with listing batches in combobox
            qry.prepare( "SELECT batchid FROM "+ui->currentoperatorlabel->text()+" WHERE id = 1" );
            if( !qry.exec() )
                  qDebug() << qry.lastError();
            else
            {
                while (qry.next())
                {
                    itemflag = 1;
                    ui->batchcombobox->addItem(qry.value(0).toString());
                }
                if(itemflag == 0)
                    ui->batchcombobox->addItem("<Empty>");
            }
        }
    }

}

void Operator::on_logoutbutton_clicked()
{
    ui->batchcombobox->clear();
    ui->loginbutton->setEnabled(1);
    ui->logoutbutton->setDisabled(1);
    ui->usernameedit->clear();
    ui->passwordedit->clear();
    ui->passwordchangegroup->setDisabled(1);
    ui->operatorgroup->setDisabled(1);
    ui->currentoperatorlabel->clear();
    ui->usernameedit->setEnabled(1);
    ui->passwordedit->setEnabled(1);
    ui->loggedintime->clear();
}

void Operator::on_parabox1_clicked()
{
    if( ui->parabox1->isChecked())
    {
        ui->parametername1->setEnabled(1);
        ui->value1->setEnabled(1);
    }
    else
    {
        ui->parametername1->setDisabled(1);
        ui->value1->setDisabled(1);
    }
}

void Operator::on_parabox2_clicked()
{
    if( ui->parabox2->isChecked())
    {
        ui->parametername2->setEnabled(1);
        ui->value2->setEnabled(1);
    }
    else
    {
        ui->parametername2->setDisabled(1);
        ui->value2->setDisabled(1);
    }
}

void Operator::on_parabox3_clicked()
{
    if( ui->parabox3->isChecked())
    {
        ui->parametername3->setEnabled(1);
        ui->value3->setEnabled(1);
    }
    else
    {
        ui->parametername3->setDisabled(1);
        ui->value3->setDisabled(1);
    }
}

void Operator::on_parabox4_clicked()
{
    if( ui->parabox4->isChecked())
    {
        ui->parametername4->setEnabled(1);
        ui->value4->setEnabled(1);
    }
    else
    {
        ui->parametername4->setDisabled(1);
        ui->value4->setDisabled(1);
    }
}

void Operator::on_parabox5_clicked()
{
    if( ui->parabox5->isChecked())
    {
        ui->parametername5->setEnabled(1);
        ui->value5->setEnabled(1);
    }
    else
    {
        ui->parametername5->setDisabled(1);
        ui->value5->setDisabled(1);
    }
}

void Operator::on_parabox6_clicked()
{
    if( ui->parabox6->isChecked())
    {
        ui->parametername6->setEnabled(1);
        ui->value6->setEnabled(1);
    }
    else
    {
        ui->parametername6->setDisabled(1);
        ui->value6->setDisabled(1);
    }
}

void Operator::on_parabox7_clicked()
{
    if( ui->parabox7->isChecked())
    {
        ui->parametername7->setEnabled(1);
        ui->value7->setEnabled(1);
    }
    else
    {
        ui->parametername7->setDisabled(1);
        ui->value7->setDisabled(1);
    }
}

void Operator::on_parabox8_clicked()
{
    if( ui->parabox8->isChecked())
    {
        ui->parametername8->setEnabled(1);
        ui->value8->setEnabled(1);
    }
    else
    {
        ui->parametername8->setDisabled(1);
        ui->value8->setDisabled(1);
    }
}

void Operator::on_parabox9_clicked()
{
    if( ui->parabox9->isChecked())
    {
        ui->parametername9->setEnabled(1);
        ui->value9->setEnabled(1);
    }
    else
    {
        ui->parametername9->setDisabled(1);
        ui->value9->setDisabled(1);
    }
}

void Operator::on_parabox10_clicked()
{
    if( ui->parabox10->isChecked())
    {
        ui->parametername10->setEnabled(1);
        ui->value10->setEnabled(1);
    }
    else
    {
        ui->parametername10->setDisabled(1);
        ui->value10->setDisabled(1);
    }
}

void Operator::on_passcancelbutton_clicked()
{
    ui->oldpassedit->clear();
    ui->newpassedit->clear();
    ui->newpasslabel->setDisabled(1);
    ui->changebutton->setDisabled(1);
}

void Operator::on_passokbutton_clicked()
{
    int flag=0;
    QString word;
    qry.prepare( "SELECT password FROM admin WHERE username = :user" );
    qry.bindValue(":user", ui->currentoperatorlabel->text());
    if( !qry.exec() )
          qDebug() << qry.lastError();
    else
    {
        while (qry.next())
        {
            word = qry.value(0).toString();
            if( word == ui->oldpassedit->text())
                flag = 1;

        }
        if(flag == 1)
        {
            ui->newpasslabel->setEnabled(1);
            ui->newpassedit->setEnabled(1);
            ui->changebutton->setEnabled(1);
        }
        else
        {
            QMessageBox::critical(this, "Login Failed", " Wrong  Password!!");
            ui->oldpassedit->clear();
        }
    }
}

void Operator::on_changebutton_clicked()
{
    qry.prepare( "UPDATE admin SET password =:pass WHERE username = :user" );
    qry.bindValue(":pass", ui->newpassedit->text());
    qry.bindValue(":user", ui->currentoperatorlabel->text());
    if( !qry.exec() )
         qDebug() << qry.lastError();
    else
    {
         qDebug( "Updated!" );
         QMessageBox::information(this, "Successful", "Password changed successfuly");
         ui->oldpassedit->clear();
         ui->newpassedit->clear();
         ui->newpasslabel->setDisabled(1);
         ui->newpassedit->setDisabled(1);
         ui->changebutton->setDisabled(1);

    }
}

void Operator::on_batchaddbuton_clicked()
{
    /* For testoing float value
    double j;
    j=ui->batchaddedit->text().toFloat();
    ui->batchdeleteedit->setText(QString::number(j,'f',3));

 batchid varchar(30) primary key, stat1 integer, para1 varchar(10), value1 varchar(10),"
" stat2 integer, para2 varchar(10), value2 varchar(10), stat3 integer, para3 varchar(10), value3 varchar(10), stat4 integer, para4 varchar(10), value4 varchar(10),"
" stat5 integer, para5 varchar(10), value5 varchar(10), stat6 integer, para6 varchar(10), value6 varchar(10), stat7 integer, para7 varchar(10), value7 varchar(10),"
" stat8 integer, para8 varchar(10), value8 varchar(10), stat9 integer, para9 varchar(10), value9 varchar(10), stat10 integer, para10 varchar(10), value10 varchar(10),"
" fillweight float(3,3),tareweight float(3,3), T1 integer, T2 integer,T3 integer, id integer )");
    */

    qry.prepare( "INSERT INTO "+ ui->currentoperatorlabel->text() +" ( batchid,stat1,para1,value1,stat2,para2,value2,stat3,para3,value3,stat4,para4,value4,"
                 "stat5,para5,value5,stat6,para6,value6,stat7,para7,value7,stat8,para8,value8,stat9,para9,value9,stat10,para10,value10,fillweight,tareweight,"
                 "T1,T2,T3,id ) VALUES ( :batch,0,NULL,NULL,0,NULL,NULL,0,NULL,NULL,0,NULL,NULL,0,NULL,NULL,0,NULL,NULL,0,NULL,NULL,0,NULL,NULL,0,NULL,NULL,"
                 "0,NULL,NULL,0,0,0,0,0,1 )" );
    qry.bindValue(":batch", ui->batchaddedit->text());
    if( !qry.exec() )
    {
         qDebug() << qry.lastError();
         QMessageBox::critical(this, "Failed", "Batch ID already exists !!");
         qDebug("Insert into user table failed");
    }
    else
    {
         qDebug() << "Insert to settings pass";

         ui->batchcombobox->clear();
         qry.prepare( "SELECT batchid FROM "+ui->currentoperatorlabel->text()+" WHERE id = 1" );
         if( !qry.exec() )
               qDebug() << qry.lastError();
         else
         {
             while (qry.next())
             {
                 ui->batchcombobox->addItem(qry.value(0).toString());
             }
         }

         QMessageBox::information(this, "Success","' "+ ui->batchaddedit->text() +" '  batch added successfuly");
         ui->batchaddedit->clear();
    }
}

void Operator::on_batchaddedit_returnPressed()
{
    on_batchaddbuton_clicked();
}

void Operator::on_batchokbutton_clicked()
{
    //baudbox->currentText()
    index = ui->batchcombobox->currentIndex();
    qry.prepare( "SELECT * FROM "+ui->currentoperatorlabel->text()+" WHERE batchid = :batch" );
    qry.bindValue(":batch", ui->batchcombobox->currentText());
    if( !qry.exec() )
          qDebug() << qry.lastError();
    else
    {
        qry.first();

        if(qry.value(1).toInt() == 1 )
        {
            ui->parabox1->setChecked(1);
            ui->parametername1->setEnabled(1);
            ui->value1->setEnabled(1);
        }
        else
        {
            ui->parabox1->setChecked(0);
            ui->parametername1->setDisabled(1);
            ui->value1->setDisabled(1);
        }
        ui->parametername1->setText(qry.value(2).toString());
        ui->value1->setText(qry.value(3).toString());

        if(qry.value(4).toInt() == 1 )
        {
            ui->parabox2->setChecked(1);
            ui->parametername2->setEnabled(1);
            ui->value2->setEnabled(1);
        }
        else
        {
            ui->parabox2->setChecked(0);  // Stopped Here, continue with other parameters
            ui->parametername2->setDisabled(1);
            ui->value2->setDisabled(1);
        }
        ui->parametername2->setText(qry.value(5).toString());
        ui->value2->setText(qry.value(6).toString());

        if(qry.value(7).toInt() == 1 )
        {
            ui->parabox3->setChecked(1);
            ui->parametername3->setEnabled(1);
            ui->value3->setEnabled(1);
        }
        else
        {
            ui->parabox3->setChecked(0);  // Stopped Here, continue with other parameters
            ui->parametername3->setDisabled(1);
            ui->value3->setDisabled(1);
        }
        ui->parametername3->setText(qry.value(8).toString());
        ui->value3->setText(qry.value(9).toString());

        if(qry.value(10).toInt() == 1 )
        {
            ui->parabox4->setChecked(1);
            ui->parametername4->setEnabled(1);
            ui->value4->setEnabled(1);
        }
        else
        {
            ui->parabox4->setChecked(0);  // Stopped Here, continue with other parameters
            ui->parametername4->setDisabled(1);
            ui->value4->setDisabled(1);
        }
        ui->parametername4->setText(qry.value(11).toString());
        ui->value4->setText(qry.value(12).toString());

        if(qry.value(13).toInt() == 1 )
        {
            ui->parabox5->setChecked(1);
            ui->parametername5->setEnabled(1);
            ui->value5->setEnabled(1);
        }
        else
        {
            ui->parabox5->setChecked(0);  // Stopped Here, continue with other parameters
            ui->parametername5->setDisabled(1);
            ui->value5->setDisabled(1);
        }
        ui->parametername5->setText(qry.value(14).toString());
        ui->value5->setText(qry.value(15).toString());

        if(qry.value(16).toInt() == 1 )
        {
            ui->parabox6->setChecked(1);
            ui->parametername6->setEnabled(1);
            ui->value6->setEnabled(1);
        }
        else
        {
            ui->parabox6->setChecked(0);  // Stopped Here, continue with other parameters
            ui->parametername6->setDisabled(1);
            ui->value6->setDisabled(1);
        }
        ui->parametername6->setText(qry.value(17).toString());
        ui->value6->setText(qry.value(18).toString());

        if(qry.value(19).toInt() == 1 )
        {
            ui->parabox7->setChecked(1);
            ui->parametername7->setEnabled(1);
            ui->value7->setEnabled(1);
        }
        else
        {
            ui->parabox7->setChecked(0);  // Stopped Here, continue with other parameters
            ui->parametername7->setDisabled(1);
            ui->value7->setDisabled(1);
        }
        ui->parametername7->setText(qry.value(20).toString());
        ui->value7->setText(qry.value(21).toString());

        if(qry.value(22).toInt() == 1 )
        {
            ui->parabox8->setChecked(1);
            ui->parametername8->setEnabled(1);
            ui->value8->setEnabled(1);
        }
        else
        {
            ui->parabox8->setChecked(0);  // Stopped Here, continue with other parameters
            ui->parametername8->setDisabled(1);
            ui->value8->setDisabled(1);
        }
        ui->parametername8->setText(qry.value(23).toString());
        ui->value8->setText(qry.value(24).toString());

        if(qry.value(25).toInt() == 1 )
        {
            ui->parabox9->setChecked(1);
            ui->parametername9->setEnabled(1);
            ui->value9->setEnabled(1);
        }
        else
        {
            ui->parabox9->setChecked(0);  // Stopped Here, continue with other parameters
            ui->parametername9->setDisabled(1);
            ui->value9->setDisabled(1);
        }
        ui->parametername9->setText(qry.value(26).toString());
        ui->value9->setText(qry.value(27).toString());

        if(qry.value(28).toInt() == 1 )
        {
            ui->parabox10->setChecked(1);
            ui->parametername10->setEnabled(1);
            ui->value10->setEnabled(1);
        }
        else
        {
            ui->parabox10->setChecked(0);
            ui->parametername10->setDisabled(1);
            ui->value10->setDisabled(1);
        }
        ui->parametername10->setText(qry.value(29).toString());
        ui->value10->setText(qry.value(30).toString());

        ui->fillweight->setText(QString::number(qry.value(31).toFloat(),'f',3));
        ui->tareweight->setText(QString::number(qry.value(32).toFloat(),'f',3));

        ui->tolerance1->setText(QString::number(qry.value(33).toInt()));
        ui->tolerance2->setText(QString::number(qry.value(34).toInt()));
        ui->tolerance3->setText(QString::number(qry.value(35).toInt()));

        ui->batcheditgroup->setEnabled(1);
        ui->savebutton->setEnabled(1);
        ui->resetbutton->setEnabled(1);
    }
}

void Operator::on_deletebutton_clicked()
{
        qry.prepare( "DELETE FROM "+ ui->currentoperatorlabel->text() +" WHERE batchid = :batch" );
        qry.bindValue(":batch",ui->batchdeleteedit->text());
        if( !qry.exec() )
        {
            qDebug() << qry.lastError();
            QMessageBox::critical(this, "Invalid Batch", " Invalid Batch ID !!");
        }
        else
        {
            qDebug( "Deleted!" );

            ui->batchcombobox->clear();
            qry.prepare( "SELECT batchid FROM "+ui->currentoperatorlabel->text()+" WHERE id = 1" );
            if( !qry.exec() )
                  qDebug() << qry.lastError();
            else
            {
                while (qry.next())
                {
                    ui->batchcombobox->addItem(qry.value(0).toString());
                }
            }
            ui->batchdeleteedit->clear();
            QMessageBox::information(this, "Successful", "Batch ID '"+ui->batchdeleteedit->text()+"' deleted successfuly");
        }
}

void Operator::on_resetbutton_clicked()
{
    ui->batchcombobox->setCurrentIndex(index);
    qry.prepare( "SELECT * FROM "+ui->currentoperatorlabel->text()+" WHERE batchid = :batch" );
    qry.bindValue(":batch", ui->batchcombobox->currentText());
    if( !qry.exec() )
          qDebug() << qry.lastError();
    else
    {
        qry.first();

        if(qry.value(1).toInt() == 1 )
        {
            ui->parabox1->setChecked(1);
            ui->parametername1->setEnabled(1);
            ui->value1->setEnabled(1);
        }
        else
        {
            ui->parabox1->setChecked(0);
            ui->parametername1->setDisabled(1);
            ui->value1->setDisabled(1);
        }
        ui->parametername1->setText(qry.value(2).toString());
        ui->value1->setText(qry.value(3).toString());

        if(qry.value(4).toInt() == 1 )
        {
            ui->parabox2->setChecked(1);
            ui->parametername2->setEnabled(1);
            ui->value2->setEnabled(1);
        }
        else
        {
            ui->parabox2->setChecked(0);  // Stopped Here, continue with other parameters
            ui->parametername2->setDisabled(1);
            ui->value2->setDisabled(1);
        }
        ui->parametername2->setText(qry.value(5).toString());
        ui->value2->setText(qry.value(6).toString());

        if(qry.value(7).toInt() == 1 )
        {
            ui->parabox3->setChecked(1);
            ui->parametername3->setEnabled(1);
            ui->value3->setEnabled(1);
        }
        else
        {
            ui->parabox3->setChecked(0);  // Stopped Here, continue with other parameters
            ui->parametername3->setDisabled(1);
            ui->value3->setDisabled(1);
        }
        ui->parametername3->setText(qry.value(8).toString());
        ui->value3->setText(qry.value(9).toString());

        if(qry.value(10).toInt() == 1 )
        {
            ui->parabox4->setChecked(1);
            ui->parametername4->setEnabled(1);
            ui->value4->setEnabled(1);
        }
        else
        {
            ui->parabox4->setChecked(0);  // Stopped Here, continue with other parameters
            ui->parametername4->setDisabled(1);
            ui->value4->setDisabled(1);
        }
        ui->parametername4->setText(qry.value(11).toString());
        ui->value4->setText(qry.value(12).toString());

        if(qry.value(13).toInt() == 1 )
        {
            ui->parabox5->setChecked(1);
            ui->parametername5->setEnabled(1);
            ui->value5->setEnabled(1);
        }
        else
        {
            ui->parabox5->setChecked(0);  // Stopped Here, continue with other parameters
            ui->parametername5->setDisabled(1);
            ui->value5->setDisabled(1);
        }
        ui->parametername5->setText(qry.value(14).toString());
        ui->value5->setText(qry.value(15).toString());

        if(qry.value(16).toInt() == 1 )
        {
            ui->parabox6->setChecked(1);
            ui->parametername6->setEnabled(1);
            ui->value6->setEnabled(1);
        }
        else
        {
            ui->parabox6->setChecked(0);  // Stopped Here, continue with other parameters
            ui->parametername6->setDisabled(1);
            ui->value6->setDisabled(1);
        }
        ui->parametername6->setText(qry.value(17).toString());
        ui->value6->setText(qry.value(18).toString());

        if(qry.value(19).toInt() == 1 )
        {
            ui->parabox7->setChecked(1);
            ui->parametername7->setEnabled(1);
            ui->value7->setEnabled(1);
        }
        else
        {
            ui->parabox7->setChecked(0);  // Stopped Here, continue with other parameters
            ui->parametername7->setDisabled(1);
            ui->value7->setDisabled(1);
        }
        ui->parametername7->setText(qry.value(20).toString());
        ui->value7->setText(qry.value(21).toString());

        if(qry.value(22).toInt() == 1 )
        {
            ui->parabox8->setChecked(1);
            ui->parametername8->setEnabled(1);
            ui->value8->setEnabled(1);
        }
        else
        {
            ui->parabox8->setChecked(0);  // Stopped Here, continue with other parameters
            ui->parametername8->setDisabled(1);
            ui->value8->setDisabled(1);
        }
        ui->parametername8->setText(qry.value(23).toString());
        ui->value8->setText(qry.value(24).toString());

        if(qry.value(25).toInt() == 1 )
        {
            ui->parabox9->setChecked(1);
            ui->parametername9->setEnabled(1);
            ui->value9->setEnabled(1);
        }
        else
        {
            ui->parabox9->setChecked(0);  // Stopped Here, continue with other parameters
            ui->parametername9->setDisabled(1);
            ui->value9->setDisabled(1);
        }
        ui->parametername9->setText(qry.value(26).toString());
        ui->value9->setText(qry.value(27).toString());

        if(qry.value(28).toInt() == 1 )
        {
            ui->parabox10->setChecked(1);
            ui->parametername10->setEnabled(1);
            ui->value10->setEnabled(1);
        }
        else
        {
            ui->parabox10->setChecked(0);  // Stopped Here, continue with other parameters
            ui->parametername10->setDisabled(1);
            ui->value10->setDisabled(1);
        }
        ui->parametername10->setText(qry.value(29).toString());
        ui->value10->setText(qry.value(30).toString());

        ui->fillweight->setText(QString::number(qry.value(31).toFloat(),'f',3));
        ui->tareweight->setText(QString::number(qry.value(32).toFloat(),'f',3));

        ui->tolerance1->setText(QString::number(qry.value(33).toInt()));
        ui->tolerance2->setText(QString::number(qry.value(34).toInt()));
        ui->tolerance3->setText(QString::number(qry.value(35).toInt()));
    }
}

void Operator::on_savebutton_clicked()
{
    qry.prepare( "UPDATE "+ ui->currentoperatorlabel->text() +" SET stat1=:st1,para1=:pr1,value1=:vl1,stat2=:st2,para2=:pr2,value2=:vl2,"
                 "stat3=:st3,para3=:pr3,value3=:vl3,stat4=:st4,para4=:pr4,value4=:vl4,stat5=:st5,para5=:pr5,value5=:vl5,stat6=:st6,para6=:pr6,value6=:vl6,"
                 "stat7=:st7,para7=:pr7,value7=:vl7,stat8=:st8,para8=:pr8,value8=:vl8,stat9=:st9,para9=:pr9,value9=:vl9,stat10=:st10,para10=:pr10,value10=:vl10,"
                 "fillweight=:fill,tareweight=:tare,T1=:tol1,T2=:tol2,T3=:tol3 WHERE batchid = :batch" );
    if(ui->parabox1->isChecked())
        qry.bindValue(":st1",1);
    else
        qry.bindValue(":st1",0);
    qry.bindValue(":pr1",ui->parametername1->text());
    qry.bindValue(":vl1",ui->value1->text());

    if(ui->parabox2->isChecked())
        qry.bindValue(":st2",1);
    else
        qry.bindValue(":st2",0);
    qry.bindValue(":pr2",ui->parametername2->text());
    qry.bindValue(":vl2",ui->value2->text());

    if(ui->parabox3->isChecked())
        qry.bindValue(":st3",1);
    else
        qry.bindValue(":st3",0);
    qry.bindValue(":pr3",ui->parametername3->text());
    qry.bindValue(":vl3",ui->value3->text());

    if(ui->parabox4->isChecked())
        qry.bindValue(":st4",1);
    else
        qry.bindValue(":st4",0);
    qry.bindValue(":pr4",ui->parametername4->text());
    qry.bindValue(":vl4",ui->value4->text());

    if(ui->parabox5->isChecked())
        qry.bindValue(":st5",1);
    else
        qry.bindValue(":st5",0);
    qry.bindValue(":pr5",ui->parametername5->text());
    qry.bindValue(":vl5",ui->value5->text());

    if(ui->parabox6->isChecked())
        qry.bindValue(":st6",1);
    else
        qry.bindValue(":st6",0);
    qry.bindValue(":pr6",ui->parametername6->text());
    qry.bindValue(":vl6",ui->value6->text());

    if(ui->parabox7->isChecked())
        qry.bindValue(":st7",1);
    else
        qry.bindValue(":st7",0);
    qry.bindValue(":pr7",ui->parametername7->text());
    qry.bindValue(":vl7",ui->value7->text());

    if(ui->parabox8->isChecked())
        qry.bindValue(":st8",1);
    else
        qry.bindValue(":st8",0);
    qry.bindValue(":pr8",ui->parametername8->text());
    qry.bindValue(":vl8",ui->value8->text());

    if(ui->parabox9->isChecked())
        qry.bindValue(":st9",1);
    else
        qry.bindValue(":st9",0);
    qry.bindValue(":pr9",ui->parametername9->text());
    qry.bindValue(":vl9",ui->value9->text());

    if(ui->parabox10->isChecked())
        qry.bindValue(":st10",1);
    else
        qry.bindValue(":st10",0);
    qry.bindValue(":pr10",ui->parametername10->text());
    qry.bindValue(":vl10",ui->value10->text());

    qry.bindValue(":fill",ui->fillweight->text().toFloat());
    qry.bindValue(":tare",ui->tareweight->text().toFloat());

    qry.bindValue(":tol1",ui->tolerance1->text().toInt());
    qry.bindValue(":tol2",ui->tolerance2->text().toInt());
    qry.bindValue(":tol3",ui->tolerance3->text().toInt());

    qry.bindValue(":batch", ui->batchcombobox->currentText());
    if( !qry.exec() )
    {
         qDebug() << qry.lastError();
         qDebug("Batch Update failed");
    }
    else
    {
         qDebug() << "Batch Update success";
         QMessageBox::information(this, "Success","' "+ ui->batchcombobox->currentText() +" '  updated successfuly");

    }
}

void Operator::on_cancelbutton_clicked()
{
    qry.finish();
    QDialog::reject();
}
