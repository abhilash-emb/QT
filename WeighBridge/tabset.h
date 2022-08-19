#ifndef TABSET_H
#define TABSET_H

#include <QDialog>
#include <QtGui>
#include <QtSql>

#include "qextserialport.h"

class QTabWidget;

class TabSet : public QDialog
{
    Q_OBJECT

    public:

    explicit TabSet(QWidget *parent = 0);
    private:
        QTabWidget *tabWidget;
};

class CommunicationTab : public QWidget
{
    Q_OBJECT

 public:
    QSqlDatabase db;
    QSqlQuery qry;
    QSqlQuery qry1;
    QLineEdit *printer_portedit;
    QLineEdit *portedit;
    QComboBox *baudbox;
    QComboBox *databitsbox;
    QComboBox *paritybox;
    QComboBox *stopbitsbox;
    QRadioButton *radiobutton1;
    QRadioButton *radiobutton2;
    QDialogButtonBox buttonBox;
    explicit CommunicationTab(QWidget *parent = 0);

private slots:
    void on_accept_click();
    void on_default_click();

};

class PreferencesTab : public QWidget
{
    Q_OBJECT

 public:
    QRadioButton *manualbutton;
    QRadioButton *autobutton;
    QLineEdit *dataedit;
    QLineEdit *weightedit;
    QPushButton *save;
    QPushButton *reset;
    QSqlDatabase db;
    QSqlQuery qry;
    QSqlQuery qry1;
    explicit PreferencesTab(QWidget *parent = 0);

private slots:
     void on_save_click();
};

class HeadFootTab : public QWidget
{
    Q_OBJECT

public:
    QSqlDatabase db;
    QSqlQuery qry;
    QLineEdit *headernameedit;
    QLineEdit *footernameedit;
    explicit HeadFootTab(QWidget *parent = 0);

private slots:
    void on_setbutton_click();

};

class ChPwdTab : public QWidget
{
    Q_OBJECT

 public:
    QSqlDatabase db;
    QSqlQuery qry;
    QLineEdit *oldpassedit;
    QLineEdit *newpassedit;
    QLabel *status;
    QPushButton *changebutton;
    explicit ChPwdTab(QWidget *parent = 0);

private slots:
     void on_changebutton_click();

};

class DelRecordTab : public QWidget
{
    Q_OBJECT

 public:
     explicit DelRecordTab(QWidget *parent = 0);
     QSqlDatabase db;
     QSqlQuery qry ;
     QLineEdit *passwordedit;
     QPushButton *loginbutton;
     QPushButton *logoutbutton;
     QLineEdit *recieptedit;
     QPushButton *checkbutton;
     QPushButton *deletebutton;
     QPlainTextEdit *detailtextedit;

 private slots:

     void on_loginbutton_click();
     void on_logoutbutton_click();
     void on_checkbutton_click();
     void on_deletebutton_click();

};

class SetupTab : public QWidget
{
    Q_OBJECT

 public:
     explicit SetupTab(QWidget *parent = 0);
     QSqlDatabase db;
     QSqlQuery qry ;
     QComboBox *resolution_combobox;
     QLineEdit *Oldweight_edit;
     QLineEdit *Newweight_edit;
     QPushButton *smart_button;
     QPushButton *reset_calib_button;
     QPushButton *save_button;
     QPushButton *reset_button;

 private slots:

     void on_save_button_click();
     void on_reset_button_click();
     void on_smart_button_click();
     void on_reset_calib_button_click();

};

class LoadcellTab : public QWidget
{
    Q_OBJECT

 public:
     explicit LoadcellTab(QWidget *parent = 0);
    ~LoadcellTab();

     QextSerialPort *port;
     QSqlDatabase    db;
     QSqlQuery       qry ;
     QRadioButton   *one_radiobutton;
     QRadioButton   *two_radiobutton;
     QRadioButton   *four_radiobutton;
     QRadioButton   *six_radiobutton;
     QRadioButton   *eight_radiobutton;
     QLabel         *DLC1_Label;
     QLabel         *DLC2_Label;
     QLabel         *DLC3_Label;
     QLabel         *DLC4_Label;
     QLabel         *DLC5_Label;
     QLabel         *DLC6_Label;
     QLabel         *DLC7_Label;
     QLabel         *DLC8_Label;
     QPushButton    *register_DLC1_button;
     QPushButton    *register_DLC2_button;
     QPushButton    *register_DLC3_button;
     QPushButton    *register_DLC4_button;
     QPushButton    *register_DLC5_button;
     QPushButton    *register_DLC6_button;
     QPushButton    *register_DLC7_button;
     QPushButton    *register_DLC8_button;
     QComboBox      *DLC1_offset;
     QComboBox      *DLC2_offset;
     QComboBox      *DLC3_offset;
     QComboBox      *DLC4_offset;
     QComboBox      *DLC5_offset;
     QComboBox      *DLC6_offset;
     QComboBox      *DLC7_offset;
     QComboBox      *DLC8_offset;
     QLabel         *DLC1_Count_Label;
     QLabel         *DLC2_Count_Label;
     QLabel         *DLC3_Count_Label;
     QLabel         *DLC4_Count_Label;
     QLabel         *DLC5_Count_Label;
     QLabel         *DLC6_Count_Label;
     QLabel         *DLC7_Count_Label;
     QLabel         *DLC8_Count_Label;
     QLabel         *DLC1_status;
     QLabel         *DLC2_status;
     QLabel         *DLC3_status;
     QLabel         *DLC4_status;
     QLabel         *DLC5_status;
     QLabel         *DLC6_status;
     QLabel         *DLC7_status;
     QLabel         *DLC8_status;
     QPushButton    *save_button;
     QPushButton    *reset_button;
     QPushButton    *TestDLC_button;

 private slots:

     void on_one_radiobutton_click();
     void on_two_radiobutton_click();
     void on_four_radiobutton_click();
     void on_six_radiobutton_click();
     void on_eight_radiobutton_click();

     void on_register_DLC1_button_click();
     void on_register_DLC2_button_click();
     void on_register_DLC3_button_click();
     void on_register_DLC4_button_click();
     void on_register_DLC5_button_click();
     void on_register_DLC6_button_click();
     void on_register_DLC7_button_click();
     void on_register_DLC8_button_click();

     void on_save_button_click();
     void on_reset_button_click();
     void on_TestDLC_button_button_click();

     void clear_status();


};

#endif // TABSET_H
