#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QShortcut>
#include <QtSql>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    QSqlDatabase database;
    QSqlQuery qry;
    QShortcut *shortcut1;
    QShortcut *shortcut2;
    QShortcut *shortcut3;
    QShortcut *shortcut4;
    QShortcut *shortcut5;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_settingsbutton_clicked();

    void on_operatorbutton_clicked();

    void on_startbutton_clicked();

    void on_exitbutton_clicked();

    void on_helpbutton_clicked();

    void update_time();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
