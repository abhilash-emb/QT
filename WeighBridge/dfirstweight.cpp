#include "dfirstweight.h"
#include "ui_dfirstweight.h"

#include <QtSql>
#include <QtGui>

DFirstWeight::DFirstWeight(QWidget *parent, QString lastweight,int option) :
    QDialog(parent),
    ui(new Ui::DFirstWeight)
{
    ui->setupUi(this);

    first_print = 0;

    PortSettings portsettings = {BAUD9600, DATA_8, PAR_NONE, STOP_1, FLOW_OFF, 10};
    printer_port = new QextSerialPort("COM7", portsettings, QextSerialPort::Polling);

    db = QSqlDatabase :: database("detailsdb");
    qry = QSqlQuery(db);
    db1 = QSqlDatabase :: database("settingsdb");
    qry1 = QSqlQuery(db1);

    qry1.prepare( "SELECT pr_port FROM settings WHERE id = 1" );
       if( !qry1.exec() )
       {
           qDebug()<<"Printer port settings : ";
           qDebug()<< qry1.lastError();
       }
       else
       {
                qDebug()<<"Printer port settings database opened";
                 qry1.first();

                 printer_port->setPortName(qry1.value(0).toString());
       }

    if(option == 0)
    {
        ui->modelabel->setText("Manual");
    }
    else
    {
        ui->modelabel->setText("Auto");
        ui->weightlineedit->setText(lastweight);
    }

    ui->saveprintbutton->setDisabled(1);
    ui->acceptbutton->setEnabled(1);

    if (!printer_port->isOpen())
    {
         printer_port->open(QIODevice::ReadWrite);
         qDebug()<<"Printer port opened ";
    }
}

DFirstWeight::~DFirstWeight()
{
    printer_port->close();
    qDebug()<<"Printer port closed";
    delete ui;
}

void DFirstWeight::on_acceptbutton_clicked()
{
    //accept
    int status = 0;
    if(!ui->vehiclelineedit->text().isEmpty())
    {
        qry1.prepare( "SELECT lastbill,maxlimit,upstatus FROM settings WHERE id = 1" );
         if( !qry1.exec() )
           qDebug() << qry1.lastError();
         else
         {
                 qry1.first();

                 if(qry1.value(0).toInt() > (qry1.value(1).toInt()+100))
                 {
                     ui->billnolineedit->setText("100");
                     if(qry1.value(2).toInt() == 0)
                     {
                         status=1;
                         qry1.prepare( "UPDATE settings SET upstatus=1 WHERE id = 1" );
                         if( !qry1.exec() )
                         {
                             qDebug( "Update save fail" );
                             qDebug() << qry1.lastError();
                         }
                         else
                         {
                             qDebug( "Update save Success" );
                         }
                     }

                 }
                 else
                 {
                    ui->billnolineedit->setText(qry1.value(0).toString());
                    status=qry1.value(2).toInt();
                 }


                if(status == 0)   // Bill number is not used yet
                {
                    qry.prepare("INSERT INTO details (bill,vehicle, customer, material)"
                                        "VALUES (:bill,:vehicle, :customer, :material)");
                    qry.bindValue(":bill",ui->billnolineedit->text().toInt());
                    qry.bindValue(":vehicle", ui->vehiclelineedit->text().toUpper());
                    qry.bindValue(":customer", ui->customerlineedit->text().toUpper());
                    qry.bindValue(":material", ui->materiallineedit->text().toUpper());

                    if( !qry.exec() )
                    {
                      qDebug( "Insert by status Fail" );
                      qDebug() << qry.lastError();
                    }
                    else
                        qDebug( "Insert by status success" );

                }
                else            // Bill number is not used atleast once
                {
                    qry.prepare( "UPDATE details SET vehicle=:vehicle, customer=:customer, material=:material WHERE bill=:bill" );
                    qry.bindValue(":bill",ui->billnolineedit->text().toInt());
                    qry.bindValue(":vehicle", ui->vehiclelineedit->text().toUpper());
                    qry.bindValue(":customer", ui->customerlineedit->text().toUpper());
                    qry.bindValue(":material", ui->materiallineedit->text().toUpper());

                    if( !qry.exec() )
                    {
                        qDebug( "update by status Fail");
                        qDebug() << qry.lastError();
                    }
                    else
                        qDebug( "update by status success");
                }


                ui->acceptbutton->setDisabled(1);
                ui->saveprintbutton->setEnabled(1);
                ui->statuslabel->clear();

                qry1.prepare( "UPDATE settings SET lastbill=:last WHERE id = 1" );
                qry1.bindValue(":last",ui->billnolineedit->text().toInt()+1);
                if( !qry1.exec() )
                   qDebug() << qry1.lastError();
                 else
                 {
                    qDebug( "First Weight Bill Saved" );
                    ui->statuslabel->setText("Bill Saved");
                 }

           }// end of query else
    }//end of 'if' for field empty check
    else
        ui->statuslabel->setText("Fields Empty");
}

