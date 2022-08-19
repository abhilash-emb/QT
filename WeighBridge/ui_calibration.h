/********************************************************************************
** Form generated from reading UI file 'calibration.ui'
**
** Created: Tue Oct 1 16:34:02 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBRATION_H
#define UI_CALIBRATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_calibration
{
public:
    QLineEdit *calibration_edit;
    QPushButton *update_button;
    QLabel *label;

    void setupUi(QDialog *calibration)
    {
        if (calibration->objectName().isEmpty())
            calibration->setObjectName(QString::fromUtf8("calibration"));
        calibration->resize(259, 66);
        calibration_edit = new QLineEdit(calibration);
        calibration_edit->setObjectName(QString::fromUtf8("calibration_edit"));
        calibration_edit->setGeometry(QRect(16, 34, 150, 24));
        QFont font;
        font.setPointSize(10);
        calibration_edit->setFont(font);
        calibration_edit->setAlignment(Qt::AlignCenter);
        update_button = new QPushButton(calibration);
        update_button->setObjectName(QString::fromUtf8("update_button"));
        update_button->setGeometry(QRect(170, 33, 75, 25));
        QFont font1;
        font1.setPointSize(8);
        update_button->setFont(font1);
        label = new QLabel(calibration);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(17, 10, 151, 21));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);

        retranslateUi(calibration);

        QMetaObject::connectSlotsByName(calibration);
    } // setupUi

    void retranslateUi(QDialog *calibration)
    {
        calibration->setWindowTitle(QApplication::translate("calibration", "Clibration", 0, QApplication::UnicodeUTF8));
        update_button->setText(QApplication::translate("calibration", "Update", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("calibration", "Calibration", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class calibration: public Ui_calibration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBRATION_H
