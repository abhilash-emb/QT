/********************************************************************************
** Form generated from reading UI file 'dviewticket.ui'
**
** Created: Tue Sep 24 16:55:09 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DVIEWTICKET_H
#define UI_DVIEWTICKET_H

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

class Ui_DViewTicket
{
public:
    QLabel *receiptlabel;
    QLineEdit *receipt_edit;
    QPushButton *gobutton;
    QPushButton *closebutton;
    QPushButton *printbutton;
    QPushButton *clearbutton;
    QTextEdit *display_edit;

    void setupUi(QDialog *DViewTicket)
    {
        if (DViewTicket->objectName().isEmpty())
            DViewTicket->setObjectName(QString::fromUtf8("DViewTicket"));
        DViewTicket->resize(540, 430);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/resource/Viewticket.png"), QSize(), QIcon::Normal, QIcon::Off);
        DViewTicket->setWindowIcon(icon);
        receiptlabel = new QLabel(DViewTicket);
        receiptlabel->setObjectName(QString::fromUtf8("receiptlabel"));
        receiptlabel->setGeometry(QRect(60, 20, 121, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        receiptlabel->setFont(font);
        receiptlabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        receipt_edit = new QLineEdit(DViewTicket);
        receipt_edit->setObjectName(QString::fromUtf8("receipt_edit"));
        receipt_edit->setGeometry(QRect(200, 22, 201, 27));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        receipt_edit->setFont(font1);
        receipt_edit->setAlignment(Qt::AlignCenter);
        gobutton = new QPushButton(DViewTicket);
        gobutton->setObjectName(QString::fromUtf8("gobutton"));
        gobutton->setGeometry(QRect(420, 22, 41, 27));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial Unicode MS"));
        gobutton->setFont(font2);
        closebutton = new QPushButton(DViewTicket);
        closebutton->setObjectName(QString::fromUtf8("closebutton"));
        closebutton->setGeometry(QRect(350, 380, 91, 31));
        closebutton->setFont(font2);
        closebutton->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        printbutton = new QPushButton(DViewTicket);
        printbutton->setObjectName(QString::fromUtf8("printbutton"));
        printbutton->setGeometry(QRect(90, 380, 91, 31));
        printbutton->setFont(font2);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/resource/Print.png"), QSize(), QIcon::Normal, QIcon::Off);
        printbutton->setIcon(icon1);
        printbutton->setIconSize(QSize(30, 25));
        clearbutton = new QPushButton(DViewTicket);
        clearbutton->setObjectName(QString::fromUtf8("clearbutton"));
        clearbutton->setGeometry(QRect(220, 380, 91, 31));
        clearbutton->setFont(font2);
        display_edit = new QTextEdit(DViewTicket);
        display_edit->setObjectName(QString::fromUtf8("display_edit"));
        display_edit->setEnabled(true);
        display_edit->setGeometry(QRect(10, 60, 521, 310));
        display_edit->setFont(font2);
        QWidget::setTabOrder(receipt_edit, gobutton);
        QWidget::setTabOrder(gobutton, printbutton);
        QWidget::setTabOrder(printbutton, clearbutton);
        QWidget::setTabOrder(clearbutton, closebutton);
        QWidget::setTabOrder(closebutton, display_edit);

        retranslateUi(DViewTicket);

        QMetaObject::connectSlotsByName(DViewTicket);
    } // setupUi

    void retranslateUi(QDialog *DViewTicket)
    {
        DViewTicket->setWindowTitle(QApplication::translate("DViewTicket", "View Ticket", 0, QApplication::UnicodeUTF8));
        receiptlabel->setText(QApplication::translate("DViewTicket", "Receipt No", 0, QApplication::UnicodeUTF8));
        gobutton->setText(QApplication::translate("DViewTicket", "Go", 0, QApplication::UnicodeUTF8));
        closebutton->setText(QApplication::translate("DViewTicket", "Close", 0, QApplication::UnicodeUTF8));
        printbutton->setText(QApplication::translate("DViewTicket", "Print", 0, QApplication::UnicodeUTF8));
        clearbutton->setText(QApplication::translate("DViewTicket", "Clear All", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DViewTicket: public Ui_DViewTicket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DVIEWTICKET_H
