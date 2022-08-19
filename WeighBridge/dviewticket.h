#ifndef DVIEWTICKET_H
#define DVIEWTICKET_H

#include <QDialog>
#include <QtSql>
#include "qextserialport.h"

namespace Ui {
class DViewTicket;
}

class DViewTicket : public QDialog
{
    Q_OBJECT
    
public:
    int total;
    QextSerialPort  *printer_port;
    QSqlDatabase db;
    QSqlQuery qry ;
    QSqlDatabase db_settings;
    QSqlQuery qry_settings;
    explicit DViewTicket(QWidget *parent = 0);
    ~DViewTicket();
    
private slots:

    void on_closebutton_clicked();

    void on_printbutton_clicked();

    void on_gobutton_clicked();

    void on_clearbutton_clicked();

private:
    Ui::DViewTicket *ui;
};

#endif // DVIEWTICKET_H
