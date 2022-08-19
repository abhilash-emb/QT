#ifndef DSECONDWEIGHT_H
#define DSECONDWEIGHT_H

#include <QDialog>
#include <QtSql>
#include "qextserialport.h"

namespace Ui {
class DSecondWeight;
}

class DSecondWeight : public QDialog
{
    Q_OBJECT
    
public:
    int first_print;
    int total;
    QString vehicle;
    QString customer;
    QString material;
    QString challan;
    QextSerialPort  *printer_port;
    QSqlDatabase db;
    QSqlQuery qry ;
    QSqlDatabase db1;
    QSqlQuery qry1;
    QSqlQuery qry2;
    explicit DSecondWeight(QWidget *parent = 0,QString lastweight = "0",int option = 1);
    ~DSecondWeight();
    
private slots:

    void on_closebutton_clicked();

    void on_clearbutton_clicked();

    void on_gobutton_clicked();

    void on_acceptbutton_clicked();

    void on_saveprintbutton_clicked();

private:
    Ui::DSecondWeight *ui;
};

#endif // DSECONDWEIGHT_H
