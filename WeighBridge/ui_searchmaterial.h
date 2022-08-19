/********************************************************************************
** Form generated from reading UI file 'searchmaterial.ui'
**
** Created: Tue Sep 24 14:04:04 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHMATERIAL_H
#define UI_SEARCHMATERIAL_H

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

class Ui_searchmaterial
{
public:
    QPushButton *gobutton;
    QPushButton *printbutton;
    QPushButton *clearbutton;
    QLineEdit *materialedit;
    QTextEdit *displayedit;
    QLabel *materiallabel;
    QPushButton *nextbutton;
    QPushButton *previousbutton;

    void setupUi(QDialog *searchmaterial)
    {
        if (searchmaterial->objectName().isEmpty())
            searchmaterial->setObjectName(QString::fromUtf8("searchmaterial"));
        searchmaterial->resize(540, 430);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/resource/Materialsearch.png"), QSize(), QIcon::Normal, QIcon::Off);
        searchmaterial->setWindowIcon(icon);
        gobutton = new QPushButton(searchmaterial);
        gobutton->setObjectName(QString::fromUtf8("gobutton"));
        gobutton->setGeometry(QRect(380, 22, 41, 27));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Unicode MS"));
        gobutton->setFont(font);
        printbutton = new QPushButton(searchmaterial);
        printbutton->setObjectName(QString::fromUtf8("printbutton"));
        printbutton->setGeometry(QRect(170, 380, 91, 31));
        printbutton->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/resource/Print.png"), QSize(), QIcon::Normal, QIcon::Off);
        printbutton->setIcon(icon1);
        printbutton->setIconSize(QSize(30, 26));
        clearbutton = new QPushButton(searchmaterial);
        clearbutton->setObjectName(QString::fromUtf8("clearbutton"));
        clearbutton->setGeometry(QRect(280, 380, 91, 31));
        clearbutton->setFont(font);
        materialedit = new QLineEdit(searchmaterial);
        materialedit->setObjectName(QString::fromUtf8("materialedit"));
        materialedit->setGeometry(QRect(190, 22, 181, 27));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        materialedit->setFont(font1);
        materialedit->setAlignment(Qt::AlignCenter);
        displayedit = new QTextEdit(searchmaterial);
        displayedit->setObjectName(QString::fromUtf8("displayedit"));
        displayedit->setEnabled(false);
        displayedit->setGeometry(QRect(10, 60, 521, 310));
        displayedit->setFont(font);
        materiallabel = new QLabel(searchmaterial);
        materiallabel->setObjectName(QString::fromUtf8("materiallabel"));
        materiallabel->setGeometry(QRect(90, 20, 81, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setWeight(75);
        materiallabel->setFont(font2);
        materiallabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        nextbutton = new QPushButton(searchmaterial);
        nextbutton->setObjectName(QString::fromUtf8("nextbutton"));
        nextbutton->setGeometry(QRect(390, 380, 91, 31));
        nextbutton->setFont(font);
        previousbutton = new QPushButton(searchmaterial);
        previousbutton->setObjectName(QString::fromUtf8("previousbutton"));
        previousbutton->setGeometry(QRect(60, 380, 91, 31));
        previousbutton->setFont(font);
        QWidget::setTabOrder(materialedit, gobutton);
        QWidget::setTabOrder(gobutton, printbutton);
        QWidget::setTabOrder(printbutton, clearbutton);
        QWidget::setTabOrder(clearbutton, nextbutton);
        QWidget::setTabOrder(nextbutton, previousbutton);
        QWidget::setTabOrder(previousbutton, displayedit);

        retranslateUi(searchmaterial);

        QMetaObject::connectSlotsByName(searchmaterial);
    } // setupUi

    void retranslateUi(QDialog *searchmaterial)
    {
        searchmaterial->setWindowTitle(QApplication::translate("searchmaterial", "Search by Material", 0, QApplication::UnicodeUTF8));
        gobutton->setText(QApplication::translate("searchmaterial", "Go", 0, QApplication::UnicodeUTF8));
        printbutton->setText(QApplication::translate("searchmaterial", "Print", 0, QApplication::UnicodeUTF8));
        clearbutton->setText(QApplication::translate("searchmaterial", "Clear", 0, QApplication::UnicodeUTF8));
        materiallabel->setText(QApplication::translate("searchmaterial", "Material", 0, QApplication::UnicodeUTF8));
        nextbutton->setText(QApplication::translate("searchmaterial", "Next", 0, QApplication::UnicodeUTF8));
        previousbutton->setText(QApplication::translate("searchmaterial", "Previous", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class searchmaterial: public Ui_searchmaterial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHMATERIAL_H
