#include "dreports.h"
#include "ui_dreports.h"
#include "searchreciept.h"
#include "searchcustomer.h"
#include "searchdate.h"
#include "searchmaterial.h"
#include "searchvehicle.h"
#include "Header.h"

#include <QtDebug>
#include <QtGui>

DReports::DReports(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DReports)
{
    ui->setupUi(this);

    total = 0;

    PortSettings portsettings = {BAUD9600, DATA_8, PAR_NONE, STOP_1, FLOW_OFF, 10};
    printer_port = new QextSerialPort("COM7", portsettings, QextSerialPort::Polling);

    db = QSqlDatabase :: database("detailsdb");
    qry=QSqlQuery(db);
    db_settings= QSqlDatabase :: database("settingsdb");
    qry_settings = QSqlQuery(db_settings);

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

    ui->date_edit->setVisible(0);
    ui->month_edit->setVisible(0);
    ui->year_edit->setVisible(0);
    ui->seperator_label1->setVisible(0);
    ui->seperator_label2->setVisible(0);
    ui->printbutton->setEnabled(1);
    ui->nextbutton->setDisabled(1);
    ui->previousbutton->setDisabled(1);
    ui->search_edit->setFocus();
}

DReports::~DReports()
{
    printer_port->close();
    qDebug()<<"Printer port closed";
    delete ui;
}

void DReports::on_searchbutton_clicked()
{
    int query_status = EMPTY;//,expiry_status = NOT_EXPIRED;  // EXPIRED NOT_EXPIRED
    QString selection = " ";

    ui->displayedit->clear();

    if(ui->receiptradio->isChecked())
    {
        selection = "Receipt No. ";
        qry.prepare("SELECT * FROM details WHERE bill= :bill");
        qry.bindValue(":bill",ui->search_edit->text().toInt());
    }
    else if(ui->vehicleradio->isChecked())
    {
        selection = "Vehicle No. ";
        qry.prepare("SELECT * FROM details WHERE vehicle= :vehicle");
        qry.bindValue(":vehicle",ui->search_edit->text().toUpper());

    }
    else if(ui->customerradio->isChecked())
    {
        selection = "Customer ";
        qry.prepare("SELECT * FROM details WHERE customer= :customer");
        qry.bindValue(":customer",ui->search_edit->text().toUpper());

    }
    else if(ui->materialradio->isChecked())
    {
        selection = "Material ";
        qry.prepare("SELECT * FROM details WHERE material= :material");
        qry.bindValue(":materialr",ui->search_edit->text().toUpper());

    }
    else if(ui->dateradio->isChecked())
    {
        selection = "Date ";
        qry.prepare("SELECT * FROM details WHERE date1= :date");
        qry.bindValue(":date",ui->date_edit->text()+"/"+ui->month_edit->text()+"/"+ui->year_edit->text());

    }

    if(!qry.exec())
    {
        qDebug() << qry.lastError();
        qDebug()<<"Query Search Error";
    }
    else
    {
        if(qry.first())
        {
            query_status = NOT_EMPTY;


           if( qry_settings.value(5).toInt() == NOT_EXPIRED )
                ui->printbutton->setEnabled(1);

            ui->nextbutton->setEnabled(1);

        }
        if( query_status == NOT_EMPTY )
        {
            qDebug()<<"First Customer Querry printed";

            ui->displayedit->clear();
            ui->displayedit->append("<h1><center>THOMSON<center></h1>\n");
            ui->displayedit->insertPlainText("Bill No\t: "+qry.value(0).toString()+"\t\t\t"+"Vehicle No\t: "+qry.value(1).toString()+"\n");
            ui->displayedit->insertPlainText("Customer\t: "+qry.value(3).toString()+"\t\t\t"+"Material\t: "+qry.value(4).toString()+"\n");
            ui->displayedit->insertPlainText("---------------------------------------------------------------------------------------------------------------------------\n\n");
            ui->displayedit->insertPlainText("Challan No\t: "+qry.value(2).toString()+"\n");
            ui->displayedit->insertPlainText("Charge 1\t: "+qry.value(5).toString()+"\nCharge 2\t: "+qry.value(13).toString()+"\n\n");
            ui->displayedit->insertPlainText("Date1\t: "+qry.value(7).toString()+"\t\t\t"+"Date2\t: "+qry.value(10).toString()+"\n");
            ui->displayedit->insertPlainText("Time1\t: "+qry.value(8).toString()+"\t\t\t"+"Time2\t: "+qry.value(11).toString()+"\n\n");
            ui->displayedit->insertPlainText("Tare Wght\t: "+qry.value(6).toString()+"\n");
            ui->displayedit->insertPlainText("Gross Wght\t: "+qry.value(9).toString()+"\n");
            ui->displayedit->insertPlainText("Net Wght\t: "+qry.value(12).toString()+"\n\n\n");
            total = qry.value(13).toInt()+qry.value(5).toInt();
            ui->displayedit->insertPlainText("Total Chrg\t: "+QString::number(total)+"\n");

        }
        else
        qDebug()<<"First Customer Querry Error";

     }
    if( query_status == EMPTY )
    {
        if(!ui->dateradio->isChecked())
            QMessageBox::critical(this, "Invalid search", selection+ui->search_edit->text().toUpper()+" doesn't Exists!!");
        else
            QMessageBox::critical(this, "Invalid search", selection+ui->date_edit->text()+"/"+ui->month_edit->text()+"/"+ui->year_edit->text()+" doesn't Exists!!");
        ui->displayedit->clear();
        ui->printbutton->setDisabled(1);
        ui->nextbutton->setDisabled(1);
        ui->previousbutton->setDisabled(1);
    }
}

