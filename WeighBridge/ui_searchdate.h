/********************************************************************************
** Form generated from reading UI file 'searchdate.ui'
**
** Created: Tue Sep 24 14:04:04 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHDATE_H
#define UI_SEARCHDATE_H

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

class Ui_searchdate
{
public:
    QLabel *datelabel;
    QLineEdit *dateedit;
    QPushButton *gobutton;
    QTextEdit *displayedit;
    QPushButton *printbutton;
    QPushButton *clearbutton;
    QPushButton *nextbutton;
    QPushButton *previousbutton;
    QLineEdit *monthedit;
    QLineEdit *yearedit;
    QLabel *dateseperator1;
    QLabel *dateseperator2;

    void setupUi(QDialog *searchdate)
    {
        if (searchdate->objectName().isEmpty())
            searchdate->setObjectName(QString::fromUtf8("searchdate"));
        searchdate->resize(540, 430);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/resource/Searchcalender.png"), QSize(), QIcon::Normal, QIcon::Off);
        searchdate->setWindowIcon(icon);
        datelabel = new QLabel(searchdate);
        datelabel->setObjectName(QString::fromUtf8("datelabel"));
        datelabel->setGeometry(QRect(80, 20, 81, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        datelabel->setFont(font);
        datelabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dateedit = new QLineEdit(searchdate);
        dateedit->setObjectName(QString::fromUtf8("dateedit"));
        dateedit->setGeometry(QRect(180, 22, 41, 27));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        dateedit->setFont(font1);
        dateedit->setAlignment(Qt::AlignCenter);
        gobutton = new QPushButton(searchdate);
        gobutton->setObjectName(QString::fromUtf8("gobutton"));
        gobutton->setGeometry(QRect(370, 22, 41, 27));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial Unicode MS"));
        gobutton->setFont(font2);
        displayedit = new QTextEdit(searchdate);
        displayedit->setObjectName(QString::fromUtf8("displayedit"));
        displayedit->setEnabled(false);
        displayedit->setGeometry(QRect(10, 60, 521, 310));
        displayedit->setFont(font2);
        displayedit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        displayedit->setAutoFillBackground(false);
        printbutton = new QPushButton(searchdate);
        printbutton->setObjectName(QString::fromUtf8("printbutton"));
        printbutton->setGeometry(QRect(170, 380, 91, 31));
        printbutton->setFont(font2);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/resource/Print.png"), QSize(), QIcon::Normal, QIcon::Off);
        printbutton->setIcon(icon1);
        printbutton->setIconSize(QSize(30, 26));
        clearbutton = new QPushButton(searchdate);
        clearbutton->setObjectName(QString::fromUtf8("clearbutton"));
        clearbutton->setGeometry(QRect(280, 380, 91, 31));
        clearbutton->setFont(font2);
        nextbutton = new QPushButton(searchdate);
        nextbutton->setObjectName(QString::fromUtf8("nextbutton"));
        nextbutton->setGeometry(QRect(390, 380, 91, 31));
        nextbutton->setFont(font2);
        previousbutton = new QPushButton(searchdate);
        previousbutton->setObjectName(QString::fromUtf8("previousbutton"));
        previousbutton->setGeometry(QRect(60, 380, 91, 31));
        previousbutton->setFont(font2);
        monthedit = new QLineEdit(searchdate);
        monthedit->setObjectName(QString::fromUtf8("monthedit"));
        monthedit->setGeometry(QRect(240, 22, 41, 27));
        monthedit->setFont(font1);
        monthedit->setAlignment(Qt::AlignCenter);
        yearedit = new QLineEdit(searchdate);
        yearedit->setObjectName(QString::fromUtf8("yearedit"));
        yearedit->setGeometry(QRect(300, 22, 61, 27));
        yearedit->setFont(font1);
        yearedit->setAlignment(Qt::AlignCenter);
        dateseperator1 = new QLabel(searchdate);
        dateseperator1->setObjectName(QString::fromUtf8("dateseperator1"));
        dateseperator1->setGeometry(QRect(210, 22, 46, 27));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font3.setPointSize(16);
        font3.setBold(false);
        font3.setWeight(50);
        dateseperator1->setFont(font3);
        dateseperator1->setAlignment(Qt::AlignCenter);
        dateseperator2 = new QLabel(searchdate);
        dateseperator2->setObjectName(QString::fromUtf8("dateseperator2"));
        dateseperator2->setGeometry(QRect(270, 22, 46, 27));
        dateseperator2->setFont(font3);
        dateseperator2->setAlignment(Qt::AlignCenter);
        QWidget::setTabOrder(dateedit, monthedit);
        QWidget::setTabOrder(monthedit, yearedit);
        QWidget::setTabOrder(yearedit, gobutton);
        QWidget::setTabOrder(gobutton, printbutton);
        QWidget::setTabOrder(printbutton, clearbutton);
        QWidget::setTabOrder(clearbutton, nextbutton);
        QWidget::setTabOrder(nextbutton, previousbutton);
        QWidget::setTabOrder(previousbutton, displayedit);

        retranslateUi(searchdate);

        QMetaObject::connectSlotsByName(searchdate);
    } // setupUi

    void retranslateUi(QDialog *searchdate)
    {
        searchdate->setWindowTitle(QApplication::translate("searchdate", "Search by Date", 0, QApplication::UnicodeUTF8));
        datelabel->setText(QApplication::translate("searchdate", "Date", 0, QApplication::UnicodeUTF8));
        gobutton->setText(QApplication::translate("searchdate", "Go", 0, QApplication::UnicodeUTF8));
        printbutton->setText(QApplication::translate("searchdate", "Print", 0, QApplication::UnicodeUTF8));
        clearbutton->setText(QApplication::translate("searchdate", "Clear", 0, QApplication::UnicodeUTF8));
        nextbutton->setText(QApplication::translate("searchdate", "Next", 0, QApplication::UnicodeUTF8));
        previousbutton->setText(QApplication::translate("searchdate", "Previous", 0, QApplication::UnicodeUTF8));
        dateseperator1->setText(QApplication::translate("searchdate", "/", 0, QApplication::UnicodeUTF8));
        dateseperator2->setText(QApplication::translate("searchdate", "/", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class searchdate: public Ui_searchdate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHDATE_H
