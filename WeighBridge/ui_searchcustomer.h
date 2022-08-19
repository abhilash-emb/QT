/********************************************************************************
** Form generated from reading UI file 'searchcustomer.ui'
**
** Created: Tue Sep 24 14:04:04 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHCUSTOMER_H
#define UI_SEARCHCUSTOMER_H

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

class Ui_searchcustomer
{
public:
    QPushButton *gobutton;
    QLabel *customerlabel;
    QLineEdit *customeredit;
    QTextEdit *displayedit;
    QPushButton *printbutton;
    QPushButton *clearbutton;
    QPushButton *nextbutton;
    QPushButton *previousbutton;

    void setupUi(QDialog *searchcustomer)
    {
        if (searchcustomer->objectName().isEmpty())
            searchcustomer->setObjectName(QString::fromUtf8("searchcustomer"));
        searchcustomer->resize(540, 430);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/resource/Customersearch.png"), QSize(), QIcon::Normal, QIcon::Off);
        searchcustomer->setWindowIcon(icon);
        gobutton = new QPushButton(searchcustomer);
        gobutton->setObjectName(QString::fromUtf8("gobutton"));
        gobutton->setGeometry(QRect(390, 22, 41, 27));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Unicode MS"));
        gobutton->setFont(font);
        customerlabel = new QLabel(searchcustomer);
        customerlabel->setObjectName(QString::fromUtf8("customerlabel"));
        customerlabel->setGeometry(QRect(80, 20, 111, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        customerlabel->setFont(font1);
        customerlabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        customeredit = new QLineEdit(searchcustomer);
        customeredit->setObjectName(QString::fromUtf8("customeredit"));
        customeredit->setGeometry(QRect(200, 22, 181, 27));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        customeredit->setFont(font2);
        customeredit->setAlignment(Qt::AlignCenter);
        displayedit = new QTextEdit(searchcustomer);
        displayedit->setObjectName(QString::fromUtf8("displayedit"));
        displayedit->setEnabled(false);
        displayedit->setGeometry(QRect(10, 60, 521, 310));
        displayedit->setFont(font);
        printbutton = new QPushButton(searchcustomer);
        printbutton->setObjectName(QString::fromUtf8("printbutton"));
        printbutton->setGeometry(QRect(170, 380, 91, 31));
        printbutton->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/resource/Print.png"), QSize(), QIcon::Normal, QIcon::Off);
        printbutton->setIcon(icon1);
        printbutton->setIconSize(QSize(30, 26));
        clearbutton = new QPushButton(searchcustomer);
        clearbutton->setObjectName(QString::fromUtf8("clearbutton"));
        clearbutton->setGeometry(QRect(280, 380, 91, 31));
        clearbutton->setFont(font);
        nextbutton = new QPushButton(searchcustomer);
        nextbutton->setObjectName(QString::fromUtf8("nextbutton"));
        nextbutton->setGeometry(QRect(390, 380, 91, 31));
        nextbutton->setFont(font);
        previousbutton = new QPushButton(searchcustomer);
        previousbutton->setObjectName(QString::fromUtf8("previousbutton"));
        previousbutton->setGeometry(QRect(60, 380, 91, 31));
        previousbutton->setFont(font);
        QWidget::setTabOrder(customeredit, gobutton);
        QWidget::setTabOrder(gobutton, printbutton);
        QWidget::setTabOrder(printbutton, clearbutton);
        QWidget::setTabOrder(clearbutton, nextbutton);
        QWidget::setTabOrder(nextbutton, previousbutton);
        QWidget::setTabOrder(previousbutton, displayedit);

        retranslateUi(searchcustomer);

        QMetaObject::connectSlotsByName(searchcustomer);
    } // setupUi

    void retranslateUi(QDialog *searchcustomer)
    {
        searchcustomer->setWindowTitle(QApplication::translate("searchcustomer", "Search Customer", 0, QApplication::UnicodeUTF8));
        gobutton->setText(QApplication::translate("searchcustomer", "Go", 0, QApplication::UnicodeUTF8));
        customerlabel->setText(QApplication::translate("searchcustomer", "Customer Name", 0, QApplication::UnicodeUTF8));
        printbutton->setText(QApplication::translate("searchcustomer", "Print", 0, QApplication::UnicodeUTF8));
        clearbutton->setText(QApplication::translate("searchcustomer", "Clear", 0, QApplication::UnicodeUTF8));
        nextbutton->setText(QApplication::translate("searchcustomer", "Next", 0, QApplication::UnicodeUTF8));
        previousbutton->setText(QApplication::translate("searchcustomer", "Previous", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class searchcustomer: public Ui_searchcustomer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHCUSTOMER_H
