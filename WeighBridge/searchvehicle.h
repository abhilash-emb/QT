#ifndef SEARCHVEHICLE_H
#define SEARCHVEHICLE_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class searchvehicle;
}

class searchvehicle : public QDialog
{
    Q_OBJECT
    
public:
    QSqlDatabase db;
    QSqlQuery qry ;
    QSqlDatabase db1;
    QSqlQuery qry1;
    explicit searchvehicle(QWidget *parent = 0);
    ~searchvehicle();
    
private slots:
    void on_gobutton_clicked();

    void on_clearbutton_clicked();

    void on_printbutton_clicked();

    void on_previousbutton_clicked();

    void on_nextbutton_clicked();

private:
    Ui::searchvehicle *ui;
};

#endif // SEARCHVEHICLE_H
