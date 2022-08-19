#include <mainwindow.h>
#include <ui_mainwindow.h>
#include <dsettings.h>
#include <dreports.h>
#include <dviewticket.h>
#include <dsecondweight.h>
#include <dfirstweight.h>
#include <master.h>
#include "Header.h"

#include <QtSql>
#include <QtCore>
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int month,year,expiry_status = NOT_EXPIRED;
    calibration_value = 0.0;
    option            = MANUAL;
    tare              = 0;

    timer = new QTimer(this);
    //timer->setInterval(20);

    PortSettings portsettings = {BAUD9600, DATA_8, PAR_NONE, STOP_1, FLOW_OFF, 10};
    port = new QextSerialPort("COM1", portsettings, QextSerialPort::Polling);


    detailsdb=QSqlDatabase::addDatabase("QSQLITE","detailsdb");
    detailsdb.setDatabaseName("details");
    detailsdb.setHostName("KAIM");
        detailsdb.setUserName("kaim");
        detailsdb.setPassword("1234");
        if (!detailsdb.open())
        {
             qDebug() <<"Failed";
        }


        qry1 = QSqlQuery("SELECT * FROM details",detailsdb);
        qry1.prepare( "CREATE TABLE IF NOT EXISTS details (bill integer primary key not null, vehicle varchar(15) not null ,"
                      " challan varchar(15),customer varchar(30) not null, material varchar(15),charge int,weight1 int,"
                      "date1 varchar(12),time1 varchar(10),weight2 int,date2 varchar(12),time2 varchar(10), netweight int,total int)");
        if( !qry1.exec() )
            qDebug() << qry1.lastError();
        else
            qDebug() << "Table details created!";



    settingsdb=QSqlDatabase::addDatabase("QSQLITE","settingsdb");
    settingsdb.setDatabaseName("settings");
    settingsdb.setHostName("KAIM");
        settingsdb.setUserName("kaim");
        settingsdb.setPassword("1234");


        if (!settingsdb.open())
        {
             qDebug() <<"Failed";
        }


        qry2 = QSqlQuery(settingsdb);
        qry3 = QSqlQuery(settingsdb);
        qry2.prepare( "CREATE TABLE IF NOT EXISTS settings (id integer primary key, pass varchar(30),"
                      "date varchar(25),port varchar(6),baud integer,databits integer, parity varchar(6),stopbits varchar(6),"
                      "termination integer, header varchar(100),footer varchar(100),prefer integer,exmonth integer,"
                      "exyear integer,status integer,lastbill integer,maxlimit integer,upstatus integer,freeweight integer,"
                      "setup_resolution integer, setup_Calib float(5,2),loadcell_DLCs integer, DLC1_offset integer,"
                      " DLC2_offset integer, DLC3_offset integer,DLC4_offset integer, DLC5_offset integer, DLC6_offset integer,"
                      " DLC7_offset integer, DLC8_offset integer,pr_port varchar(6),pr_baud integer,pr_databits integer,"
                      " pr_parity varchar(6),pr_stopbits varchar(6))");
        if( !qry2.exec() )
        {
            qDebug("Settings");
            qDebug() << qry2.lastError();
        }
        else
            qDebug() << "Table settings created!";
