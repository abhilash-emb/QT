#include "tabset.h"
#include "qextserialport.h"
#include "Header.h"

#include <QtSql>
#include <QtGui>
#include <QtCore>

TabSet::TabSet(QWidget *parent) : QDialog(parent)
{
    tabWidget = new QTabWidget;
    QDesktopWidget *desktop = QApplication::desktop();

    int screenWidth,screenHeight,x, y;;

        screenWidth = desktop->width();
        screenHeight = desktop->height();

        x = (screenWidth/2)-300;
        y = (screenHeight/2)-200;

        tabWidget->setWindowTitle("Settings");
        tabWidget->setWindowIcon(QIcon(":/new/resource/Settings.png"));
    tabWidget->move ( x, y );
    tabWidget->addTab(new CommunicationTab(), "Communication");
    tabWidget->addTab(new PreferencesTab(), "Preferences");
    tabWidget->addTab(new HeadFootTab(), "Header Footer");
    tabWidget->addTab(new ChPwdTab(), "Change Password");
    tabWidget->addTab(new DelRecordTab(), "Delete Record");
    tabWidget->addTab(new SetupTab(), "Set-Up");
    tabWidget->addTab(new LoadcellTab(), "Load Cell");
    tabWidget->setFixedSize(600,400);
    tabWidget->show();

    //qDebug()<<tabWidget->parent();
    //qDebug()<<TabSet::parent();
}

CommunicationTab::CommunicationTab(QWidget *parent)
    : QWidget(parent)
{
    db = QSqlDatabase::database("settingsdb");
    qry=QSqlQuery(db);
    qry1=QSqlQuery(db);
    qry1.prepare( "SELECT * FROM settings WHERE id = 1" );
     if( !qry1.exec() )
       qDebug() << qry1.lastError();
     else
     {
         qry1.first();
     }
     /*
     QString *COM1 = new QString("COM1");
     QString *COM2 = new QString("COM2");
     QString *COM3 = new QString("COM3");
     QString *COM4 = new QString("COM4");
     */
        QVBoxLayout *vlayout1 = new QVBoxLayout;
        QVBoxLayout *vlayout2 = new QVBoxLayout;
        QVBoxLayout *vlayout3 = new QVBoxLayout;

        QHBoxLayout *hlayoutlabel = new QHBoxLayout;
        QHBoxLayout *hlayout1 = new QHBoxLayout;
        QHBoxLayout *hlayout2 = new QHBoxLayout;
        QHBoxLayout *hlayout3 = new QHBoxLayout;
        QHBoxLayout *hlayout4 = new QHBoxLayout;
        QHBoxLayout *hlayout5 = new QHBoxLayout;
        QHBoxLayout *hlayout6 = new QHBoxLayout;
        QHBoxLayout *hlayout7 = new QHBoxLayout;
        QHBoxLayout *hlayout8 = new QHBoxLayout;
        QHBoxLayout *hlayout9 = new QHBoxLayout;

        QLabel *portlabel = new QLabel(tr("Port Number:"));

        portedit = new QLineEdit();
        portedit->setText(qry1.value(3).toString());
        portedit->setFixedWidth(85);

        hlayout1->addWidget(portlabel);
        hlayout1->addSpacing(45);
        hlayout1->addWidget(portedit);

        QLabel *baudlabel = new QLabel(tr("Baud Rate:"));
        baudbox = new QComboBox();
        baudbox->addItem("1200");//, BAUD1200);
        baudbox->addItem("2400");//, BAUD2400);
        baudbox->addItem("4800");//, BAUD4800);
        baudbox->addItem("9600");//, BAUD9600);
        baudbox->addItem("19200");//, BAUD19200);

        if(qry1.value(4).toInt() == 1200)
            baudbox->setCurrentIndex(0);
        else if(qry1.value(4).toInt() == 2400)
            baudbox->setCurrentIndex(1);
        else if(qry1.value(4).toInt() == 4800)
            baudbox->setCurrentIndex(2);
        else if(qry1.value(4).toInt() == 9600)
            baudbox->setCurrentIndex(3);
        else if(qry1.value(4).toInt() == 19200)
            baudbox->setCurrentIndex(4);

        baudbox->setFixedWidth(85);
        hlayout2->addWidget(baudlabel);
        hlayout2->addSpacing(30);
        hlayout2->addWidget(baudbox);


        QLabel *databitslabel = new QLabel(tr("Number of Bits:"));
        databitsbox = new QComboBox();
        databitsbox->addItem("5");//, DATA_5);
        databitsbox->addItem("6");//, DATA_6);
        databitsbox->addItem("7");//, DATA_7);
        databitsbox->addItem("8");//, DATA_8);

        if(qry1.value(5).toInt() == 5)
            databitsbox->setCurrentIndex(0);
        else if(qry1.value(5).toInt() == 6)
            databitsbox->setCurrentIndex(1);
        else if(qry1.value(5).toInt() == 7)
            databitsbox->setCurrentIndex(2);
        else if(qry1.value(5).toInt() == 8)
            databitsbox->setCurrentIndex(3);

        databitsbox->setFixedWidth(85);
        hlayout3->addWidget(databitslabel);
        hlayout3->addSpacing(30);
        hlayout3->addWidget(databitsbox);

        QString *none = new QString("NONE");
        QString *odd = new QString("ODD");
        QString *even = new QString("EVEN");

        QLabel *paritylabel = new QLabel(tr("Parity:"));
        paritybox = new QComboBox();
        paritybox->addItem("NONE");//, PAR_NONE);
        paritybox->addItem("ODD");//, PAR_ODD);
        paritybox->addItem("EVEN");//, PAR_EVEN);

        if(qry1.value(6).toString() == none)
            paritybox->setCurrentIndex(0);
        else if(qry1.value(6).toString() == odd)
            paritybox->setCurrentIndex(1);
        else if(qry1.value(6).toString() == even)
            paritybox->setCurrentIndex(2);

        paritybox->setFixedWidth(85);
        hlayout4->addWidget(paritylabel);
        hlayout4->addSpacing(30);
        hlayout4->addWidget(paritybox);



        QLabel *stopbitslabel = new QLabel(tr("No. of Stop Bits:"));
        stopbitsbox = new QComboBox();
        stopbitsbox->addItem("1");//, STOP_1);
        stopbitsbox->addItem("2");//, STOP_2);

        if(qry1.value(7).toInt() == 1)
            stopbitsbox->setCurrentIndex(0);
        else if(qry1.value(7).toInt() == 2)
            stopbitsbox->setCurrentIndex(1);

        stopbitsbox->setFixedWidth(85);

        hlayout5->addWidget(stopbitslabel);
        hlayout5->addSpacing(30);
        hlayout5->addWidget(stopbitsbox);

        QLabel *radiobuttonlabel = new QLabel(tr("TERMINATION"));
        radiobuttonlabel->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));// "termination" was here
        radiobutton1 = new QRadioButton(tr("CR"));
        radiobutton2 = new QRadioButton(tr("CR/LF"));

        if(qry1.value(8).toInt() == 0)
            radiobutton1->setChecked(1);
        else if(qry1.value(8).toInt() == 1)
            radiobutton2->setChecked(1);

        hlayout6->addWidget(radiobutton1,0,Qt::AlignHCenter);
        hlayout6->addSpacing(30);
        hlayout6->addWidget(radiobutton2,0,Qt::AlignHCenter);

        QLabel *DLClabel = new QLabel(tr("DLC PORT SETTINGS"));
        DLClabel->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
        DLClabel->setFixedWidth(160);

        hlayoutlabel->addStretch(1);
        hlayoutlabel->addWidget(DLClabel);
        hlayoutlabel->addStretch(1);

        vlayout1->addStretch(1);
        vlayout1->addLayout(hlayoutlabel);
        vlayout1->addSpacing(15);
        vlayout1->addLayout(hlayout1);
        vlayout1->addLayout(hlayout2);
        vlayout1->addLayout(hlayout3);
        vlayout1->addLayout(hlayout4);
        vlayout1->addLayout(hlayout5);
        vlayout1->addStretch(1);

        vlayout2->addStretch(1);
        vlayout2->addWidget(radiobuttonlabel,0,Qt::AlignBottom|Qt::AlignHCenter);
        vlayout2->addSpacing(20);
        vlayout2->addLayout(hlayout6);
        vlayout2->addStretch(1);

        hlayout7->addStretch(1);
        hlayout7->addLayout(vlayout2);
        hlayout7->addSpacing(50);
        hlayout7->addLayout(vlayout1);
        hlayout7->addStretch(1);

        QLabel *printer_port_label = new QLabel(tr("Printer port name "));
        printer_port_label->setFixedWidth(150);
        printer_port_label->setAlignment(Qt::AlignVCenter|Qt::AlignRight);
        printer_port_label->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));

        printer_portedit = new QLineEdit();
        printer_portedit->setFixedWidth(85);
        printer_portedit->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        printer_portedit->setText(qry1.value(30).toString());

        hlayout8->addStretch(1);
        hlayout8->addWidget(printer_port_label);
        hlayout8->addSpacing(10);
        hlayout8->addWidget(printer_portedit);
        hlayout8->addStretch(1);

        QPushButton *acceptbutton = new QPushButton(tr("Accept"));
        QPushButton *defaultbutton = new QPushButton(tr("Default"));
        acceptbutton->setFixedWidth(90);
        defaultbutton->setFixedWidth(90);

        hlayout9->addStretch(1);
        hlayout9->addWidget(acceptbutton);
        hlayout9->addSpacing(9);
        hlayout9->addWidget(defaultbutton);
        hlayout9->addStretch(1);

        vlayout3->setSpacing(1);
        vlayout3->addSpacing(10);
        vlayout3->addLayout(hlayout7);
        vlayout3->addSpacing(5);
        vlayout3->addLayout(hlayout8);
        vlayout3->addSpacing(32);
        vlayout3->addLayout(hlayout9);
        setLayout(vlayout3);

        connect(acceptbutton, SIGNAL(clicked()), this, SLOT(on_accept_click()));
        connect(defaultbutton, SIGNAL(clicked()), this , SLOT(on_default_click()));
 }

void CommunicationTab:: on_accept_click()
{
    qry.prepare( "UPDATE settings SET port=:port, baud=:baud, databits=:date, parity=:parity, stopbits=:stop, termination=:term, pr_port=:prport WHERE id = 1" );
    qry.bindValue(":port", portedit->text());
    qry.bindValue(":baud", baudbox->currentText().toInt());
    qry.bindValue(":data", databitsbox->currentText().toInt());
    qry.bindValue(":parity",paritybox->currentText());
    qry.bindValue(":stop", stopbitsbox->currentText());
    qry.bindValue(":prport",printer_portedit->text());

    if(radiobutton1->isChecked())
        qry.bindValue(":term",0);
    else
        qry.bindValue(":term",1);

    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
    {
        QMessageBox::information(this, "Info", "Settings Saved\nYou must restart application to make effect");
    }
}

void CommunicationTab:: on_default_click()
{
     portedit->setText("COM1");
     printer_portedit->setText("COM7");
     baudbox->setCurrentIndex(3);
     databitsbox->setCurrentIndex(3);
     paritybox->setCurrentIndex(0);
     stopbitsbox->setCurrentIndex(0);
     radiobutton2->setChecked(1);
}

