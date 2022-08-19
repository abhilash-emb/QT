/********************************************************************************
** Form generated from reading UI file 'dreports.ui'
**
** Created: Fri Oct 11 10:22:24 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DREPORTS_H
#define UI_DREPORTS_H

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
#include <QtGui/QRadioButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DReports
{
public:
    QGroupBox *optionsgroupbox;
    QRadioButton *dateradio;
    QRadioButton *vehicleradio;
    QRadioButton *materialradio;
    QRadioButton *receiptradio;
    QRadioButton *customerradio;
    QPushButton *searchbutton;
    QLineEdit *search_edit;
    QLineEdit *date_edit;
    QLineEdit *month_edit;
    QLineEdit *year_edit;
    QLabel *search_label;
    QLabel *seperator_label1;
    QLabel *seperator_label2;
    QPushButton *previousbutton;
    QPushButton *nextbutton;
    QTextEdit *displayedit;
    QPushButton *printbutton;
    QPushButton *clearbutton;

    void setupUi(QDialog *DReports)
    {
        if (DReports->objectName().isEmpty())
            DReports->setObjectName(QString::fromUtf8("DReports"));
        DReports->resize(540, 446);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/resource/Reports.png"), QSize(), QIcon::Normal, QIcon::Off);
        DReports->setWindowIcon(icon);
        optionsgroupbox = new QGroupBox(DReports);
        optionsgroupbox->setObjectName(QString::fromUtf8("optionsgroupbox"));
        optionsgroupbox->setGeometry(QRect(10, 0, 521, 85));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Unicode MS"));
        optionsgroupbox->setFont(font);
        dateradio = new QRadioButton(optionsgroupbox);
        dateradio->setObjectName(QString::fromUtf8("dateradio"));
        dateradio->setGeometry(QRect(438, 20, 71, 27));
        dateradio->setAutoFillBackground(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/resource/Searchcalender.png"), QSize(), QIcon::Normal, QIcon::Off);
        dateradio->setIcon(icon1);
        dateradio->setIconSize(QSize(25, 23));
        vehicleradio = new QRadioButton(optionsgroupbox);
        vehicleradio->setObjectName(QString::fromUtf8("vehicleradio"));
        vehicleradio->setGeometry(QRect(124, 20, 108, 28));
        vehicleradio->setFont(font);
        vehicleradio->setAutoFillBackground(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/resource/Secondweight.png"), QSize(), QIcon::Normal, QIcon::Off);
        vehicleradio->setIcon(icon2);
        vehicleradio->setIconSize(QSize(25, 24));
        materialradio = new QRadioButton(optionsgroupbox);
        materialradio->setObjectName(QString::fromUtf8("materialradio"));
        materialradio->setGeometry(QRect(340, 20, 91, 27));
        materialradio->setAutoFillBackground(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/resource/Materialsearch.png"), QSize(), QIcon::Normal, QIcon::Off);
        materialradio->setIcon(icon3);
        materialradio->setIconSize(QSize(25, 23));
        receiptradio = new QRadioButton(optionsgroupbox);
        receiptradio->setObjectName(QString::fromUtf8("receiptradio"));
        receiptradio->setGeometry(QRect(13, 20, 108, 27));
        receiptradio->setFont(font);
        receiptradio->setAutoFillBackground(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/resource/Receiptsearch.png"), QSize(), QIcon::Normal, QIcon::Off);
        receiptradio->setIcon(icon4);
        receiptradio->setIconSize(QSize(25, 23));
        receiptradio->setCheckable(true);
        receiptradio->setChecked(true);
        customerradio = new QRadioButton(optionsgroupbox);
        customerradio->setObjectName(QString::fromUtf8("customerradio"));
        customerradio->setGeometry(QRect(236, 20, 101, 27));
        customerradio->setFont(font);
        customerradio->setAutoFillBackground(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/resource/Customersearch.png"), QSize(), QIcon::Normal, QIcon::Off);
        customerradio->setIcon(icon5);
        customerradio->setIconSize(QSize(25, 23));
        searchbutton = new QPushButton(optionsgroupbox);
        searchbutton->setObjectName(QString::fromUtf8("searchbutton"));
        searchbutton->setGeometry(QRect(360, 50, 65, 25));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setWeight(75);
        searchbutton->setFont(font1);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../../Icon/search1.png"), QSize(), QIcon::Normal, QIcon::Off);
        searchbutton->setIcon(icon6);
        searchbutton->setIconSize(QSize(28, 23));
        searchbutton->setCheckable(false);
        searchbutton->setAutoRepeat(false);
        search_edit = new QLineEdit(optionsgroupbox);
        search_edit->setObjectName(QString::fromUtf8("search_edit"));
        search_edit->setGeometry(QRect(200, 51, 151, 24));
        QFont font2;
        font2.setPointSize(9);
        search_edit->setFont(font2);
        search_edit->setAlignment(Qt::AlignCenter);
        date_edit = new QLineEdit(optionsgroupbox);
        date_edit->setObjectName(QString::fromUtf8("date_edit"));
        date_edit->setGeometry(QRect(200, 51, 31, 24));
        date_edit->setFont(font2);
        date_edit->setMaxLength(2);
        date_edit->setAlignment(Qt::AlignCenter);
        month_edit = new QLineEdit(optionsgroupbox);
        month_edit->setObjectName(QString::fromUtf8("month_edit"));
        month_edit->setGeometry(QRect(240, 51, 31, 24));
        month_edit->setFont(font2);
        month_edit->setMaxLength(2);
        month_edit->setAlignment(Qt::AlignCenter);
        year_edit = new QLineEdit(optionsgroupbox);
        year_edit->setObjectName(QString::fromUtf8("year_edit"));
        year_edit->setGeometry(QRect(280, 51, 71, 24));
        year_edit->setFont(font2);
        year_edit->setMaxLength(4);
        year_edit->setAlignment(Qt::AlignCenter);
        search_label = new QLabel(optionsgroupbox);
        search_label->setObjectName(QString::fromUtf8("search_label"));
        search_label->setGeometry(QRect(70, 51, 121, 21));
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setWeight(75);
        search_label->setFont(font3);
        search_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        seperator_label1 = new QLabel(optionsgroupbox);
        seperator_label1->setObjectName(QString::fromUtf8("seperator_label1"));
        seperator_label1->setGeometry(QRect(228, 51, 16, 21));
        seperator_label1->setAlignment(Qt::AlignCenter);
        seperator_label2 = new QLabel(optionsgroupbox);
        seperator_label2->setObjectName(QString::fromUtf8("seperator_label2"));
        seperator_label2->setGeometry(QRect(268, 50, 16, 21));
        seperator_label2->setAlignment(Qt::AlignCenter);
        previousbutton = new QPushButton(DReports);
        previousbutton->setObjectName(QString::fromUtf8("previousbutton"));
        previousbutton->setGeometry(QRect(81, 408, 91, 31));
        previousbutton->setFont(font);
        nextbutton = new QPushButton(DReports);
        nextbutton->setObjectName(QString::fromUtf8("nextbutton"));
        nextbutton->setGeometry(QRect(371, 408, 91, 31));
        nextbutton->setFont(font);
        displayedit = new QTextEdit(DReports);
        displayedit->setObjectName(QString::fromUtf8("displayedit"));
        displayedit->setEnabled(false);
        displayedit->setGeometry(QRect(10, 90, 521, 310));
        displayedit->setFont(font);
        printbutton = new QPushButton(DReports);
        printbutton->setObjectName(QString::fromUtf8("printbutton"));
        printbutton->setGeometry(QRect(177, 408, 91, 31));
        printbutton->setFont(font);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/resource/Print.png"), QSize(), QIcon::Normal, QIcon::Off);
        printbutton->setIcon(icon7);
        printbutton->setIconSize(QSize(30, 26));
        clearbutton = new QPushButton(DReports);
        clearbutton->setObjectName(QString::fromUtf8("clearbutton"));
        clearbutton->setGeometry(QRect(274, 408, 91, 31));
        clearbutton->setFont(font);
        QWidget::setTabOrder(receiptradio, vehicleradio);
        QWidget::setTabOrder(vehicleradio, customerradio);
        QWidget::setTabOrder(customerradio, materialradio);
        QWidget::setTabOrder(materialradio, dateradio);
        QWidget::setTabOrder(dateradio, date_edit);
        QWidget::setTabOrder(date_edit, search_edit);
        QWidget::setTabOrder(search_edit, month_edit);
        QWidget::setTabOrder(month_edit, year_edit);
        QWidget::setTabOrder(year_edit, searchbutton);

        retranslateUi(DReports);

        QMetaObject::connectSlotsByName(DReports);
    } // setupUi

    void retranslateUi(QDialog *DReports)
    {
        DReports->setWindowTitle(QApplication::translate("DReports", "Reports", 0, QApplication::UnicodeUTF8));
        optionsgroupbox->setTitle(QApplication::translate("DReports", "Search Options", 0, QApplication::UnicodeUTF8));
        dateradio->setText(QApplication::translate("DReports", "Date", 0, QApplication::UnicodeUTF8));
        vehicleradio->setText(QApplication::translate("DReports", "Vehicle No", 0, QApplication::UnicodeUTF8));
        materialradio->setText(QApplication::translate("DReports", "Material", 0, QApplication::UnicodeUTF8));
        receiptradio->setText(QApplication::translate("DReports", "Receipt No", 0, QApplication::UnicodeUTF8));
        customerradio->setText(QApplication::translate("DReports", "Customer", 0, QApplication::UnicodeUTF8));
        searchbutton->setText(QApplication::translate("DReports", "Search", 0, QApplication::UnicodeUTF8));
        date_edit->setText(QString());
        month_edit->setText(QString());
        year_edit->setText(QString());
        search_label->setText(QApplication::translate("DReports", "Reciept No : ", 0, QApplication::UnicodeUTF8));
        seperator_label1->setText(QApplication::translate("DReports", "-", 0, QApplication::UnicodeUTF8));
        seperator_label2->setText(QApplication::translate("DReports", "-", 0, QApplication::UnicodeUTF8));
        previousbutton->setText(QApplication::translate("DReports", "Previous", 0, QApplication::UnicodeUTF8));
        nextbutton->setText(QApplication::translate("DReports", "Next", 0, QApplication::UnicodeUTF8));
        printbutton->setText(QApplication::translate("DReports", "Print", 0, QApplication::UnicodeUTF8));
        clearbutton->setText(QApplication::translate("DReports", "Clear", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DReports: public Ui_DReports {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DREPORTS_H
