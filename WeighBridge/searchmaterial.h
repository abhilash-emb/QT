#ifndef SEARCHMATERIAL_H
#define SEARCHMATERIAL_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class searchmaterial;
}

class searchmaterial : public QDialog
{
    Q_OBJECT
    
public:
    QSqlDatabase db;
    QSqlQuery qry ;
    QSqlDatabase db1;
    QSqlQuery qry1;
    explicit searchmaterial(QWidget *parent = 0);
    ~searchmaterial();
    
private slots:
    void on_gobutton_clicked();

    void on_printbutton_clicked();

    void on_clearbutton_clicked();

    void on_previousbutton_clicked();

    void on_nextbutton_clicked();

private:
    Ui::searchmaterial *ui;
};

#endif // SEARCHMATERIAL_H
