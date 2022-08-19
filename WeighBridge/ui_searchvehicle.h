/********************************************************************************
** Form generated from reading UI file 'searchvehicle.ui'
**
** Created: Tue Sep 24 14:04:04 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHVEHICLE_H
#define UI_SEARCHVEHICLE_H

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

class Ui_searchvehicle
{
public:
    QLabel *vehichlenolabel;
    QLineEdit *vehicleedit;
    QTextEdit *displayedit;
    QPushButton *gobutton;
    QPushButton *printbutton;
    QPushButton *clearbutton;
    QPushButton *previousbutton;
    QPushButton *nextbutton;

    void setupUi(QDialog *searchvehicle)
    {
        if (searchvehicle->objectName().isEmpty())
            searchvehicle->setObjectName(QString::fromUtf8("searchvehicle"));
        searchvehicle->resize(540, 430);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/resource/Secondweight.png"), QSize(), QIcon::Normal, QIcon::Off);
        searchvehicle->setWindowIcon(icon);
        vehichlenolabel = new QLabel(searchvehicle);
        vehichlenolabel->setObjectName(QString::fromUtf8("vehichlenolabel"));
        vehichlenolabel->setGeometry(QRect(110, 20, 81, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        vehichlenolabel->setFont(font);
        vehichlenolabel->setAlignment(Qt::AlignCenter);
        vehicleedit = new QLineEdit(searchvehicle);
        vehicleedit->setObjectName(QString::fromUtf8("vehicleedit"));
        vehicleedit->setGeometry(QRect(200, 22, 181, 27));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        vehicleedit->setFont(font1);
        vehicleedit->setAlignment(Qt::AlignCenter);
        displayedit = new QTextEdit(searchvehicle);
        displayedit->setObjectName(QString::fromUtf8("displayedit"));
        displayedit->setEnabled(false);
        displayedit->setGeometry(QRect(10, 60, 521, 310));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial Unicode MS"));
        displayedit->setFont(font2);
        gobutton = new QPushButton(searchvehicle);
        gobutton->setObjectName(QString::fromUtf8("gobutton"));
        gobutton->setGeometry(QRect(390, 22, 41, 27));
        gobutton->setFont(font2);
        printbutton = new QPushButton(searchvehicle);
        printbutton->setObjectName(QString::fromUtf8("printbutton"));
        printbutton->setGeometry(QRect(170, 380, 91, 31));
        printbutton->setFont(font2);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/resource/Print.png"), QSize(), QIcon::Normal, QIcon::Off);
        printbutton->setIcon(icon1);
        printbutton->setIconSize(QSize(30, 26));
        clearbutton = new QPushButton(searchvehicle);
        clearbutton->setObjectName(QString::fromUtf8("clearbutton"));
        clearbutton->setGeometry(QRect(280, 380, 91, 31));
        clearbutton->setFont(font2);
        previousbutton = new QPushButton(searchvehicle);
        previousbutton->setObjectName(QString::fromUtf8("previousbutton"));
        previousbutton->setGeometry(QRect(60, 380, 91, 31));
        previousbutton->setFont(font2);
        nextbutton = new QPushButton(searchvehicle);
        nextbutton->setObjectName(QString::fromUtf8("nextbutton"));
        nextbutton->setGeometry(QRect(390, 380, 91, 31));
        nextbutton->setFont(font2);
        QWidget::setTabOrder(vehicleedit, gobutton);
        QWidget::setTabOrder(gobutton, printbutton);
        QWidget::setTabOrder(printbutton, clearbutton);
        QWidget::setTabOrder(clearbutton, nextbutton);
        QWidget::setTabOrder(nextbutton, previousbutton);
        QWidget::setTabOrder(previousbutton, displayedit);

        retranslateUi(searchvehicle);

        QMetaObject::connectSlotsByName(searchvehicle);
    } // setupUi

    void retranslateUi(QDialog *searchvehicle)
    {
        searchvehicle->setWindowTitle(QApplication::translate("searchvehicle", "Dialog", 0, QApplication::UnicodeUTF8));
        vehichlenolabel->setText(QApplication::translate("searchvehicle", "Vehicle No.", 0, QApplication::UnicodeUTF8));
        gobutton->setText(QApplication::translate("searchvehicle", "Go", 0, QApplication::UnicodeUTF8));
        printbutton->setText(QApplication::translate("searchvehicle", "Print", 0, QApplication::UnicodeUTF8));
        clearbutton->setText(QApplication::translate("searchvehicle", "Clear", 0, QApplication::UnicodeUTF8));
        previousbutton->setText(QApplication::translate("searchvehicle", "Previous", 0, QApplication::UnicodeUTF8));
        nextbutton->setText(QApplication::translate("searchvehicle", "Next", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class searchvehicle: public Ui_searchvehicle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHVEHICLE_H
