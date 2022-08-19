#include "dviewticket.h"
#include "ui_dviewticket.h"
#include "qprinter.h"
#include "qpainter.h"

#include <QPrintDialog>
#include <QDesktopServices>

DViewTicket::DViewTicket(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DViewTicket)
{
    ui->setupUi(this);

    total = 0;

    db = QSqlDatabase :: database("detailsdb");
    qry = QSqlQuery(db);
    db_settings = QSqlDatabase :: database("settingsdb");
    qry_settings = QSqlQuery(db_settings);

    PortSettings portsettings = {BAUD9600, DATA_8, PAR_NONE, STOP_1, FLOW_OFF, 10};
    printer_port = new QextSerialPort("COM7", portsettings, QextSerialPort::Polling);

    qry_settings.prepare( "SELECT pr_port,status FROM settings WHERE id = 1" );
       if( !qry_settings.exec() )
       {
           qDebug()<<"Printer port settings : ";
           qDebug()<< qry_settings.lastError();
       }
       else
       {
                qDebug()<<"Printer port settings database opened";
                 qry_settings.first();

                 printer_port->setPortName(qry_settings.value(0).toString());
       }

    if (!printer_port->isOpen())
    {
         printer_port->open(QIODevice::ReadWrite);
         qDebug()<<"Printer port opened ";
    }
    ui->printbutton->setDisabled(1);

}

DViewTicket::~DViewTicket()
{
    printer_port->close();
    qDebug()<<"Printer port closed";
    delete ui;
}

void DViewTicket::on_closebutton_clicked()
{
    //close
    QDialog::reject();
}

void DViewTicket::on_gobutton_clicked()
{
    int temp_flag=0,temp_status=2;

    qry_settings.prepare("SELECT status FROM settings WHERE id=1");
    if( !qry_settings.exec() )
    {
      qDebug() << qry_settings.lastError();
      qDebug()<<"Status";
    }
    else
    {
        qry_settings.first();
        temp_status= qry_settings.value(0).toInt();
    }
    qry.prepare("SELECT * FROM details WHERE bill = :bill");
    qry.bindValue(":bill",ui->receipt_edit->text().toInt());
    if( !qry.exec() )
    {
      qDebug() << qry.lastError();
      qDebug()<<"Error at print ticket";

    }
    else
    {
        qDebug( "Executed" );
        ui->display_edit->clear();

        if (qry.first())
        {
           temp_flag=1;

           if(temp_status== 1)
                ui->printbutton->setEnabled(1);

            ui->display_edit->setEnabled(1);
            //ui->display_edit->setAlignment(Qt::AlignCenter);
            ui->display_edit->append("<h1><center>THOMSON<center></h1>\n");
            ui->display_edit->insertPlainText("Bill No\t: "+qry.value(0).toString()+"\t\t\t"+"Vehicle No\t: "+qry.value(1).toString()+"\n");
            ui->display_edit->insertPlainText("Customer\t: "+qry.value(3).toString()+"\t\t\t"+"Material\t: "+qry.value(4).toString()+"\n");
            ui->display_edit->insertPlainText("---------------------------------------------------------------------------------------------------------------------------\n\n");
            ui->display_edit->insertPlainText("Challan No\t: "+qry.value(2).toString()+"\n");
            ui->display_edit->insertPlainText("Charge 1\t: "+qry.value(5).toString()+"\nCharge 2\t: "+qry.value(13).toString()+"\n\n");
            ui->display_edit->insertPlainText("Date1\t: "+qry.value(7).toString()+"\t\t\t"+"Date2\t: "+qry.value(10).toString()+"\n");
            ui->display_edit->insertPlainText("Time1\t: "+qry.value(8).toString()+"\t\t\t"+"Time2\t: "+qry.value(11).toString()+"\n\n");
            ui->display_edit->insertPlainText("Tare Wght\t: "+qry.value(6).toString()+"\n");
            ui->display_edit->insertPlainText("Gross Wght\t: "+qry.value(9).toString()+"\n");
            ui->display_edit->insertPlainText("Net Wght\t: "+qry.value(12).toString()+"\n\n\n");
            total = qry.value(13).toInt()+qry.value(5).toInt();
            ui->display_edit->insertPlainText("Total Chrg\t: "+QString::number(total)+"\n");
        }

     }
    if(temp_flag==0)
    {
        ui->display_edit->setText("\n\n\t\t                 No Entry Found !!");
        ui->printbutton->setDisabled(1);
    }
}

void DViewTicket::on_clearbutton_clicked()
{
    ui->receipt_edit->clear();
    ui->display_edit->clear();
}