/*

         qry2.prepare("INSERT INTO settings (id ,pass,date,exmonth ,exyear ,status,lastbill,maxlimit,upstatus,port,setup_resolution,"
         "setup_Calib, loadcell_DLCs, DLC1_offset, DLC2_offset, DLC3_offset, DLC4_offset,DLC5_offset, DLC6_offset, DLC7_offset, DLC8_offset,pr_port)"
                      "VALUES (1,'123',:date,:exmonth ,:exyear,:status,:last,:maxlimit,:upstatus,'COM1',2,1,4,1,1,1,1,1,1,1,1,'COM2' )");
         qry2.bindValue(":date",QDate::currentDate().toString("d/M/yy")+" at "+QTime::currentTime().toString("h:mm ap"));
         qry2.bindValue(":exmonth",QDate::currentDate().toString("M").toInt());
         qry2.bindValue(":exyear",QDate::currentDate().toString("yyyy").toInt());
         qry2.bindValue(":status",NOT_EXPIRED);
         qry2.bindValue(":last",100);
         qry2.bindValue(":maxlimit",100);
         qry2.bindValue(":upstatus",DB_NEW);
         if( !qry2.exec() )
         {
               qDebug() << qry2.lastError();
               qDebug("Insert setting fail");
         }
         else
               qDebug() << "insert settings pass";



        qry2.prepare("UPDATE settings SET exmonth=:exmonth ,exyear=:exyear,status=:stat WHERE id=1");
        qry2.bindValue(":exmonth",12);
        qry2.bindValue(":exyear",2013);
        qry2.bindValue(":stat",NOT_EXPIRED);
        if( !qry2.exec() )
        {
            qDebug() << qry2.lastError();
            qDebug("Insert expiry fail");
        }
        else
            qDebug() << "insert expiry pass";
*/
/*
        qry2.prepare("UPDATE settings SET lastbill=199 WHERE id=1");
        if( !qry2.exec() )
        {
             qDebug() << qry2.lastError();
             qDebug("Insert lastbill fail");
        }
        else
             qDebug() << "insert last bill pass";

       qry2.prepare("UPDATE settings SET lastbill=100,upstatus=0 WHERE id=1");
       if( !qry2.exec() )
       {
            qDebug() << qry2.lastError();
            qDebug("Insert lastbill fail");
       }
       else
            qDebug() << "insert last bill pass";

       qry2.prepare("UPDATE settings SET pr_port='COM7' WHERE id=1");
       if( !qry2.exec() )
       {
            qDebug() << qry2.lastError();
            qDebug("Printer port name update fail");
       }
       else
            qDebug() << "Printer port name update success";

*/

       qry2.prepare( "SELECT * FROM settings WHERE id = 1" );
          if( !qry2.exec() )
          {
               qDebug("Settings 2");
            qDebug() << qry2.lastError();
          }
          else
          {
                    qry2.first();

                    port->setPortName(qry2.value(3).toString());
                    //ui->portlabel->setText(qry2.value(3).toString());

                        if(qry2.value(4).toInt() == 1200)
                        {
                            //ui->baudlabel->setText("1200");
                            port->setBaudRate((BaudRateType)qry2.value(4).toInt());
                        }
                        else if(qry2.value(4).toInt() == 2400)
                        {
                            //ui->baudlabel->setText("2400");
                            port->setBaudRate((BaudRateType)qry2.value(4).toInt());
                        }
                        else if(qry2.value(4).toInt() == 4800)
                        {
                            //ui->baudlabel->setText("4800");
                            port->setBaudRate((BaudRateType)qry2.value(4).toInt());
                        }
                        else if(qry2.value(4).toInt() == 9600)
                        {
                            //ui->baudlabel->setText("9600");
                            port->setBaudRate((BaudRateType)qry2.value(4).toInt());
                        }
                        else if(qry2.value(4).toInt() == 19200)
                        {
                            //ui->baudlabel->setText("19200");
                            port->setBaudRate((BaudRateType)qry2.value(4).toInt());
                        }

                        if(qry2.value(5).toInt() == 5)
                        {
                            //ui->datalabel->setText("5");
                            port->setDataBits((DataBitsType)qry2.value(5).toInt());
                        }
                        else if(qry2.value(5).toInt() == 6)
                        {
                            //ui->datalabel->setText("6");
                            port->setDataBits((DataBitsType)qry2.value(5).toInt());
                        }
                        else if(qry2.value(5).toInt() == 7)
                        {
                            //ui->datalabel->setText("7");
                            port->setDataBits((DataBitsType)qry2.value(5).toInt());
                        }
                        else if(qry2.value(5).toInt() == 8)
                        {
                            //ui->datalabel->setText("8");
                            port->setDataBits((DataBitsType)qry2.value(5).toInt());
                        }

                        QString *none = new QString("NONE");
                        QString *odd = new QString("ODD");
                        QString *even = new QString("EVEN");

                        if(qry2.value(6).toString() == none)
                        {
                            //ui->paritylabel->setText("NONE");
                            port->setParity((ParityType)qry2.value(6).toString().toInt());
                        }
                        else if(qry2.value(6).toString() == odd)
                        {
                            //ui->paritylabel->setText("ODD");
                            port->setParity((ParityType)qry2.value(6).toString().toInt());
                        }

                        else if(qry2.value(6).toString() == even)
                        {
                            //ui->paritylabel->setText("EVEN");
                            port->setParity((ParityType)qry2.value(6).toString().toInt());
                        }

                        if(qry2.value(7).toInt() == 1)
                        {
                            //ui->stoplabel->setText("1");
                            port->setStopBits((StopBitsType)qry2.value(7).toInt());
                        }
                        else if(qry2.value(7).toInt() == 2)
                        {
                            //ui->stoplabel->setText("2");
                            port->setStopBits((StopBitsType)qry2.value(7).toInt());
                        }

                    ui->exmonthlabel->setText(qry2.value(12).toString());
                    ui->exyearlabel->setText(qry2.value(13).toString());
                    ui->headerlabel->setText(qry2.value(9).toString());
                    ui->footerlabel->setText(qry2.value(10).toString());

                    maxlimit = qry2.value(18).toInt();
                    option = qry2.value(11).toInt();            // 0 = MANUAL, 1 = AUTO
                    calibration_value = qry2.value(20).toFloat();

                    if(qry2.value(14).toInt() == NOT_EXPIRED)
                    {
                        month =QDate::currentDate().toString("M").toInt();
                        year =QDate::currentDate().toString("yyyy").toInt();

                        if( year >= qry2.value(13).toInt())         // Check YEAR
                        {
                            if(year > qry2.value(13).toInt())
                            {
                                expiry_status = EXPIRED;            //expired
                                ui->expirylabel->setText("Licence Expired, Please renew licence Immediately");

                            }
                            else
                            {
                                if(month > qry2.value(12).toInt())  // Check MONTH
                                {
                                    expiry_status = EXPIRED;        //expired
                                    ui->expirylabel->setText("Licence Expired, Please renew licence Immediately");
                                }

                            }

                        }

                    }
                    else
                        ui->expirylabel->setText("Licence Expired, Please renew licence Immediately");

          }

          if(expiry_status == EXPIRED)      // If expired UPDATE database
          {
                qry3.prepare( "UPDATE settings SET status= :status WHERE id = 1" );
                qry3.bindValue(":status",EXPIRED);
                   if( !qry3.exec() )
                   {
                       qDebug() << qry3.lastError();
                       qDebug("qry3 failed");
                   }
                   else
                   {
                      qDebug("qry3 success");
                   }
          }

          connect(timer, SIGNAL(timeout()), SLOT(onReadyRead()));
          connect(port, SIGNAL(readyRead()), SLOT(onReadyRead()));

    if (!port->isOpen())
    {
         port->open(QIODevice::ReadWrite);
         timer->setInterval(10);
         timer->start();

    }

    //clock display on main page
    QTimer *qtimer = new QTimer(this);
    connect(qtimer, SIGNAL(timeout()), this, SLOT(update_time()));
    qtimer->start(1000);

    //track mouse
    qApp->installEventFilter(this);

    shortcut1= new QShortcut(QKeySequence("F1"), this);
    connect(shortcut1, SIGNAL(activated()), this, SLOT(on_firstweightbutton_clicked()));
    shortcut2= new QShortcut(QKeySequence("F2"), this);
    connect(shortcut2, SIGNAL(activated()), this, SLOT(on_secondweightbutton_clicked()));
    shortcut3= new QShortcut(QKeySequence("F3"), this);
    connect(shortcut3, SIGNAL(activated()), this, SLOT(on_viewticketbutton_clicked()));
    shortcut4= new QShortcut(QKeySequence("F4"), this);
    connect(shortcut4, SIGNAL(activated()), this, SLOT(on_viewreportbutton_clicked()));
    shortcut5= new QShortcut(QKeySequence("F5"), this);
    connect(shortcut5, SIGNAL(activated()), this, SLOT(on_settingsbutton_clicked()));
    shortcut6= new QShortcut(QKeySequence("F6"), this);
    connect(shortcut6, SIGNAL(activated()), this, SLOT(on_helpbutton_clicked()));
    shortcut7= new QShortcut(QKeySequence("F7"), this);
    connect(shortcut7, SIGNAL(activated()), this, SLOT(on_exitbutton_clicked()));

