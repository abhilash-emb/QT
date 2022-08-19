/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created: Wed Nov 6 16:29:06 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QFrame *frame;
    QLineEdit *passwordedit;
    QPushButton *cancelbutton;
    QPushButton *okbutton;
    QFrame *passwordframe;
    QFrame *frame_2;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(270, 344);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Settings->sizePolicy().hasHeightForWidth());
        Settings->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/images/admin.png"), QSize(), QIcon::Normal, QIcon::Off);
        Settings->setWindowIcon(icon);
        frame = new QFrame(Settings);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(-10, -1, 291, 351));
        frame->setStyleSheet(QString::fromUtf8("image: url(:/new/images/Adminlogin.jpg);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        passwordedit = new QLineEdit(frame);
        passwordedit->setObjectName(QString::fromUtf8("passwordedit"));
        passwordedit->setGeometry(QRect(54, 217, 182, 23));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        passwordedit->setFont(font);
        passwordedit->setMaxLength(30);
        passwordedit->setEchoMode(QLineEdit::Password);
        passwordedit->setAlignment(Qt::AlignCenter);
        cancelbutton = new QPushButton(frame);
        cancelbutton->setObjectName(QString::fromUtf8("cancelbutton"));
        cancelbutton->setGeometry(QRect(107, 286, 78, 26));
        okbutton = new QPushButton(frame);
        okbutton->setObjectName(QString::fromUtf8("okbutton"));
        okbutton->setGeometry(QRect(237, 215, 28, 27));
        okbutton->setMinimumSize(QSize(0, 0));
        okbutton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/images/enter.png"), QSize(), QIcon::Normal, QIcon::Off);
        okbutton->setIcon(icon1);
        okbutton->setIconSize(QSize(20, 20));
        passwordframe = new QFrame(frame);
        passwordframe->setObjectName(QString::fromUtf8("passwordframe"));
        passwordframe->setGeometry(QRect(25, 216, 25, 24));
        passwordframe->setStyleSheet(QString::fromUtf8("image: url(:/new/images/password.ico);"));
        passwordframe->setFrameShape(QFrame::StyledPanel);
        passwordframe->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(85, 52, 117, 112));
        frame_2->setStyleSheet(QString::fromUtf8("image: url(:/new/images/admin.png);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        QWidget::setTabOrder(passwordedit, okbutton);
        QWidget::setTabOrder(okbutton, cancelbutton);

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Admin Login", 0, QApplication::UnicodeUTF8));
        cancelbutton->setText(QApplication::translate("Settings", "Cancel", 0, QApplication::UnicodeUTF8));
        okbutton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
