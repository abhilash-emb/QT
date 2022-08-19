/********************************************************************************
** Form generated from reading UI file 'unlock.ui'
**
** Created: Wed Nov 6 16:29:06 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNLOCK_H
#define UI_UNLOCK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_unlock
{
public:
    QFrame *useravatar;
    QLabel *username;
    QLineEdit *passwordedit;
    QFrame *passwordlogo;
    QLabel *label;

    void setupUi(QDialog *unlock)
    {
        if (unlock->objectName().isEmpty())
            unlock->setObjectName(QString::fromUtf8("unlock"));
        unlock->resize(240, 278);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/images/operator.png"), QSize(), QIcon::Normal, QIcon::Off);
        unlock->setWindowIcon(icon);
        unlock->setStyleSheet(QString::fromUtf8("background-color: rgb(127, 127, 127);"));
        useravatar = new QFrame(unlock);
        useravatar->setObjectName(QString::fromUtf8("useravatar"));
        useravatar->setGeometry(QRect(80, 28, 103, 101));
        useravatar->setStyleSheet(QString::fromUtf8("image: url(:/new/images/operator.png);"));
        useravatar->setFrameShape(QFrame::StyledPanel);
        useravatar->setFrameShadow(QFrame::Raised);
        username = new QLabel(unlock);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(4, 141, 233, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        username->setFont(font);
        username->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 194, 11);"));
        username->setAlignment(Qt::AlignCenter);
        passwordedit = new QLineEdit(unlock);
        passwordedit->setObjectName(QString::fromUtf8("passwordedit"));
        passwordedit->setGeometry(QRect(40, 189, 182, 24));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        passwordedit->setFont(font1);
        passwordedit->setStyleSheet(QString::fromUtf8("color: rgb(127, 0, 63); \n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 4px;\n"
""));
        passwordedit->setMaxLength(30);
        passwordedit->setEchoMode(QLineEdit::Password);
        passwordedit->setAlignment(Qt::AlignCenter);
        passwordlogo = new QFrame(unlock);
        passwordlogo->setObjectName(QString::fromUtf8("passwordlogo"));
        passwordlogo->setGeometry(QRect(10, 188, 26, 25));
        passwordlogo->setStyleSheet(QString::fromUtf8("image: url(:/new/images/password.ico);"));
        passwordlogo->setFrameShape(QFrame::StyledPanel);
        passwordlogo->setFrameShadow(QFrame::Raised);
        label = new QLabel(unlock);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 250, 161, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial Unicode MS"));
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 158, 23);"));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(unlock);

        QMetaObject::connectSlotsByName(unlock);
    } // setupUi

    void retranslateUi(QDialog *unlock)
    {
        unlock->setWindowTitle(QApplication::translate("unlock", "Login", 0, QApplication::UnicodeUTF8));
        username->setText(QString());
        label->setText(QApplication::translate("unlock", "Session Locked", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class unlock: public Ui_unlock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNLOCK_H
