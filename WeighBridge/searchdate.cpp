#include "searchdate.h"
#include "ui_searchdate.h"

#include <QtSql>
#include <QtGui>
#include <QPrintDialog>
#include <QDesktopServices>

searchdate::searchdate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchdate)
{
    ui->setupUi(this);
    db = QSqlDatabase :: database("detailsdb");
    qry=QSqlQuery(db);
    qry1=QSqlQuery(db);
    db2 = QSqlDatabase :: database("settingsdb");
    qry2 = QSqlQuery(db2);
    ui->printbutton->setDisabled(1);
    ui->nextbutton->setDisabled(1);
    ui->previousbutton->setDisabled(1);
}

searchdate::~searchdate()
{
    delete ui;
}

void searchdate::on_gobutton_clicked()
{
    int temp_flag=0,temp_status=2;

    qry2.prepare("SELECT status FROM settings WHERE id=1");
    if( !qry2.exec() )
    {
      qDebug() << qry2.lastError();
      qDebug()<<"Status";
    }
    else
    {
        qry2.first();
        temp_status= qry2.value(0).toInt();
    }

    qry.prepare("SELECT * FROM details WHERE date1= :date");
    qry.bindValue(":date",ui->dateedit->text()+"/"+ui->monthedit->text()+"/"+ui->yearedit->text());
    if(!qry.exec())
    {
        qDebug() << qry.lastError();
        qDebug()<<"Date Search Error";
    }
    else
    {
        qDebug( "Executed" );

        while(qry.next())
        {
            temp_flag=1;
            ui->nextbutton->setEnabled(1);
        }

        if(temp_flag==1)
        {
            qry.first();
            qDebug()<<"First Querry printed";

            if(temp_status==1)
                ui->printbutton->setEnabled(1);


            ui->displayedit->clear();
            ui->displayedit->append("<h1><center>THOMSON<center></h1>\n");
            ui->displayedit->insertPlainText("Bill No\t: "+qry.value(0).toString()+"\t\t\t"+"Vehicle No\t: "+qry.value(1).toString()+"\n\n");
            ui->displayedit->insertPlainText("Customer\t: "+qry.value(3).toString()+"\t\t\t"+"Material\t: "+qry.value(4).toString()+"\n");
            ui->displayedit->insertPlainText("---------------------------------------------------------------------------------------------------------------------------\n\n");
            ui->displayedit->insertPlainText("Challan No\t: "+qry.value(2).toString()+"\t\t\t"+"Charge\t: "+qry.value(5).toString()+"\n\n");
            ui->displayedit->insertPlainText("Date1\t: "+qry.value(7).toString()+"\t\t\t"+"Date2\t: "+qry.value(10).toString()+"\n");
            ui->displayedit->insertPlainText("Time1\t: "+qry.value(8).toString()+"\t\t\t"+"Time2\t: "+qry.value(11).toString()+"\n\n");
            ui->displayedit->insertPlainText("Tare Wght\t: "+qry.value(6).toString()+"\n");
            ui->displayedit->insertPlainText("Gross Wght\t: "+qry.value(9).toString()+"\n");
            ui->displayedit->insertPlainText("Net Wght\t: "+qry.value(12).toString()+"\n\n\n");
            ui->displayedit->insertPlainText("Total Chrg\t: "+qry.value(13).toString()+"\n");
        }
        else
        qDebug()<<"First Querry Error";
     }
    if(temp_flag==0)
    {
        QMessageBox::critical(this, "Invalid Date", "No Entry exists on this date");
        ui->displayedit->clear();
        ui->printbutton->setDisabled(1);
        ui->previousbutton->setDisabled(1);
        ui->nextbutton->setDisabled(1);
    }

}

void searchdate::on_printbutton_clicked()
{
    QPrinter printer;
     QTextDocument *document = ui->displayedit->document();


        printer.setOutputFormat( QPrinter::PdfFormat );
        printer.setOutputFileName( "Sample.pdf" );
        printer.setPageSize(QPrinter::A4);
        document->print(&printer);

    QDesktopServices::openUrl(QUrl("file:///./Sample.pdf", QUrl::TolerantMode));
}

