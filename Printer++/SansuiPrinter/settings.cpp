#include "settings.h"
#include "ui_settings.h"

#include <QtGui>


settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{
    db = QSqlDatabase :: database("PrinterDB");
    qry = QSqlQuery(db);
    ui->setupUi(this);
}

settings::~settings()
{
    delete ui;
}

void settings::on_order_radiobutton_clicked()
{
    ui->selection_disp_label->setText("Order No :");
    ui->search_lineedit->clear();
}

void settings::on_quality_radiobutton_clicked()
{
    ui->selection_disp_label->setText("Quality :");
    ui->search_lineedit->clear();
}

void settings::on_size_radiobutton_clicked()
{
    ui->selection_disp_label->setText("Size :");
    ui->search_lineedit->clear();
}

void settings::on_password_ok_button_clicked()
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
            if(ui->oldpass_edit->text() == password )
            {
                ui->newpass_label->setEnabled(1);
                ui->newpass_edit->setEnabled(1);
                ui->password_change_button->setEnabled(1);
                ui->password_cancel_button->setEnabled(1);
            }
            else
            {
                QMessageBox::critical(this, "Login Failed", "Login Failed, Wrong password !!");
                ui->oldpass_edit->clear();
            }
        }
}

void settings::on_password_cancel_button_clicked()
{
    ui->oldpass_edit->clear();
    ui->newpass_edit->clear();
    ui->newpass_edit->setDisabled(1);
    ui->password_change_button->setDisabled(1);
    ui->password_cancel_button->setDisabled(1);
    ui->newpass_label->setDisabled(1);
}

void settings::on_password_change_button_clicked()
{
    if(!ui->newpass_edit->text().isEmpty())
    {
        qry.prepare( "UPDATE settings SET password =:pass WHERE id = 1" );
        qry.bindValue(":pass", ui->newpass_edit->text());
        if( !qry.exec() )
        {
            QMessageBox::warning(this, "Warning", "Error with database : Settings");
            qDebug() << qry.lastError();
        }
        else
         {
             qDebug( "Updated!" );
             ui->oldpass_edit->clear();
             ui->password_ok_button->setEnabled(1);
             ui->newpass_edit->clear();
             ui->newpass_edit->setDisabled(1);
             ui->password_change_button->setDisabled(1);
             ui->password_cancel_button->setDisabled(1);
             ui->newpass_label->setDisabled(1);
             QMessageBox::information(this, "Successful", "Password changed successfuly");
         }
     }
    else
        QMessageBox::information(this, "Info","Enter new PASSWORD....");
}

