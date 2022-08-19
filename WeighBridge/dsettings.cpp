#include <QtCore>
#include <QtGui>
#include <QtDebug>

#include "dsettings.h"
#include "ui_dsettings.h"
#include "tabset.h"

dsettings::dsettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dsettings)
{
    ui->setupUi(this);

    db = QSqlDatabase :: database("settingsdb");
    qry = QSqlQuery(db);

}

dsettings::~dsettings()
{
    delete ui;
}

void dsettings::on_lineEdit_returnPressed()
{
    QString word;


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

    if(ui->lineEdit->text() == word)
    {
        QDialog::reject();
        TabSet tabset(this);
    }
    else
    {
        QMessageBox::critical(this, "Password Error", "The password you've entered is incorrect");
        ui->lineEdit->clear();
    }
}