PreferencesTab::PreferencesTab(QWidget *parent)
    : QWidget(parent)
{
    db = QSqlDatabase::database("settingsdb");
    qry=QSqlQuery(db);
    qry1=QSqlQuery(db);

    qry1.prepare( "SELECT prefer,maxlimit,freeweight FROM settings WHERE id = 1" );
     if( !qry1.exec() )
       qDebug() << qry1.lastError();
     else
     {
         qry1.first();
     }

    QVBoxLayout *vertical1 = new QVBoxLayout;
    QVBoxLayout *vertical2 = new QVBoxLayout;
    QVBoxLayout *vertical3 = new QVBoxLayout;

    QHBoxLayout *horizontal1 = new QHBoxLayout;
    QHBoxLayout *horizontal2 = new QHBoxLayout;
    QHBoxLayout *horizontal3 = new QHBoxLayout;
    QHBoxLayout *horizontal4 = new QHBoxLayout;
    QHBoxLayout *horizontal5 = new QHBoxLayout;

    save = new QPushButton(tr("Save"));
    save->setFixedWidth(90);

    reset = new QPushButton(tr("Reset"));
    reset->setFixedWidth(90);

    QLabel *radiobuttonlabel = new QLabel(tr("OPTIONS"));
    radiobuttonlabel->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));

    manualbutton = new QRadioButton(tr("Manual"));
    autobutton = new QRadioButton(tr("Auto"));

    if(qry1.value(0).toInt() == 0)
        manualbutton->setChecked(1);
    else if(qry1.value(0).toInt() == 1)
        autobutton->setChecked(1);

    QLabel *datalabel = new QLabel(tr("Max. Database limit"));
    QLabel *weightlabel = new QLabel(tr("Start Weight Display"));
    dataedit = new QLineEdit();
    weightedit = new QLineEdit();

    dataedit->setFixedWidth(75);
    dataedit->setAlignment(Qt::AlignHCenter);
    weightedit->setFixedWidth(75);
    weightedit->setAlignment(Qt::AlignHCenter);

    horizontal1->addWidget(manualbutton,0,Qt::AlignRight);
    horizontal1->addSpacing(50);
    horizontal1->addWidget(autobutton,0,Qt::AlignLeft);

    horizontal2->addStretch(1);
    horizontal2->addWidget(datalabel,0,Qt::AlignHCenter);
    horizontal2->addSpacing(10);
    horizontal2->addWidget(dataedit,0,Qt::AlignLeft);
    horizontal2->addStretch(1);

    horizontal3->addStretch(1);
    horizontal3->addWidget(weightlabel,0,Qt::AlignHCenter);
    horizontal3->addSpacing(10);
    horizontal3->addWidget(weightedit,0,Qt::AlignLeft);
    horizontal3->addStretch(1);

    vertical1->addStretch(1);
    vertical1->addLayout(horizontal2);
    vertical1->addStretch(1);

    vertical2->addStretch(1);
    vertical2->addLayout(horizontal3);
    vertical2->addStretch(1);

    horizontal4->addStretch(1);
    horizontal4->addLayout(vertical1);
    horizontal4->addSpacing(60);
    horizontal4->addLayout(vertical2);
    horizontal4->addStretch(1);

    horizontal5->addStretch(1);
    horizontal5->addWidget(save);
    horizontal5->addSpacing(9);
    horizontal5->addWidget(reset);
    horizontal5->addStretch(1);

    vertical3->setSpacing(1);
    vertical3->addSpacing(60);
    vertical3->addWidget(radiobuttonlabel,0,Qt::AlignHCenter);
    vertical3->addSpacing(20);
    vertical3->addLayout(horizontal1);
    vertical3->addSpacing((40));
    vertical3->addLayout(horizontal4);
    vertical3->addSpacing((137));
    vertical3->addLayout(horizontal5);
    vertical3->addStretch(1);

    setLayout(vertical3);

    dataedit->setText(qry1.value(1).toString());
    weightedit->setText(qry1.value(2).toString());

    connect(save,SIGNAL(clicked()),this,SLOT(on_save_click()));


}

void PreferencesTab :: on_save_click()
{
    qry.prepare( "UPDATE settings SET prefer=:prefer,maxlimit=:maxlimit,freeweight=:free WHERE id = 1" );
    if(manualbutton->isChecked())
        qry.bindValue(":prefer",0);
    else
        qry.bindValue(":prefer",1);
    qry.bindValue(":maxlimit",dataedit->text().toInt());
    qry.bindValue(":free",weightedit->text().toInt());

    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
    {

        QMessageBox::information(this, "Info", "Preference Saved\nYou must restart application to make effect");
    }
}

HeadFootTab::HeadFootTab(QWidget *parent)
    : QWidget(parent)
{
    db = QSqlDatabase::database("settingsdb");
    qry=QSqlQuery(db);

    QHBoxLayout *horizontal1 = new QHBoxLayout;
    QHBoxLayout *horizontal2 = new QHBoxLayout;
    QVBoxLayout *mainLayout = new QVBoxLayout;


    QLabel *headerlabel = new QLabel(tr("Header Name:"));
    headernameedit = new QLineEdit();
    headernameedit->setFixedWidth(300);
    horizontal1->addStretch(1);
    horizontal1->addWidget(headerlabel);
    horizontal1->addWidget(headernameedit);
    horizontal1->addStretch(1);

    QLabel *footerlabel = new QLabel(tr("Footer Name :"));
    footernameedit = new QLineEdit();
    footernameedit->setFixedWidth(300);
    horizontal2->addStretch(1);
    horizontal2->addWidget(footerlabel);
    horizontal2->addWidget(footernameedit);
    horizontal2->addStretch(1);

    QPushButton *setbutton = new QPushButton(tr("Set"));
    setbutton->setFixedWidth(90);



        mainLayout->setSpacing(15);
        mainLayout->addSpacing(60);
        mainLayout->addLayout(horizontal1);
        mainLayout->addLayout(horizontal2);
        mainLayout->addSpacing(53);
        mainLayout->addWidget(setbutton,0,Qt::AlignHCenter);
        mainLayout->addStretch(1);
        setLayout(mainLayout);
        connect(setbutton,SIGNAL(clicked()),this,SLOT(on_setbutton_click()));

        qry.prepare( "SELECT header, footer FROM settings WHERE id = 1" );
        if( !qry.exec() )
            qDebug() << qry.lastError();
        else
        {
            qry.first();
            headernameedit->setText(qry.value(0).toString());
            footernameedit->setText(qry.value(1).toString());
        }
}

void HeadFootTab ::on_setbutton_click()
{
    qry.prepare( "UPDATE settings SET header=:header, footer=:footer WHERE id = 1" );
    qry.bindValue(":header",headernameedit->text());
    qry.bindValue(":footer",footernameedit->text());

    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
    {
        QMessageBox::information(this, "Info", "Header/Footer Saved\nYou must restart application to make effect");
    }
}

ChPwdTab::ChPwdTab(QWidget *parent)
    : QWidget(parent)
{
    db = QSqlDatabase::database("settingsdb");
    qry=QSqlQuery(db);

    QHBoxLayout *horizontal1 = new QHBoxLayout;
    QHBoxLayout *horizontal2 = new QHBoxLayout;
    QVBoxLayout *mainLayout = new QVBoxLayout;

    QLabel *oldpasslabel = new QLabel(tr("Old  Password:"));
    oldpassedit = new QLineEdit();
    oldpassedit->setEchoMode(QLineEdit::Password);
    oldpassedit->setAlignment(Qt::AlignCenter);
    oldpassedit->setFixedWidth(300);
    horizontal1->addStretch(1);
    horizontal1->addWidget(oldpasslabel);
    horizontal1->addWidget(oldpassedit);
    horizontal1->addStretch(1);

    QLabel *newpasslabel = new QLabel(tr("New Password:"));
    newpassedit = new QLineEdit();
    newpassedit->setEchoMode(QLineEdit::Password);
    newpassedit->setAlignment(Qt::AlignCenter);
    newpassedit->setFixedWidth(300);
    horizontal2->addStretch(1);
    horizontal2->addWidget(newpasslabel);
    horizontal2->addWidget(newpassedit);
    horizontal2->addStretch(1);

    status =new QLabel (tr(""));
    status->setFont(QFont( "serif", 11, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));

    changebutton = new QPushButton(tr("Change"));
    changebutton->setFixedWidth(90);


        mainLayout->setSpacing(15);
        mainLayout->addSpacing(60);
        mainLayout->addLayout(horizontal1);
        mainLayout->addLayout(horizontal2);
        mainLayout->addSpacing(10);
        mainLayout->addWidget(status,0,Qt::AlignHCenter);
        mainLayout->addSpacing(10);
        mainLayout->addWidget(changebutton,0,Qt::AlignHCenter);
        mainLayout->addStretch(1);
        setLayout(mainLayout);

        qry.prepare("SELECT pass, date FROM settings WHERE id = 1");
        if( !qry.exec() )
          qDebug() << qry.lastError();
        else
            qDebug( "Executed" );

        while (qry.next())
        {
           status->setText("Last changed on "+qry.value(1).toString());
           qDebug( "while" );
        }


        //connect(loginbutton, SIGNAL(clicked()), this, SLOT(loginbutton_click()));
        connect(changebutton, SIGNAL(clicked()), this , SLOT(on_changebutton_click()));
}

void ChPwdTab :: on_changebutton_click()
{
    QString word;
    if(!oldpassedit->text().isEmpty() && !newpassedit->text().isEmpty())
    {
        qry.prepare("SELECT pass, date FROM settings WHERE id = 1");
        if( !qry.exec() )
            qDebug() << qry.lastError();
        else
        {
            qDebug( "Executed" );
            qry.first();
            word = qry.value(0).toString();
        }

        if(oldpassedit->text() == word)
        {
            qry.prepare( "UPDATE settings SET pass =:pass, date =:date WHERE id = 1" );
            qry.bindValue(":pass", newpassedit->text());
            qry.bindValue(":date",QDate::currentDate().toString("d/M/yy")+" at "+QTime::currentTime().toString("h:mm ap"));
              if( !qry.exec() )
                qDebug() << qry.lastError();
              else
              {
                qDebug( "Updated!" );
                status->setText("Password Changed on "+QDate::currentDate().toString("d/M/yy")+" at "+QTime::currentTime().toString("h:mm ap"));
                oldpassedit->clear();
                newpassedit->clear();
              }
        }
        else
        {
            QMessageBox::critical(this, "Password Error", "Old password you've entered is incorrect");
            oldpassedit->clear();
            newpassedit->clear();
        }
    }
    else
        QMessageBox::critical(this, "Empty", "Password Fields are Empty");


}


