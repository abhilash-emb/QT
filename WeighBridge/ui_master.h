/********************************************************************************
** Form generated from reading UI file 'master.ui'
**
** Created: Tue Dec 11 14:55:09 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MASTER_H
#define UI_MASTER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_master
{
public:
    QLineEdit *passedit;
    QPushButton *okbutton;

    void setupUi(QDialog *master)
    {
        if (master->objectName().isEmpty())
            master->setObjectName(QString::fromUtf8("master"));
        master->resize(249, 40);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/resource/exit (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        master->setWindowIcon(icon);
        master->setStyleSheet(QString::fromUtf8(""));
        passedit = new QLineEdit(master);
        passedit->setObjectName(QString::fromUtf8("passedit"));
        passedit->setGeometry(QRect(10, 8, 181, 24));
        passedit->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText);
        passedit->setEchoMode(QLineEdit::Password);
        passedit->setAlignment(Qt::AlignCenter);
        okbutton = new QPushButton(master);
        okbutton->setObjectName(QString::fromUtf8("okbutton"));
        okbutton->setGeometry(QRect(200, 9, 41, 24));

        retranslateUi(master);

        QMetaObject::connectSlotsByName(master);
    } // setupUi

    void retranslateUi(QDialog *master)
    {
        master->setWindowTitle(QApplication::translate("master", "Dialog", 0, QApplication::UnicodeUTF8));
        okbutton->setText(QApplication::translate("master", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class master: public Ui_master {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MASTER_H
