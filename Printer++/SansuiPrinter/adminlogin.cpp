#include "adminlogin.h"
#include "ui_adminlogin.h"

#include "settings.h"
#include <QtGui>

adminlogin::adminlogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminlogin)
{
    db = QSqlDatabase :: database("PrinterDB");
    qry = QSqlQuery(db);
    ui->setupUi(this);
}

adminlogin::~adminlogin()
{
    delete ui;
}

void adminlogin::on_okbutton_clicked()
{
    QString password;
    qry.prepare("SELECT password FROM settings WHERE id=1");
        if(!qry.exec())
        {
            QMessageBox::warning(this, "Warning", "Error with database : Settings");
            qDebug() << qry.lastError();
        }
        else
        {
            qry.first();
            password = qry.value(0).toString();
            if(ui->password_edit->text() == password )
            {
                qDebug("Login Success");
                QDialog::reject();
                settings setting;
                setting.setModal(true);
                setting.exec();
            }
            else
            {
                QMessageBox::critical(this, "Login Failed", "Login Failed, Wrong password !!");
                ui->password_edit->clear();
            }
        }
}

void adminlogin::on_password_edit_returnPressed()
{
    on_okbutton_clicked();
}