/*
    QTime dieTime = QTime::currentTime().addSecs(3);
        while(QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    MainWindow::on_systemInit();

*/

    ui->firstweightbutton->setDisabled(1);
    ui->secondweightbutton->setDisabled(1);

    QTimer::singleShot(3*1000, this, SLOT(on_systemInit()));
    statusBar()->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
    statusBar()->showMessage("Detecting hardware...");
}

MainWindow::~MainWindow()
{
    port->write("ED");
    detailsdb.close();
    settingsdb.close();
    port->close();
    timer->stop();
    delete ui;
}

void MainWindow::onReadyRead()
{
    QByteArray val,edit;
    QString display;
    int i=0,j=0,k=0,intval=0,weight =0;

    if (port->bytesAvailable())
    {
        ui->currentweightedit->clear();
        val=port->readAll();
/*
        edit[0]=val[0];
        for(i=1;i>=0;i++)
        {
            if(val[i]!='0' && val[i]!='\n' )
            {
                for(j=1;val[i]!='\n';j++)
                {
                    edit[j]=val[i];
                    i++;
                }
                break;
            }
            else if(val[i] == '\n')
                k=1;

        }
        if(k == 0)
        {*/
               ui->currentweightedit->clear();
               weight = (val.toInt()*calibration_value) - tare;
               if(weight < maxlimit)
               {
                   ui->currentweightedit->setText("0");
                   Qweight = "0";
               }
               else
               {
                   ui->currentweightedit->setText(QString::number(weight));
                   Qweight = QString::number(weight);
               }
    }
}