void DReports::on_dateradio_clicked()
{
    ui->search_label->setText("Date : ");
    ui->search_edit->setVisible(0);
    ui->seperator_label1->setVisible(1);
    ui->seperator_label2->setVisible(1);
    ui->date_edit->setVisible(1);
    ui->month_edit->setVisible(1);
    ui->year_edit->setVisible(1);
    ui->date_edit->setFocus();
}

void DReports::on_receiptradio_clicked()
{
    ui->search_label->setText("Reciept No : ");
    ui->search_edit->setVisible(1);
    ui->seperator_label1->setVisible(0);
    ui->seperator_label2->setVisible(0);
    ui->date_edit->setVisible(0);
    ui->month_edit->setVisible(0);
    ui->year_edit->setVisible(0);
    ui->search_edit->setFocus();
}

void DReports::on_vehicleradio_clicked()
{
    ui->search_label->setText("Vehicle No : ");
    ui->search_edit->setVisible(1);
    ui->seperator_label1->setVisible(0);
    ui->seperator_label2->setVisible(0);
    ui->date_edit->setVisible(0);
    ui->month_edit->setVisible(0);
    ui->year_edit->setVisible(0);
    ui->search_edit->setFocus();
}

void DReports::on_customerradio_clicked()
{
    ui->search_label->setText("Customer : ");
    ui->search_edit->setVisible(1);
    ui->seperator_label1->setVisible(0);
    ui->seperator_label2->setVisible(0);
    ui->date_edit->setVisible(0);
    ui->month_edit->setVisible(0);
    ui->year_edit->setVisible(0);
    ui->search_edit->setFocus();
}

void DReports::on_materialradio_clicked()
{
    ui->search_label->setText("Material : ");
    ui->search_edit->setVisible(1);
    ui->seperator_label1->setVisible(0);
    ui->seperator_label2->setVisible(0);
    ui->date_edit->setVisible(0);
    ui->month_edit->setVisible(0);
    ui->year_edit->setVisible(0);
    ui->search_edit->setFocus();
}

