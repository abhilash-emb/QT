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

public slots:
    void update_time();
    void onReadyRead();

public:
    int             maxlimit;
    int             option;
    int             tare;
    float           calibration_value;
    QString         Qweight;
    QShortcut       *shortcut1;
    QShortcut       *shortcut2;
    QShortcut       *shortcut3;
    QShortcut       *shortcut4;
    QShortcut       *shortcut5;
    QShortcut       *shortcut6;
    QShortcut       *shortcut7;
    QShortcut       *mastercut;
    QTimer          *timer;
    QextSerialPort  *port;
    QSqlDatabase    detailsdb;
    QSqlDatabase    settingsdb;
    QSqlQuery       qry1;
    QSqlQuery       qry2;
    QSqlQuery       qry3;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:
    void on_actionFirst_Weight_triggered();

    void on_actionSecond_Weight_triggered();

    void on_actionView_Ticket_triggered();

    void on_actionReport_triggered();

    void on_actionSettings_triggered();

    void on_actionHelp_triggered();

    void on_actionExit_triggered();

    void on_firstweightbutton_clicked();

    void on_secondweightbutton_clicked();

    void on_viewticketbutton_clicked();

    void on_viewreportbutton_clicked();

    void on_settingsbutton_clicked();

    void on_helpbutton_clicked();

    void on_exitbutton_clicked();

    //void on_calibration();

    void on_systemInit();

    void on_tare_button_clicked();

private:
    Ui::MainWindow *ui;
    bool eventFilter(QObject *pobj, QEvent *pevent);
};

#endif // MAINWINDOW_H