void DFirstWeight::on_saveprintbutton_clicked()
{
    const char new_line = 0x0A;
    const char tab = 0x09;
    char print_str[100];
    int i = 0;
    QString q_str;

    //save/print
    if(!ui->weightlineedit->text().isEmpty())
    {
        if(first_print == 0)
        {
            qry.prepare( "UPDATE details SET challan = :challan, charge = :charge, weight1=:weight1,date1=:date1,time1=:time1 WHERE bill = :bill" );
            qry.bindValue(":bill",ui->billnolineedit->text().toInt());
            qry.bindValue(":challan",ui->challanlineedit->text().toUpper());
            qry.bindValue(":charge",ui->chargelineedit->text().toInt());
            qry.bindValue(":weight1",ui->weightlineedit->text().toInt());
            qry.bindValue(":date1",QDate::currentDate().toString("d/M/yyyy"));
            qry.bindValue(":time1",QTime::currentTime().toString("h:mm ap"));
            if( !qry.exec() )
            {
                qDebug() << qry.lastError();
                qDebug( "First Weight Complete data save failed" );
                ui->statuslabel->setText("Not saved..");
                QMessageBox::warning(this, "Failed", "Save failed....");
            }
            else
            {
                qDebug( "First Weight Complete data saved" );
                ui->statuslabel->setText("Saved..");
                ui->saveprintbutton->setText("Print");
                first_print = 1;
            }
        }
        if((first_print == 1)||(first_print == 2))
        {

            q_str = "THOMSON";
            for(i=0;i<q_str.length();i++)
                print_str[i]=q_str[i].toAscii();
            printer_port->write(print_str,q_str.length());
            printer_port->write(&new_line,1);

            q_str = "-----------------------------------------";
            for(i=0;i<q_str.length();i++)
                print_str[i]=q_str[i].toAscii();
            printer_port->write(print_str,q_str.length());
            printer_port->write(&new_line,1);

            q_str = "Bill No  : "+ui->billnolineedit->text();
            for(i=0;i<q_str.length();i++)
                print_str[i]=q_str[i].toAscii();
            printer_port->write(print_str,q_str.length());
            printer_port->write(&tab,1);
            printer_port->write(&tab,1);

            q_str = "Veh No : "+ui->vehiclelineedit->text().toUpper();
            for(i=0;i<q_str.length();i++)
                print_str[i]=q_str[i].toAscii();
            printer_port->write(print_str,q_str.length());
            printer_port->write(&new_line,1);

            q_str = "Customer : "+ui->customerlineedit->text().toUpper();
            for(i=0;i<q_str.length();i++)
                print_str[i]=q_str[i].toAscii();
            printer_port->write(print_str,q_str.length());
            printer_port->write(&tab,1);
            printer_port->write(&tab,1);

            q_str = "Matrl  : "+ ui->materiallineedit->text().toUpper();
            for(i=0;i<q_str.length();i++)
                print_str[i]=q_str[i].toAscii();
            printer_port->write(print_str,q_str.length());
            printer_port->write(&new_line,1);

            q_str = "-----------------------------------------";
            for(i=0;i<q_str.length();i++)
                print_str[i]=q_str[i].toAscii();
            printer_port->write(print_str,q_str.length());
            printer_port->write(&new_line,1);

            q_str = "Challan  : "+ ui->challanlineedit->text().toUpper();
            for(i=0;i<q_str.length();i++)
                print_str[i]=q_str[i].toAscii();
            printer_port->write(print_str,q_str.length());
            printer_port->write(&new_line,1);

            q_str = "Charge   : "+ ui->chargelineedit->text();
            for(i=0;i<q_str.length();i++)
                print_str[i]=q_str[i].toAscii();
            printer_port->write(print_str,q_str.length());
            printer_port->write(&new_line,1);

            q_str = "Date   : "+QDate::currentDate().toString("d/M/yyyy")+"   "+QTime::currentTime().toString("h:mm ap");
            for(i=0;i<q_str.length();i++)
                print_str[i]=q_str[i].toAscii();
            printer_port->write(print_str,q_str.length());
            printer_port->write(&new_line,1);

            q_str = "Weight  : "+ui->weightlineedit->text()+" Kg";
            for(i=0;i<q_str.length();i++)
                print_str[i]=q_str[i].toAscii();
            printer_port->write(print_str,q_str.length());
            printer_port->write(&new_line,1);

            q_str = "-----------------------------------------";
            for(i=0;i<q_str.length();i++)
                print_str[i]=q_str[i].toAscii();
            printer_port->write(print_str,q_str.length());
            printer_port->write(&new_line,1);
            printer_port->write(&new_line,1);
            printer_port->write(&new_line,1);
            printer_port->write(&new_line,1);

            if(first_print == 2)
                QMessageBox::information(this, "Printing", ".....Printing Ticket....");
            else
            {
                first_print = 2;
                QMessageBox::information(this, "Saved", ".....Save successful, Printing Ticket....");
            }

        }

    }
    else
        ui->statuslabel->setText("Fields Empty");

}

void DFirstWeight::on_clearallbutton_clicked()
{
    ui->vehiclelineedit->clear();
    ui->customerlineedit->clear();
    ui->materiallineedit->clear();
    ui->billnolineedit->clear();
    ui->challanlineedit->clear();
    ui->weightlineedit->clear();
    ui->chargelineedit->clear();
    ui->statuslabel->clear();
    ui->saveprintbutton->setDisabled(1);
    ui->acceptbutton->setEnabled(1);
}

void DFirstWeight::on_closebutton_clicked()
{
    //close
    QDialog::reject();
}