void searchdate::on_clearbutton_clicked()
{
    ui->displayedit->clear();
    ui->dateedit->clear();
    ui->monthedit->clear();
    ui->yearedit->clear();
    ui->printbutton->setDisabled(1);
    ui->nextbutton->setDisabled(1);
    ui->previousbutton->setDisabled(1);
}

void searchdate::on_nextbutton_clicked()
{
        if(qry.next())
        {
            ui->previousbutton->setEnabled(1);
            ui->displayedit->clear();
            ui->displayedit->append("<h1><center>THOMSON<center></h1>\n");
            ui->displayedit->insertPlainText("Bill No\t: "+qry.value(0).toString()+"\t\t\t"+"Vehicle No\t: "+qry.value(1).toString()+"\n\n");
            ui->displayedit->insertPlainText("Customer\t: "+qry.value(3).toString()+"\t\t\t"+"Material\t: "+qry.value(4).toString()+"\n");
            ui->displayedit->insertPlainText("---------------------------------------------------------------------------------------------------------------------------\n\n");
            ui->displayedit->insertPlainText("Challan No\t: "+qry.value(2).toString()+"\t\t\t"+"Charge\t: "+qry.value(5).toString()+"\n\n");
            ui->displayedit->insertPlainText("Date1\t: "+qry.value(7).toString()+"\t\t\t"+"Date2\t: "+qry.value(10).toString()+"\n");
            ui->displayedit->insertPlainText("Time1\t: "+qry.value(8).toString()+"\t\t\t"+"Time2\t: "+qry.value(11).toString()+"\n\n");
            ui->displayedit->insertPlainText("Tare Wght\t: "+qry.value(6).toString()+"\n");
            ui->displayedit->insertPlainText("Gross Wght\t: "+qry.value(9).toString()+"\n");
            ui->displayedit->insertPlainText("Net Wght\t: "+qry.value(12).toString()+"\n\n\n");
            ui->displayedit->insertPlainText("Total Chrg\t: "+qry.value(13).toString()+"\n");
        }
        else
        {
            ui->nextbutton->setDisabled(1);
            QMessageBox::critical(this, "Entrie Finished", "No more Entries");
            qry.previous();
        }
}

void searchdate::on_previousbutton_clicked()
{
    if(qry.previous())
    {
        ui->nextbutton->setEnabled(1);
        ui->displayedit->clear();
        ui->displayedit->append("<h1><center>THOMSON<center></h1>\n");
        ui->displayedit->insertPlainText("Bill No\t: "+qry.value(0).toString()+"\t\t\t"+"Vehicle No\t: "+qry.value(1).toString()+"\n\n");
        ui->displayedit->insertPlainText("Customer\t: "+qry.value(3).toString()+"\t\t\t"+"Material\t: "+qry.value(4).toString()+"\n");
        ui->displayedit->insertPlainText("---------------------------------------------------------------------------------------------------------------------------\n\n");
        ui->displayedit->insertPlainText("Challan No\t: "+qry.value(2).toString()+"\t\t\t"+"Charge\t: "+qry.value(5).toString()+"\n\n");
        ui->displayedit->insertPlainText("Date1\t: "+qry.value(7).toString()+"\t\t\t"+"Date2\t: "+qry.value(10).toString()+"\n");
        ui->displayedit->insertPlainText("Time1\t: "+qry.value(8).toString()+"\t\t\t"+"Time2\t: "+qry.value(11).toString()+"\n\n");
        ui->displayedit->insertPlainText("Tare Wght\t: "+qry.value(6).toString()+"\n");
        ui->displayedit->insertPlainText("Gross Wght\t: "+qry.value(9).toString()+"\n");
        ui->displayedit->insertPlainText("Net Wght\t: "+qry.value(12).toString()+"\n\n\n");
        ui->displayedit->insertPlainText("Total Chrg\t: "+qry.value(13).toString()+"\n");
    }
    else
    {
        ui->previousbutton->setDisabled(1);
        QMessageBox::critical(this, "Entrie Finished", "No more Entries");
        qry.next();
    }
}
