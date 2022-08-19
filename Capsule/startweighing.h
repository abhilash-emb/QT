#ifndef STARTWEIGHING_H
#define STARTWEIGHING_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class startweighing;
}

class startweighing : public QDialog
{
    Q_OBJECT
    
public:
    QSqlDatabase db;
    QSqlQuery qry;
    explicit startweighing(QWidget *parent = 0);
    ~startweighing();
    
private slots:
    void on_cancelbutton_clicked();

    void on_okbutton_clicked();

private:
    Ui::startweighing *ui;
};

#endif // STARTWEIGHING_H
