/********************************************************************************
** Form generated from reading UI file 'sampletab.ui'
**
** Created: Thu Nov 15 18:22:32 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAMPLETAB_H
#define UI_SAMPLETAB_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sampletab
{
public:
    QWidget *communication;
    QGroupBox *groupBox;
    QRadioButton *radiobutton1;
    QRadioButton *radiobutton2;
    QGroupBox *groupBox_2;
    QComboBox *stopbitsbox;
    QComboBox *databitsbox;
    QComboBox *paritybox;
    QComboBox *portbox;
    QComboBox *baudbox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *accept;
    QPushButton *cancel;
    QWidget *prefrences;
    QGroupBox *groupBox_3;
    QRadioButton *radiobutton1_2;
    QRadioButton *radiobutton2_2;
    QWidget *headerfooter;
    QLineEdit *headernameedit;
    QLineEdit *footernameedit;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *setbutton;
    QWidget *changepassword;
    QLineEdit *oldpassedit;
    QLineEdit *newpassedit;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *changebutton;
    QWidget *deleterecord;
    QLabel *label_10;
    QLineEdit *passwordedit;
    QPushButton *loginbutton;
    QPushButton *logoutbutton;
    QLabel *label_11;
    QLineEdit *recieptedit;
    QPushButton *checkbutton;
    QPushButton *deletebutton;
    QTextEdit *detailtextedit;
    QLabel *label_12;

    void setupUi(QTabWidget *sampletab)
    {
        if (sampletab->objectName().isEmpty())
            sampletab->setObjectName(QString::fromUtf8("sampletab"));
        sampletab->resize(480, 430);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sampletab->sizePolicy().hasHeightForWidth());
        sampletab->setSizePolicy(sizePolicy);
        communication = new QWidget();
        communication->setObjectName(QString::fromUtf8("communication"));
        groupBox = new QGroupBox(communication);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 220, 191, 61));
        radiobutton1 = new QRadioButton(groupBox);
        radiobutton1->setObjectName(QString::fromUtf8("radiobutton1"));
        radiobutton1->setGeometry(QRect(20, 30, 82, 17));
        radiobutton1->setChecked(false);
        radiobutton2 = new QRadioButton(groupBox);
        radiobutton2->setObjectName(QString::fromUtf8("radiobutton2"));
        radiobutton2->setGeometry(QRect(100, 30, 82, 17));
        radiobutton2->setChecked(true);
        groupBox_2 = new QGroupBox(communication);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(210, 80, 261, 201));
        stopbitsbox = new QComboBox(groupBox_2);
        stopbitsbox->setObjectName(QString::fromUtf8("stopbitsbox"));
        stopbitsbox->setGeometry(QRect(150, 150, 91, 22));
        databitsbox = new QComboBox(groupBox_2);
        databitsbox->setObjectName(QString::fromUtf8("databitsbox"));
        databitsbox->setGeometry(QRect(150, 90, 91, 22));
        paritybox = new QComboBox(groupBox_2);
        paritybox->setObjectName(QString::fromUtf8("paritybox"));
        paritybox->setGeometry(QRect(150, 120, 91, 22));
        portbox = new QComboBox(groupBox_2);
        portbox->setObjectName(QString::fromUtf8("portbox"));
        portbox->setGeometry(QRect(150, 30, 91, 22));
        baudbox = new QComboBox(groupBox_2);
        baudbox->setObjectName(QString::fromUtf8("baudbox"));
        baudbox->setGeometry(QRect(150, 60, 91, 22));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 31, 101, 20));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 60, 101, 21));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 91, 101, 20));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 120, 101, 21));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 150, 101, 21));
        stopbitsbox->raise();
        databitsbox->raise();
        portbox->raise();
        paritybox->raise();
        baudbox->raise();
        stopbitsbox->raise();
        databitsbox->raise();
        paritybox->raise();
        portbox->raise();
        baudbox->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        accept = new QPushButton(communication);
        accept->setObjectName(QString::fromUtf8("accept"));
        accept->setGeometry(QRect(120, 320, 90, 30));
        cancel = new QPushButton(communication);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(260, 320, 90, 30));
        sampletab->addTab(communication, QString());
        prefrences = new QWidget();
        prefrences->setObjectName(QString::fromUtf8("prefrences"));
        groupBox_3 = new QGroupBox(prefrences);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(100, 80, 261, 51));
        radiobutton1_2 = new QRadioButton(groupBox_3);
        radiobutton1_2->setObjectName(QString::fromUtf8("radiobutton1_2"));
        radiobutton1_2->setGeometry(QRect(40, 20, 81, 21));
        radiobutton1_2->setChecked(true);
        radiobutton2_2 = new QRadioButton(groupBox_3);
        radiobutton2_2->setObjectName(QString::fromUtf8("radiobutton2_2"));
        radiobutton2_2->setGeometry(QRect(180, 20, 82, 21));
        sampletab->addTab(prefrences, QString());
        headerfooter = new QWidget();
        headerfooter->setObjectName(QString::fromUtf8("headerfooter"));
        headernameedit = new QLineEdit(headerfooter);
        headernameedit->setObjectName(QString::fromUtf8("headernameedit"));
        headernameedit->setGeometry(QRect(130, 80, 280, 22));
        footernameedit = new QLineEdit(headerfooter);
        footernameedit->setObjectName(QString::fromUtf8("footernameedit"));
        footernameedit->setGeometry(QRect(130, 110, 280, 22));
        label_6 = new QLabel(headerfooter);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(70, 81, 41, 20));
        label_7 = new QLabel(headerfooter);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(70, 110, 41, 21));
        setbutton = new QPushButton(headerfooter);
        setbutton->setObjectName(QString::fromUtf8("setbutton"));
        setbutton->setGeometry(QRect(200, 170, 90, 25));
        sampletab->addTab(headerfooter, QString());
        changepassword = new QWidget();
        changepassword->setObjectName(QString::fromUtf8("changepassword"));
        oldpassedit = new QLineEdit(changepassword);
        oldpassedit->setObjectName(QString::fromUtf8("oldpassedit"));
        oldpassedit->setGeometry(QRect(130, 80, 280, 22));
        newpassedit = new QLineEdit(changepassword);
        newpassedit->setObjectName(QString::fromUtf8("newpassedit"));
        newpassedit->setGeometry(QRect(130, 110, 280, 22));
        label_8 = new QLabel(changepassword);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(50, 80, 71, 21));
        label_9 = new QLabel(changepassword);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(50, 110, 71, 21));
        changebutton = new QPushButton(changepassword);
        changebutton->setObjectName(QString::fromUtf8("changebutton"));
        changebutton->setGeometry(QRect(200, 170, 90, 25));
        sampletab->addTab(changepassword, QString());
        deleterecord = new QWidget();
        deleterecord->setObjectName(QString::fromUtf8("deleterecord"));
        label_10 = new QLabel(deleterecord);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(5, 0, 71, 20));
        passwordedit = new QLineEdit(deleterecord);
        passwordedit->setObjectName(QString::fromUtf8("passwordedit"));
        passwordedit->setGeometry(QRect(5, 20, 296, 23));
        loginbutton = new QPushButton(deleterecord);
        loginbutton->setObjectName(QString::fromUtf8("loginbutton"));
        loginbutton->setGeometry(QRect(305, 20, 81, 23));
        logoutbutton = new QPushButton(deleterecord);
        logoutbutton->setObjectName(QString::fromUtf8("logoutbutton"));
        logoutbutton->setGeometry(QRect(390, 20, 81, 23));
        label_11 = new QLabel(deleterecord);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(5, 45, 71, 18));
        recieptedit = new QLineEdit(deleterecord);
        recieptedit->setObjectName(QString::fromUtf8("recieptedit"));
        recieptedit->setGeometry(QRect(5, 65, 296, 23));
        checkbutton = new QPushButton(deleterecord);
        checkbutton->setObjectName(QString::fromUtf8("checkbutton"));
        checkbutton->setGeometry(QRect(305, 65, 81, 23));
        deletebutton = new QPushButton(deleterecord);
        deletebutton->setObjectName(QString::fromUtf8("deletebutton"));
        deletebutton->setGeometry(QRect(390, 65, 81, 23));
        detailtextedit = new QTextEdit(deleterecord);
        detailtextedit->setObjectName(QString::fromUtf8("detailtextedit"));
        detailtextedit->setGeometry(QRect(5, 112, 466, 289));
        label_12 = new QLabel(deleterecord);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(5, 91, 81, 16));
        sampletab->addTab(deleterecord, QString());

        retranslateUi(sampletab);

        sampletab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(sampletab);
    } // setupUi

    void retranslateUi(QTabWidget *sampletab)
    {
        sampletab->setWindowTitle(QApplication::translate("sampletab", "TabWidget", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("sampletab", "Termination", 0, QApplication::UnicodeUTF8));
        radiobutton1->setText(QApplication::translate("sampletab", "CR", 0, QApplication::UnicodeUTF8));
        radiobutton2->setText(QApplication::translate("sampletab", "CR / LF", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("sampletab", "Port Settings", 0, QApplication::UnicodeUTF8));
        stopbitsbox->clear();
        stopbitsbox->insertItems(0, QStringList()
         << QApplication::translate("sampletab", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("sampletab", "2", 0, QApplication::UnicodeUTF8)
        );
        databitsbox->clear();
        databitsbox->insertItems(0, QStringList()
         << QApplication::translate("sampletab", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("sampletab", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("sampletab", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("sampletab", "8", 0, QApplication::UnicodeUTF8)
        );
        paritybox->clear();
        paritybox->insertItems(0, QStringList()
         << QApplication::translate("sampletab", "NONE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("sampletab", "ODD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("sampletab", "EVEN", 0, QApplication::UnicodeUTF8)
        );
        portbox->clear();
        portbox->insertItems(0, QStringList()
         << QApplication::translate("sampletab", "COM1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("sampletab", "COM2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("sampletab", "COM3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("sampletab", "COM4", 0, QApplication::UnicodeUTF8)
        );
        baudbox->clear();
        baudbox->insertItems(0, QStringList()
         << QApplication::translate("sampletab", "1200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("sampletab", "2400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("sampletab", "4800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("sampletab", "9600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("sampletab", "19200", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("sampletab", "Port Number", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("sampletab", "Baud Rate", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("sampletab", "Number of Bits", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("sampletab", "Parity", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("sampletab", "No of Stop Bits", 0, QApplication::UnicodeUTF8));
        accept->setText(QApplication::translate("sampletab", "Accept", 0, QApplication::UnicodeUTF8));
        cancel->setText(QApplication::translate("sampletab", "Cancel", 0, QApplication::UnicodeUTF8));
        sampletab->setTabText(sampletab->indexOf(communication), QApplication::translate("sampletab", "Communication", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("sampletab", "Options", 0, QApplication::UnicodeUTF8));
        radiobutton1_2->setText(QApplication::translate("sampletab", "Manual", 0, QApplication::UnicodeUTF8));
        radiobutton2_2->setText(QApplication::translate("sampletab", "Auto", 0, QApplication::UnicodeUTF8));
        sampletab->setTabText(sampletab->indexOf(prefrences), QApplication::translate("sampletab", "Preferences", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("sampletab", "Header", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("sampletab", "Footer", 0, QApplication::UnicodeUTF8));
        setbutton->setText(QApplication::translate("sampletab", "Set", 0, QApplication::UnicodeUTF8));
        sampletab->setTabText(sampletab->indexOf(headerfooter), QApplication::translate("sampletab", "Header Footer", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("sampletab", "Old Password", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("sampletab", "New Password", 0, QApplication::UnicodeUTF8));
        changebutton->setText(QApplication::translate("sampletab", "Change", 0, QApplication::UnicodeUTF8));
        sampletab->setTabText(sampletab->indexOf(changepassword), QApplication::translate("sampletab", "Change Password", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("sampletab", "Password", 0, QApplication::UnicodeUTF8));
        loginbutton->setText(QApplication::translate("sampletab", "Login", 0, QApplication::UnicodeUTF8));
        logoutbutton->setText(QApplication::translate("sampletab", "Logout", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("sampletab", "Receipt No", 0, QApplication::UnicodeUTF8));
        checkbutton->setText(QApplication::translate("sampletab", "Check", 0, QApplication::UnicodeUTF8));
        deletebutton->setText(QApplication::translate("sampletab", "Delete", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("sampletab", "Receipt Detals", 0, QApplication::UnicodeUTF8));
        sampletab->setTabText(sampletab->indexOf(deleterecord), QApplication::translate("sampletab", "Delete  Record", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class sampletab: public Ui_sampletab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAMPLETAB_H
