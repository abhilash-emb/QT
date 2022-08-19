#ifndef DSETTINGS_H
#define DSETTINGS_H

#include <QDialog>
#include <QtSql>
#include "qextserialport.h"

namespace Ui {
class dsettings;
}

class dsettings : public QDialog
{
    Q_OBJECT
    
public:
    QSqlDatabase db;
    QSqlQuery qry;
    explicit dsettings(QWidget *parent = 0);
    ~dsettings();
    
private slots:
    void on_lineEdit_returnPressed();

private:
    Ui::dsettings *ui;
};

#endif // DSETTINGS_H
