#ifndef DFIRSTWEIGHT_H
#define DFIRSTWEIGHT_H

#include <QDialog>
#include <QtSql>
#include "qextserialport.h"


namespace Ui {
class DFirstWeight;
}

class DFirstWeight : public QDialog
{
    Q_OBJECT
    
public:
    int first_print;
    QextSerialPort  *printer_port;
    QSqlDatabase db;
    QSqlQuery qry ;
    QSqlDatabase db1;
    QSqlQuery qry1;
    QSqlQuery qry2;
    explicit DFirstWeight(QWidget *parent = 0,QString lastweight = "0",int option = 1);
    ~DFirstWeight();
    
private slots:

    void on_acceptbutton_clicked();

    void on_saveprintbutton_clicked();

    void on_clearallbutton_clicked();

    void on_closebutton_clicked();

private:
    Ui::DFirstWeight *ui;
};

#endif // DFIRSTWEIGHT_H
