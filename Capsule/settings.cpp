#include "settings.h"
#include "ui_settings.h"

#include "administrator.h"

#include <QtGui>

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    db = QSqlDatabase :: database("database");
    qry = QSqlQuery(db);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_okbutton_clicked()
{
    QString word;
    qry.prepare("SELECT password FROM settings WHERE id=1");
        if(!qry.exec())
            qDebug("Error at prefer");
        else
        {
            qry.first();
            word = qry.value(0).toString();
            if(ui->passwordedit->text() == word )
            {
                qDebug("Login Success");
                QDialog::reject();
                administrator admin;
                admin.setModal(true);
                admin.exec();
            }
            else
            {
                QMessageBox::critical(this, "Login Failed", "Authentication Failure, Wrong password !!");
               ui->passwordedit->clear();
            }
        }
}

void Settings::on_cancelbutton_clicked()
{
    QDialog::reject();
}
