/********************************************************************************
** Form generated from reading UI file 'administrator.ui'
**
** Created: Wed Nov 6 16:29:06 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTRATOR_H
#define UI_ADMINISTRATOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_administrator
{
public:
    QGroupBox *operatormodifygroupBox;
    QLineEdit *operatorusername;
    QLabel *operatorusernamelabel;
    QGroupBox *resetpasswordgroup;
    QLineEdit *newpassword;
    QPushButton *resetbutton;
    QGroupBox *deletegroup;
    QPushButton *deletebutton;
    QPushButton *okbutton;
    QPushButton *opusercancelbutton;
    QGroupBox *settingsgroup;
    QGroupBox *admingroup;
    QLabel *olpasswordlabel;
    QLabel *newpasswordlabel;
    QLineEdit *oldpassedit;
    QLineEdit *newpassedit;
    QPushButton *passokbutton;
    QPushButton *changebutton;
    QPushButton *passcancelbutton;
    QGroupBox *scanintervalgroup;
    QRadioButton *radiobutton2secs;
    QRadioButton *radiobutton3secs;
    QRadioButton *radiobutton4secs;
    QGroupBox *headerfootergroup;
    QLineEdit *header;
    QLineEdit *footer;
    QLabel *label;
    QLabel *label_2;
    QPushButton *cancelbutton;
    QPushButton *savebutton;
    QGroupBox *deviceselectgroup;
    QComboBox *devicecombobox;
    QLabel *devicelabel;
    QGroupBox *newoperatorgroup;
    QLineEdit *newusernameedit;
    QPushButton *newpasscancelbutton;
    QLabel *newpaawordlabel;
    QPushButton *newpassokbutton;

    void setupUi(QDialog *administrator)
    {
        if (administrator->objectName().isEmpty())
            administrator->setObjectName(QString::fromUtf8("administrator"));
        administrator->resize(495, 560);
        administrator->setMinimumSize(QSize(494, 494));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        administrator->setWindowIcon(icon);
        operatormodifygroupBox = new QGroupBox(administrator);
        operatormodifygroupBox->setObjectName(QString::fromUtf8("operatormodifygroupBox"));
        operatormodifygroupBox->setGeometry(QRect(7, 80, 481, 131));
        operatorusername = new QLineEdit(operatormodifygroupBox);
        operatorusername->setObjectName(QString::fromUtf8("operatorusername"));
        operatorusername->setGeometry(QRect(154, 20, 151, 22));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font.setPointSize(9);
        operatorusername->setFont(font);
        operatorusername->setMaxLength(30);
        operatorusername->setAlignment(Qt::AlignCenter);
        operatorusernamelabel = new QLabel(operatormodifygroupBox);
        operatorusernamelabel->setObjectName(QString::fromUtf8("operatorusernamelabel"));
        operatorusernamelabel->setGeometry(QRect(24, 20, 121, 22));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font1.setBold(true);
        font1.setWeight(75);
        operatorusernamelabel->setFont(font1);
        operatorusernamelabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        resetpasswordgroup = new QGroupBox(operatormodifygroupBox);
        resetpasswordgroup->setObjectName(QString::fromUtf8("resetpasswordgroup"));
        resetpasswordgroup->setEnabled(false);
        resetpasswordgroup->setGeometry(QRect(10, 49, 225, 71));
        newpassword = new QLineEdit(resetpasswordgroup);
        newpassword->setObjectName(QString::fromUtf8("newpassword"));
        newpassword->setGeometry(QRect(15, 30, 131, 22));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setWeight(75);
        newpassword->setFont(font2);
        newpassword->setMaxLength(30);
        newpassword->setEchoMode(QLineEdit::Password);
        newpassword->setAlignment(Qt::AlignCenter);
        resetbutton = new QPushButton(resetpasswordgroup);
        resetbutton->setObjectName(QString::fromUtf8("resetbutton"));
        resetbutton->setGeometry(QRect(151, 29, 61, 24));
        resetbutton->setFont(font1);
        deletegroup = new QGroupBox(operatormodifygroupBox);
        deletegroup->setObjectName(QString::fromUtf8("deletegroup"));
        deletegroup->setEnabled(false);
        deletegroup->setGeometry(QRect(247, 50, 225, 71));
        deletebutton = new QPushButton(deletegroup);
        deletebutton->setObjectName(QString::fromUtf8("deletebutton"));
        deletebutton->setGeometry(QRect(51, 26, 121, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setWeight(75);
        deletebutton->setFont(font3);
        deletebutton->setStyleSheet(QString::fromUtf8("color: rgb(252, 9, 0);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/images/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        deletebutton->setIcon(icon1);
        deletebutton->setIconSize(QSize(18, 17));
        okbutton = new QPushButton(operatormodifygroupBox);
        okbutton->setObjectName(QString::fromUtf8("okbutton"));
        okbutton->setGeometry(QRect(311, 19, 65, 24));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial Unicode MS"));
        okbutton->setFont(font4);
        opusercancelbutton = new QPushButton(operatormodifygroupBox);
        opusercancelbutton->setObjectName(QString::fromUtf8("opusercancelbutton"));
        opusercancelbutton->setGeometry(QRect(380, 19, 65, 24));
        opusercancelbutton->setFont(font4);
        settingsgroup = new QGroupBox(administrator);
        settingsgroup->setObjectName(QString::fromUtf8("settingsgroup"));
        settingsgroup->setGeometry(QRect(7, 225, 481, 328));
        admingroup = new QGroupBox(settingsgroup);
        admingroup->setObjectName(QString::fromUtf8("admingroup"));
        admingroup->setGeometry(QRect(10, 166, 301, 151));
        olpasswordlabel = new QLabel(admingroup);
        olpasswordlabel->setObjectName(QString::fromUtf8("olpasswordlabel"));
        olpasswordlabel->setGeometry(QRect(10, 40, 71, 21));
        olpasswordlabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        newpasswordlabel = new QLabel(admingroup);
        newpasswordlabel->setObjectName(QString::fromUtf8("newpasswordlabel"));
        newpasswordlabel->setEnabled(false);
        newpasswordlabel->setGeometry(QRect(10, 70, 71, 21));
        newpasswordlabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        oldpassedit = new QLineEdit(admingroup);
        oldpassedit->setObjectName(QString::fromUtf8("oldpassedit"));
        oldpassedit->setGeometry(QRect(90, 40, 151, 20));
        oldpassedit->setFont(font3);
        oldpassedit->setMaxLength(30);
        oldpassedit->setEchoMode(QLineEdit::Password);
        oldpassedit->setAlignment(Qt::AlignCenter);
        newpassedit = new QLineEdit(admingroup);
        newpassedit->setObjectName(QString::fromUtf8("newpassedit"));
        newpassedit->setEnabled(false);
        newpassedit->setGeometry(QRect(90, 70, 151, 20));
        newpassedit->setFont(font3);
        newpassedit->setMaxLength(30);
        newpassedit->setEchoMode(QLineEdit::Password);
        newpassedit->setAlignment(Qt::AlignCenter);
        passokbutton = new QPushButton(admingroup);
        passokbutton->setObjectName(QString::fromUtf8("passokbutton"));
        passokbutton->setGeometry(QRect(244, 39, 47, 23));
        passokbutton->setFont(font4);
        changebutton = new QPushButton(admingroup);
        changebutton->setObjectName(QString::fromUtf8("changebutton"));
        changebutton->setEnabled(false);
        changebutton->setGeometry(QRect(70, 110, 75, 24));
        passcancelbutton = new QPushButton(admingroup);
        passcancelbutton->setObjectName(QString::fromUtf8("passcancelbutton"));
        passcancelbutton->setEnabled(false);
        passcancelbutton->setGeometry(QRect(150, 110, 75, 24));
        scanintervalgroup = new QGroupBox(settingsgroup);
        scanintervalgroup->setObjectName(QString::fromUtf8("scanintervalgroup"));
        scanintervalgroup->setGeometry(QRect(320, 166, 151, 118));
        radiobutton2secs = new QRadioButton(scanintervalgroup);
        radiobutton2secs->setObjectName(QString::fromUtf8("radiobutton2secs"));
        radiobutton2secs->setGeometry(QRect(52, 24, 51, 17));
        radiobutton2secs->setChecked(false);
        radiobutton3secs = new QRadioButton(scanintervalgroup);
        radiobutton3secs->setObjectName(QString::fromUtf8("radiobutton3secs"));
        radiobutton3secs->setGeometry(QRect(52, 54, 51, 17));
        radiobutton3secs->setChecked(true);
        radiobutton4secs = new QRadioButton(scanintervalgroup);
        radiobutton4secs->setObjectName(QString::fromUtf8("radiobutton4secs"));
        radiobutton4secs->setGeometry(QRect(52, 84, 51, 17));
        headerfootergroup = new QGroupBox(settingsgroup);
        headerfootergroup->setObjectName(QString::fromUtf8("headerfootergroup"));
        headerfootergroup->setGeometry(QRect(10, 79, 461, 80));
        header = new QLineEdit(headerfootergroup);
        header->setObjectName(QString::fromUtf8("header"));
        header->setGeometry(QRect(70, 19, 381, 22));
        header->setFont(font4);
        header->setMaxLength(100);
        footer = new QLineEdit(headerfootergroup);
        footer->setObjectName(QString::fromUtf8("footer"));
        footer->setGeometry(QRect(70, 46, 381, 22));
        footer->setFont(font4);
        footer->setMaxLength(100);
        label = new QLabel(headerfootergroup);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 51, 22));
        label->setFont(font1);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(headerfootergroup);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 46, 51, 22));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cancelbutton = new QPushButton(settingsgroup);
        cancelbutton->setObjectName(QString::fromUtf8("cancelbutton"));
        cancelbutton->setGeometry(QRect(400, 290, 73, 27));
        savebutton = new QPushButton(settingsgroup);
        savebutton->setObjectName(QString::fromUtf8("savebutton"));
        savebutton->setGeometry(QRect(320, 290, 73, 27));
        deviceselectgroup = new QGroupBox(settingsgroup);
        deviceselectgroup->setObjectName(QString::fromUtf8("deviceselectgroup"));
        deviceselectgroup->setGeometry(QRect(10, 18, 461, 55));
        devicecombobox = new QComboBox(deviceselectgroup);
        devicecombobox->setObjectName(QString::fromUtf8("devicecombobox"));
        devicecombobox->setGeometry(QRect(190, 20, 181, 22));
        devicecombobox->setFont(font4);
        devicelabel = new QLabel(deviceselectgroup);
        devicelabel->setObjectName(QString::fromUtf8("devicelabel"));
        devicelabel->setGeometry(QRect(100, 20, 81, 21));
        devicelabel->setFont(font1);
        devicelabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        newoperatorgroup = new QGroupBox(administrator);
        newoperatorgroup->setObjectName(QString::fromUtf8("newoperatorgroup"));
        newoperatorgroup->setGeometry(QRect(7, 10, 481, 61));
        newusernameedit = new QLineEdit(newoperatorgroup);
        newusernameedit->setObjectName(QString::fromUtf8("newusernameedit"));
        newusernameedit->setGeometry(QRect(175, 23, 151, 22));
        newusernameedit->setFont(font4);
        newusernameedit->setMaxLength(30);
        newusernameedit->setAlignment(Qt::AlignCenter);
        newpasscancelbutton = new QPushButton(newoperatorgroup);
        newpasscancelbutton->setObjectName(QString::fromUtf8("newpasscancelbutton"));
        newpasscancelbutton->setGeometry(QRect(396, 22, 60, 24));
        newpasscancelbutton->setFont(font4);
        newpaawordlabel = new QLabel(newoperatorgroup);
        newpaawordlabel->setObjectName(QString::fromUtf8("newpaawordlabel"));
        newpaawordlabel->setGeometry(QRect(17, 23, 151, 22));
        newpaawordlabel->setFont(font1);
        newpaawordlabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        newpassokbutton = new QPushButton(newoperatorgroup);
        newpassokbutton->setObjectName(QString::fromUtf8("newpassokbutton"));
        newpassokbutton->setGeometry(QRect(332, 22, 60, 24));
        newpassokbutton->setFont(font4);
        QWidget::setTabOrder(newusernameedit, newpassokbutton);
        QWidget::setTabOrder(newpassokbutton, newpasscancelbutton);
        QWidget::setTabOrder(newpasscancelbutton, operatorusername);
        QWidget::setTabOrder(operatorusername, okbutton);
        QWidget::setTabOrder(okbutton, opusercancelbutton);
        QWidget::setTabOrder(opusercancelbutton, newpassword);
        QWidget::setTabOrder(newpassword, resetbutton);
        QWidget::setTabOrder(resetbutton, deletebutton);
        QWidget::setTabOrder(deletebutton, devicecombobox);
        QWidget::setTabOrder(devicecombobox, header);
        QWidget::setTabOrder(header, footer);
        QWidget::setTabOrder(footer, oldpassedit);
        QWidget::setTabOrder(oldpassedit, passokbutton);
        QWidget::setTabOrder(passokbutton, newpassedit);
        QWidget::setTabOrder(newpassedit, changebutton);
        QWidget::setTabOrder(changebutton, passcancelbutton);
        QWidget::setTabOrder(passcancelbutton, radiobutton2secs);
        QWidget::setTabOrder(radiobutton2secs, radiobutton3secs);
        QWidget::setTabOrder(radiobutton3secs, radiobutton4secs);
        QWidget::setTabOrder(radiobutton4secs, savebutton);
        QWidget::setTabOrder(savebutton, cancelbutton);

        retranslateUi(administrator);

        QMetaObject::connectSlotsByName(administrator);
    } // setupUi

    void retranslateUi(QDialog *administrator)
    {
        administrator->setWindowTitle(QApplication::translate("administrator", "Settings", 0, QApplication::UnicodeUTF8));
        operatormodifygroupBox->setTitle(QApplication::translate("administrator", "Operator Modify", 0, QApplication::UnicodeUTF8));
        operatorusernamelabel->setText(QApplication::translate("administrator", "Operator Username", 0, QApplication::UnicodeUTF8));
        resetpasswordgroup->setTitle(QApplication::translate("administrator", "Reset Operator Password", 0, QApplication::UnicodeUTF8));
        resetbutton->setText(QApplication::translate("administrator", "Reset", 0, QApplication::UnicodeUTF8));
        deletegroup->setTitle(QApplication::translate("administrator", "Delete Operator", 0, QApplication::UnicodeUTF8));
        deletebutton->setText(QApplication::translate("administrator", "Delete", 0, QApplication::UnicodeUTF8));
        okbutton->setText(QApplication::translate("administrator", "OK", 0, QApplication::UnicodeUTF8));
        opusercancelbutton->setText(QApplication::translate("administrator", "Cancel", 0, QApplication::UnicodeUTF8));
        settingsgroup->setTitle(QApplication::translate("administrator", "Application Settings", 0, QApplication::UnicodeUTF8));
        admingroup->setTitle(QApplication::translate("administrator", "Admin Password Change", 0, QApplication::UnicodeUTF8));
        olpasswordlabel->setText(QApplication::translate("administrator", "Old Password", 0, QApplication::UnicodeUTF8));
        newpasswordlabel->setText(QApplication::translate("administrator", "New Password", 0, QApplication::UnicodeUTF8));
        passokbutton->setText(QApplication::translate("administrator", "OK", 0, QApplication::UnicodeUTF8));
        changebutton->setText(QApplication::translate("administrator", "Change", 0, QApplication::UnicodeUTF8));
        passcancelbutton->setText(QApplication::translate("administrator", "Cancel", 0, QApplication::UnicodeUTF8));
        scanintervalgroup->setTitle(QApplication::translate("administrator", "Scan Interval", 0, QApplication::UnicodeUTF8));
        radiobutton2secs->setText(QApplication::translate("administrator", "2 Secs", 0, QApplication::UnicodeUTF8));
        radiobutton3secs->setText(QApplication::translate("administrator", "3 Secs", 0, QApplication::UnicodeUTF8));
        radiobutton4secs->setText(QApplication::translate("administrator", "4 Secs", 0, QApplication::UnicodeUTF8));
        headerfootergroup->setTitle(QApplication::translate("administrator", "Header-Footer", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("administrator", "Header", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("administrator", "Footer", 0, QApplication::UnicodeUTF8));
        cancelbutton->setText(QApplication::translate("administrator", "Cancel", 0, QApplication::UnicodeUTF8));
        savebutton->setText(QApplication::translate("administrator", "Save", 0, QApplication::UnicodeUTF8));
        deviceselectgroup->setTitle(QApplication::translate("administrator", "Device select", 0, QApplication::UnicodeUTF8));
        devicecombobox->clear();
        devicecombobox->insertItems(0, QStringList()
         << QApplication::translate("administrator", "Sansui", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("administrator", "Accurate Scales", 0, QApplication::UnicodeUTF8)
        );
        devicelabel->setText(QApplication::translate("administrator", "Device Name", 0, QApplication::UnicodeUTF8));
        newoperatorgroup->setTitle(QApplication::translate("administrator", "Add New Operator", 0, QApplication::UnicodeUTF8));
        newpasscancelbutton->setText(QApplication::translate("administrator", "Cancel", 0, QApplication::UnicodeUTF8));
        newpaawordlabel->setText(QApplication::translate("administrator", "New Operator Username", 0, QApplication::UnicodeUTF8));
        newpassokbutton->setText(QApplication::translate("administrator", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class administrator: public Ui_administrator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRATOR_H
