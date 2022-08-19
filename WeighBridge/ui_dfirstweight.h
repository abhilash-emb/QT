/********************************************************************************
** Form generated from reading UI file 'dfirstweight.ui'
**
** Created: Tue Oct 8 13:11:30 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DFIRSTWEIGHT_H
#define UI_DFIRSTWEIGHT_H

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

class Ui_DFirstWeight
{
public:
    QLabel *vehiclelabel;
    QLabel *customerlabel;
    QLabel *materiallabel;
    QLabel *billnolabel;
    QLabel *challanlabel;
    QLabel *chargelabel;
    QLabel *weightlabel;
    QLineEdit *vehiclelineedit;
    QLineEdit *customerlineedit;
    QLineEdit *materiallineedit;
    QLineEdit *billnolineedit;
    QLineEdit *challanlineedit;
    QLabel *kglabel;
    QLabel *modelabel;
    QLineEdit *chargelineedit;
    QLineEdit *weightlineedit;
    QLabel *statuslabel;
    QGroupBox *buttonbox;
    QPushButton *closebutton;
    QPushButton *saveprintbutton;
    QPushButton *clearallbutton;
    QPushButton *acceptbutton;

    void setupUi(QDialog *DFirstWeight)
    {
        if (DFirstWeight->objectName().isEmpty())
            DFirstWeight->setObjectName(QString::fromUtf8("DFirstWeight"));
        DFirstWeight->resize(540, 340);
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Unicode MS"));
        DFirstWeight->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/resource/Firstweight.png"), QSize(), QIcon::Normal, QIcon::Off);
        DFirstWeight->setWindowIcon(icon);
        vehiclelabel = new QLabel(DFirstWeight);
        vehiclelabel->setObjectName(QString::fromUtf8("vehiclelabel"));
        vehiclelabel->setGeometry(QRect(20, 31, 81, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font1.setPointSize(10);
        vehiclelabel->setFont(font1);
        vehiclelabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        customerlabel = new QLabel(DFirstWeight);
        customerlabel->setObjectName(QString::fromUtf8("customerlabel"));
        customerlabel->setGeometry(QRect(30, 70, 71, 31));
        customerlabel->setFont(font1);
        customerlabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        materiallabel = new QLabel(DFirstWeight);
        materiallabel->setObjectName(QString::fromUtf8("materiallabel"));
        materiallabel->setGeometry(QRect(40, 110, 61, 31));
        materiallabel->setFont(font1);
        materiallabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        billnolabel = new QLabel(DFirstWeight);
        billnolabel->setObjectName(QString::fromUtf8("billnolabel"));
        billnolabel->setGeometry(QRect(40, 150, 61, 31));
        billnolabel->setFont(font1);
        billnolabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        challanlabel = new QLabel(DFirstWeight);
        challanlabel->setObjectName(QString::fromUtf8("challanlabel"));
        challanlabel->setGeometry(QRect(20, 191, 81, 31));
        challanlabel->setFont(font1);
        challanlabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        chargelabel = new QLabel(DFirstWeight);
        chargelabel->setObjectName(QString::fromUtf8("chargelabel"));
        chargelabel->setGeometry(QRect(40, 231, 61, 31));
        chargelabel->setFont(font1);
        chargelabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        weightlabel = new QLabel(DFirstWeight);
        weightlabel->setObjectName(QString::fromUtf8("weightlabel"));
        weightlabel->setGeometry(QRect(40, 270, 61, 31));
        weightlabel->setFont(font1);
        weightlabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        vehiclelineedit = new QLineEdit(DFirstWeight);
        vehiclelineedit->setObjectName(QString::fromUtf8("vehiclelineedit"));
        vehiclelineedit->setGeometry(QRect(120, 31, 201, 27));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        vehiclelineedit->setFont(font2);
        vehiclelineedit->setInputMethodHints(Qt::ImhNone);
        vehiclelineedit->setAlignment(Qt::AlignCenter);
        customerlineedit = new QLineEdit(DFirstWeight);
        customerlineedit->setObjectName(QString::fromUtf8("customerlineedit"));
        customerlineedit->setGeometry(QRect(120, 71, 201, 27));
        customerlineedit->setFont(font2);
        customerlineedit->setInputMethodHints(Qt::ImhNone);
        customerlineedit->setAlignment(Qt::AlignCenter);
        materiallineedit = new QLineEdit(DFirstWeight);
        materiallineedit->setObjectName(QString::fromUtf8("materiallineedit"));
        materiallineedit->setGeometry(QRect(120, 111, 201, 27));
        materiallineedit->setFont(font2);
        materiallineedit->setInputMethodHints(Qt::ImhNone);
        materiallineedit->setAlignment(Qt::AlignCenter);
        billnolineedit = new QLineEdit(DFirstWeight);
        billnolineedit->setObjectName(QString::fromUtf8("billnolineedit"));
        billnolineedit->setEnabled(false);
        billnolineedit->setGeometry(QRect(120, 151, 201, 27));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        billnolineedit->setFont(font3);
        billnolineedit->setStyleSheet(QString::fromUtf8("color: rgb(166, 0, 16);"));
        billnolineedit->setAlignment(Qt::AlignCenter);
        challanlineedit = new QLineEdit(DFirstWeight);
        challanlineedit->setObjectName(QString::fromUtf8("challanlineedit"));
        challanlineedit->setGeometry(QRect(120, 191, 201, 27));
        challanlineedit->setFont(font2);
        challanlineedit->setInputMethodHints(Qt::ImhNone);
        challanlineedit->setAlignment(Qt::AlignCenter);
        kglabel = new QLabel(DFirstWeight);
        kglabel->setObjectName(QString::fromUtf8("kglabel"));
        kglabel->setGeometry(QRect(320, 271, 51, 31));
        kglabel->setFont(font2);
        kglabel->setAlignment(Qt::AlignCenter);
        modelabel = new QLabel(DFirstWeight);
        modelabel->setObjectName(QString::fromUtf8("modelabel"));
        modelabel->setGeometry(QRect(4, 323, 61, 16));
        QFont font4;
        font4.setItalic(true);
        modelabel->setFont(font4);
        chargelineedit = new QLineEdit(DFirstWeight);
        chargelineedit->setObjectName(QString::fromUtf8("chargelineedit"));
        chargelineedit->setGeometry(QRect(120, 231, 201, 27));
        chargelineedit->setFont(font2);
        chargelineedit->setAlignment(Qt::AlignCenter);
        weightlineedit = new QLineEdit(DFirstWeight);
        weightlineedit->setObjectName(QString::fromUtf8("weightlineedit"));
        weightlineedit->setGeometry(QRect(120, 271, 201, 27));
        weightlineedit->setFont(font3);
        weightlineedit->setStyleSheet(QString::fromUtf8("color: rgb(212, 0, 3);"));
        weightlineedit->setAlignment(Qt::AlignCenter);
        statuslabel = new QLabel(DFirstWeight);
        statuslabel->setObjectName(QString::fromUtf8("statuslabel"));
        statuslabel->setGeometry(QRect(407, 323, 131, 16));
        QFont font5;
        font5.setBold(false);
        font5.setItalic(true);
        font5.setWeight(50);
        statuslabel->setFont(font5);
        statuslabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        buttonbox = new QGroupBox(DFirstWeight);
        buttonbox->setObjectName(QString::fromUtf8("buttonbox"));
        buttonbox->setGeometry(QRect(390, 31, 141, 271));
        closebutton = new QPushButton(buttonbox);
        closebutton->setObjectName(QString::fromUtf8("closebutton"));
        closebutton->setGeometry(QRect(20, 200, 101, 51));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        closebutton->setPalette(palette);
        closebutton->setFont(font);
        closebutton->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        saveprintbutton = new QPushButton(buttonbox);
        saveprintbutton->setObjectName(QString::fromUtf8("saveprintbutton"));
        saveprintbutton->setGeometry(QRect(20, 80, 101, 51));
        saveprintbutton->setFont(font);
        clearallbutton = new QPushButton(buttonbox);
        clearallbutton->setObjectName(QString::fromUtf8("clearallbutton"));
        clearallbutton->setGeometry(QRect(20, 140, 101, 51));
        clearallbutton->setFont(font);
        acceptbutton = new QPushButton(buttonbox);
        acceptbutton->setObjectName(QString::fromUtf8("acceptbutton"));
        acceptbutton->setGeometry(QRect(20, 20, 101, 51));
        acceptbutton->setFont(font);
        vehiclelabel->raise();
        customerlabel->raise();
        materiallabel->raise();
        billnolabel->raise();
        challanlabel->raise();
        chargelabel->raise();
        weightlabel->raise();
        vehiclelineedit->raise();
        customerlineedit->raise();
        materiallineedit->raise();
        billnolineedit->raise();
        challanlineedit->raise();
        kglabel->raise();
        modelabel->raise();
        weightlineedit->raise();
        chargelineedit->raise();
        statuslabel->raise();
        buttonbox->raise();
        QWidget::setTabOrder(vehiclelineedit, customerlineedit);
        QWidget::setTabOrder(customerlineedit, materiallineedit);
        QWidget::setTabOrder(materiallineedit, acceptbutton);
        QWidget::setTabOrder(acceptbutton, challanlineedit);
        QWidget::setTabOrder(challanlineedit, chargelineedit);
        QWidget::setTabOrder(chargelineedit, weightlineedit);
        QWidget::setTabOrder(weightlineedit, saveprintbutton);
        QWidget::setTabOrder(saveprintbutton, closebutton);
        QWidget::setTabOrder(closebutton, clearallbutton);
        QWidget::setTabOrder(clearallbutton, billnolineedit);

        retranslateUi(DFirstWeight);

        QMetaObject::connectSlotsByName(DFirstWeight);
    } // setupUi

    void retranslateUi(QDialog *DFirstWeight)
    {
        DFirstWeight->setWindowTitle(QApplication::translate("DFirstWeight", "First Weight", 0, QApplication::UnicodeUTF8));
        vehiclelabel->setText(QApplication::translate("DFirstWeight", "Vehicle No", 0, QApplication::UnicodeUTF8));
        customerlabel->setText(QApplication::translate("DFirstWeight", "Customer", 0, QApplication::UnicodeUTF8));
        materiallabel->setText(QApplication::translate("DFirstWeight", "Material", 0, QApplication::UnicodeUTF8));
        billnolabel->setText(QApplication::translate("DFirstWeight", "Bill No", 0, QApplication::UnicodeUTF8));
        challanlabel->setText(QApplication::translate("DFirstWeight", "Challan No", 0, QApplication::UnicodeUTF8));
        chargelabel->setText(QApplication::translate("DFirstWeight", "Charge", 0, QApplication::UnicodeUTF8));
        weightlabel->setText(QApplication::translate("DFirstWeight", "Weight", 0, QApplication::UnicodeUTF8));
        kglabel->setText(QApplication::translate("DFirstWeight", "  KG", 0, QApplication::UnicodeUTF8));
        modelabel->setText(QApplication::translate("DFirstWeight", "text", 0, QApplication::UnicodeUTF8));
        statuslabel->setText(QApplication::translate("DFirstWeight", "Status", 0, QApplication::UnicodeUTF8));
        buttonbox->setTitle(QString());
        closebutton->setText(QApplication::translate("DFirstWeight", "Close", 0, QApplication::UnicodeUTF8));
        saveprintbutton->setText(QApplication::translate("DFirstWeight", "Save/Print", 0, QApplication::UnicodeUTF8));
        clearallbutton->setText(QApplication::translate("DFirstWeight", "Reset", 0, QApplication::UnicodeUTF8));
        acceptbutton->setText(QApplication::translate("DFirstWeight", "Accept", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DFirstWeight: public Ui_DFirstWeight {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DFIRSTWEIGHT_H
