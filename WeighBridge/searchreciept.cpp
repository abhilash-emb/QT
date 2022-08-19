#include "searchreciept.h"
#include "ui_searchreciept.h"

#include <QtGui>
#include <QtSql>
#include <QPrintDialog>
#include <QDesktopServices>

searchreciept::searchreciept(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchreciept)
{
    ui->setupUi(this);
    db = QSqlDatabase :: database("detailsdb");
    qry=QSqlQuery(db);
    db1 = QSqlDatabase :: database("settingsdb");
    qry1 = QSqlQuery(db1);

    ui->printbutton->setDisabled(1);
}

searchreciept::~searchreciept()
{
    delete ui;
}

void searchreciept::on_gobutton_clicked()
{
    int temp_flag=0,temp_status=2;

    ui->displayedit->clear();
    qry1.prepare("SELECT status FROM settings WHERE id=1");
    if( !qry1.exec() )
    {
      qDebug() << qry1.lastError();
      qDebug()<<"Status";
    }
    else
    {
        qry1.first();
        temp_status= qry1.value(0).toInt();
    }

    qry.prepare("SELECT * FROM details WHERE bill= :bill");
    qry.bindValue(":bill",ui->receiptedit->text().toInt());
    if(!qry.exec())
    {
        qDebug() << qry.lastError();
        qDebug()<<"Search Error";
    }
    else
    {
        qDebug( "Executed" );

        while (qry.next())
        {
            temp_flag=1;

            if(temp_status==1)
                ui->printbutton->setEnabled(1);
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

     }
    if(temp_flag==0)
    {
        QMessageBox::critical(this, "Invalid Reciept Number", "Reciept number doesn't Exists");
        ui->displayedit->clear();
        ui->printbutton->setDisabled(1);
    }

}

void searchreciept::on_printbutton_clicked()
{
    QPrinter printer;
     QTextDocument *document = ui->displayedit->document();


        printer.setOutputFormat( QPrinter::PdfFormat );
        printer.setOutputFileName( "Sample.pdf" );
        printer.setPageSize(QPrinter::A4);

        document->print(&printer);

    QDesktopServices::openUrl(QUrl("file:///./Sample.pdf", QUrl::TolerantMode));
}

void searchreciept::on_clearbutton_clicked()
{
    ui->displayedit->clear();
    ui->receiptedit->clear();
    ui->printbutton->setDisabled(1);
}
