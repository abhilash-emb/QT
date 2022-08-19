/********************************************************************************
** Form generated from reading UI file 'dsettings.ui'
**
** Created: Wed Sep 25 12:56:16 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DSETTINGS_H
#define UI_DSETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_dsettings
{
public:
    QLineEdit *lineEdit;

    void setupUi(QDialog *dsettings)
    {
        if (dsettings->objectName().isEmpty())
            dsettings->setObjectName(QString::fromUtf8("dsettings"));
        dsettings->resize(271, 44);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/resource/Password.png"), QSize(), QIcon::Normal, QIcon::Off);
        dsettings->setWindowIcon(icon);
        lineEdit = new QLineEdit(dsettings);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 251, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Unicode MS"));
        lineEdit->setFont(font);
        lineEdit->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText);
        lineEdit->setEchoMode(QLineEdit::Password);
        lineEdit->setAlignment(Qt::AlignCenter);

        retranslateUi(dsettings);

        QMetaObject::connectSlotsByName(dsettings);
    } // setupUi

    void retranslateUi(QDialog *dsettings)
    {
        dsettings->setWindowTitle(QApplication::translate("dsettings", "Admin Password", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dsettings: public Ui_dsettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DSETTINGS_H
