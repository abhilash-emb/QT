#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QShortcut>

#include "qextserialport.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    int stop_click;
    QShortcut *help_shortcut;
    QShortcut *start_shortcut;
    QShortcut *stop_shortcut;
    QString batch;
    QSqlDatabase database;
    QSqlQuery qry,sec_qry;
    QextSerialPort *port;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;

private slots:
    void update_time();
    void on_start_button_clicked();
    void on_stop_button_clicked();
    void on_actionSettings_triggered();
    void on_actionAbout_triggered();
};

#endif // MAINWINDOW_H