bool MainWindow::eventFilter(QObject *pobj, QEvent *pevent)
{
    if (pevent->type() == QEvent::MouseMove)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(pevent);
        QPoint point_ms = mouseEvent->globalPos();

        QPoint point_p1 = ui->firstweightbutton->mapToGlobal(ui->firstweightbutton->rect().topLeft());
        QPoint point_p2 = ui->secondweightbutton->mapToGlobal(ui->secondweightbutton->rect().topLeft());
        QPoint point_p3 = ui->viewticketbutton->mapToGlobal(ui->viewticketbutton->rect().topLeft());
        QPoint point_p4 = ui->viewreportbutton->mapToGlobal(ui->viewreportbutton->rect().topLeft());
        QPoint point_p5 = ui->settingsbutton->mapToGlobal(ui->settingsbutton->rect().topLeft());
        QPoint point_p6 = ui->helpbutton->mapToGlobal(ui->helpbutton->rect().topLeft());
        QPoint point_p7 = ui->exitbutton->mapToGlobal(ui->exitbutton->rect().topLeft());


        int ms_x,ms_y,p1_x,p1_y,p2_x,p2_y,p3_x,p3_y,p4_x,p4_y,p5_x,p5_y,p6_x,p6_y,p7_x,p7_y;
        ms_x = point_ms.x(); ms_y = point_ms.y();
        p1_x = point_p1.x(); p1_y = point_p1.y();
        p2_x = point_p2.x(); p2_y = point_p2.y();
        p3_x = point_p3.x(); p3_y = point_p3.y();
        p4_x = point_p4.x(); p4_y = point_p4.y();
        p5_x = point_p5.x(); p5_y = point_p5.y();
        p6_x = point_p6.x(); p6_y = point_p6.y();
        p7_x = point_p7.x(); p7_y = point_p7.y();

        point_p1.setX(p1_x+60);
        point_p2.setX(p1_x+60);
        point_p3.setX(p1_x+60);
        point_p4.setX(p1_x+60);
        point_p5.setX(p1_x+60);
        point_p6.setX(p1_x+60);
        point_p7.setX(p1_x+60);

        if( (ms_x > p1_x && ms_x < p1_x + 61)  && (ms_y > p1_y && ms_y < p1_y + 51) ) {
            QToolTip::showText(point_p1, "Click this for vehicle\nfirst time");
        }
        else if( (ms_x > p2_x && ms_x < p2_x + 61)  && (ms_y > p2_y && ms_y < p2_y + 51) ) {
            QToolTip::showText(point_p2, "Press this for vehicle\nsecond time");
        }
        else if( (ms_x > p3_x && ms_x < p3_x + 61)  && (ms_y > p3_y && ms_y < p3_y + 51) ) {
            QToolTip::showText(point_p3, "View Receipt Details");
        }
        else if( (ms_x > p4_x && ms_x < p4_x + 61)  && (ms_y > p4_y && ms_y < p4_y + 51) ) {
            QToolTip::showText(point_p4, "Generate Report");
        }
        else if( (ms_x > p5_x && ms_x < p5_x + 61)  && (ms_y > p5_y && ms_y < p5_y + 51) ) {
            QToolTip::showText(point_p5, "Modify Settings");
        }
        else if( (ms_x > p6_x && ms_x < p6_x + 61)  && (ms_y > p6_y && ms_y < p6_y + 51) ) {
            QToolTip::showText(point_p6, "Help");
        }
        else if( (ms_x > p7_x && ms_x < p7_x + 61)  && (ms_y > p7_y && ms_y < p7_y + 51) ) {
            QToolTip::showText(point_p7, "Exit Program");
        }
        else
            QToolTip::hideText();
    }
    return false;
}

