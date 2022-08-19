#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class adminlogin;
}

class adminlogin : public QDialog
{
    Q_OBJECT
    
public:
    QSqlDatabase db;
    QSqlQuery qry;
    explicit adminlogin(QWidget *parent = 0);
    ~adminlogin();
    
private slots:
    void on_okbutton_clicked();

    void on_password_edit_returnPressed();

private:
    Ui::adminlogin *ui;
};

#endif // ADMINLOGIN_H
