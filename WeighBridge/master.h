#ifndef MASTER_H
#define MASTER_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class master;
}

class master : public QDialog
{
    Q_OBJECT
    
public:
    QSqlDatabase db;
    QSqlQuery qry ;
    explicit master(QWidget *parent = 0);
    ~master();
    
private slots:
    void on_okbutton_clicked();

private:
    Ui::master *ui;
};

#endif // MASTER_H
