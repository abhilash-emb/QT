#ifndef SEARCHCUSTOMER_H
#define SEARCHCUSTOMER_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class searchcustomer;
}

class searchcustomer : public QDialog
{
    Q_OBJECT
    
public:
    QSqlDatabase db;
    QSqlQuery qry ;
    QSqlDatabase db1;
    QSqlQuery qry1;
    explicit searchcustomer(QWidget *parent = 0);
    ~searchcustomer();
    
private slots:
    void on_gobutton_clicked();

    void on_printbutton_clicked();

    void on_clearbutton_clicked();

    void on_previousbutton_clicked();

    void on_nextbutton_clicked();

private:
    Ui::searchcustomer *ui;
};

#endif // SEARCHCUSTOMER_H
