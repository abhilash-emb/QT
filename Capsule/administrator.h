#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class administrator;
}

class administrator : public QDialog
{
    Q_OBJECT
    
public:
    QSqlDatabase db;
    QSqlQuery qry;
    explicit administrator(QWidget *parent = 0);
    ~administrator();
    
private slots:
    void on_okbutton_clicked();

    void on_cancelbutton_clicked();

    void on_passokbutton_clicked();

    void on_changebutton_clicked();

    void on_passcancelbutton_clicked();

    void on_savebutton_clicked();

    void on_newpassokbutton_clicked();

    void on_newpasscancelbutton_clicked();

    void on_opusercancelbutton_clicked();

    void on_resetbutton_clicked();

    void on_deletebutton_clicked();

private:
    Ui::administrator *ui;
};

#endif // ADMINISTRATOR_H
