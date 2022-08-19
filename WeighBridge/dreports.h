#ifndef DREPORTS_H
#define DREPORTS_H

#include <QDialog>
#include <QtSql>
#include "qextserialport.h"

namespace Ui {
class DReports;
}

class DReports : public QDialog
{
    Q_OBJECT
    
public:
    int total;
    QextSerialPort  *printer_port;
    QSqlDatabase db;
    QSqlQuery qry ;
    QSqlDatabase db_settings;
    QSqlQuery qry_settings;
    explicit DReports(QWidget *parent = 0);
    ~DReports();
    
private slots:
       void on_searchbutton_clicked();

       void on_dateradio_clicked();

       void on_receiptradio_clicked();

       void on_vehicleradio_clicked();

       void on_customerradio_clicked();

       void on_materialradio_clicked();

       void on_nextbutton_clicked();

       void on_previousbutton_clicked();

       void on_printbutton_clicked();

       void on_clearbutton_clicked();

private:
    Ui::DReports *ui;
};

#endif // DREPORTS_H