void settings::on_search_button_clicked()
{
    int current_row = 0,temp_flag = 0;

    if(ui->order_radiobutton->isChecked())
    {
        ui->display_table->clearContents();
        ui->display_table->setRowCount(0);

        qry.prepare("SELECT * FROM record WHERE ordernum= :ord");
        qry.bindValue(":ord",ui->search_lineedit->text().toUpper());
        if(!qry.exec())
        {
            qDebug() << qry.lastError();
            qDebug()<<"Order Search Error";
        }
        else
        {
            while (qry.next())
            {
                temp_flag=1;
                current_row = ui->display_table->rowCount();
                ui->display_table->insertRow(current_row);
                ui->display_table->setCellWidget(current_row,0,new QLabel(tr(qry.value(0).toString().toAscii())));
                ui->display_table->setCellWidget(current_row,1,new QLabel(tr(qry.value(1).toString().toAscii())));
                ui->display_table->setCellWidget(current_row,2,new QLabel(tr(qry.value(6).toString().toAscii())));
                ui->display_table->setCellWidget(current_row,3,new QLabel(tr(qry.value(7).toString().toAscii())));
                ui->display_table->setCellWidget(current_row,4,new QLabel(tr(qry.value(4).toString().toAscii())));
                ui->display_table->setCellWidget(current_row,5,new QLabel(tr(qry.value(5).toString().toAscii())));
                ui->display_table->setCellWidget(current_row,6,new QLabel(tr(qry.value(2).toString().toAscii())));
                ui->display_table->setCellWidget(current_row,7,new QLabel(tr(qry.value(3).toString().toAscii())));
               /* ui->display_table->setItem(row,0,new QTableWidgetItem(qry.value(0).toString()));
                ui->display_table->setItem(row,1,new QTableWidgetItem(qry.value(1).toString()));
                ui->display_table->setItem(row,2,new QTableWidgetItem(qry.value(6).toString()));
                ui->display_table->setItem(row,3,new QTableWidgetItem(qry.value(7).toString()));
                ui->display_table->setItem(row,4,new QTableWidgetItem(qry.value(4).toString()));
                ui->display_table->setItem(row,5,new QTableWidgetItem(qry.value(5).toString()));
                ui->display_table->setItem(row,6,new QTableWidgetItem(qry.value(2).toString()));
                ui->display_table->setItem(row,7,new QTableWidgetItem(qry.value(3).toString()));*/

            }
            if(temp_flag == 0)
            {
               QMessageBox::information(this, "No Record Found", "Zero records found in search");
            }

         }
    }
    else if(ui->quality_radiobutton->isChecked())
    {
        ui->display_table->clearContents();
        ui->display_table->setRowCount(0);

        qry.prepare("SELECT * FROM record WHERE quality= :qual");
        qry.bindValue(":qual",ui->search_lineedit->text().toUpper());
        if(!qry.exec())
        {
            qDebug() << qry.lastError();
            qDebug()<<"Order Search Error";
        }
        else
        {
            while (qry.next())
            {
                temp_flag=1;
                current_row = ui->display_table->rowCount();
                ui->display_table->insertRow(current_row);
                ui->display_table->setCellWidget(current_row,0,new QLabel(tr(qry.value(0).toString().toAscii())));
                ui->display_table->setCellWidget(current_row,1,new QLabel(tr(qry.value(1).toString().toAscii())));
                ui->display_table->setCellWidget(current_row,2,new QLabel(tr(qry.value(6).toString().toAscii())));
                ui->display_table->setCellWidget(current_row,3,new QLabel(tr(qry.value(7).toString().toAscii())));
                ui->display_table->setCellWidget(current_row,4,new QLabel(tr(qry.value(4).toString().toAscii())));
                ui->display_table->setCellWidget(current_row,5,new QLabel(tr(qry.value(5).toString().toAscii())));
                ui->display_table->setCellWidget(current_row,6,new QLabel(tr(qry.value(2).toString().toAscii())));
                ui->display_table->setCellWidget(current_row,7,new QLabel(tr(qry.value(3).toString().toAscii())));
                /*
                ui->display_table->setItem(row,0,new QTableWidgetItem(qry.value(0).toString()));
                ui->display_table->setItem(row,1,new QTableWidgetItem(qry.value(1).toString()));
                ui->display_table->setItem(row,2,new QTableWidgetItem(qry.value(6).toString()));
                ui->display_table->setItem(row,3,new QTableWidgetItem(qry.value(7).toString()));
                ui->display_table->setItem(row,4,new QTableWidgetItem(qry.value(4).toString()));
                ui->display_table->setItem(row,5,new QTableWidgetItem(qry.value(5).toString()));
                ui->display_table->setItem(row,6,new QTableWidgetItem(qry.value(2).toString()));
                ui->display_table->setItem(row,7,new QTableWidgetItem(qry.value(3).toString()));*/

            }
            if(temp_flag == 0)
            {
               QMessageBox::information(this, "No Record Found", "Zero records found in search");
            }

         }
    }
    else if(ui->size_radiobutton->isChecked())
    {
        ui->display_table->clearContents();
        ui->display_table->setRowCount(0);

        qry.prepare("SELECT * FROM record WHERE size= :sz");
        qry.bindValue(":sz",ui->search_lineedit->text().toUpper());
        if(!qry.exec())
        {
            qDebug() << qry.lastError();
            qDebug()<<"Order Search Error";
        }
        else
        {
            while (qry.next())
            {
                temp_flag=1;
                current_row = ui->display_table->rowCount();
                ui->display_table->insertRow(current_row);
                ui->display_table->setCellWidget(current_row,0,new QLabel(tr(qry.value(0).toString().toAscii())));
                ui->display_table->setCellWidget(current_row,1,new QLabel(tr(qry.value(1).toString().toAscii())));
                ui->display_table->setCellWidget(current_row,2,new QLabel(tr(qry.value(6).toString().toAscii())));
                ui->display_table->setCellWidget(current_row,3,new QLabel(tr(qry.value(7).toString().toAscii())));
                ui->display_table->setCellWidget(current_row,4,new QLabel(tr(qry.value(4).toString().toAscii())));
                ui->display_table->setCellWidget(current_row,5,new QLabel(tr(qry.value(5).toString().toAscii())));
                ui->display_table->setCellWidget(current_row,6,new QLabel(tr(qry.value(2).toString().toAscii())));
                ui->display_table->setCellWidget(current_row,7,new QLabel(tr(qry.value(3).toString().toAscii())));
                /*
                ui->display_table->setItem(row,0,new QTableWidgetItem(qry.value(0).toString()));
                ui->display_table->setItem(row,1,new QTableWidgetItem(qry.value(1).toString()));
                ui->display_table->setItem(row,2,new QTableWidgetItem(qry.value(6).toString()));
                ui->display_table->setItem(row,3,new QTableWidgetItem(qry.value(7).toString()));
                ui->display_table->setItem(row,4,new QTableWidgetItem(qry.value(4).toString()));
                ui->display_table->setItem(row,5,new QTableWidgetItem(qry.value(5).toString()));
                ui->display_table->setItem(row,6,new QTableWidgetItem(qry.value(2).toString()));
                ui->display_table->setItem(row,7,new QTableWidgetItem(qry.value(3).toString()));*/

            }
            if(temp_flag == 0)
            {
               QMessageBox::information(this, "No Record Found", "Zero records found in search");
            }

         }
    }
}


void settings::on_clear_button_clicked()
{
    ui->display_table->clearContents();
    ui->display_table->setRowCount(0);
    ui->oldpass_edit->clear();
    ui->password_ok_button->setEnabled(1);
    ui->newpass_edit->clear();
    ui->newpass_edit->setDisabled(1);
    ui->password_change_button->setDisabled(1);
    ui->password_cancel_button->setDisabled(1);
    ui->newpass_label->setDisabled(1);
    ui->order_radiobutton->setChecked(1);
    ui->selection_disp_label->setText("Order No :");
    ui->search_lineedit->clear();
}

void settings::on_oldpass_edit_returnPressed()
{
    on_password_ok_button_clicked();
}

void settings::on_newpass_edit_returnPressed()
{
    on_password_change_button_clicked();
}