void DViewTicket::on_printbutton_clicked()
{
    const char new_line = 0x0A;
    const char tab = 0x09;
    char print_str[100];
    int i = 0;
    QString q_str;

    QPrinter printer;
     QTextDocument *document = ui->display_edit->document();


        printer.setOutputFormat( QPrinter::PdfFormat );
        printer.setOutputFileName( "./Receipt/Receipt_No_"+ui->receipt_edit->text()+".pdf" );

            document->print(&printer);

    QDesktopServices::openUrl(QUrl("file:///./Receipt/Receipt_No_"+ui->receipt_edit->text()+".pdf", QUrl::TolerantMode));

    /*
    ui->display_edit->append("<h1><center>THOMSON<center></h1>\n");
    ui->display_edit->insertPlainText("Bill No\t: "+qry.value(0).toString()+"\t\t\t"+"Vehicle No\t: "+qry.value(1).toString()+"\n");
    ui->display_edit->insertPlainText("Customer\t: "+qry.value(3).toString()+"\t\t\t"+"Material\t: "+qry.value(4).toString()+"\n");
    ui->display_edit->insertPlainText("---------------------------------------------------------------------------------------------------------------------------\n\n");
    ui->display_edit->insertPlainText("Challan No\t: "+qry.value(2).toString()+"\n");
    ui->display_edit->insertPlainText("Charge 1\t: "+qry.value(5).toString()+"\nCharge 2\t: "+qry.value(13).toString()+"\n\n");
    ui->display_edit->insertPlainText("Date1\t: "+qry.value(7).toString()+"\t\t\t"+"Date2\t: "+qry.value(10).toString()+"\n");
    ui->display_edit->insertPlainText("Time1\t: "+qry.value(8).toString()+"\t\t\t"+"Time2\t: "+qry.value(11).toString()+"\n\n");
    ui->display_edit->insertPlainText("Tare Wght\t: "+qry.value(6).toString()+"\n");
    ui->display_edit->insertPlainText("Gross Wght\t: "+qry.value(9).toString()+"\n");
    ui->display_edit->insertPlainText("Net Wght\t: "+qry.value(12).toString()+"\n\n\n");
    total = qry.value(13).toInt()+qry.value(5).toInt();
    ui->display_edit->insertPlainText("Total Chrg\t: "+QString::number(total)+"\n");
    */

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

    q_str = "Bill No  : "+qry.value(0).toString();
    for(i=0;i<q_str.length();i++)
        print_str[i]=q_str[i].toAscii();
    printer_port->write(print_str,q_str.length());
    printer_port->write(&tab,1);
    printer_port->write(&tab,1);

    q_str = "Veh No : "+qry.value(1).toString();
    for(i=0;i<q_str.length();i++)
        print_str[i]=q_str[i].toAscii();
    printer_port->write(print_str,q_str.length());
    printer_port->write(&new_line,1);

    q_str = "Customer : "+qry.value(3).toString();
    for(i=0;i<q_str.length();i++)
        print_str[i]=q_str[i].toAscii();
    printer_port->write(print_str,q_str.length());
    printer_port->write(&tab,1);
    printer_port->write(&tab,1);

    q_str = "Matrl  : "+qry.value(4).toString();
    for(i=0;i<q_str.length();i++)
        print_str[i]=q_str[i].toAscii();
    printer_port->write(print_str,q_str.length());
    printer_port->write(&new_line,1);

    q_str = "-----------------------------------------";
    for(i=0;i<q_str.length();i++)
        print_str[i]=q_str[i].toAscii();
    printer_port->write(print_str,q_str.length());
    printer_port->write(&new_line,1);

    q_str = "Challan  : "+qry.value(2).toString();
    for(i=0;i<q_str.length();i++)
        print_str[i]=q_str[i].toAscii();
    printer_port->write(print_str,q_str.length());
    printer_port->write(&new_line,1);

    q_str = "Charge 1 : "+qry.value(5).toString();
    for(i=0;i<q_str.length();i++)
        print_str[i]=q_str[i].toAscii();
    printer_port->write(print_str,q_str.length());
    printer_port->write(&new_line,1);

    q_str = "Charge 2 : "+qry.value(13).toString();
    for(i=0;i<q_str.length();i++)
        print_str[i]=q_str[i].toAscii();
    printer_port->write(print_str,q_str.length());
    printer_port->write(&new_line,1);
    printer_port->write(&new_line,1);

    q_str = "Date 1 : "+qry.value(7).toString();
    for(i=0;i<q_str.length();i++)
        print_str[i]=q_str[i].toAscii();
    printer_port->write(print_str,q_str.length());
    printer_port->write(&tab,1);

    q_str = "Time 1 : "+qry.value(8).toString();
    for(i=0;i<q_str.length();i++)
        print_str[i]=q_str[i].toAscii();
    printer_port->write(print_str,q_str.length());
    printer_port->write(&new_line,1);

    q_str = "Date 2 : "+qry.value(10).toString();
    for(i=0;i<q_str.length();i++)
        print_str[i]=q_str[i].toAscii();
    printer_port->write(print_str,q_str.length());
    printer_port->write(&tab,1);

    q_str = "Time 2 : "+qry.value(11).toString();
    for(i=0;i<q_str.length();i++)
        print_str[i]=q_str[i].toAscii();
    printer_port->write(print_str,q_str.length());
    printer_port->write(&new_line,1);
    printer_port->write(&new_line,1);

    q_str = "Tare Weight  : "+qry.value(6).toString()+" Kg";
    for(i=0;i<q_str.length();i++)
        print_str[i]=q_str[i].toAscii();
    printer_port->write(print_str,q_str.length());
    printer_port->write(&new_line,1);

    q_str = "Gross Weight : "+qry.value(9).toString()+" Kg";
    for(i=0;i<q_str.length();i++)
        print_str[i]=q_str[i].toAscii();
    printer_port->write(print_str,q_str.length());
    printer_port->write(&new_line,1);

    q_str = "Net Weight   : "+qry.value(12).toString()+" Kg";
    for(i=0;i<q_str.length();i++)
        print_str[i]=q_str[i].toAscii();
    printer_port->write(print_str,q_str.length());
    printer_port->write(&new_line,1);
    printer_port->write(&new_line,1);

    q_str = "-----------------------------------------";
    for(i=0;i<q_str.length();i++)
        print_str[i]=q_str[i].toAscii();
    printer_port->write(print_str,q_str.length());
    printer_port->write(&new_line,1);

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

}

