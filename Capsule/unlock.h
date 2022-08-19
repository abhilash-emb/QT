#ifndef UNLOCK_H
#define UNLOCK_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class unlock;
}

class unlock : public QDialog
{
    Q_OBJECT
    
public:
    QSqlDatabase db;
    QSqlQuery qry;
    explicit unlock(QWidget *parent ,QString user = " ");
    ~unlock();
    
private slots:
    void on_passwordedit_returnPressed();

private:
    Ui::unlock *ui;
};

#endif // UNLOCK_H
