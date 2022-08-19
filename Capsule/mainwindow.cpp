#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "settings.h"
#include "operator.h"
#include "startweighing.h"

#include <QtSql>
#include <QtCore>
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QTimer *qtimer = new QTimer(this);
    connect(qtimer, SIGNAL(timeout()), this, SLOT(update_time()));
    qtimer->start(1000);
    ui->setupUi(this);

    database=QSqlDatabase::addDatabase("QSQLITE","database");
    database.setDatabaseName("maindatabase");
    database.setHostName("KAIM");
    database.setUserName("kaim");
    database.setPassword("8A3A62311D");
    if (!database.open())
    {
         qDebug() <<"Failed";
    }

    qry = QSqlQuery(database);
    qry.prepare( "CREATE TABLE IF NOT EXISTS settings (id integer primary key, password varchar(30), interval integer, header varchar(100),footer varchar(100),"
                  "exmonth integer, exyear integer, status integer, device integer)");
    if( !qry.exec() )
          qDebug() << qry.lastError();
    else
          qDebug() << "Table settings created!";


/*
    qry.prepare("INSERT INTO settings ( id ,password, interval, header, footer, exmonth, exyear , status , device ) VALUES (1 , '123' , 3 , NULL , NULL , 12 , 2014 , 1 , 0)");
    if( !qry.exec() )
    {
           qDebug() << qry.lastError();
           qDebug("Insert setting fail");
    }
    else
           qDebug() << "Insert to settings pass";

    */

    qry.prepare( "CREATE TABLE IF NOT EXISTS admin (username varchar(30) primary key, password varchar(30))");
    if( !qry.exec() )
    {
          qDebug() << qry.lastError();
          qDebug() << "Table admin Error";
    }
    else
          qDebug() << "Table admin created!";

    /*
    qry.prepare("INSERT INTO admin ( username ,password ) VALUES ('user','password')");
    if( !qry.exec() )
    {
           qDebug() << qry.lastError();
           qDebug("Insert admin fail");
    }
    else
           qDebug() << "Insert to admin pass";

    */

    qry.prepare("SELECT header, footer FROM settings WHERE id=1");
        if(!qry.exec())
            qDebug("Error at prefer");
        else
        {
            qry.first();
            ui->header->setText(qry.value(0).toString());
            ui->footer->setText(qry.value(1).toString());
        }

    shortcut1= new QShortcut(QKeySequence("F1"), this);
    connect(shortcut1, SIGNAL(activated()), this, SLOT(on_settingsbutton_clicked()));
    shortcut2= new QShortcut(QKeySequence("F2"), this);
    connect(shortcut2, SIGNAL(activated()), this, SLOT(on_operatorbutton_clicked()));
    shortcut3= new QShortcut(QKeySequence("F3"), this);
    connect(shortcut3, SIGNAL(activated()), this, SLOT(on_startbutton_clicked()));
    shortcut4= new QShortcut(QKeySequence("F4"), this);
    connect(shortcut4, SIGNAL(activated()), this, SLOT(on_exitbutton_clicked()));
    shortcut5= new QShortcut(QKeySequence("F5"), this);
    connect(shortcut5, SIGNAL(activated()), this, SLOT(on_helpbutton_clicked()));

    ui->statusBar->showMessage("Select any Option");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_time()
{
    ui->datetimelabel->setText(QDate::currentDate().toString("d MMM yyyy")+ "    " + QTime::currentTime().toString("h:mm:ss ap"));
}

void MainWindow::on_settingsbutton_clicked()
{
    ui->statusBar->showMessage("Admin Login");
    Settings settings;
    settings.setModal(true);
    settings.exec();
    ui->statusBar->showMessage("Select any Option");
}

void MainWindow::on_operatorbutton_clicked()
{
    ui->statusBar->showMessage("Operator Menu");
    Operator operators;
    operators.setModal(true);
    operators.exec();
    ui->statusBar->showMessage("Select any Option");
}

void MainWindow::on_startbutton_clicked()
{
    ui->statusBar->showMessage("Operator Login");
    startweighing start;
    start.setModal(true);
    start.exec();
    ui->statusBar->showMessage("Select any Option");
}

void MainWindow::on_exitbutton_clicked()
{
    ui->statusBar->showMessage("Exit");
    QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this,"Confirm","    Do you want to exit?",QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::Yes)
            qApp->quit();
    ui->statusBar->showMessage("Select any Option");
}

void MainWindow::on_helpbutton_clicked()
{
    ui->statusBar->showMessage("Help");
    QMessageBox::information(this, "Help", "Please contact supplier for any kind of help");
    ui->statusBar->showMessage("Select any Option");
}
