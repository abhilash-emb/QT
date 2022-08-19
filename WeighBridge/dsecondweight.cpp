#include "dsecondweight.h"
#include "ui_dsecondweight.h"

#include <QtCore>
#include <QtGui>

DSecondWeight::DSecondWeight(QWidget *parent, QString lastweight, int option) :
    QDialog(parent),
    ui(new Ui::DSecondWeight)
{
    ui->setupUi(this);

    first_print = 0;

    total = 0;

    PortSettings portsettings = {BAUD9600, DATA_8, PAR_NONE, STOP_1, FLOW_OFF, 10};
    printer_port = new QextSerialPort("COM7", portsettings, QextSerialPort::Polling);

    db = QSqlDatabase :: database("detailsdb");
    qry=QSqlQuery(db);
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
        ui->modelabel->setText("Manual");
    else
    {
        ui->modelabel->setText("Auto");
        ui->grossweight_edit->setText(lastweight);
    }

    ui->acceptbutton->setDisabled(1);
    ui->saveprintbutton->setDisabled(1);

    if (!printer_port->isOpen())
    {
         printer_port->open(QIODevice::ReadWrite);
         qDebug()<<"Printer port opened ";
    }

}

DSecondWeight::~DSecondWeight()
{
    printer_port->close();
    qDebug()<<"Printer port closed";
    delete ui;
}

void DSecondWeight::on_closebutton_clicked()
{
    QDialog::reject();
}

void DSecondWeight::on_clearbutton_clicked()
{
    ui->date1_edit->clear();
    ui->date2_edit->clear();
    ui->time1_edit->clear();
    ui->time2_edit->clear();
    ui->grossweight_edit->clear();
    ui->tareweight_edit->clear();
    ui->totalcharge_edit->clear();
    ui->netweight_edit->clear();
    ui->reciept_edit->clear();
    ui->status_label->clear();
    ui->acceptbutton->setDisabled(1);
    ui->saveprintbutton->setDisabled(1);
}

void DSecondWeight::on_gobutton_clicked()
{
    int temp_flag=0;
    qry.prepare("SELECT weight1, date1, time1, netweight ,charge,vehicle,customer,material,challan,total FROM details WHERE bill = :bill");
    qry.bindValue(":bill",ui->reciept_edit->text().toInt());
    if( !qry.exec() )
    {
      qDebug() << qry.lastError();
    }
    else
    {
        ui->date1_edit->clear();
        ui->date2_edit->clear();
        ui->time1_edit->clear();
        ui->time2_edit->clear();
        ui->tareweight_edit->clear();
        ui->totalcharge_edit->clear();
        ui->netweight_edit->clear();
        ui->status_label->clear();
        qDebug( "Executed" );

        while(qry.next())
        {
            temp_flag=1;
            ui->tareweight_edit->setText(qry.value(0).toString());
            ui->date1_edit->setText(qry.value(1).toString());
            ui->time1_edit->setText(qry.value(2).toString());
            ui->date2_edit->setText(QDate::currentDate().toString("d/M/yyyy"));
            ui->time2_edit->setText(QTime::currentTime().toString("h:mm ap"));
            ui->netweight_edit->setText(qry.value(3).toString());
            ui->totalcharge_edit->setText(qry.value(9).toString());
            total = qry.value(4).toInt();
            vehicle = qry.value(5).toString();
            customer = qry.value(6).toString();
            material = qry.value(7).toString();
            challan  = qry.value(8).toString();
        }

     }
    if(temp_flag==0)
    {
        ui->status_label->setText("No Entry Found !!");
        QMessageBox::information(this, "No entry", "No entry found....");
        ui->acceptbutton->setDisabled(1);
    }
    else
        ui->acceptbutton->setEnabled(1);
}

void DSecondWeight::on_acceptbutton_clicked()
{
    int tare,gross,net;

    if(!ui->grossweight_edit->text().isEmpty())
    {

        tare=ui->tareweight_edit->text().toInt();
        gross=ui->grossweight_edit->text().toInt();
        net=gross-tare;

        ui->netweight_edit->setText(QString::number(net));
        ui->saveprintbutton->setEnabled(1);
        ui->acceptbutton->setDisabled(1);
        ui->status_label->clear();
    }
    else
        ui->status_label->setText("Gross Field Empty");
}