DelRecordTab::DelRecordTab(QWidget *parent)
    : QWidget(parent)
{

    QLabel *passwordlabel = new QLabel(tr("Password:"));
    passwordedit = new QLineEdit();
    passwordedit->setEchoMode(QLineEdit::Password);
    passwordedit->setFixedWidth(300);

    loginbutton = new QPushButton(tr("Login"));
    loginbutton->setFixedWidth(75);

    logoutbutton = new QPushButton(tr("Logout"));
    logoutbutton->setFixedWidth(75);

    QLabel *recieptlabel = new QLabel(tr("Reciept No:"));
    recieptedit = new QLineEdit();
    recieptedit->setFixedWidth(300);

    checkbutton = new QPushButton(tr("Check"));
    checkbutton->setFixedWidth(75);

    deletebutton = new QPushButton(tr("Delete"));
    deletebutton->setFixedWidth(75);

    QLabel *detaillabel = new QLabel(tr("Reciept Details:"));
    detailtextedit =new QPlainTextEdit();
    //detailtextedit->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //setFixedSize(455,250);

    recieptedit->setDisabled(1);
    checkbutton->setDisabled(1);
    deletebutton->setDisabled(1);
    detailtextedit->setDisabled(1);
    logoutbutton->setDisabled(1);

    QHBoxLayout *mainHLayout1 = new QHBoxLayout;
    QHBoxLayout *mainHLayout2= new QHBoxLayout;
    QVBoxLayout *mainVLayout = new QVBoxLayout;


        mainHLayout1->addWidget(passwordedit,0,Qt::AlignLeft);
        mainHLayout1->addWidget(loginbutton,0,Qt::AlignLeft);
        mainHLayout1->addWidget(logoutbutton,0,Qt::AlignLeft);
        mainHLayout1->addStretch(1);

        mainHLayout2->addWidget(recieptedit,0,Qt::AlignLeft);
        mainHLayout2->addWidget(checkbutton,0,Qt::AlignLeft);
        mainHLayout2->addWidget(deletebutton,0,Qt::AlignLeft);
        mainHLayout2->addStretch(1);

        mainVLayout->setSpacing(3);
        //mainVLayout->addStretch(1);
        mainVLayout->addWidget(passwordlabel);
        mainVLayout->addLayout(mainHLayout1);
        mainVLayout->addWidget(recieptlabel);
        mainVLayout->addLayout(mainHLayout2);
        mainVLayout->addWidget(detaillabel);
        mainVLayout->addWidget(detailtextedit);
       // mainVLayout->addStretch(1);

        setLayout(mainVLayout);

        connect(loginbutton, SIGNAL(clicked()), this, SLOT(on_loginbutton_click()));
        connect(logoutbutton, SIGNAL(clicked()), this, SLOT(on_logoutbutton_click()));
        connect(checkbutton,SIGNAL(clicked()),this,SLOT(on_checkbutton_click()));
        connect(deletebutton,SIGNAL(clicked()),this,SLOT(on_deletebutton_click()));
}
void DelRecordTab :: on_checkbutton_click()
{
    db = QSqlDatabase :: database("detailsdb");
    qry = QSqlQuery(db);
    int f=0;

    qry.prepare("SELECT * FROM details WHERE bill = :bill");
    qry.bindValue(":bill",recieptedit->text().toInt());
    if( !qry.exec() )
    {
      qDebug() << qry.lastError();
      qDebug()<<"Error at print ticket";

    }
    else
    {
        qDebug( "Executed" );
        detailtextedit->clear();
        while (qry.next())
        {
            f=1;
            deletebutton->setEnabled(1);
            detailtextedit->insertPlainText("Bill No\t: "+qry.value(0).toString()+"\t\t"+"Vehicle No\t: "+qry.value(1).toString()+"\n");
            detailtextedit->insertPlainText("Customer\t: "+qry.value(3).toString()+"\t\t"+"Material\t: "+qry.value(4).toString()+"\n");
            detailtextedit->insertPlainText("-------------------------------------------------------------------------------------------------------------\n\n\n");
            detailtextedit->insertPlainText("Challan No\t: "+qry.value(2).toString()+"\t\t"+"Charge\t: "+qry.value(5).toString()+"\n\n");
            detailtextedit->insertPlainText("Date1\t: "+qry.value(7).toString()+"\t\t"+"Date2\t: "+qry.value(10).toString()+"\n");
            detailtextedit->insertPlainText("Time1\t: "+qry.value(8).toString()+"\t\t"+"Time2\t: "+qry.value(11).toString()+"\n\n");
            detailtextedit->insertPlainText("Tare Wght\t: "+qry.value(6).toString()+"\n");
            detailtextedit->insertPlainText("Gross Wght\t: "+qry.value(9).toString()+"\n");
            detailtextedit->insertPlainText("Net Wght\t: "+qry.value(12).toString()+"\n\n\n");
            detailtextedit->insertPlainText("Total Chrg\t: "+qry.value(13).toString()+"\n");

        }

     }
    if(f==0)
    {
        QMessageBox::critical(this, "Invalid Reciept Number", "Reciept number doesn't Exists");
        recieptedit->clear();
        deletebutton->setDisabled(1);
    }
}


void DelRecordTab :: on_deletebutton_click()
{
    db = QSqlDatabase :: database("detailsdb");
    qry = QSqlQuery(db);

    qry.prepare( "DELETE FROM details WHERE bill = :bill" );
    qry.bindValue(":bill",recieptedit->text().toInt());
      if( !qry.exec() )
      {
        qDebug() << qry.lastError();
        detailtextedit->clear();
        detailtextedit->insertPlainText("\n\n\t\tRecord Not found !!\n");
      }
      else
        {
            qDebug( "Deleted!" );
            detailtextedit->clear();
            detailtextedit->insertPlainText("\n\n\t\tRecord Deleted !!\n");
        }

}
void DelRecordTab::on_loginbutton_click()
{

    QSqlDatabase db = QSqlDatabase::database("settingsdb");
    QString word;

    QSqlQuery qry(db);

    qry.prepare("SELECT pass FROM settings WHERE id = 1");
    if( !qry.exec() )
      qDebug() << qry.lastError();
    else
        qDebug( "Executed" );

    while (qry.next())
    {
       word = qry.value(0).toString();
       qDebug( "while" );
    }

    if(passwordedit->text() == word)
    {
        recieptedit->setEnabled(1);
        checkbutton->setEnabled(1);
        detailtextedit->setEnabled(1);
        logoutbutton->setEnabled(1);
        loginbutton->setDisabled(1);
    }
    else
    {
        QMessageBox::critical(this, "Password Error", "You have entered wrong password !!!");
        passwordedit->clear();
    }

}

void DelRecordTab::on_logoutbutton_click()
{
    recieptedit->clear();
    detailtextedit->clear();
    passwordedit->clear();
    recieptedit->setDisabled(1);
    checkbutton->setDisabled(1);
    deletebutton->setDisabled(1);
    detailtextedit->setDisabled(1);
    logoutbutton->setDisabled(1);
    loginbutton->setEnabled(1);
}

