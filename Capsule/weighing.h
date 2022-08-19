#ifndef WEIGHING_H
#define WEIGHING_H

#include <QDialog>
#include <QMainWindow>
#include <QtSql>

#include "qextserialport.h"

namespace Ui {
class weighing;
}

class weighing : public QDialog
{
    Q_OBJECT
    
public:
    int period,count,read_flag,stopclick_check,limit,first_read;
    double *inputs;
    float lt1,lt2,lt3,gt1,gt2,gt3;
    double t1,t2,t3;
    double flw,trw,T11,T12,T21,T22,T31,T32;
    double last_weight,min,max,mean,diff,total,percent,current_weight;
    QextSerialPort *port;
    QTimer *timer;
    QTimer *serial_timer;
    QSqlDatabase db;
    QSqlQuery qry;
    explicit weighing(QWidget *parent = 0,QString user = " ");
    ~weighing();
    
private slots:
    void on_startbutton_clicked();

    void on_okbutton_clicked();

    void update_time();

    void on_lockbutton_clicked();

    void on_endbatch_clicked();

    void read_weight();

    void on_stopbutton_clicked();

    void onReadyRead();

private:
    Ui::weighing *ui;
};

#endif // WEIGHING_H
