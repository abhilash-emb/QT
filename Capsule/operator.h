#ifndef OPERATOR_H
#define OPERATOR_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class Operator;
}

class Operator : public QDialog
{
    Q_OBJECT
    
public:
    int index;
    QSqlDatabase db;
    QSqlQuery qry;
    explicit Operator(QWidget *parent = 0);
    ~Operator();
    
private slots:
    void on_loginbutton_clicked();

    void on_logoutbutton_clicked();

    void on_parabox1_clicked();

    void on_parabox2_clicked();

    void on_parabox3_clicked();

    void on_parabox4_clicked();

    void on_parabox5_clicked();

    void on_parabox6_clicked();

    void on_parabox7_clicked();

    void on_parabox8_clicked();

    void on_parabox9_clicked();

    void on_parabox10_clicked();

    void on_passcancelbutton_clicked();

    void on_passokbutton_clicked();

    void on_changebutton_clicked();

    void on_batchaddbuton_clicked();

    void on_batchaddedit_returnPressed();

    void on_batchokbutton_clicked();

    void on_deletebutton_clicked();

    void on_resetbutton_clicked();

    void on_savebutton_clicked();

    void on_cancelbutton_clicked();

private:
    Ui::Operator *ui;
};

#endif // OPERATOR_H