SetupTab::SetupTab(QWidget *parent)
    : QWidget(parent)
{
    db  = QSqlDatabase::database("settingsdb");
    qry = QSqlQuery(db);

    qry.prepare("SELECT setup_resolution FROM settings WHERE id = 1");
    if( !qry.exec() )
      qDebug() << qry.lastError();
    else
    {
        qDebug( "Executed" );
        qry.first();
    }

    QHBoxLayout *horizontal0 = new QHBoxLayout;
    QHBoxLayout *horizontal1 = new QHBoxLayout;
    QHBoxLayout *horizontal2 = new QHBoxLayout;
    QHBoxLayout *horizontal3 = new QHBoxLayout;
    QHBoxLayout *horizontal4 = new QHBoxLayout;
    QHBoxLayout *horizontal5 = new QHBoxLayout;
    QHBoxLayout *horizontal6 = new QHBoxLayout;


    QVBoxLayout *vertical1 = new QVBoxLayout;
    QVBoxLayout *vertical2 = new QVBoxLayout;
    QVBoxLayout *mainLayout = new QVBoxLayout;

    QLabel *resolution_label = new QLabel(tr("Resolution :"));
    resolution_label->setFixedWidth(60);
    resolution_combobox = new QComboBox();
    resolution_combobox->addItem("1");
    resolution_combobox->addItem("2");
    resolution_combobox->addItem("5");
    resolution_combobox->addItem("10");
    resolution_combobox->addItem("20");
    resolution_combobox->addItem("50");
    resolution_combobox->setFixedWidth(60);

    if(qry.value(0).toInt() == 1)
        resolution_combobox->setCurrentIndex(0);
    else if(qry.value(0).toInt() == 2)
        resolution_combobox->setCurrentIndex(1);
    else if(qry.value(0).toInt() == 5)
        resolution_combobox->setCurrentIndex(2);
    else if(qry.value(0).toInt() == 10)
        resolution_combobox->setCurrentIndex(3);
    else if(qry.value(0).toInt() == 20)
        resolution_combobox->setCurrentIndex(4);
    else if(qry.value(0).toInt() == 50)
        resolution_combobox->setCurrentIndex(5);

    horizontal0->addStretch(1);
    horizontal0->addWidget(resolution_label);
    horizontal0->addSpacing(10);
    horizontal0->addWidget(resolution_combobox);
    horizontal0->addStretch(1);

    vertical1->addStretch(1);
    vertical1->addLayout(horizontal0);
    vertical1->addSpacing(65);

    QLabel *calib_label = new QLabel(tr("CALIBRATION"));
    calib_label->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
    calib_label->setFixedWidth(120);
    calib_label->setAlignment(Qt::AlignRight);

    horizontal1->addStretch(1);
    horizontal1->addWidget(calib_label,0,Qt::AlignCenter);
    horizontal1->addStretch(1);

    QLabel *oldweight_label = new QLabel(tr("Old Weight"));
    oldweight_label->setFont(QFont( "serif", 8, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
    oldweight_label->setFixedWidth(60);
    oldweight_label->setAlignment(Qt::AlignLeft);

    QLabel *newweight_label = new QLabel(tr("New Weight"));
    newweight_label->setFont(QFont( "serif", 8, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
    newweight_label->setFixedWidth(66);
    newweight_label->setAlignment(Qt::AlignLeft);

    //horizontal2->addStretch(1);
    horizontal2->addSpacing(104);
    horizontal2->addWidget(oldweight_label);
    horizontal2->addSpacing(6);
    horizontal2->addWidget(newweight_label);
    horizontal2->addStretch(1);

    smart_button = new QPushButton(tr("Smart Calibration"));
    smart_button->setFixedWidth(90);
    Oldweight_edit = new QLineEdit();
    Oldweight_edit->setFixedWidth(60);
    Oldweight_edit->setAlignment(Qt::AlignCenter|Qt::AlignHCenter);
    Newweight_edit = new QLineEdit();
    Newweight_edit->setFixedWidth(60);
    Newweight_edit->setAlignment(Qt::AlignCenter|Qt::AlignHCenter);

    reset_calib_button = new QPushButton(tr("Reset calibration"));
    reset_calib_button->setFixedWidth(90);

    //horizontal3->addStretch(1);
    horizontal3->addWidget(smart_button);
    horizontal3->addSpacing(10);
    horizontal3->addWidget(Oldweight_edit);
    horizontal3->addSpacing(5);
    horizontal3->addWidget(Newweight_edit);
    horizontal3->addStretch(1);


    //horizontal4->addStretch(1);
    horizontal4->addWidget(reset_calib_button);
    horizontal4->addSpacing(60);
    horizontal4->addSpacing(60);
    horizontal4->addStretch(1);

    vertical2->addStretch(1);
    vertical2->addLayout(horizontal1);
    vertical2->addSpacing(35);
    vertical2->addLayout(horizontal2);
    vertical2->addSpacing(1);
    vertical2->addLayout(horizontal3);
    vertical2->addSpacing(1);
    vertical2->addLayout(horizontal4);
    vertical2->addStretch(1);

    horizontal5->addStretch(1);
    horizontal5->addLayout(vertical1);
    horizontal5->addSpacing(60);
    horizontal5->addLayout(vertical2);
    horizontal5->addStretch(1);

    save_button = new QPushButton(tr("Save"));
    save_button->setFixedWidth(90);
    reset_button = new QPushButton(tr("Reset"));
    reset_button->setFixedWidth(90);

    horizontal6->addStretch(1);
    horizontal6->addWidget(save_button);
    horizontal6->addSpacing(5);
    horizontal6->addWidget(reset_button);
    horizontal6->addStretch(1);

    mainLayout->addSpacing(30);
    mainLayout->addLayout(horizontal5);
    mainLayout->addSpacing(80);
    mainLayout->addLayout(horizontal6);
    mainLayout->addSpacing(23);
    //mainLayout->addStretch(1);

    setLayout(mainLayout);

        connect(save_button, SIGNAL(clicked()), this, SLOT(on_save_button_click()));
        connect(reset_button, SIGNAL(clicked()), this, SLOT(on_reset_button_click()));
        connect(smart_button, SIGNAL(clicked()), this, SLOT(on_smart_button_click()));
        connect(reset_calib_button, SIGNAL(clicked()), this, SLOT(on_reset_calib_button_click()));
}

void SetupTab :: on_smart_button_click()
{
    float calib = 0.0;

    calib = ((Newweight_edit->text().toFloat())/(Oldweight_edit->text().toFloat()));

    qry.prepare("UPDATE settings SET setup_Calib = :caliber WHERE id = 1");
    qry.bindValue(":caliber", calib);
    if( !qry.exec() )
      qDebug() << qry.lastError();
    else
    {
        qDebug( "Executed" );
        QMessageBox::information(this, "Info", "Calibration Updated\nYou must restart application to make effect");
    }
}

void SetupTab :: on_reset_calib_button_click()
{
    qry.prepare("UPDATE settings SET setup_Calib = 1 WHERE id = 1");
    if( !qry.exec() )
      qDebug() << qry.lastError();
    else
    {
        qDebug( "Executed" );
        QMessageBox::information(this, "Info", "Calibration Reset Successful\nYou must restart application to make effect");
    }
}

void SetupTab :: on_save_button_click()
{
    int value = 0;

    if(resolution_combobox->currentIndex() == 0)
        value = 1;
    else if(resolution_combobox->currentIndex() == 1)
        value = 2;
    else if(resolution_combobox->currentIndex() == 2)
        value = 5;
    else if(resolution_combobox->currentIndex() == 3)
        value = 10;
    else if(resolution_combobox->currentIndex() == 4)
        value = 20;
    else if(resolution_combobox->currentIndex() == 5)
        value = 50;

    qry.prepare("UPDATE settings SET setup_resolution =:resolution WHERE id = 1");
    qry.bindValue(":resolution", value);
    if( !qry.exec() )
      qDebug() << qry.lastError();
    else
    {
        qDebug( "Executed" );
        QMessageBox::information(this, "Info", "Resolution Upadted\nYou must restart application to make effect");
    }
}


void SetupTab :: on_reset_button_click()
{
    qry.prepare("SELECT setup_resolution FROM settings WHERE id = 1");
    if( !qry.exec() )
      qDebug() << qry.lastError();
    else
    {
        qDebug( "Executed" );
        qry.first();
    }

    if(qry.value(0).toInt() == 1)
        resolution_combobox->setCurrentIndex(0);
    else if(qry.value(0).toInt() == 2)
        resolution_combobox->setCurrentIndex(1);
    else if(qry.value(0).toInt() == 5)
        resolution_combobox->setCurrentIndex(2);
    else if(qry.value(0).toInt() == 10)
        resolution_combobox->setCurrentIndex(3);
    else if(qry.value(0).toInt() == 20)
        resolution_combobox->setCurrentIndex(4);
    else if(qry.value(0).toInt() == 50)
        resolution_combobox->setCurrentIndex(5);

}

LoadcellTab::LoadcellTab(QWidget *parent)
    : QWidget(parent)
{
    db  = QSqlDatabase::database("settingsdb");
    qry = QSqlQuery(db);

    PortSettings portsettings = {BAUD9600, DATA_8, PAR_NONE, STOP_1, FLOW_OFF, 10};
    port = new QextSerialPort("COM1", portsettings, QextSerialPort::Polling);

    qry.prepare("SELECT port,baud,databits, parity,stopbits,termination,loadcell_DLCs,DLC1_offset,DLC2_offset,DLC3_offset,DLC4_offset,DLC5_offset,DLC6_offset,DLC7_offset,DLC8_offset FROM settings WHERE id = 1");
    if( !qry.exec() )
      qDebug() << qry.lastError();
    else
    {
        qDebug( "Executed" );
        qry.first();

        port->setPortName(qry.value(0).toString());

            if(qry.value(1).toInt() == 1200)
            {
                port->setBaudRate((BaudRateType)qry.value(1).toInt());
            }
            else if(qry.value(1).toInt() == 2400)
            {
                port->setBaudRate((BaudRateType)qry.value(1).toInt());
            }
            else if(qry.value(1).toInt() == 4800)
            {
                port->setBaudRate((BaudRateType)qry.value(1).toInt());
            }
            else if(qry.value(1).toInt() == 9600)
            {
                port->setBaudRate((BaudRateType)qry.value(1).toInt());
            }
            else if(qry.value(1).toInt() == 19200)
            {
                port->setBaudRate((BaudRateType)qry.value(1).toInt());
            }

            if(qry.value(2).toInt() == 5)
            {
                port->setDataBits((DataBitsType)qry.value(2).toInt());
            }
            else if(qry.value(2).toInt() == 6)
            {
                port->setDataBits((DataBitsType)qry.value(2).toInt());
            }
            else if(qry.value(2).toInt() == 7)
            {
                port->setDataBits((DataBitsType)qry.value(2).toInt());
            }
            else if(qry.value(2).toInt() == 8)
            {
                port->setDataBits((DataBitsType)qry.value(2).toInt());
            }

            QString *none = new QString("NONE");
            QString *odd = new QString("ODD");
            QString *even = new QString("EVEN");

            if(qry.value(3).toString() == none)
            {
                port->setParity((ParityType)qry.value(3).toString().toInt());
            }
            else if(qry.value(3).toString() == odd)
            {
                port->setParity((ParityType)qry.value(3).toString().toInt());
            }

            else if(qry.value(3).toString() == even)
            {
                port->setParity((ParityType)qry.value(3).toString().toInt());
            }

            if(qry.value(4).toInt() == 1)
            {
                port->setStopBits((StopBitsType)qry.value(4).toInt());
            }
            else if(qry.value(4).toInt() == 2)
            {
                port->setStopBits((StopBitsType)qry.value(4).toInt());
            }

    }

    if (!port->isOpen())
    {
         port->open(QIODevice::ReadWrite);
    }

    QHBoxLayout *horizontal0 = new QHBoxLayout;
    QHBoxLayout *horizontal1 = new QHBoxLayout;
    QHBoxLayout *horizontal2 = new QHBoxLayout;
    QHBoxLayout *horizontal3 = new QHBoxLayout;
    QHBoxLayout *horizontal4 = new QHBoxLayout;
    QHBoxLayout *horizontal5 = new QHBoxLayout;
    QHBoxLayout *horizontal6 = new QHBoxLayout;
    QHBoxLayout *horizontal7 = new QHBoxLayout;
    QHBoxLayout *horizontal8 = new QHBoxLayout;
    QHBoxLayout *horizontal9 = new QHBoxLayout;
    QHBoxLayout *horizontal10 = new QHBoxLayout;
    QHBoxLayout *horizontal11 = new QHBoxLayout;

    QVBoxLayout *mainLayout = new QVBoxLayout;

    QLabel *cell_label = new QLabel(tr("TOTAL NUMBER OF DLCs"));
    cell_label->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
    cell_label->setFixedWidth(250);
    cell_label->setAlignment(Qt::AlignHCenter);

    horizontal0->addStretch(1);
    horizontal0->addWidget(cell_label);
    horizontal0->addStretch(1);

    one_radiobutton = new QRadioButton(tr("1"));
    one_radiobutton->setFixedWidth(48);
    two_radiobutton = new QRadioButton(tr("2"));
    two_radiobutton->setFixedWidth(48);
    four_radiobutton = new QRadioButton(tr("4"));
    four_radiobutton->setFixedWidth(48);
    six_radiobutton = new QRadioButton(tr("6"));
    six_radiobutton->setFixedWidth(50);
    eight_radiobutton = new QRadioButton(tr("8"));
    eight_radiobutton->setFixedWidth(30);

    if(qry.value(6).toInt() == 1)
        one_radiobutton->setChecked(1);
    else if(qry.value(6).toInt() == 2)
        two_radiobutton->setChecked(1);
    else if(qry.value(6).toInt() == 4)
        four_radiobutton->setChecked(1);
    else if(qry.value(6).toInt() == 6)
        six_radiobutton->setChecked(1);
    else if(qry.value(6).toInt() == 8)
        eight_radiobutton->setChecked(1);

    horizontal1->addStretch(1);
    horizontal1->addWidget(one_radiobutton);
    horizontal1->addWidget(two_radiobutton);
    horizontal1->addWidget(four_radiobutton);
    horizontal1->addWidget(six_radiobutton);
    horizontal1->addWidget(eight_radiobutton);
    horizontal1->addStretch(1);

    QLabel *DLC_Label = new QLabel(tr("DLC"));
    DLC_Label->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
    DLC_Label->setFixedWidth(70);
    DLC_Label->setAlignment(Qt::AlignHCenter);
    QLabel *Offset_Label = new QLabel(tr("OFFSET"));
    Offset_Label->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
    Offset_Label->setFixedWidth(70);
    Offset_Label->setAlignment(Qt::AlignHCenter);
    QLabel *Count_Label = new QLabel(tr("COUNT"));
    Count_Label->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
    Count_Label->setFixedWidth(70);
    Count_Label->setAlignment(Qt::AlignHCenter);
    QLabel *Status_Label = new QLabel(tr("STATUS"));
    Status_Label->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
    Status_Label->setFixedWidth(70);
    Status_Label->setAlignment(Qt::AlignHCenter);

    horizontal2->addStretch(1);
    horizontal2->addWidget(DLC_Label);
    horizontal2->addSpacing(70);
    horizontal2->addSpacing(20);
    horizontal2->addWidget(Offset_Label);
    horizontal2->addSpacing(30);
    horizontal2->addWidget(Count_Label);
    horizontal2->addSpacing(30);
    horizontal2->addWidget(Status_Label);
    horizontal2->addStretch(1);

    DLC1_Label = new QLabel(tr("DLC 1"));
    DLC1_Label->setFixedWidth(70);
    DLC1_Label->setAlignment(Qt::AlignHCenter|Qt::AlignCenter);
    DLC1_Label->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
    register_DLC1_button = new QPushButton(tr("Register"));
    register_DLC1_button->setFixedWidth(70);
    DLC1_offset = new QComboBox();
    DLC1_offset->addItem("1");
    DLC1_offset->addItem("2");
    DLC1_offset->addItem("5");
    DLC1_offset->addItem("10");
    DLC1_offset->addItem("20");
    DLC1_offset->setFixedWidth(70);
    DLC1_Count_Label = new QLabel(tr(" "));
    DLC1_Count_Label->setFixedWidth(70);
    DLC1_Count_Label->setAlignment(Qt::AlignLeft|Qt::AlignCenter);
    DLC1_status = new QLabel(tr("--"));
    DLC1_status->setFixedWidth(70);
    DLC1_status->setAlignment(Qt::AlignLeft|Qt::AlignCenter);

    if(qry.value(7) == 0)
        DLC1_offset->setCurrentIndex(0);
    else if(qry.value(7) == 1)
        DLC1_offset->setCurrentIndex(1);
    else if(qry.value(7) == 2)
        DLC1_offset->setCurrentIndex(2);
    else if(qry.value(7) == 3)
        DLC1_offset->setCurrentIndex(3);
    else if(qry.value(7) == 4)
        DLC1_offset->setCurrentIndex(4);

    horizontal3->addStretch(1);
    horizontal3->addWidget(DLC1_Label);
    horizontal3->addWidget(register_DLC1_button);
    horizontal3->addSpacing(20);
    horizontal3->addWidget(DLC1_offset);
    horizontal3->addSpacing(30);
    horizontal3->addWidget(DLC1_Count_Label);
    horizontal3->addSpacing(30);
    horizontal3->addWidget(DLC1_status);
    horizontal3->addStretch(1);

    DLC2_Label = new QLabel(tr("DLC 2"));
    DLC2_Label->setFixedWidth(70);
    DLC2_Label->setAlignment(Qt::AlignHCenter|Qt::AlignCenter);
    DLC2_Label->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
    register_DLC2_button = new QPushButton(tr("Register"));
    register_DLC2_button->setFixedWidth(70);
    DLC2_offset = new QComboBox();
    DLC2_offset->addItem("1");
    DLC2_offset->addItem("2");
    DLC2_offset->addItem("5");
    DLC2_offset->addItem("10");
    DLC2_offset->addItem("20");
    DLC2_offset->setFixedWidth(70);
    DLC2_Count_Label = new QLabel(tr(" "));
    DLC2_Count_Label->setFixedWidth(70);
    DLC2_Count_Label->setAlignment(Qt::AlignLeft|Qt::AlignCenter);
    DLC2_status = new QLabel(tr("--"));
    DLC2_status->setFixedWidth(70);
    DLC2_status->setAlignment(Qt::AlignLeft|Qt::AlignCenter);

    if(qry.value(8) == 0)
        DLC2_offset->setCurrentIndex(0);
    else if(qry.value(8) == 1)
        DLC2_offset->setCurrentIndex(1);
    else if(qry.value(8) == 2)
        DLC2_offset->setCurrentIndex(2);
    else if(qry.value(8) == 3)
        DLC2_offset->setCurrentIndex(3);
    else if(qry.value(8) == 4)
        DLC2_offset->setCurrentIndex(4);

    horizontal4->addStretch(1);
    horizontal4->addWidget(DLC2_Label);
    horizontal4->addWidget(register_DLC2_button);
    horizontal4->addSpacing(20);
    horizontal4->addWidget(DLC2_offset);
    horizontal4->addSpacing(30);
    horizontal4->addWidget(DLC2_Count_Label);
    horizontal4->addSpacing(30);
    horizontal4->addWidget(DLC2_status);
    horizontal4->addStretch(1);

    DLC3_Label = new QLabel(tr("DLC 3"));
    DLC3_Label->setFixedWidth(70);
    DLC3_Label->setAlignment(Qt::AlignHCenter|Qt::AlignCenter);
    DLC3_Label->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
    register_DLC3_button = new QPushButton(tr("Register"));
    register_DLC3_button->setFixedWidth(70);
    DLC3_offset = new QComboBox();
    DLC3_offset->addItem("1");
    DLC3_offset->addItem("2");
    DLC3_offset->addItem("5");
    DLC3_offset->addItem("10");
    DLC3_offset->addItem("20");
    DLC3_offset->setFixedWidth(70);
    DLC3_Count_Label = new QLabel(tr(" "));
    DLC3_Count_Label->setFixedWidth(70);
    DLC3_Count_Label->setAlignment(Qt::AlignLeft|Qt::AlignCenter);
    DLC3_status = new QLabel(tr("--"));
    DLC3_status->setFixedWidth(70);
    DLC3_status->setAlignment(Qt::AlignLeft|Qt::AlignCenter);

    if(qry.value(9) == 0)
        DLC3_offset->setCurrentIndex(0);
    else if(qry.value(9) == 1)
        DLC3_offset->setCurrentIndex(1);
    else if(qry.value(9) == 2)
        DLC3_offset->setCurrentIndex(2);
    else if(qry.value(9) == 3)
        DLC3_offset->setCurrentIndex(3);
    else if(qry.value(9) == 4)
        DLC3_offset->setCurrentIndex(4);

    horizontal5->addStretch(1);
    horizontal5->addWidget(DLC3_Label);
    horizontal5->addWidget(register_DLC3_button);
    horizontal5->addSpacing(20);
    horizontal5->addWidget(DLC3_offset);
    horizontal5->addSpacing(30);
    horizontal5->addWidget(DLC3_Count_Label);
    horizontal5->addSpacing(30);
    horizontal5->addWidget(DLC3_status);
    horizontal5->addStretch(1);

    DLC4_Label = new QLabel(tr("DLC 4"));
    DLC4_Label->setFixedWidth(70);
    DLC4_Label->setAlignment(Qt::AlignHCenter|Qt::AlignCenter);
    DLC4_Label->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
    register_DLC4_button = new QPushButton(tr("Register"));
    register_DLC4_button->setFixedWidth(70);
    DLC4_offset = new QComboBox();
    DLC4_offset->addItem("1");
    DLC4_offset->addItem("2");
    DLC4_offset->addItem("5");
    DLC4_offset->addItem("10");
    DLC4_offset->addItem("20");
    DLC4_offset->setFixedWidth(70);
    DLC4_Count_Label = new QLabel(tr(" "));
    DLC4_Count_Label->setFixedWidth(70);
    DLC4_Count_Label->setAlignment(Qt::AlignLeft|Qt::AlignCenter);
    DLC4_status = new QLabel(tr("--"));
    DLC4_status->setFixedWidth(70);
    DLC4_status->setAlignment(Qt::AlignLeft|Qt::AlignCenter);

    if(qry.value(10) == 0)
        DLC4_offset->setCurrentIndex(0);
    else if(qry.value(10) == 1)
        DLC4_offset->setCurrentIndex(1);
    else if(qry.value(10) == 2)
        DLC4_offset->setCurrentIndex(2);
    else if(qry.value(10) == 3)
        DLC4_offset->setCurrentIndex(3);
    else if(qry.value(10) == 4)
        DLC4_offset->setCurrentIndex(4);

    horizontal6->addStretch(1);
    horizontal6->addWidget(DLC4_Label);
    horizontal6->addWidget(register_DLC4_button);
    horizontal6->addSpacing(20);
    horizontal6->addWidget(DLC4_offset);
    horizontal6->addSpacing(30);
    horizontal6->addWidget(DLC4_Count_Label);
    horizontal6->addSpacing(30);
    horizontal6->addWidget(DLC4_status);
    horizontal6->addStretch(1);

    DLC5_Label = new QLabel(tr("DLC 5"));
    DLC5_Label->setFixedWidth(70);
    DLC5_Label->setAlignment(Qt::AlignHCenter|Qt::AlignCenter);
    DLC5_Label->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
    register_DLC5_button = new QPushButton(tr("Register"));
    register_DLC5_button->setFixedWidth(70);
    DLC5_offset = new QComboBox();
    DLC5_offset->addItem("1");
    DLC5_offset->addItem("2");
    DLC5_offset->addItem("5");
    DLC5_offset->addItem("10");
    DLC5_offset->addItem("20");
    DLC5_offset->setFixedWidth(70);
    DLC5_Count_Label = new QLabel(tr(" "));
    DLC5_Count_Label->setFixedWidth(70);
    DLC5_Count_Label->setAlignment(Qt::AlignLeft|Qt::AlignCenter);
    DLC5_status = new QLabel(tr("--"));
    DLC5_status->setFixedWidth(70);
    DLC5_status->setAlignment(Qt::AlignLeft|Qt::AlignCenter);

    if(qry.value(11) == 0)
        DLC5_offset->setCurrentIndex(0);
    else if(qry.value(11) == 1)
        DLC5_offset->setCurrentIndex(1);
    else if(qry.value(11) == 2)
        DLC5_offset->setCurrentIndex(2);
    else if(qry.value(11) == 3)
        DLC5_offset->setCurrentIndex(3);
    else if(qry.value(11) == 4)
        DLC5_offset->setCurrentIndex(4);

    horizontal7->addStretch(1);
    horizontal7->addWidget(DLC5_Label);
    horizontal7->addWidget(register_DLC5_button);
    horizontal7->addSpacing(20);
    horizontal7->addWidget(DLC5_offset);
    horizontal7->addSpacing(30);
    horizontal7->addWidget(DLC5_Count_Label);
    horizontal7->addSpacing(30);
    horizontal7->addWidget(DLC5_status);
    horizontal7->addStretch(1);

    DLC6_Label = new QLabel(tr("DLC 6"));
    DLC6_Label->setFixedWidth(70);
    DLC6_Label->setAlignment(Qt::AlignHCenter|Qt::AlignCenter);
    DLC6_Label->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
    register_DLC6_button = new QPushButton(tr("Register"));
    register_DLC6_button->setFixedWidth(70);
    DLC6_offset = new QComboBox();
    DLC6_offset->addItem("1");
    DLC6_offset->addItem("2");
    DLC6_offset->addItem("5");
    DLC6_offset->addItem("10");
    DLC6_offset->addItem("20");
    DLC6_offset->setFixedWidth(70);
    DLC6_Count_Label = new QLabel(tr(" "));
    DLC6_Count_Label->setFixedWidth(70);
    DLC6_Count_Label->setAlignment(Qt::AlignLeft|Qt::AlignCenter);
    DLC6_status = new QLabel(tr("--"));
    DLC6_status->setFixedWidth(70);
    DLC6_status->setAlignment(Qt::AlignLeft|Qt::AlignCenter);

    if(qry.value(12) == 0)
        DLC6_offset->setCurrentIndex(0);
    else if(qry.value(12) == 1)
        DLC6_offset->setCurrentIndex(1);
    else if(qry.value(12) == 2)
        DLC6_offset->setCurrentIndex(2);
    else if(qry.value(12) == 3)
        DLC6_offset->setCurrentIndex(3);
    else if(qry.value(12) == 4)
        DLC6_offset->setCurrentIndex(4);

    horizontal8->addStretch(1);
    horizontal8->addWidget(DLC6_Label);
    horizontal8->addWidget(register_DLC6_button);
    horizontal8->addSpacing(20);
    horizontal8->addWidget(DLC6_offset);
    horizontal8->addSpacing(30);
    horizontal8->addWidget(DLC6_Count_Label);
    horizontal8->addSpacing(30);
    horizontal8->addWidget(DLC6_status);
    horizontal8->addStretch(1);

    DLC7_Label = new QLabel(tr("DLC 7"));
    DLC7_Label->setFixedWidth(70);
    DLC7_Label->setAlignment(Qt::AlignHCenter|Qt::AlignCenter);
    DLC7_Label->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
    register_DLC7_button = new QPushButton(tr("Register"));
    register_DLC7_button->setFixedWidth(70);
    DLC7_offset = new QComboBox();
    DLC7_offset->addItem("1");
    DLC7_offset->addItem("2");
    DLC7_offset->addItem("5");
    DLC7_offset->addItem("10");
    DLC7_offset->addItem("20");
    DLC7_offset->setFixedWidth(70);
    DLC7_Count_Label = new QLabel(tr(" "));
    DLC7_Count_Label->setFixedWidth(70);
    DLC7_Count_Label->setAlignment(Qt::AlignLeft|Qt::AlignCenter);
    DLC7_status = new QLabel(tr("--"));
    DLC7_status->setFixedWidth(70);
    DLC7_status->setAlignment(Qt::AlignLeft|Qt::AlignCenter);

    if(qry.value(13) == 0)
        DLC7_offset->setCurrentIndex(0);
    else if(qry.value(13) == 1)
        DLC7_offset->setCurrentIndex(1);
    else if(qry.value(13) == 2)
        DLC7_offset->setCurrentIndex(2);
    else if(qry.value(13) == 3)
        DLC7_offset->setCurrentIndex(3);
    else if(qry.value(13) == 4)
        DLC7_offset->setCurrentIndex(4);

    horizontal9->addStretch(1);
    horizontal9->addWidget(DLC7_Label);
    horizontal9->addWidget(register_DLC7_button);
    horizontal9->addSpacing(20);
    horizontal9->addWidget(DLC7_offset);
    horizontal9->addSpacing(30);
    horizontal9->addWidget(DLC7_Count_Label);
    horizontal9->addSpacing(30);
    horizontal9->addWidget(DLC7_status);
    horizontal9->addStretch(1);

    DLC8_Label = new QLabel(tr("DLC 8"));
    DLC8_Label->setFixedWidth(70);
    DLC8_Label->setAlignment(Qt::AlignHCenter|Qt::AlignCenter);
    DLC8_Label->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
    register_DLC8_button = new QPushButton(tr("Register"));
    register_DLC8_button->setFixedWidth(70);
    DLC8_offset = new QComboBox();
    DLC8_offset->addItem("1");
    DLC8_offset->addItem("2");
    DLC8_offset->addItem("5");
    DLC8_offset->addItem("10");
    DLC8_offset->addItem("20");
    DLC8_offset->setFixedWidth(70);
    DLC8_Count_Label = new QLabel(tr(" "));
    DLC8_Count_Label->setFixedWidth(70);
    DLC8_Count_Label->setAlignment(Qt::AlignLeft|Qt::AlignCenter);
    DLC8_status = new QLabel(tr("--"));
    DLC8_status->setFixedWidth(70);
    DLC8_status->setAlignment(Qt::AlignLeft|Qt::AlignCenter);

    if(qry.value(14) == 0)
        DLC8_offset->setCurrentIndex(0);
    else if(qry.value(14) == 1)
        DLC8_offset->setCurrentIndex(1);
    else if(qry.value(14) == 2)
        DLC8_offset->setCurrentIndex(2);
    else if(qry.value(14) == 3)
        DLC8_offset->setCurrentIndex(3);
    else if(qry.value(14) == 4)
        DLC8_offset->setCurrentIndex(4);

    horizontal10->addStretch(1);
    horizontal10->addWidget(DLC8_Label);
    horizontal10->addWidget(register_DLC8_button);
    horizontal10->addSpacing(20);
    horizontal10->addWidget(DLC8_offset);
    horizontal10->addSpacing(30);
    horizontal10->addWidget(DLC8_Count_Label);
    horizontal10->addSpacing(30);
    horizontal10->addWidget(DLC8_status);
    horizontal10->addStretch(1);

    save_button = new QPushButton(tr("Save"));
    save_button->setFixedWidth(90);
    reset_button = new QPushButton(tr("Reset"));
    reset_button->setFixedWidth(90);
    TestDLC_button = new QPushButton(tr("Test DLC"));
    TestDLC_button->setFixedWidth(90);

    horizontal11->addStretch(1);
    horizontal11->addWidget(save_button);
    horizontal11->addSpacing(5);
    horizontal11->addWidget(reset_button);
    horizontal11->addSpacing(5);
    horizontal11->addWidget(TestDLC_button);
    horizontal11->addStretch(1);

    mainLayout->addSpacing(6);
    mainLayout->addLayout(horizontal0);
    mainLayout->addLayout(horizontal1);
    mainLayout->addSpacing(15);
    mainLayout->addLayout(horizontal2);
    mainLayout->addSpacing(7);
    mainLayout->addLayout(horizontal3);
    mainLayout->addLayout(horizontal4);
    mainLayout->addLayout(horizontal5);
    mainLayout->addLayout(horizontal6);
    mainLayout->addLayout(horizontal7);
    mainLayout->addLayout(horizontal8);
    mainLayout->addLayout(horizontal9);
    mainLayout->addLayout(horizontal10);
    mainLayout->addSpacing(10);
    mainLayout->addLayout(horizontal11);
    mainLayout->addStretch(1);

    setLayout(mainLayout);

    switch(qry.value(6).toInt())
    {
        case 1 : on_one_radiobutton_click();
                break;
        case 2 : on_two_radiobutton_click();
                break;
        case 4 : on_four_radiobutton_click();
                break;
        case 6 : on_six_radiobutton_click();
                break;
        case 8 : on_eight_radiobutton_click();
                break;
    }

    connect(one_radiobutton, SIGNAL(clicked()), this, SLOT(on_one_radiobutton_click()));
    connect(two_radiobutton, SIGNAL(clicked()), this , SLOT(on_two_radiobutton_click()));
    connect(four_radiobutton, SIGNAL(clicked()), this, SLOT(on_four_radiobutton_click()));
    connect(six_radiobutton, SIGNAL(clicked()), this , SLOT(on_six_radiobutton_click()));
    connect(eight_radiobutton, SIGNAL(clicked()), this , SLOT(on_eight_radiobutton_click()));

    connect(register_DLC1_button, SIGNAL(clicked()), this , SLOT(on_register_DLC1_button_click()));
    connect(register_DLC2_button, SIGNAL(clicked()), this , SLOT(on_register_DLC2_button_click()));
    connect(register_DLC3_button, SIGNAL(clicked()), this , SLOT(on_register_DLC3_button_click()));
    connect(register_DLC4_button, SIGNAL(clicked()), this , SLOT(on_register_DLC4_button_click()));
    connect(register_DLC5_button, SIGNAL(clicked()), this , SLOT(on_register_DLC5_button_click()));
    connect(register_DLC6_button, SIGNAL(clicked()), this , SLOT(on_register_DLC6_button_click()));
    connect(register_DLC7_button, SIGNAL(clicked()), this , SLOT(on_register_DLC7_button_click()));
    connect(register_DLC8_button, SIGNAL(clicked()), this , SLOT(on_register_DLC8_button_click()));

    connect(save_button, SIGNAL(clicked()), this , SLOT(on_save_button_click()));
    connect(reset_button, SIGNAL(clicked()), this , SLOT(on_reset_button_click()));    
    connect(TestDLC_button, SIGNAL(clicked()), this , SLOT(on_TestDLC_button_button_click()));
}

LoadcellTab::~LoadcellTab()
{
    port->close();
}

void LoadcellTab::on_TestDLC_button_button_click()
{
    QString rxdata;
    int count =0;
    qry.prepare("SELECT loadcell_DLCs,DLC1_offset,DLC2_offset,DLC3_offset,DLC4_offset,DLC5_offset,DLC6_offset,DLC7_offset,DLC8_offset FROM settings WHERE id = 1");
    if( !qry.exec() )
      qDebug() << qry.lastError();
    else
    {
        qDebug( "Executed" );
        qry.first();

        if(qry.value(0).toInt() == 4)
            four_radiobutton->setChecked(1);
        else if(qry.value(0).toInt() == 6)
            six_radiobutton->setChecked(1);
        else if(qry.value(0).toInt() == 8)
            eight_radiobutton->setChecked(1);

        on_eight_radiobutton_click();

        DLC1_status->setText("--");
        DLC2_status->setText("--");
        DLC3_status->setText("--");
        DLC4_status->setText("--");
        DLC5_status->setText("--");
        DLC6_status->setText("--");
        DLC7_status->setText("--");
        DLC8_status->setText("--");

        if(qry.value(1) == 0)
            DLC1_offset->setCurrentIndex(0);
        else if(qry.value(1) == 1)
            DLC1_offset->setCurrentIndex(1);
        else if(qry.value(1) == 2)
            DLC1_offset->setCurrentIndex(2);
        else if(qry.value(1) == 3)
            DLC1_offset->setCurrentIndex(3);
        else if(qry.value(1) == 4)
            DLC1_offset->setCurrentIndex(4);

        if(qry.value(2) == 0)
            DLC2_offset->setCurrentIndex(0);
        else if(qry.value(2) == 1)
            DLC2_offset->setCurrentIndex(1);
        else if(qry.value(2) == 2)
            DLC2_offset->setCurrentIndex(2);
        else if(qry.value(2) == 3)
            DLC2_offset->setCurrentIndex(3);
        else if(qry.value(2) == 4)
            DLC2_offset->setCurrentIndex(4);

        if(qry.value(3) == 0)
            DLC3_offset->setCurrentIndex(0);
        else if(qry.value(3) == 1)
            DLC3_offset->setCurrentIndex(1);
        else if(qry.value(3) == 2)
            DLC3_offset->setCurrentIndex(2);
        else if(qry.value(3) == 3)
            DLC3_offset->setCurrentIndex(3);
        else if(qry.value(3) == 4)
            DLC3_offset->setCurrentIndex(4);

        if(qry.value(4) == 0)
            DLC4_offset->setCurrentIndex(0);
        else if(qry.value(4) == 1)
            DLC4_offset->setCurrentIndex(1);
        else if(qry.value(4) == 2)
            DLC4_offset->setCurrentIndex(2);
        else if(qry.value(4) == 3)
            DLC4_offset->setCurrentIndex(3);
        else if(qry.value(4) == 4)
            DLC4_offset->setCurrentIndex(4);

        if(qry.value(5) == 0)
            DLC5_offset->setCurrentIndex(0);
        else if(qry.value(5) == 1)
            DLC5_offset->setCurrentIndex(1);
        else if(qry.value(5) == 2)
            DLC5_offset->setCurrentIndex(2);
        else if(qry.value(5) == 3)
            DLC5_offset->setCurrentIndex(3);
        else if(qry.value(5) == 4)
            DLC5_offset->setCurrentIndex(4);

        if(qry.value(6) == 0)
            DLC6_offset->setCurrentIndex(0);
        else if(qry.value(6) == 1)
            DLC6_offset->setCurrentIndex(1);
        else if(qry.value(6) == 2)
            DLC6_offset->setCurrentIndex(2);
        else if(qry.value(6) == 3)
            DLC6_offset->setCurrentIndex(3);
        else if(qry.value(6) == 4)
            DLC6_offset->setCurrentIndex(4);

        if(qry.value(7) == 0)
            DLC7_offset->setCurrentIndex(0);
        else if(qry.value(7) == 1)
            DLC7_offset->setCurrentIndex(1);
        else if(qry.value(7) == 2)
            DLC7_offset->setCurrentIndex(2);
        else if(qry.value(7) == 3)
            DLC7_offset->setCurrentIndex(3);
        else if(qry.value(7) == 4)
            DLC7_offset->setCurrentIndex(4);

        if(qry.value(8) == 0)
            DLC8_offset->setCurrentIndex(0);
        else if(qry.value(8) == 1)
            DLC8_offset->setCurrentIndex(1);
        else if(qry.value(8) == 2)
            DLC8_offset->setCurrentIndex(2);
        else if(qry.value(8) == 3)
            DLC8_offset->setCurrentIndex(3);
        else if(qry.value(8) == 4)
            DLC8_offset->setCurrentIndex(4);

        count = qry.value(0).toInt();
        switch(count)
        {
            case 1 : on_one_radiobutton_click();
                    break;
            case 2 : on_two_radiobutton_click();
                    break;
            case 4 : on_four_radiobutton_click();
                    break;
            case 6 : on_six_radiobutton_click();
                    break;
        }


        port->write("TS");

        while(port->bytesAvailable() <= 0)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        rxdata = port->readAll();
        if(rxdata.toInt() == SUCCESS)
        {
            DLC1_status->setStyleSheet("QLabel {color : green; }");
            DLC1_status->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
            DLC1_status->setText("PASS");
        }
        else
        {
            DLC1_status->setStyleSheet("QLabel {color : red; }");
            DLC1_status->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
            DLC1_status->setText("FAIL");
        }

        if((count == 2)||(count == 4)||(count == 6)||(count == 8))
        {
            while(port->bytesAvailable() <= 0);
                //QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
            rxdata = port->readAll();
            if(rxdata.toInt() == SUCCESS)
            {
                DLC2_status->setStyleSheet("QLabel {color : green; }");
                DLC2_status->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
                DLC2_status->setText("PASS");
            }
            else
            {
                DLC2_status->setStyleSheet("QLabel {color : red; }");
                DLC2_status->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
                DLC2_status->setText("FAIL");
            }
        }

        if((count == 4)||(count == 6)||(count == 8))
        {
            while(port->bytesAvailable() <= 0)
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
            rxdata = port->readAll();
            if(rxdata.toInt() == SUCCESS)
            {
                DLC3_status->setStyleSheet("QLabel {color : green; }");
                DLC3_status->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
                DLC3_status->setText("PASS");
            }
            else
            {
                DLC3_status->setStyleSheet("QLabel {color : red; }");
                DLC3_status->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
                DLC3_status->setText("FAIL");
            }

            while(port->bytesAvailable() <= 0)
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
            rxdata = port->readAll();
            if(rxdata.toInt() == SUCCESS)
            {
                DLC4_status->setStyleSheet("QLabel {color : green; }");
                DLC4_status->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
                DLC4_status->setText("PASS");
            }
            else
            {
                DLC4_status->setStyleSheet("QLabel {color : red; }");
                DLC4_status->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
                DLC4_status->setText("FAIL");
            }
        }

        if((count == 6)||(count == 8))
        {
            while(port->bytesAvailable() <= 0)
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
            rxdata = port->readAll();
            if(rxdata.toInt() == SUCCESS)
            {
                DLC5_status->setStyleSheet("QLabel {color : green; }");
                DLC5_status->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
                DLC5_status->setText("PASS");
            }
            else
            {
                DLC5_status->setStyleSheet("QLabel {color : red; }");
                DLC5_status->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
                DLC5_status->setText("FAIL");
            }

            while(port->bytesAvailable() <= 0)
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
            rxdata = port->readAll();
            if(rxdata.toInt() == SUCCESS)
            {
                DLC6_status->setStyleSheet("QLabel {color : green; }");
                DLC6_status->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
                DLC6_status->setText("PASS");
            }
            else
            {
                DLC6_status->setStyleSheet("QLabel {color : red; }");
                DLC6_status->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
                DLC6_status->setText("FAIL");
            }
        }

        if(count == 8)
        {
            while(port->bytesAvailable() <= 0)
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
            rxdata = port->readAll();
            if(rxdata.toInt() == SUCCESS)
            {
                DLC7_status->setStyleSheet("QLabel {color : green; }");
                DLC7_status->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
                DLC7_status->setText("PASS");
            }
            else
            {
                DLC7_status->setStyleSheet("QLabel {color : red; }");
                DLC7_status->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
                DLC7_status->setText("FAIL");
            }

            while(port->bytesAvailable() <= 0)
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
            rxdata = port->readAll();
            if(rxdata.toInt() == SUCCESS)
            {
                DLC8_status->setStyleSheet("QLabel {color : green; }");
                DLC8_status->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
                DLC8_status->setText("PASS");
            }
            else
            {
                DLC8_status->setStyleSheet("QLabel {color : red; }");
                DLC8_status->setFont(QFont( "serif", 9, QFont::AbsoluteSpacing|QFont::Bold,FALSE ));
                DLC8_status->setText("FAIL");
            }
        }
    }


}

void LoadcellTab::on_one_radiobutton_click()
{
    clear_status();

    DLC2_Label->setVisible(0);
    register_DLC2_button->setVisible(0);
    DLC2_offset->setVisible(0);
    DLC2_Count_Label->setVisible(0);
    DLC2_status->setVisible(0);

    DLC3_Label->setVisible(0);
    register_DLC3_button->setVisible(0);
    DLC3_offset->setVisible(0);
    DLC3_Count_Label->setVisible(0);
    DLC3_status->setVisible(0);

    DLC4_Label->setVisible(0);
    register_DLC4_button->setVisible(0);
    DLC4_offset->setVisible(0);
    DLC4_Count_Label->setVisible(0);
    DLC4_status->setVisible(0);

    DLC5_Label->setVisible(0);
    register_DLC5_button->setVisible(0);
    DLC5_offset->setVisible(0);
    DLC5_Count_Label->setVisible(0);
    DLC5_status->setVisible(0);

    DLC6_Label->setVisible(0);
    register_DLC6_button->setVisible(0);
    DLC6_offset->setVisible(0);
    DLC6_Count_Label->setVisible(0);
    DLC6_status->setVisible(0);

    DLC7_Label->setVisible(0);
    register_DLC7_button->setVisible(0);
    DLC7_offset->setVisible(0);
    DLC7_Count_Label->setVisible(0);
    DLC7_status->setVisible(0);

    DLC8_Label->setVisible(0);
    register_DLC8_button->setVisible(0);
    DLC8_offset->setVisible(0);
    DLC8_Count_Label->setVisible(0);
    DLC8_status->setVisible(0);
}

void LoadcellTab::on_two_radiobutton_click()
{
    clear_status();

    DLC2_Label->setVisible(1);
    register_DLC2_button->setVisible(1);
    DLC2_offset->setVisible(1);
    DLC2_Count_Label->setVisible(1);
    DLC2_status->setVisible(1);

    DLC3_Label->setVisible(0);
    register_DLC3_button->setVisible(0);
    DLC3_offset->setVisible(0);
    DLC3_Count_Label->setVisible(0);
    DLC3_status->setVisible(0);

    DLC4_Label->setVisible(0);
    register_DLC4_button->setVisible(0);
    DLC4_offset->setVisible(0);
    DLC4_Count_Label->setVisible(0);
    DLC4_status->setVisible(0);

    DLC5_Label->setVisible(0);
    register_DLC5_button->setVisible(0);
    DLC5_offset->setVisible(0);
    DLC5_Count_Label->setVisible(0);
    DLC5_status->setVisible(0);

    DLC6_Label->setVisible(0);
    register_DLC6_button->setVisible(0);
    DLC6_offset->setVisible(0);
    DLC6_Count_Label->setVisible(0);
    DLC6_status->setVisible(0);

    DLC7_Label->setVisible(0);
    register_DLC7_button->setVisible(0);
    DLC7_offset->setVisible(0);
    DLC7_Count_Label->setVisible(0);
    DLC7_status->setVisible(0);

    DLC8_Label->setVisible(0);
    register_DLC8_button->setVisible(0);
    DLC8_offset->setVisible(0);
    DLC8_Count_Label->setVisible(0);
    DLC8_status->setVisible(0);
}

void LoadcellTab::on_four_radiobutton_click()
{
    clear_status();

    DLC2_Label->setVisible(1);
    register_DLC2_button->setVisible(1);
    DLC2_offset->setVisible(1);
    DLC2_Count_Label->setVisible(1);
    DLC2_status->setVisible(1);

    DLC3_Label->setVisible(1);
    register_DLC3_button->setVisible(1);
    DLC3_offset->setVisible(1);
    DLC3_Count_Label->setVisible(1);
    DLC3_status->setVisible(1);

    DLC4_Label->setVisible(1);
    register_DLC4_button->setVisible(1);
    DLC4_offset->setVisible(1);
    DLC4_Count_Label->setVisible(1);
    DLC4_status->setVisible(1);

    DLC5_Label->setVisible(0);
    register_DLC5_button->setVisible(0);
    DLC5_offset->setVisible(0);
    DLC5_Count_Label->setVisible(0);
    DLC5_status->setVisible(0);

    DLC6_Label->setVisible(0);
    register_DLC6_button->setVisible(0);
    DLC6_offset->setVisible(0);
    DLC6_Count_Label->setVisible(0);
    DLC6_status->setVisible(0);

    DLC7_Label->setVisible(0);
    register_DLC7_button->setVisible(0);
    DLC7_offset->setVisible(0);
    DLC7_Count_Label->setVisible(0);
    DLC7_status->setVisible(0);

    DLC8_Label->setVisible(0);
    register_DLC8_button->setVisible(0);
    DLC8_offset->setVisible(0);
    DLC8_Count_Label->setVisible(0);
    DLC8_status->setVisible(0);
}

void LoadcellTab::on_six_radiobutton_click()
{
    clear_status();

    DLC2_Label->setVisible(1);
    register_DLC2_button->setVisible(1);
    DLC2_offset->setVisible(1);
    DLC2_Count_Label->setVisible(1);
    DLC2_status->setVisible(1);

    DLC3_Label->setVisible(1);
    register_DLC3_button->setVisible(1);
    DLC3_offset->setVisible(1);
    DLC3_Count_Label->setVisible(1);
    DLC3_status->setVisible(1);

    DLC4_Label->setVisible(1);
    register_DLC4_button->setVisible(1);
    DLC4_offset->setVisible(1);
    DLC4_Count_Label->setVisible(1);
    DLC4_status->setVisible(1);

    DLC5_Label->setVisible(1);
    register_DLC5_button->setVisible(1);
    DLC5_offset->setVisible(1);
    DLC5_Count_Label->setVisible(1);
    DLC5_status->setVisible(1);

    DLC6_Label->setVisible(1);
    register_DLC6_button->setVisible(1);
    DLC6_offset->setVisible(1);
    DLC6_Count_Label->setVisible(1);
    DLC6_status->setVisible(1);

    DLC7_Label->setVisible(0);
    register_DLC7_button->setVisible(0);
    DLC7_offset->setVisible(0);
    DLC7_Count_Label->setVisible(0);
    DLC7_status->setVisible(0);

    DLC8_Label->setVisible(0);
    register_DLC8_button->setVisible(0);
    DLC8_offset->setVisible(0);
    DLC8_Count_Label->setVisible(0);
    DLC8_status->setVisible(0);
}
void LoadcellTab::on_eight_radiobutton_click()
{
    clear_status();

    DLC2_Label->setVisible(1);
    register_DLC2_button->setVisible(1);
    DLC2_offset->setVisible(1);
    DLC2_Count_Label->setVisible(1);
    DLC2_status->setVisible(1);

    DLC3_Label->setVisible(1);
    register_DLC3_button->setVisible(1);
    DLC3_offset->setVisible(1);
    DLC3_Count_Label->setVisible(1);
    DLC3_status->setVisible(1);

    DLC4_Label->setVisible(1);
    register_DLC4_button->setVisible(1);
    DLC4_offset->setVisible(1);
    DLC4_Count_Label->setVisible(1);
    DLC4_status->setVisible(1);

    DLC5_Label->setVisible(1);
    register_DLC5_button->setVisible(1);
    DLC5_offset->setVisible(1);
    DLC5_Count_Label->setVisible(1);
    DLC5_status->setVisible(1);

    DLC6_Label->setVisible(1);
    register_DLC6_button->setVisible(1);
    DLC6_offset->setVisible(1);
    DLC6_Count_Label->setVisible(1);
    DLC6_status->setVisible(1);

    DLC7_Label->setVisible(1);
    register_DLC7_button->setVisible(1);
    DLC7_offset->setVisible(1);
    DLC7_Count_Label->setVisible(1);
    DLC7_status->setVisible(1);

    DLC8_Label->setVisible(1);
    register_DLC8_button->setVisible(1);
    DLC8_offset->setVisible(1);
    DLC8_Count_Label->setVisible(1);
    DLC8_status->setVisible(1);
}

void LoadcellTab::on_register_DLC1_button_click()
{
    clear_status();
    QString rxdata;
    port->write("R1");
    while(!port->bytesAvailable());
    rxdata = port->readAll();
    DLC1_Count_Label->setText(rxdata);
}
void LoadcellTab::on_register_DLC2_button_click()
{
    clear_status();
    QString rxdata;
    port->write("R2");
    while(!port->bytesAvailable());
    rxdata = port->readAll();
    DLC2_Count_Label->setText(rxdata);
}
void LoadcellTab::on_register_DLC3_button_click()
{
    clear_status();
    QString rxdata;
    port->write("R3");
    while(!port->bytesAvailable());
    rxdata = port->readAll();
    DLC3_Count_Label->setText(rxdata);
}
void LoadcellTab::on_register_DLC4_button_click()
{
    clear_status();
    QString rxdata;
    port->write("R4");
    while(!port->bytesAvailable());
    rxdata = port->readAll();
    DLC4_Count_Label->setText(rxdata);
}
void LoadcellTab::on_register_DLC5_button_click()
{
    clear_status();
    QString rxdata;
    port->write("R5");
    while(!port->bytesAvailable());
    rxdata = port->readAll();
    DLC5_Count_Label->setText(rxdata);
}
void LoadcellTab::on_register_DLC6_button_click()
{
    clear_status();
    QString rxdata;
    port->write("R6");
    while(!port->bytesAvailable());
    rxdata = port->readAll();
    DLC6_Count_Label->setText(rxdata);
}
void LoadcellTab::on_register_DLC7_button_click()
{
    clear_status();
    QString rxdata;
    port->write("R7");
    while(!port->bytesAvailable());
    rxdata = port->readAll();
    DLC7_Count_Label->setText(rxdata);
}
void LoadcellTab::on_register_DLC8_button_click()
{
    clear_status();
    QString rxdata;
    port->write("R8");
    while(!port->bytesAvailable());
    rxdata = port->readAll();
    DLC8_Count_Label->setText(rxdata);
}

void LoadcellTab::on_save_button_click()
{
    if(one_radiobutton->isChecked())
    {
        port->write("D1");

        qry.prepare("UPDATE settings SET loadcell_DLCs=:dlc,DLC1_offset=:dlc1 WHERE id = 1");
        qry.bindValue(":dlc", 1);
        qry.bindValue(":dlc1", DLC1_offset->currentIndex());
        if( !qry.exec() )
            qDebug() << qry.lastError();
        else
        {
            qDebug( "Executed" );
            QMessageBox::information(this, "Info", "Device Upadted\nYou must restart application to make effect");
        }
    }
    else if(two_radiobutton->isChecked())
    {
        port->write("D2");

        qry.prepare("UPDATE settings SET loadcell_DLCs=:dlc,DLC1_offset=:dlc1,DLC2_offset=:dlc2 WHERE id = 1");
        qry.bindValue(":dlc", 2);
        qry.bindValue(":dlc1", DLC1_offset->currentIndex());
        qry.bindValue(":dlc2", DLC2_offset->currentIndex());
        if( !qry.exec() )
            qDebug() << qry.lastError();
        else
        {
            qDebug( "Executed" );
            QMessageBox::information(this, "Info", "Device Upadted\nYou must restart application to make effect");
        }
    }
    else if(four_radiobutton->isChecked())
    {
        port->write("D4");

        qry.prepare("UPDATE settings SET loadcell_DLCs=:dlc,DLC1_offset=:dlc1,DLC2_offset=:dlc2,DLC3_offset=:dlc3,DLC4_offset=:dlc4 WHERE id = 1");
        qry.bindValue(":dlc", 4);
        qry.bindValue(":dlc1", DLC1_offset->currentIndex());
        qry.bindValue(":dlc2", DLC2_offset->currentIndex());
        qry.bindValue(":dlc3", DLC3_offset->currentIndex());
        qry.bindValue(":dlc4", DLC4_offset->currentIndex());
        if( !qry.exec() )
            qDebug() << qry.lastError();
        else
        {
            qDebug( "Executed" );
            QMessageBox::information(this, "Info", "Device Upadted\nYou must restart application to make effect");
        }
    }
    else if(six_radiobutton->isChecked())
    {
        port->write("D6");

        qry.prepare("UPDATE settings SET loadcell_DLCs=:dlc,DLC1_offset=:dlc1,DLC2_offset=:dlc2,DLC3_offset=:dlc3,DLC4_offset=:dlc4,DLC5_offset=:dlc5,DLC6_offset=:dlc6 WHERE id = 1");
        qry.bindValue(":dlc", 6);
        qry.bindValue(":dlc1", DLC1_offset->currentIndex());
        qry.bindValue(":dlc2", DLC2_offset->currentIndex());
        qry.bindValue(":dlc3", DLC3_offset->currentIndex());
        qry.bindValue(":dlc4", DLC4_offset->currentIndex());
        qry.bindValue(":dlc5", DLC5_offset->currentIndex());
        qry.bindValue(":dlc6", DLC6_offset->currentIndex());
        if( !qry.exec() )
            qDebug() << qry.lastError();
        else
        {
            qDebug( "Executed" );
            QMessageBox::information(this, "Info", "Device Upadted\nYou must restart application to make effect");
        }
    }
    else if(eight_radiobutton->isChecked())
    {
        port->write("D8");

        qry.prepare("UPDATE settings SET loadcell_DLCs=:dlc,DLC1_offset=:dlc1,DLC2_offset=:dlc2,DLC3_offset=:dlc3,DLC4_offset=:dlc4,DLC5_offset=:dlc5,DLC6_offset=:dlc6,DLC7_offset=:dlc7,DLC8_offset=:dlc8 WHERE id = 1");
        qry.bindValue(":dlc", 8);
        qry.bindValue(":dlc1", DLC1_offset->currentIndex());
        qry.bindValue(":dlc2", DLC2_offset->currentIndex());
        qry.bindValue(":dlc3", DLC3_offset->currentIndex());
        qry.bindValue(":dlc4", DLC4_offset->currentIndex());
        qry.bindValue(":dlc5", DLC5_offset->currentIndex());
        qry.bindValue(":dlc6", DLC6_offset->currentIndex());
        qry.bindValue(":dlc7", DLC7_offset->currentIndex());
        qry.bindValue(":dlc8", DLC8_offset->currentIndex());
        if( !qry.exec() )
            qDebug() << qry.lastError();
        else
        {
            qDebug( "Executed" );
            QMessageBox::information(this, "Info", "Device Upadted\nYou must restart application to make effect");
        }
    }

}

void LoadcellTab::on_reset_button_click()
{
    qry.prepare("SELECT loadcell_DLCs,DLC1_offset,DLC2_offset,DLC3_offset,DLC4_offset,DLC5_offset,DLC6_offset,DLC7_offset,DLC8_offset FROM settings WHERE id = 1");
    if( !qry.exec() )
      qDebug() << qry.lastError();
    else
    {
        qDebug( "Executed" );
        qry.first();

        if(qry.value(0).toInt() == 1)
            one_radiobutton->setChecked(1);
        else if(qry.value(0).toInt() == 2)
            two_radiobutton->setChecked(1);
        else if(qry.value(0).toInt() == 4)
            four_radiobutton->setChecked(1);
        else if(qry.value(0).toInt() == 6)
            six_radiobutton->setChecked(1);
        else if(qry.value(0).toInt() == 8)
            eight_radiobutton->setChecked(1);


        on_one_radiobutton_click();

        if(qry.value(1) == 0)
            DLC1_offset->setCurrentIndex(0);
        else if(qry.value(1) == 1)
            DLC1_offset->setCurrentIndex(1);
        else if(qry.value(1) == 2)
            DLC1_offset->setCurrentIndex(2);
        else if(qry.value(1) == 3)
            DLC1_offset->setCurrentIndex(3);
        else if(qry.value(1) == 4)
            DLC1_offset->setCurrentIndex(4);

        if((qry.value(0).toInt() == 2)||(qry.value(0).toInt() == 4)||(qry.value(0).toInt() == 6)||(qry.value(0).toInt() == 8))
        {
            on_two_radiobutton_click();

            if(qry.value(2) == 0)
                DLC2_offset->setCurrentIndex(0);
            else if(qry.value(2) == 1)
                DLC2_offset->setCurrentIndex(1);
            else if(qry.value(2) == 2)
                DLC2_offset->setCurrentIndex(2);
            else if(qry.value(2) == 3)
                DLC2_offset->setCurrentIndex(3);
            else if(qry.value(2) == 4)
                DLC2_offset->setCurrentIndex(4);
        }

        if((qry.value(0).toInt() == 4)||(qry.value(0).toInt() == 6)||(qry.value(0).toInt() == 8))
        {
            on_four_radiobutton_click();

            if(qry.value(3) == 0)
                DLC3_offset->setCurrentIndex(0);
            else if(qry.value(3) == 1)
                DLC3_offset->setCurrentIndex(1);
            else if(qry.value(3) == 2)
                DLC3_offset->setCurrentIndex(2);
            else if(qry.value(3) == 3)
                DLC3_offset->setCurrentIndex(3);
            else if(qry.value(3) == 4)
                DLC3_offset->setCurrentIndex(4);

            if(qry.value(4) == 0)
                DLC4_offset->setCurrentIndex(0);
            else if(qry.value(4) == 1)
                DLC4_offset->setCurrentIndex(1);
            else if(qry.value(4) == 2)
                DLC4_offset->setCurrentIndex(2);
            else if(qry.value(4) == 3)
                DLC4_offset->setCurrentIndex(3);
            else if(qry.value(4) == 4)
                DLC4_offset->setCurrentIndex(4);
        }
        if((qry.value(0).toInt() == 6)||(qry.value(0).toInt() == 8))
        {
            on_six_radiobutton_click();

            if(qry.value(5) == 0)
                DLC5_offset->setCurrentIndex(0);
            else if(qry.value(5) == 1)
                DLC5_offset->setCurrentIndex(1);
            else if(qry.value(5) == 2)
                DLC5_offset->setCurrentIndex(2);
            else if(qry.value(5) == 3)
                DLC5_offset->setCurrentIndex(3);
            else if(qry.value(5) == 4)
                DLC5_offset->setCurrentIndex(4);

            if(qry.value(6) == 0)
                DLC6_offset->setCurrentIndex(0);
            else if(qry.value(6) == 1)
                DLC6_offset->setCurrentIndex(1);
            else if(qry.value(6) == 2)
                DLC6_offset->setCurrentIndex(2);
            else if(qry.value(6) == 3)
                DLC6_offset->setCurrentIndex(3);
            else if(qry.value(6) == 4)
                DLC6_offset->setCurrentIndex(4);
        }

        if(qry.value(0).toInt() == 8)
        {

            on_eight_radiobutton_click();

            if(qry.value(7) == 0)
                DLC7_offset->setCurrentIndex(0);
            else if(qry.value(7) == 1)
                DLC7_offset->setCurrentIndex(1);
            else if(qry.value(7) == 2)
                DLC7_offset->setCurrentIndex(2);
            else if(qry.value(7) == 3)
                DLC7_offset->setCurrentIndex(3);
            else if(qry.value(7) == 4)
                DLC7_offset->setCurrentIndex(4);

            if(qry.value(8) == 0)
                DLC8_offset->setCurrentIndex(0);
            else if(qry.value(8) == 1)
                DLC8_offset->setCurrentIndex(1);
            else if(qry.value(8) == 2)
                DLC8_offset->setCurrentIndex(2);
            else if(qry.value(8) == 3)
                DLC8_offset->setCurrentIndex(3);
            else if(qry.value(8) == 4)
                DLC8_offset->setCurrentIndex(4);
        }
    }

}

void LoadcellTab::clear_status()
{
    DLC1_status->clear();
    DLC2_status->clear();
    DLC3_status->clear();
    DLC4_status->clear();
    DLC5_status->clear();
    DLC6_status->clear();
    DLC7_status->clear();
    DLC8_status->clear();
}
