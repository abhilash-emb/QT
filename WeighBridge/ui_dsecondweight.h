/********************************************************************************
** Form generated from reading UI file 'dsecondweight.ui'
**
** Created: Thu Oct 10 14:31:13 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DSECONDWEIGHT_H
#define UI_DSECONDWEIGHT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DSecondWeight
{
public:
    QPushButton *gobutton;
    QLabel *receiptlabel;
    QLineEdit *reciept_edit;
    QLineEdit *grossweight_edit;
    QLineEdit *tareweight_edit;
    QLineEdit *netweight_edit;
    QLabel *grosslabel;
    QLabel *tarelabel;
    QLabel *netweightlabel;
    QLabel *grosskglabel;
    QLabel *tarekglabel;
    QLabel *netkglabel;
    QLineEdit *date2_edit;
    QLineEdit *time2_edit;
    QLineEdit *date1_edit;
    QLineEdit *time1_edit;
    QLineEdit *totalcharge_edit;
    QLabel *chargelabel;
    QLabel *datelabel;
    QLabel *timelabel;
    QLabel *modelabel;
    QLabel *status_label;
    QGroupBox *buttongroupbox;
    QPushButton *closebutton;
    QPushButton *saveprintbutton;
    QPushButton *clearbutton;
    QPushButton *acceptbutton;

    void setupUi(QDialog *DSecondWeight)
    {
        if (DSecondWeight->objectName().isEmpty())
            DSecondWeight->setObjectName(QString::fromUtf8("DSecondWeight"));
        DSecondWeight->resize(540, 340);
        DSecondWeight->setMouseTracking(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/resource/Secondweight.png"), QSize(), QIcon::Normal, QIcon::Off);
        DSecondWeight->setWindowIcon(icon);
        gobutton = new QPushButton(DSecondWeight);
        gobutton->setObjectName(QString::fromUtf8("gobutton"));
        gobutton->setGeometry(QRect(420, 30, 51, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Unicode MS"));
        gobutton->setFont(font);
        gobutton->setStyleSheet(QString::fromUtf8(""));
        receiptlabel = new QLabel(DSecondWeight);
        receiptlabel->setObjectName(QString::fromUtf8("receiptlabel"));
        receiptlabel->setGeometry(QRect(70, 30, 131, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        receiptlabel->setFont(font1);
        receiptlabel->setAutoFillBackground(true);
        receiptlabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        reciept_edit = new QLineEdit(DSecondWeight);
        reciept_edit->setObjectName(QString::fromUtf8("reciept_edit"));
        reciept_edit->setGeometry(QRect(220, 30, 191, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        reciept_edit->setFont(font2);
        reciept_edit->setAlignment(Qt::AlignCenter);
        grossweight_edit = new QLineEdit(DSecondWeight);
        grossweight_edit->setObjectName(QString::fromUtf8("grossweight_edit"));
        grossweight_edit->setGeometry(QRect(90, 100, 121, 27));
        grossweight_edit->setFont(font1);
        grossweight_edit->setAlignment(Qt::AlignCenter);
        tareweight_edit = new QLineEdit(DSecondWeight);
        tareweight_edit->setObjectName(QString::fromUtf8("tareweight_edit"));
        tareweight_edit->setEnabled(false);
        tareweight_edit->setGeometry(QRect(90, 150, 121, 27));
        tareweight_edit->setFont(font1);
        tareweight_edit->setAlignment(Qt::AlignCenter);
        netweight_edit = new QLineEdit(DSecondWeight);
        netweight_edit->setObjectName(QString::fromUtf8("netweight_edit"));
        netweight_edit->setEnabled(false);
        netweight_edit->setGeometry(QRect(90, 197, 121, 27));
        netweight_edit->setFont(font2);
        netweight_edit->setStyleSheet(QString::fromUtf8("color: rgb(162, 6, 8);"));
        netweight_edit->setAlignment(Qt::AlignCenter);
        grosslabel = new QLabel(DSecondWeight);
        grosslabel->setObjectName(QString::fromUtf8("grosslabel"));
        grosslabel->setGeometry(QRect(20, 97, 51, 31));
        grosslabel->setFont(font1);
        tarelabel = new QLabel(DSecondWeight);
        tarelabel->setObjectName(QString::fromUtf8("tarelabel"));
        tarelabel->setGeometry(QRect(20, 147, 51, 31));
        tarelabel->setFont(font1);
        tarelabel->setAutoFillBackground(true);
        netweightlabel = new QLabel(DSecondWeight);
        netweightlabel->setObjectName(QString::fromUtf8("netweightlabel"));
        netweightlabel->setGeometry(QRect(20, 195, 51, 31));
        netweightlabel->setFont(font1);
        grosskglabel = new QLabel(DSecondWeight);
        grosskglabel->setObjectName(QString::fromUtf8("grosskglabel"));
        grosskglabel->setGeometry(QRect(220, 97, 41, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font3.setBold(true);
        font3.setWeight(75);
        grosskglabel->setFont(font3);
        tarekglabel = new QLabel(DSecondWeight);
        tarekglabel->setObjectName(QString::fromUtf8("tarekglabel"));
        tarekglabel->setGeometry(QRect(220, 147, 41, 31));
        tarekglabel->setFont(font3);
        netkglabel = new QLabel(DSecondWeight);
        netkglabel->setObjectName(QString::fromUtf8("netkglabel"));
        netkglabel->setGeometry(QRect(220, 194, 41, 31));
        netkglabel->setFont(font3);
        date2_edit = new QLineEdit(DSecondWeight);
        date2_edit->setObjectName(QString::fromUtf8("date2_edit"));
        date2_edit->setEnabled(false);
        date2_edit->setGeometry(QRect(270, 100, 111, 27));
        date2_edit->setFont(font2);
        date2_edit->setStyleSheet(QString::fromUtf8("color: rgb(8, 139, 24);"));
        date2_edit->setAlignment(Qt::AlignCenter);
        time2_edit = new QLineEdit(DSecondWeight);
        time2_edit->setObjectName(QString::fromUtf8("time2_edit"));
        time2_edit->setEnabled(false);
        time2_edit->setGeometry(QRect(402, 100, 111, 27));
        time2_edit->setFont(font2);
        time2_edit->setStyleSheet(QString::fromUtf8("color: rgb(8, 139, 24);"));
        time2_edit->setAlignment(Qt::AlignCenter);
        date1_edit = new QLineEdit(DSecondWeight);
        date1_edit->setObjectName(QString::fromUtf8("date1_edit"));
        date1_edit->setEnabled(false);
        date1_edit->setGeometry(QRect(270, 150, 111, 27));
        date1_edit->setFont(font2);
        date1_edit->setStyleSheet(QString::fromUtf8("color: rgb(212, 0, 3);"));
        date1_edit->setAlignment(Qt::AlignCenter);
        time1_edit = new QLineEdit(DSecondWeight);
        time1_edit->setObjectName(QString::fromUtf8("time1_edit"));
        time1_edit->setEnabled(false);
        time1_edit->setGeometry(QRect(400, 150, 111, 27));
        time1_edit->setFont(font2);
        time1_edit->setStyleSheet(QString::fromUtf8("color: rgb(212, 0, 3);"));
        time1_edit->setAlignment(Qt::AlignCenter);
        totalcharge_edit = new QLineEdit(DSecondWeight);
        totalcharge_edit->setObjectName(QString::fromUtf8("totalcharge_edit"));
        totalcharge_edit->setGeometry(QRect(400, 197, 111, 27));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        totalcharge_edit->setFont(font4);
        totalcharge_edit->setAlignment(Qt::AlignCenter);
        chargelabel = new QLabel(DSecondWeight);
        chargelabel->setObjectName(QString::fromUtf8("chargelabel"));
        chargelabel->setGeometry(QRect(270, 200, 111, 21));
        chargelabel->setFont(font4);
        chargelabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        datelabel = new QLabel(DSecondWeight);
        datelabel->setObjectName(QString::fromUtf8("datelabel"));
        datelabel->setGeometry(QRect(300, 80, 46, 13));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font5.setPointSize(9);
        datelabel->setFont(font5);
        datelabel->setAlignment(Qt::AlignCenter);
        timelabel = new QLabel(DSecondWeight);
        timelabel->setObjectName(QString::fromUtf8("timelabel"));
        timelabel->setGeometry(QRect(430, 80, 46, 13));
        timelabel->setFont(font5);
        timelabel->setAlignment(Qt::AlignCenter);
        modelabel = new QLabel(DSecondWeight);
        modelabel->setObjectName(QString::fromUtf8("modelabel"));
        modelabel->setGeometry(QRect(2, 323, 71, 16));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font6.setItalic(true);
        modelabel->setFont(font6);
        status_label = new QLabel(DSecondWeight);
        status_label->setObjectName(QString::fromUtf8("status_label"));
        status_label->setGeometry(QRect(366, 323, 171, 16));
        QFont font7;
        font7.setPointSize(8);
        font7.setBold(false);
        font7.setItalic(true);
        font7.setWeight(50);
        status_label->setFont(font7);
        status_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        buttongroupbox = new QGroupBox(DSecondWeight);
        buttongroupbox->setObjectName(QString::fromUtf8("buttongroupbox"));
        buttongroupbox->setGeometry(QRect(55, 240, 431, 71));
        closebutton = new QPushButton(buttongroupbox);
        closebutton->setObjectName(QString::fromUtf8("closebutton"));
        closebutton->setGeometry(QRect(320, 16, 91, 40));
        QFont font8;
        font8.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font8.setPointSize(8);
        closebutton->setFont(font8);
        closebutton->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        saveprintbutton = new QPushButton(buttongroupbox);
        saveprintbutton->setObjectName(QString::fromUtf8("saveprintbutton"));
        saveprintbutton->setGeometry(QRect(120, 16, 91, 40));
        saveprintbutton->setFont(font8);
        clearbutton = new QPushButton(buttongroupbox);
        clearbutton->setObjectName(QString::fromUtf8("clearbutton"));
        clearbutton->setGeometry(QRect(220, 16, 91, 40));
        clearbutton->setFont(font8);
        acceptbutton = new QPushButton(buttongroupbox);
        acceptbutton->setObjectName(QString::fromUtf8("acceptbutton"));
        acceptbutton->setGeometry(QRect(20, 16, 91, 40));
        acceptbutton->setFont(font8);
        acceptbutton->setAutoFillBackground(false);
        QWidget::setTabOrder(reciept_edit, gobutton);
        QWidget::setTabOrder(gobutton, grossweight_edit);
        QWidget::setTabOrder(grossweight_edit, acceptbutton);
        QWidget::setTabOrder(acceptbutton, totalcharge_edit);
        QWidget::setTabOrder(totalcharge_edit, saveprintbutton);
        QWidget::setTabOrder(saveprintbutton, clearbutton);
        QWidget::setTabOrder(clearbutton, closebutton);
        QWidget::setTabOrder(closebutton, date2_edit);
        QWidget::setTabOrder(date2_edit, time2_edit);
        QWidget::setTabOrder(time2_edit, date1_edit);
        QWidget::setTabOrder(date1_edit, time1_edit);
        QWidget::setTabOrder(time1_edit, netweight_edit);
        QWidget::setTabOrder(netweight_edit, tareweight_edit);

        retranslateUi(DSecondWeight);

        QMetaObject::connectSlotsByName(DSecondWeight);
    } // setupUi

    void retranslateUi(QDialog *DSecondWeight)
    {
        DSecondWeight->setWindowTitle(QApplication::translate("DSecondWeight", "Second Weight", 0, QApplication::UnicodeUTF8));
        gobutton->setText(QApplication::translate("DSecondWeight", "Go", 0, QApplication::UnicodeUTF8));
        receiptlabel->setText(QApplication::translate("DSecondWeight", "Enter Receipt No.", 0, QApplication::UnicodeUTF8));
        reciept_edit->setText(QString());
        grossweight_edit->setText(QString());
        tareweight_edit->setText(QString());
        netweight_edit->setText(QString());
        grosslabel->setText(QApplication::translate("DSecondWeight", "Gross", 0, QApplication::UnicodeUTF8));
        tarelabel->setText(QApplication::translate("DSecondWeight", "Tare", 0, QApplication::UnicodeUTF8));
        netweightlabel->setText(QApplication::translate("DSecondWeight", "Net", 0, QApplication::UnicodeUTF8));
        grosskglabel->setText(QApplication::translate("DSecondWeight", "KG", 0, QApplication::UnicodeUTF8));
        tarekglabel->setText(QApplication::translate("DSecondWeight", "KG", 0, QApplication::UnicodeUTF8));
        netkglabel->setText(QApplication::translate("DSecondWeight", "KG", 0, QApplication::UnicodeUTF8));
        totalcharge_edit->setText(QString());
        chargelabel->setText(QApplication::translate("DSecondWeight", "Charge Rs.", 0, QApplication::UnicodeUTF8));
        datelabel->setText(QApplication::translate("DSecondWeight", "Date", 0, QApplication::UnicodeUTF8));
        timelabel->setText(QApplication::translate("DSecondWeight", "Time", 0, QApplication::UnicodeUTF8));
        modelabel->setText(QApplication::translate("DSecondWeight", "TextLabel", 0, QApplication::UnicodeUTF8));
        status_label->setText(QApplication::translate("DSecondWeight", "Status", 0, QApplication::UnicodeUTF8));
        buttongroupbox->setTitle(QString());
        closebutton->setText(QApplication::translate("DSecondWeight", "Close", 0, QApplication::UnicodeUTF8));
        saveprintbutton->setText(QApplication::translate("DSecondWeight", "Save/Print", 0, QApplication::UnicodeUTF8));
        clearbutton->setText(QApplication::translate("DSecondWeight", "Reset", 0, QApplication::UnicodeUTF8));
        acceptbutton->setText(QApplication::translate("DSecondWeight", "Accept", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DSecondWeight: public Ui_DSecondWeight {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DSECONDWEIGHT_H
