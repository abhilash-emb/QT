/********************************************************************************
** Form generated from reading UI file 'adminlogin.ui'
**
** Created: Sat Sep 7 12:32:19 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINLOGIN_H
#define UI_ADMINLOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_adminlogin
{
public:
    QFrame *admin_image;
    QLineEdit *password_edit;
    QPushButton *okbutton;

    void setupUi(QDialog *adminlogin)
    {
        if (adminlogin->objectName().isEmpty())
            adminlogin->setObjectName(QString::fromUtf8("adminlogin"));
        adminlogin->resize(255, 40);
        adminlogin->setMinimumSize(QSize(255, 40));
        adminlogin->setMaximumSize(QSize(255, 40));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/images/Admin.ico"), QSize(), QIcon::Normal, QIcon::Off);
        adminlogin->setWindowIcon(icon);
        admin_image = new QFrame(adminlogin);
        admin_image->setObjectName(QString::fromUtf8("admin_image"));
        admin_image->setGeometry(QRect(4, 4, 31, 31));
        admin_image->setStyleSheet(QString::fromUtf8("image: url(:/new/images/Admin.ico);"));
        admin_image->setFrameShape(QFrame::StyledPanel);
        admin_image->setFrameShadow(QFrame::Raised);
        password_edit = new QLineEdit(adminlogin);
        password_edit->setObjectName(QString::fromUtf8("password_edit"));
        password_edit->setGeometry(QRect(41, 7, 161, 25));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        password_edit->setFont(font);
        password_edit->setMaxLength(20);
        password_edit->setEchoMode(QLineEdit::Password);
        password_edit->setAlignment(Qt::AlignCenter);
        okbutton = new QPushButton(adminlogin);
        okbutton->setObjectName(QString::fromUtf8("okbutton"));
        okbutton->setGeometry(QRect(210, 6, 41, 27));

        retranslateUi(adminlogin);

        QMetaObject::connectSlotsByName(adminlogin);
    } // setupUi

    void retranslateUi(QDialog *adminlogin)
    {
        adminlogin->setWindowTitle(QApplication::translate("adminlogin", "Admin Login", 0, QApplication::UnicodeUTF8));
        okbutton->setText(QApplication::translate("adminlogin", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class adminlogin: public Ui_adminlogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINLOGIN_H
