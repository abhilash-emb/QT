#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT
    
public:
    QSqlDatabase db;
    QSqlQuery qry;
    explicit Settings(QWidget *parent = 0);
    ~Settings();
    
private slots:
    void on_okbutton_clicked();

    void on_cancelbutton_clicked();

private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