void MainWindow::update_time()
{
    ui->currentdatetimeedit->setText(QDate::currentDate().toString()+ "       " + QTime::currentTime().toString("h:mm:ss ap"));
}


void MainWindow::on_actionFirst_Weight_triggered()
{
    on_firstweightbutton_clicked();
}

void MainWindow::on_actionSecond_Weight_triggered()
{
    on_secondweightbutton_clicked();
}

void MainWindow::on_actionView_Ticket_triggered()
{
    on_viewticketbutton_clicked();
}

void MainWindow::on_actionReport_triggered()
{
    on_viewreportbutton_clicked();
}

void MainWindow::on_actionSettings_triggered()
{
    on_settingsbutton_clicked();
}

void MainWindow::on_actionHelp_triggered()
{
    on_helpbutton_clicked();
}

void MainWindow::on_actionExit_triggered()
{
    on_exitbutton_clicked();
}

void MainWindow::on_firstweightbutton_clicked()
{
    /*
    QString value= "2";
    int weight = 0;
    int i=0;

    statusBar()->setStyleSheet("QStatusBar {color : red; }");
    statusBar()->showMessage("Stopped...");

    while(port->bytesAvailable()<=0);
    value=port->readAll();

    for(i=0;i>=0;i++)
    {
        if(value[i] == '\n')
            break;
        else if(i>20)
            break;

        final[i]=value[i];
    }

    statusBar()->showMessage(value);
    weight = (value.toInt()*calibration_value) - tare;
    */

    port->write("ED");                      // Command to MU for stop sending DLC readings
    DFirstWeight dfirstweight(this,Qweight,option);//QString::number( weight),option);
    dfirstweight.setModal(true);
    dfirstweight.exec();
    port->write("BG");
    statusBar()->setStyleSheet("QStatusBar {color : blue; }");
    statusBar()->showMessage("Start...");
}

void MainWindow::on_secondweightbutton_clicked()
{
    /*
    QString value = "2";
    int weight = 0;
    int i=0;
    statusBar()->setStyleSheet("QStatusBar {color : red; }");
    statusBar()->showMessage("Stopped...");

    while(!port->bytesAvailable());
    value=port->readAll();

    for(i=0;i>=0;i++)
    {
        if(value[i] == '\n')
            break;
        else if(i>20)
            break;

        final[i]=value[i];
    }

    weight = (value.toInt()*calibration_value)-tare;
    */

    port->write("ED");                      // Command to MU for stop sending DLC readings
    DSecondWeight dsecondweight(this,Qweight,option);
    dsecondweight.setModal(true);
    dsecondweight.exec();
    port->write("BG");
    statusBar()->setStyleSheet("QStatusBar {color : blue; }");
    statusBar()->showMessage("Start...");
}

void MainWindow::on_viewticketbutton_clicked()
{
    //view receipt details
    statusBar()->setStyleSheet("QStatusBar {color : red; }");
    statusBar()->showMessage("Stopped...");
    port->write("ED");                      // Command to MU for stop sending DLC readings
    DViewTicket dviewticket;
    dviewticket.setModal(true);
    dviewticket.exec();
    port->write("BG");
    statusBar()->setStyleSheet("QStatusBar {color : blue; }");
    statusBar()->showMessage("Start...");
}

void MainWindow::on_viewreportbutton_clicked()
{
    //generate report
    statusBar()->setStyleSheet("QStatusBar {color : red; }");
    statusBar()->showMessage("Stopped...");
    port->write("ED");                      // Command to MU for stop sending DLC readings
    DReports dreports;
    dreports.setModal(true);
    dreports.exec();
    port->write("BG");
    statusBar()->setStyleSheet("QStatusBar {color : blue; }");
    statusBar()->showMessage("Start...");
}