void DReports::on_nextbutton_clicked()
{
    if(qry.next())
    {
        ui->previousbutton->setEnabled(1);
        ui->displayedit->clear();
        ui->displayedit->append("<h1><center>THOMSON<center></h1>\n");
        ui->displayedit->insertPlainText("Bill No\t: "+qry.value(0).toString()+"\t\t\t"+"Vehicle No\t: "+qry.value(1).toString()+"\n");
        ui->displayedit->insertPlainText("Customer\t: "+qry.value(3).toString()+"\t\t\t"+"Material\t: "+qry.value(4).toString()+"\n");
        ui->displayedit->insertPlainText("---------------------------------------------------------------------------------------------------------------------------\n\n");
        ui->displayedit->insertPlainText("Challan No\t: "+qry.value(2).toString()+"\n");
        ui->displayedit->insertPlainText("Charge 1\t: "+qry.value(5).toString()+"\nCharge 2\t: "+qry.value(13).toString()+"\n\n");
        ui->displayedit->insertPlainText("Date1\t: "+qry.value(7).toString()+"\t\t\t"+"Date2\t: "+qry.value(10).toString()+"\n");
        ui->displayedit->insertPlainText("Time1\t: "+qry.value(8).toString()+"\t\t\t"+"Time2\t: "+qry.value(11).toString()+"\n\n");
        ui->displayedit->insertPlainText("Tare Wght\t: "+qry.value(6).toString()+"\n");
        ui->displayedit->insertPlainText("Gross Wght\t: "+qry.value(9).toString()+"\n");
        ui->displayedit->insertPlainText("Net Wght\t: "+qry.value(12).toString()+"\n\n\n");
        total = qry.value(13).toInt()+qry.value(5).toInt();
        ui->displayedit->insertPlainText("Total Chrg\t: "+QString::number(total)+"\n");
     }
    else
    {
        ui->nextbutton->setDisabled(1);
        QMessageBox::critical(this, "Last entry", "No more Entries, you are at last entry");
        qry.previous();
    }
}

void DReports::on_previousbutton_clicked()
{
    if(qry.previous())
    {
        ui->nextbutton->setEnabled(1);
        ui->displayedit->clear();
        ui->displayedit->append("<h1><center>THOMSON<center></h1>\n");
        ui->displayedit->insertPlainText("Bill No\t: "+qry.value(0).toString()+"\t\t\t"+"Vehicle No\t: "+qry.value(1).toString()+"\n");
        ui->displayedit->insertPlainText("Customer\t: "+qry.value(3).toString()+"\t\t\t"+"Material\t: "+qry.value(4).toString()+"\n");
        ui->displayedit->insertPlainText("---------------------------------------------------------------------------------------------------------------------------\n\n");
        ui->displayedit->insertPlainText("Challan No\t: "+qry.value(2).toString()+"\n");
        ui->displayedit->insertPlainText("Charge 1\t: "+qry.value(5).toString()+"\nCharge 2\t: "+qry.value(13).toString()+"\n\n");
        ui->displayedit->insertPlainText("Date1\t: "+qry.value(7).toString()+"\t\t\t"+"Date2\t: "+qry.value(10).toString()+"\n");
        ui->displayedit->insertPlainText("Time1\t: "+qry.value(8).toString()+"\t\t\t"+"Time2\t: "+qry.value(11).toString()+"\n\n");
        ui->displayedit->insertPlainText("Tare Wght\t: "+qry.value(6).toString()+"\n");
        ui->displayedit->insertPlainText("Gross Wght\t: "+qry.value(9).toString()+"\n");
        ui->displayedit->insertPlainText("Net Wght\t: "+qry.value(12).toString()+"\n\n\n");
        total = qry.value(13).toInt()+qry.value(5).toInt();
        ui->displayedit->insertPlainText("Total Chrg\t: "+QString::number(total)+"\n");
    }
    else
    {
        ui->previousbutton->setDisabled(1);
        QMessageBox::critical(this, "First entry", "No more Entries, you are at first entry");
        qry.next();
    }
}

void DReports::on_printbutton_clicked()
{
    const char new_line = 0x0A;
    const char tab = 0x09;
    char print_str[100];
    int i = 0;
    QString q_str;

    QPrinter printer;
    QTextDocument *document = ui->displayedit->document();

        printer.setOutputFormat( QPrinter::PdfFormat );
        printer.setOutputFileName( "Sample.pdf" );
        printer.setPageSize(QPrinter::A4);
        document->print(&printer);

    QDesktopServices::openUrl(QUrl("file:///./Sample.pdf", QUrl::TolerantMode));

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

void DReports::on_clearbutton_clicked()
{
    ui->displayedit->clear();
    ui->search_edit->clear();
    ui->printbutton->setDisabled(1);
    ui->nextbutton->setDisabled(1);
    ui->previousbutton->setDisabled(1);
}
