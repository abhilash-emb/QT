/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Nov 6 16:29:06 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLogin;
    QAction *actionOperator;
    QAction *actionStart_Weighing;
    QAction *actionSettings;
    QAction *actionHelp;
    QAction *actionExit;
    QWidget *centralWidget;
    QPushButton *settingsbutton;
    QPushButton *operatorbutton;
    QPushButton *startbutton;
    QPushButton *exitbutton;
    QPushButton *helpbutton;
    QFrame *frame_2;
    QFrame *frame_3;
    QFrame *frame;
    QLabel *datetimelabel;
    QLabel *header;
    QLabel *footer;
    QLabel *versionlabel;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(630, 480);
        MainWindow->setMinimumSize(QSize(630, 480));
        MainWindow->setMaximumSize(QSize(630, 480));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/images/appicon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionLogin = new QAction(MainWindow);
        actionLogin->setObjectName(QString::fromUtf8("actionLogin"));
        actionOperator = new QAction(MainWindow);
        actionOperator->setObjectName(QString::fromUtf8("actionOperator"));
        actionStart_Weighing = new QAction(MainWindow);
        actionStart_Weighing->setObjectName(QString::fromUtf8("actionStart_Weighing"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        settingsbutton = new QPushButton(centralWidget);
        settingsbutton->setObjectName(QString::fromUtf8("settingsbutton"));
        settingsbutton->setGeometry(QRect(30, 394, 90, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Unicode MS"));
        settingsbutton->setFont(font);
        settingsbutton->setStyleSheet(QString::fromUtf8(""));
        settingsbutton->setLocale(QLocale(QLocale::English, QLocale::India));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        settingsbutton->setIcon(icon1);
        settingsbutton->setIconSize(QSize(26, 26));
        operatorbutton = new QPushButton(centralWidget);
        operatorbutton->setObjectName(QString::fromUtf8("operatorbutton"));
        operatorbutton->setGeometry(QRect(140, 394, 90, 40));
        operatorbutton->setFont(font);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/images/operator.png"), QSize(), QIcon::Normal, QIcon::Off);
        operatorbutton->setIcon(icon2);
        operatorbutton->setIconSize(QSize(26, 26));
        startbutton = new QPushButton(centralWidget);
        startbutton->setObjectName(QString::fromUtf8("startbutton"));
        startbutton->setGeometry(QRect(249, 394, 131, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setWeight(75);
        startbutton->setFont(font1);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/images/capsules.png"), QSize(), QIcon::Normal, QIcon::Off);
        startbutton->setIcon(icon3);
        startbutton->setIconSize(QSize(28, 29));
        exitbutton = new QPushButton(centralWidget);
        exitbutton->setObjectName(QString::fromUtf8("exitbutton"));
        exitbutton->setGeometry(QRect(400, 394, 90, 40));
        exitbutton->setFont(font);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        exitbutton->setIcon(icon4);
        exitbutton->setIconSize(QSize(24, 24));
        helpbutton = new QPushButton(centralWidget);
        helpbutton->setObjectName(QString::fromUtf8("helpbutton"));
        helpbutton->setGeometry(QRect(510, 394, 90, 40));
        helpbutton->setFont(font);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/images/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        helpbutton->setIcon(icon5);
        helpbutton->setIconSize(QSize(26, 26));
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(170, 260, 120, 80));
        frame_2->setStyleSheet(QString::fromUtf8("image: url(:/new/images/capsules.png);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(350, 270, 101, 61));
        frame_3->setStyleSheet(QString::fromUtf8("image: url(:/new/images/capsules_1.png);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(230, 200, 171, 131));
        frame->setStyleSheet(QString::fromUtf8("image: url(:/new/images/background.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        datetimelabel = new QLabel(centralWidget);
        datetimelabel->setObjectName(QString::fromUtf8("datetimelabel"));
        datetimelabel->setGeometry(QRect(180, 360, 271, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setWeight(75);
        datetimelabel->setFont(font2);
        datetimelabel->setStyleSheet(QString::fromUtf8("color: rgb(212, 0, 3);"));
        datetimelabel->setAlignment(Qt::AlignCenter);
        header = new QLabel(centralWidget);
        header->setObjectName(QString::fromUtf8("header"));
        header->setGeometry(QRect(20, 40, 591, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font3.setPointSize(24);
        font3.setBold(true);
        font3.setWeight(75);
        header->setFont(font3);
        header->setStyleSheet(QString::fromUtf8("color: rgb(236, 45, 96);"));
        header->setAlignment(Qt::AlignCenter);
        footer = new QLabel(centralWidget);
        footer->setObjectName(QString::fromUtf8("footer"));
        footer->setGeometry(QRect(20, 440, 591, 20));
        footer->setFont(font);
        footer->setAlignment(Qt::AlignCenter);
        versionlabel = new QLabel(centralWidget);
        versionlabel->setObjectName(QString::fromUtf8("versionlabel"));
        versionlabel->setGeometry(QRect(570, -2, 61, 20));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Capzule", 0, QApplication::UnicodeUTF8));
        actionLogin->setText(QApplication::translate("MainWindow", "Login", 0, QApplication::UnicodeUTF8));
        actionOperator->setText(QApplication::translate("MainWindow", "Operator", 0, QApplication::UnicodeUTF8));
        actionStart_Weighing->setText(QApplication::translate("MainWindow", "Start Weighing", 0, QApplication::UnicodeUTF8));
        actionSettings->setText(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        settingsbutton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        settingsbutton->setText(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        operatorbutton->setText(QApplication::translate("MainWindow", "Operator", 0, QApplication::UnicodeUTF8));
        startbutton->setText(QApplication::translate("MainWindow", "Start Weighing", 0, QApplication::UnicodeUTF8));
        exitbutton->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        helpbutton->setText(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        datetimelabel->setText(QString());
        header->setText(QApplication::translate("MainWindow", "header", 0, QApplication::UnicodeUTF8));
        footer->setText(QApplication::translate("MainWindow", "footer", 0, QApplication::UnicodeUTF8));
        versionlabel->setText(QApplication::translate("MainWindow", "Capzule 1.0", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
