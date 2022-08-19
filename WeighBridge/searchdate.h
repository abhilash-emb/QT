#ifndef SEARCHDATE_H
#define SEARCHDATE_H

#include <QDialog>
#include <QtSql>


namespace Ui {
class searchdate;
}

class searchdate : public QDialog
{
    Q_OBJECT
    
public:
    QSqlDatabase db;
    QSqlQuery qry ;
    QSqlQuery qry1 ;
    QSqlDatabase db2;
    QSqlQuery qry2;
    explicit searchdate(QWidget *parent = 0);
    ~searchdate();
    
private slots:
    void on_gobutton_clicked();

    void on_printbutton_clicked();

    void on_clearbutton_clicked();

    void on_nextbutton_clicked();

    void on_previousbutton_clicked();

private:
    Ui::searchdate *ui;
};

#endif // SEARCHDATE_H
