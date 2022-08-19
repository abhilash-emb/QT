#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtGui>
#include "adminlogin.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    stop_click = 0;

    QTimer *qtimer = new QTimer(this);
    connect(qtimer, SIGNAL(timeout()), this, SLOT(update_time()));
    qtimer->start(30000);

    PortSettings portsettings = {BAUD9600, DATA_8, PAR_NONE, STOP_1, FLOW_OFF, 10};
    port = new QextSerialPort("COM1", portsettings, QextSerialPort::Polling);

    database = QSqlDatabase::addDatabase("QSQLITE","PrinterDB");
    database.setDatabaseName("Records");
    if (!database.open())
    {
        QMessageBox::warning(this, "Warning", "Database not open");
        qDebug() <<"Failed";
    }
    else
        qDebug() <<"Success";

    qry = QSqlQuery(database);
    sec_qry = QSqlQuery(database);
    qry.prepare( "CREATE TABLE IF NOT EXISTS record (ordernum varchar(10) , weight varchar(7), tare varchar(6),tareperc varchar(6),"
                 "quality varchar(10), size varchar(8),date varchar(11),time varchar(10))");
    if( !qry.exec() )
    {
        QMessageBox::warning(this, "Warning", "Error with database : Records");
        qDebug() << qry.lastError();
    }
    else
          qDebug() << "Table Record created!";

    qry.prepare( "CREATE TABLE IF NOT EXISTS settings (id integer primary key, password varchar(20))");
    if( !qry.exec() )
    {
        QMessageBox::warning(this, "Warning", "Error with database : Settings");
        qDebug() << qry.lastError();
    }
    else
          qDebug() << "Table settings created!";

    /*
    qry.prepare("INSERT INTO settings ( id ,password) VALUES (1 , '123')");
    if( !qry.exec() )
    {
           qDebug() << qry.lastError();
           qDebug("Insert setting fail");
    }
    else
           qDebug() << "Insert to settings pass";
   // */

    help_shortcut = new QShortcut(QKeySequence("F1"), this);
    connect(help_shortcut, SIGNAL(activated()), this, SLOT(on_actionAbout_triggered()));
    start_shortcut = new QShortcut(QKeySequence("F2"), this);
    connect(start_shortcut, SIGNAL(activated()), this, SLOT(on_start_button_clicked()));
    stop_shortcut = new QShortcut(QKeySequence("F3"), this);
    connect(stop_shortcut, SIGNAL(activated()), this, SLOT(on_stop_button_clicked()));

    ui->setupUi(this);

    ui->start_button->setEnabled(1);
    ui->stop_button->setDisabled(1);
    ui->weight_edit->setDisabled(1);
    ui->date_label->setText(QDate::currentDate().toString("dd/MM/yyyy"));
    ui->time_label->setText(QTime::currentTime().toString("hh:mm AP"));
    ui->totalitemdisp_label->setText("0");
    ui->tolerancedisp_label->setText("Nil");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_time()
{
    ui->date_label->setText(QDate::currentDate().toString("dd/MM/yyyy"));
    ui->time_label->setText(QTime::currentTime().toString("hh:mm AP"));
}

void MainWindow::on_start_button_clicked()
{

        QString value_recieved;
        int item_count = 1,length =0,error_free = 0,i = 0;
        float tolerance = 0.0,rx = 0.0;

        stop_click = 0;

        ui->weight_edit->clear();
        ui->weight_edit->setEnabled(1);
        ui->start_button->setDisabled(1);
        ui->stop_button->setEnabled(1);

        while(stop_click == 0)
        {
            error_free = 0;
            if (!port->isOpen())
                 port->open(QIODevice::ReadWrite);

            while(!port->bytesAvailable() && stop_click == 0)
                    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

            value_recieved = port->readAll();
            length = value_recieved.length();

            for(i=0;i<length;i++)
                if((value_recieved[i] >='0' && value_recieved[i] <='9' )||value_recieved[i] == '.');
                else
                {
                    error_free = 1;
                    break;
                }

            if(error_free == 0)
            {
                if(!ui->order_edit->text().isEmpty()&&!ui->tolerance_edit->text().isEmpty()&&!ui->quality_edit->text().isEmpty()&&!ui->size_edit->text().isEmpty())
                {

                    tolerance = ui->tolerance_edit->text().toFloat();
                    rx  = value_recieved.toFloat();

                    if(tolerance > 0.0)
                        tolerance = ((rx-tolerance)/tolerance)*100;

                    ui->tolerancedisp_label->setText(QString::number(tolerance,'f',2)+" %");
                    ui->weight_edit->clear();
                    ui->weight_edit->setText(value_recieved);

                    qry.prepare("INSERT INTO record (ordernum , weight, tare, tareperc, quality, size, date, time ) VALUES (:orderno, :wght, :tr, :trpr, :qual, :sz, :dt, :tm)");
                    qry.bindValue(":orderno",ui->order_edit->text().toUpper());
                    qry.bindValue(":wght",ui->weight_edit->text());
                    qry.bindValue(":tr",ui->tolerance_edit->text());
                    qry.bindValue(":trpr",ui->tolerancedisp_label->text());
                    qry.bindValue(":qual",ui->quality_edit->text().toUpper());
                    qry.bindValue(":sz",ui->size_edit->text().toUpper());
                    qry.bindValue(":dt",ui->date_label->text());
                    qry.bindValue(":tm",ui->time_label->text().toUpper());
                    if( !qry.exec() )
                    {
                           qDebug("Order No. already exists");
                    }
                    else
                        qDebug("Order No. inserted");

                    ui->statusBar->showMessage("Saved",1000);
                    ui->totalitemdisp_label->setText(QString::number(item_count++));
                }
                else if( stop_click == 0 )
                   QMessageBox::warning(this, "Warning", "Fields are empty, Item not saved....");
            }
            port->flush();

            if (port->isOpen())
            port->close();
        }


}

void MainWindow::on_stop_button_clicked()
{
    stop_click = 1;
    ui->start_button->setEnabled(1);
    ui->stop_button->setDisabled(1);
    ui->weight_edit->clear();
    ui->weight_edit->setDisabled(1);
    ui->quality_edit->clear();
    ui->size_edit->clear();
    ui->tolerance_edit->clear();
    ui->tolerancedisp_label->clear();
    ui->order_edit->clear();
    ui->statusBar->clearMessage();
    ui->totalitemdisp_label->setText("0");
    ui->tolerancedisp_label->setText("Nil");
}
void MainWindow::on_actionSettings_triggered()
{
    adminlogin admin;
    admin.setModal(true);
    admin.exec();
}
void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, tr("About Printer++"),tr("<h2>Printer++  Ver. 1.0</h2>"
                                                      "<p>An application enabling database management "
                                                      "of weights measured using Sansui weighing systems."
                                                      " </p>"
                                                      "Copyright &copy; AB Corp, Bangalore <br />"
                                                      "<br />Contact Us : "
                                                      "<br />All rights reserved."
                                                       ));
}