void MainWindow::on_settingsbutton_clicked()
{
    //change settings
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Confirm","You need to restart application once you enter settings menu\nDo you want to enter settings menu?\n",QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        statusBar()->setStyleSheet("QStatusBar {color : red; }");
        statusBar()->showMessage("Restart System...");

        ui->firstweightbutton->setDisabled(1);
        ui->secondweightbutton->setDisabled(1);

        port->write("ED");                 // Command to MU for stop sending DLC readings
        port->close();
        timer->stop();
        dsettings objds;
        objds.setModal(true);
        objds.exec();
    }
}

void MainWindow::on_helpbutton_clicked()
{
    //help
    QMessageBox::about(this, tr("About WeighBridge"),tr("<h2>WeighBridge  Ver. 1.0</h2>"
                                                        "<p>WeighBridge  Ver. 1.0 vehicle weigh scale software  <br />"
                                                        "turns your vehicle weight data into intelligence according  <br />"
                                                        "to your business, allowing you to improve and speedup profits.</p>"
                                                        "<p>Vehicle scale operations currently using a manual ticketing <br />"
                                                        "system can automate their process with WeighBridge  Ver. 1.0 <br />"
                                                        "data management software. Print tickets or reports as well as <br />"
                                                        "store information to a main database. WeighBridge  Ver. 1.0 is <br />"
                                                        "adaptable to a wide variety of industries and can be made <br />"
                                                        "compatible with many popular operating systems. WeighBridge <br />"
                                                        "Ver.1.0 can be paired with a range of weighing systems and <br />"
                                                        "indicators for a complete weighing and data management solution.</p>"
                                                        "Copyright &copy; 2013 KAIM SoftTech &trade;, Bangalore <br />"
                                                        "<br />Please contact supplier for any kind of help<br />"
                                                        "<br />Contact Us : <a href='http://kaimsofttech.com/'>KAIM SoftTech&trade;</a>"
                                                        "<br />All rights reserved."));
}

void MainWindow::on_exitbutton_clicked()
{
    //exit
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Confirm","    Do you want to exit?",QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
        qApp->quit();
}

/*
void MainWindow:: on_calibration()
{
    calibration calib;
    calib.setModal(true);
    calib.exec();
}
*/

void MainWindow::on_systemInit()
{
    QString value;
    int success = SUCCESS;
    QTime dieTime = QTime::currentTime().addSecs(2);
    port->write("IN");
    while(!port->bytesAvailable())
    {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
            if(QTime::currentTime() > dieTime)
            {
                 success = FAIL;
                 break;
            }
    }
    if(success == SUCCESS)
    {
        value=port->readAll();
        if(value.toInt() == SUCCESS)
        {
            statusBar()->setStyleSheet("QStatusBar {color : green; }");
            statusBar()->showMessage("Hardware connected....",3000);
            statusBar()->showMessage("Start....");
            ui->firstweightbutton->setEnabled(1);
            ui->secondweightbutton->setEnabled(1);
        }
        else
        {
            QMessageBox::information(this, "Failed", "Hardware Detected and DLC initialization failed....");
            statusBar()->setStyleSheet("QStatusBar {color : red; }");
            statusBar()->showMessage("DLC communication failed....");
        }
    }
    else
    {
        success = SUCCESS;
        port->write("BG");      // when settings is selected Qt will send ED command to stop reading DLC
        QTime dieTime = QTime::currentTime().addSecs(2);
        while(!port->bytesAvailable())
        {
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
                if(QTime::currentTime() > dieTime)
                {
                    success = FAIL;
                    break;
                }
        }
        if(success == FAIL)
        {
            QMessageBox::warning(this, "Failed", "No response from hardware, initialization failed....");
            statusBar()->setStyleSheet("QStatusBar {color : red; }");
            statusBar()->showMessage("Hardware communication failed....");
        }
        else
        {
            statusBar()->setStyleSheet("QStatusBar {color : blue; }");
            statusBar()->showMessage("Start....");
            ui->firstweightbutton->setEnabled(1);
            ui->secondweightbutton->setEnabled(1);
        }

    }
}

void MainWindow::on_tare_button_clicked()
{
        tare = ui->currentweightedit->text().toInt();
}
