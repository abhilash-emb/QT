#ifndef SEARCHRECIEPT_H
#define SEARCHRECIEPT_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class searchreciept;
}

class searchreciept : public QDialog
{
    Q_OBJECT
    
public:
    QSqlDatabase db;
    QSqlQuery qry ;
    QSqlDatabase db1;
    QSqlQuery qry1;
    explicit searchreciept(QWidget *parent = 0);
    ~searchreciept();
    
private slots:
    void on_gobutton_clicked();

    void on_printbutton_clicked();

    void on_clearbutton_clicked();

private:
    Ui::searchreciept *ui;
};

#endif // SEARCHRECIEPT_H
