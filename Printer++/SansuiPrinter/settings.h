#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class settings;
}

class settings : public QDialog
{
    Q_OBJECT
    
public:
    QSqlDatabase db;
    QSqlQuery qry;
    explicit settings(QWidget *parent = 0);
    ~settings();
    
private slots:
    void on_order_radiobutton_clicked();

    void on_quality_radiobutton_clicked();

    void on_size_radiobutton_clicked();

    void on_password_ok_button_clicked();

    void on_password_cancel_button_clicked();

    void on_password_change_button_clicked();

    void on_search_button_clicked();

    void on_clear_button_clicked();

    void on_oldpass_edit_returnPressed();

    void on_newpass_edit_returnPressed();

private:
    Ui::settings *ui;
};

#endif // SETTINGS_H