void DSecondWeight::on_saveprintbutton_clicked()
{
    const char new_line = 0x0A;
    const char tab = 0x09;
    char print_str[100];
    int i = 0;
    QString q_str;

    if(!ui->totalcharge_edit->text().isEmpty())
    {

        if(first_print == 0)
        {
            qry.prepare("UPDATE details SET weight2 = :weight2, date2 = :date2, time2 =:time2, netweight =:netweight, total =:total WHERE bill = :bill");
            qry.bindValue(":bill",ui->reciept_edit->text().toInt());
            qry.bindValue(":weight2",ui->grossweight_edit->text().toInt());
            qry.bindValue(":date2",ui->date2_edit->text());
            qry.bindValue(":time2",ui->time2_edit->text());
            qry.bindValue(":netweight",ui->netweight_edit->text().toInt());
            qry.bindValue(":total",ui->totalcharge_edit->text().toInt());
            if( !qry.exec() )
            {
                qDebug() << qry.lastError();
                ui->status_label->setText("No Entry Found !!");
                QMessageBox::information(this, "Failed", "Save Failed....");
            }
            else
            {
                qDebug() << "Entry Saved Completly";
                ui->saveprintbutton->setText("Print");
                ui->status_label->setText("Save Successful");
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

            q_str = "Bill No  : "+ui->reciept_edit->text();
            for(i=0;i<q_str.length();i++)
                print_str[i]=q_str[i].toAscii();
            printer_port->write(print_str,q_str.length());
            printer_port->write(&tab,1);
            printer_port->write(&tab,1);

            q_str = "Veh No : "+vehicle;
            for(i=0;i<q_str.length();i++)
                print_str[i]=q_str[i].toAscii();
            printer_port->write(print_str,q_str.length());
            printer_port->write(&new_line,1);

            q_str = "Customer : "+customer;
            for(i=0;i<q_str.length();i++)
                print_str[i]=q_str[i].toAscii();
            printer_port->write(print_str,q_str.length());
            printer_port->write(&tab,1);
            printer_port->write(&tab,1);

            q_str = "Matrl  : "+material;
            for(i=0;i<q_str.length();i++)
                print_str[i]=q_str[i].toAscii();
            printer_port->write(print_str,q_str.length());
            printer_port->write(&new_line,1);

            q_str = "-----------------------------------------";
            for(i=0;i<q_str.length();i++)
                print_str[i]=q_str[i].toAscii();
            printer_port->write(print_str,q_str.length());
            printer_port->write(&new_line,1);

            q_str = "Challan  : "+challan;
            for(i=0;i<q_str.length();i++)
                print_str[i]=q_str[i].toAscii();
            printer_port->write(print_str,q_str.length());
            printer_port->write(&new_line,1);

            q_str = "Charge 1 : "+QString::number(total);
            for(i=0;i<q_str.length();i++)
                print_str[i]=q_str[i].toAscii();
            printer_port->write(print_str,q_str.length());
            printer_port->write(&new_line,1);

            q_str = "Charge 2 : "+ui->totalcharge_edit->text();
            for(i=0;i<q_str.length();i++)
                print_str[i]=q_str[i].toAscii();
            printer_port->write(print_str,q_str.length());
            printer_port->write(&new_line,1);
            printer_port->write(&new_line,1);

            q_str = "Date 1 : "+ui->date1_edit->text();
            for(i=0;i<q_str.length();i++)
                print_str[i]=q_str[i].toAscii();
            printer_port->write(print_str,q_str.length());
            printer_port->write(&tab,1);

            q_str = "Time 1 : "+ui->time1_edit->text();
            for(i=0;i<q_str.length();i++)
                print_str[i]=q_str[i].toAscii();
            printer_port->write(print_str,q_str.length());
            printer_port->write(&new_line,1);

            q_str = "Date 2 : "+ui->date2_edit->text();
            for(i=0;i<q_str.length();i++)
                print_str[i]=q_str[i].toAscii();
            printer_port->write(print_str,q_str.length());
            printer_port->write(&tab,1);

            q_str = "Time 2 : "+ui->time2_edit->text();
            for(i=0;i<q_str.length();i++)
                print_str[i]=q_str[i].toAscii();
            printer_port->write(print_str,q_str.length());
            printer_port->write(&new_line,1);
            printer_port->write(&new_line,1);

            q_str = "Tare Weight  : "+ui->tareweight_edit->text()+" Kg";
            for(i=0;i<q_str.length();i++)
                print_str[i]=q_str[i].toAscii();
            printer_port->write(print_str,q_str.length());
            printer_port->write(&new_line,1);

            q_str = "Gross Weight : "+ui->grossweight_edit->text()+" Kg";
            for(i=0;i<q_str.length();i++)
                print_str[i]=q_str[i].toAscii();
            printer_port->write(print_str,q_str.length());
            printer_port->write(&new_line,1);

            q_str = "Net Weight   : "+ui->netweight_edit->text()+" Kg";
            for(i=0;i<q_str.length();i++)
                print_str[i]=q_str[i].toAscii();
            printer_port->write(print_str,q_str.length());
            printer_port->write(&new_line,1);

            q_str = "-----------------------------------------";
            for(i=0;i<q_str.length();i++)
                print_str[i]=q_str[i].toAscii();
            printer_port->write(print_str,q_str.length());
            printer_port->write(&new_line,1);

            total = total+ ui->totalcharge_edit->text().toInt();

            q_str = "TOTAL        : "+QString::number(total)+" Rs";
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
            ui->status_label->setText("Total Charge Empty");
}
