/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Sep 23 11:12:38 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSettings;
    QAction *actionAbout;
    QWidget *centralWidget;
    QFrame *app_image;
    QLabel *name_label;
    QLabel *name_label2;
    QLabel *versio_label;
    QLabel *date_label;
    QLabel *time_label;
    QLabel *toleranceper_label;
    QLabel *tolerancedisp_label;
    QLabel *totalitemdisp_label;
    QLabel *totalitem_label;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *quality_edit;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *order_edit;
    QLineEdit *tolerance_edit;
    QLabel *order_label;
    QLineEdit *size_edit;
    QGroupBox *groupBox_2;
    QPushButton *stop_button;
    QLineEdit *weight_edit;
    QPushButton *start_button;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuAdmin;
    QMenu *menuAbout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(620, 280);
        MainWindow->setMaximumSize(QSize(620, 280));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/images/app_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/images/Settings.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon1);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/images/Help.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon2);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        app_image = new QFrame(centralWidget);
        app_image->setObjectName(QString::fromUtf8("app_image"));
        app_image->setGeometry(QRect(434, 179, 71, 61));
        app_image->setStyleSheet(QString::fromUtf8("image: url(:/new/images/back_ground.png);"));
        app_image->setFrameShape(QFrame::StyledPanel);
        app_image->setFrameShadow(QFrame::Raised);
        name_label = new QLabel(centralWidget);
        name_label->setObjectName(QString::fromUtf8("name_label"));
        name_label->setGeometry(QRect(484, 218, 81, 21));
        QFont font;
        font.setPointSize(20);
        font.setItalic(false);
        name_label->setFont(font);
        name_label2 = new QLabel(centralWidget);
        name_label2->setObjectName(QString::fromUtf8("name_label2"));
        name_label2->setGeometry(QRect(564, 210, 31, 16));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        name_label2->setFont(font1);
        versio_label = new QLabel(centralWidget);
        versio_label->setObjectName(QString::fromUtf8("versio_label"));
        versio_label->setGeometry(QRect(590, 228, 21, 16));
        date_label = new QLabel(centralWidget);
        date_label->setObjectName(QString::fromUtf8("date_label"));
        date_label->setGeometry(QRect(440, 2, 91, 20));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setWeight(75);
        date_label->setFont(font2);
        date_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        time_label = new QLabel(centralWidget);
        time_label->setObjectName(QString::fromUtf8("time_label"));
        time_label->setGeometry(QRect(550, 2, 61, 20));
        time_label->setFont(font2);
        time_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        toleranceper_label = new QLabel(centralWidget);
        toleranceper_label->setObjectName(QString::fromUtf8("toleranceper_label"));
        toleranceper_label->setGeometry(QRect(20, 130, 81, 21));
        toleranceper_label->setFont(font2);
        toleranceper_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        tolerancedisp_label = new QLabel(centralWidget);
        tolerancedisp_label->setObjectName(QString::fromUtf8("tolerancedisp_label"));
        tolerancedisp_label->setGeometry(QRect(103, 130, 81, 21));
        tolerancedisp_label->setFont(font2);
        tolerancedisp_label->setStyleSheet(QString::fromUtf8("color: rgb(179, 4, 7);"));
        tolerancedisp_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        totalitemdisp_label = new QLabel(centralWidget);
        totalitemdisp_label->setObjectName(QString::fromUtf8("totalitemdisp_label"));
        totalitemdisp_label->setGeometry(QRect(103, 110, 81, 21));
        totalitemdisp_label->setFont(font2);
        totalitemdisp_label->setStyleSheet(QString::fromUtf8("color: rgb(85, 0, 255);"));
        totalitemdisp_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        totalitem_label = new QLabel(centralWidget);
        totalitem_label->setObjectName(QString::fromUtf8("totalitem_label"));
        totalitem_label->setGeometry(QRect(20, 110, 81, 21));
        totalitem_label->setFont(font2);
        totalitem_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 601, 81));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 20, 81, 16));
        label->setFont(font2);
        quality_edit = new QLineEdit(groupBox);
        quality_edit->setObjectName(QString::fromUtf8("quality_edit"));
        quality_edit->setGeometry(QRect(340, 40, 120, 30));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        quality_edit->setFont(font3);
        quality_edit->setMaxLength(11);
        quality_edit->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(340, 20, 81, 16));
        label_2->setFont(font2);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(470, 20, 81, 16));
        label_3->setFont(font2);
        order_edit = new QLineEdit(groupBox);
        order_edit->setObjectName(QString::fromUtf8("order_edit"));
        order_edit->setGeometry(QRect(10, 40, 190, 30));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        order_edit->setFont(font4);
        order_edit->setStyleSheet(QString::fromUtf8("color: rgb(179, 4, 7);"));
        order_edit->setMaxLength(10);
        order_edit->setAlignment(Qt::AlignCenter);
        tolerance_edit = new QLineEdit(groupBox);
        tolerance_edit->setObjectName(QString::fromUtf8("tolerance_edit"));
        tolerance_edit->setGeometry(QRect(210, 40, 120, 30));
        tolerance_edit->setFont(font3);
        tolerance_edit->setAlignment(Qt::AlignCenter);
        order_label = new QLabel(groupBox);
        order_label->setObjectName(QString::fromUtf8("order_label"));
        order_label->setGeometry(QRect(10, 20, 91, 16));
        order_label->setFont(font2);
        size_edit = new QLineEdit(groupBox);
        size_edit->setObjectName(QString::fromUtf8("size_edit"));
        size_edit->setGeometry(QRect(470, 40, 120, 30));
        size_edit->setFont(font3);
        size_edit->setMaxLength(8);
        size_edit->setAlignment(Qt::AlignCenter);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 160, 404, 81));
        stop_button = new QPushButton(groupBox_2);
        stop_button->setObjectName(QString::fromUtf8("stop_button"));
        stop_button->setGeometry(QRect(320, 20, 75, 53));
        stop_button->setFont(font2);
        stop_button->setStyleSheet(QString::fromUtf8("color: rgb(179, 4, 7);"));
        weight_edit = new QLineEdit(groupBox_2);
        weight_edit->setObjectName(QString::fromUtf8("weight_edit"));
        weight_edit->setEnabled(false);
        weight_edit->setGeometry(QRect(10, 21, 220, 51));
        QFont font5;
        font5.setPointSize(28);
        weight_edit->setFont(font5);
        weight_edit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        start_button = new QPushButton(groupBox_2);
        start_button->setObjectName(QString::fromUtf8("start_button"));
        start_button->setGeometry(QRect(238, 20, 75, 53));
        start_button->setFont(font2);
        start_button->setStyleSheet(QString::fromUtf8("color: rgb(4, 100, 31);"));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 620, 20));
        menuAdmin = new QMenu(menuBar);
        menuAdmin->setObjectName(QString::fromUtf8("menuAdmin"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        MainWindow->setMenuBar(menuBar);
        QWidget::setTabOrder(order_edit, tolerance_edit);
        QWidget::setTabOrder(tolerance_edit, quality_edit);
        QWidget::setTabOrder(quality_edit, size_edit);
        QWidget::setTabOrder(size_edit, weight_edit);
        QWidget::setTabOrder(weight_edit, start_button);
        QWidget::setTabOrder(start_button, stop_button);

        menuBar->addAction(menuAdmin->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuAdmin->addAction(actionSettings);
        menuAbout->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Printer++   Ver 1.0", 0, QApplication::UnicodeUTF8));
        actionSettings->setText(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        name_label->setText(QApplication::translate("MainWindow", "Printer", 0, QApplication::UnicodeUTF8));
        name_label2->setText(QApplication::translate("MainWindow", "++", 0, QApplication::UnicodeUTF8));
        versio_label->setText(QApplication::translate("MainWindow", "1.0", 0, QApplication::UnicodeUTF8));
        date_label->setText(QString());
        time_label->setText(QString());
        toleranceper_label->setText(QApplication::translate("MainWindow", "Tolerance    :", 0, QApplication::UnicodeUTF8));
        tolerancedisp_label->setText(QString());
        totalitemdisp_label->setText(QString());
        totalitem_label->setText(QApplication::translate("MainWindow", "Total Items :", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Product Details", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Tolerance", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        quality_edit->setWhatsThis(QApplication::translate("MainWindow", "Quality of product", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        quality_edit->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Quality", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Size", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        order_edit->setWhatsThis(QApplication::translate("MainWindow", "Order Number", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        order_edit->setText(QString());
#ifndef QT_NO_WHATSTHIS
        tolerance_edit->setWhatsThis(QApplication::translate("MainWindow", "Actual weight expected", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        tolerance_edit->setText(QString());
        order_label->setText(QApplication::translate("MainWindow", "Order Number", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        size_edit->setWhatsThis(QApplication::translate("MainWindow", "Size category of product", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        size_edit->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Weight Measured", 0, QApplication::UnicodeUTF8));
        stop_button->setText(QApplication::translate("MainWindow", "STOP", 0, QApplication::UnicodeUTF8));
        weight_edit->setText(QString());
        start_button->setText(QApplication::translate("MainWindow", "START", 0, QApplication::UnicodeUTF8));
        menuAdmin->setTitle(QApplication::translate("MainWindow", "Administrator", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
