/********************************************************************************
** Form generated from reading UI file 'searchreciept.ui'
**
** Created: Tue Sep 24 14:04:04 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHRECIEPT_H
#define UI_SEARCHRECIEPT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_searchreciept
{
public:
    QLineEdit *receiptedit;
    QPushButton *gobutton;
    QLabel *receiptlabel;
    QTextEdit *displayedit;
    QPushButton *printbutton;
    QPushButton *clearbutton;

    void setupUi(QDialog *searchreciept)
    {
        if (searchreciept->objectName().isEmpty())
            searchreciept->setObjectName(QString::fromUtf8("searchreciept"));
        searchreciept->resize(540, 430);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/resource/Receiptsearch.png"), QSize(), QIcon::Normal, QIcon::Off);
        searchreciept->setWindowIcon(icon);
        receiptedit = new QLineEdit(searchreciept);
        receiptedit->setObjectName(QString::fromUtf8("receiptedit"));
        receiptedit->setGeometry(QRect(200, 22, 181, 27));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        receiptedit->setFont(font);
        receiptedit->setAlignment(Qt::AlignCenter);
        gobutton = new QPushButton(searchreciept);
        gobutton->setObjectName(QString::fromUtf8("gobutton"));
        gobutton->setGeometry(QRect(390, 22, 41, 27));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial Unicode MS"));
        gobutton->setFont(font1);
        receiptlabel = new QLabel(searchreciept);
        receiptlabel->setObjectName(QString::fromUtf8("receiptlabel"));
        receiptlabel->setGeometry(QRect(110, 20, 81, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setWeight(75);
        receiptlabel->setFont(font2);
        receiptlabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        displayedit = new QTextEdit(searchreciept);
        displayedit->setObjectName(QString::fromUtf8("displayedit"));
        displayedit->setEnabled(false);
        displayedit->setGeometry(QRect(10, 60, 521, 310));
        displayedit->setFont(font1);
        printbutton = new QPushButton(searchreciept);
        printbutton->setObjectName(QString::fromUtf8("printbutton"));
        printbutton->setGeometry(QRect(170, 380, 91, 31));
        printbutton->setFont(font1);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/resource/Print.png"), QSize(), QIcon::Normal, QIcon::Off);
        printbutton->setIcon(icon1);
        printbutton->setIconSize(QSize(30, 26));
        clearbutton = new QPushButton(searchreciept);
        clearbutton->setObjectName(QString::fromUtf8("clearbutton"));
        clearbutton->setGeometry(QRect(280, 380, 91, 31));
        clearbutton->setFont(font1);
        QWidget::setTabOrder(receiptedit, gobutton);
        QWidget::setTabOrder(gobutton, printbutton);
        QWidget::setTabOrder(printbutton, clearbutton);
        QWidget::setTabOrder(clearbutton, displayedit);

        retranslateUi(searchreciept);

        QMetaObject::connectSlotsByName(searchreciept);
    } // setupUi

    void retranslateUi(QDialog *searchreciept)
    {
        searchreciept->setWindowTitle(QApplication::translate("searchreciept", "Dialog", 0, QApplication::UnicodeUTF8));
        gobutton->setText(QApplication::translate("searchreciept", "Go", 0, QApplication::UnicodeUTF8));
        receiptlabel->setText(QApplication::translate("searchreciept", "Receipt No.", 0, QApplication::UnicodeUTF8));
        printbutton->setText(QApplication::translate("searchreciept", "Print", 0, QApplication::UnicodeUTF8));
        clearbutton->setText(QApplication::translate("searchreciept", "Clear", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class searchreciept: public Ui_searchreciept {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHRECIEPT_H
