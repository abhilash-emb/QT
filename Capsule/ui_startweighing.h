/********************************************************************************
** Form generated from reading UI file 'startweighing.ui'
**
** Created: Wed Nov 6 16:29:06 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWEIGHING_H
#define UI_STARTWEIGHING_H

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

class Ui_startweighing
{
public:
    QFrame *loginwindowframe;
    QLineEdit *usernameedit;
    QLineEdit *passwordedit;
    QPushButton *okbutton;
    QPushButton *cancelbutton;
    QFrame *loginuserframe;
    QFrame *userframe;
    QFrame *passwordframe;

    void setupUi(QDialog *startweighing)
    {
        if (startweighing->objectName().isEmpty())
            startweighing->setObjectName(QString::fromUtf8("startweighing"));
        startweighing->resize(270, 344);
        startweighing->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/images/user.ico"), QSize(), QIcon::Normal, QIcon::Off);
        startweighing->setWindowIcon(icon);
        loginwindowframe = new QFrame(startweighing);
        loginwindowframe->setObjectName(QString::fromUtf8("loginwindowframe"));
        loginwindowframe->setGeometry(QRect(-10, -20, 291, 371));
        loginwindowframe->setStyleSheet(QString::fromUtf8("image: url(:/new/images/operatorlogin.png);"));
        loginwindowframe->setFrameShape(QFrame::StyledPanel);
        loginwindowframe->setFrameShadow(QFrame::Raised);
        usernameedit = new QLineEdit(loginwindowframe);
        usernameedit->setObjectName(QString::fromUtf8("usernameedit"));
        usernameedit->setGeometry(QRect(48, 210, 187, 24));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        usernameedit->setFont(font);
        usernameedit->setMaxLength(30);
        usernameedit->setAlignment(Qt::AlignCenter);
        passwordedit = new QLineEdit(loginwindowframe);
        passwordedit->setObjectName(QString::fromUtf8("passwordedit"));
        passwordedit->setGeometry(QRect(48, 238, 187, 24));
        passwordedit->setFont(font);
        passwordedit->setMaxLength(30);
        passwordedit->setEchoMode(QLineEdit::Password);
        passwordedit->setAlignment(Qt::AlignCenter);
        okbutton = new QPushButton(loginwindowframe);
        okbutton->setObjectName(QString::fromUtf8("okbutton"));
        okbutton->setGeometry(QRect(237, 236, 27, 28));
        okbutton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/images/enter.png"), QSize(), QIcon::Normal, QIcon::Off);
        okbutton->setIcon(icon1);
        okbutton->setIconSize(QSize(20, 22));
        cancelbutton = new QPushButton(loginwindowframe);
        cancelbutton->setObjectName(QString::fromUtf8("cancelbutton"));
        cancelbutton->setGeometry(QRect(103, 303, 89, 28));
        cancelbutton->setStyleSheet(QString::fromUtf8(""));
        loginuserframe = new QFrame(loginwindowframe);
        loginuserframe->setObjectName(QString::fromUtf8("loginuserframe"));
        loginuserframe->setGeometry(QRect(103, 82, 98, 104));
        loginuserframe->setStyleSheet(QString::fromUtf8("image: url(:/new/images/operator.png);"));
        loginuserframe->setFrameShape(QFrame::StyledPanel);
        loginuserframe->setFrameShadow(QFrame::Raised);
        userframe = new QFrame(loginwindowframe);
        userframe->setObjectName(QString::fromUtf8("userframe"));
        userframe->setGeometry(QRect(25, 213, 21, 21));
        userframe->setStyleSheet(QString::fromUtf8("image: url(:/new/images/user.ico);"));
        userframe->setFrameShape(QFrame::StyledPanel);
        userframe->setFrameShadow(QFrame::Raised);
        passwordframe = new QFrame(loginwindowframe);
        passwordframe->setObjectName(QString::fromUtf8("passwordframe"));
        passwordframe->setGeometry(QRect(25, 239, 19, 21));
        passwordframe->setStyleSheet(QString::fromUtf8("image: url(:/new/images/password.ico);"));
        passwordframe->setFrameShape(QFrame::StyledPanel);
        passwordframe->setFrameShadow(QFrame::Raised);

        retranslateUi(startweighing);

        QMetaObject::connectSlotsByName(startweighing);
    } // setupUi

    void retranslateUi(QDialog *startweighing)
    {
        startweighing->setWindowTitle(QApplication::translate("startweighing", "Operator Login", 0, QApplication::UnicodeUTF8));
        usernameedit->setText(QString());
        passwordedit->setText(QString());
        okbutton->setText(QString());
        cancelbutton->setText(QApplication::translate("startweighing", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class startweighing: public Ui_startweighing {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWEIGHING_H
