/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created: Mon Sep 9 14:10:39 2013
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
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_settings
{
public:
    QGroupBox *password_groupbox;
    QLineEdit *oldpass_edit;
    QLineEdit *newpass_edit;
    QPushButton *password_change_button;
    QPushButton *password_ok_button;
    QLabel *oldpass_label;
    QLabel *newpass_label;
    QPushButton *password_cancel_button;
    QGroupBox *admin_groupbox;
    QGroupBox *search_groupbox;
    QRadioButton *order_radiobutton;
    QRadioButton *quality_radiobutton;
    QRadioButton *size_radiobutton;
    QLineEdit *search_lineedit;
    QLabel *selection_disp_label;
    QPushButton *search_button;
    QPushButton *clear_button;
    QTableWidget *display_table;

    void setupUi(QDialog *settings)
    {
        if (settings->objectName().isEmpty())
            settings->setObjectName(QString::fromUtf8("settings"));
        settings->resize(540, 390);
        settings->setMaximumSize(QSize(540, 390));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/images/Settings.ico"), QSize(), QIcon::Normal, QIcon::Off);
        settings->setWindowIcon(icon);
        password_groupbox = new QGroupBox(settings);
        password_groupbox->setObjectName(QString::fromUtf8("password_groupbox"));
        password_groupbox->setGeometry(QRect(10, 0, 521, 61));
        oldpass_edit = new QLineEdit(password_groupbox);
        oldpass_edit->setObjectName(QString::fromUtf8("oldpass_edit"));
        oldpass_edit->setGeometry(QRect(18, 33, 140, 20));
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        font.setWeight(75);
        oldpass_edit->setFont(font);
        oldpass_edit->setMaxLength(20);
        oldpass_edit->setEchoMode(QLineEdit::Password);
        oldpass_edit->setAlignment(Qt::AlignCenter);
        newpass_edit = new QLineEdit(password_groupbox);
        newpass_edit->setObjectName(QString::fromUtf8("newpass_edit"));
        newpass_edit->setEnabled(false);
        newpass_edit->setGeometry(QRect(238, 33, 140, 20));
        newpass_edit->setFont(font);
        newpass_edit->setMaxLength(20);
        newpass_edit->setEchoMode(QLineEdit::Password);
        newpass_edit->setAlignment(Qt::AlignCenter);
        password_change_button = new QPushButton(password_groupbox);
        password_change_button->setObjectName(QString::fromUtf8("password_change_button"));
        password_change_button->setEnabled(false);
        password_change_button->setGeometry(QRect(380, 32, 60, 22));
        password_ok_button = new QPushButton(password_groupbox);
        password_ok_button->setObjectName(QString::fromUtf8("password_ok_button"));
        password_ok_button->setGeometry(QRect(161, 32, 51, 22));
        oldpass_label = new QLabel(password_groupbox);
        oldpass_label->setObjectName(QString::fromUtf8("oldpass_label"));
        oldpass_label->setGeometry(QRect(20, 18, 71, 10));
        oldpass_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        newpass_label = new QLabel(password_groupbox);
        newpass_label->setObjectName(QString::fromUtf8("newpass_label"));
        newpass_label->setEnabled(false);
        newpass_label->setGeometry(QRect(240, 18, 71, 10));
        newpass_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        password_cancel_button = new QPushButton(password_groupbox);
        password_cancel_button->setObjectName(QString::fromUtf8("password_cancel_button"));
        password_cancel_button->setEnabled(false);
        password_cancel_button->setGeometry(QRect(440, 32, 60, 22));
        admin_groupbox = new QGroupBox(settings);
        admin_groupbox->setObjectName(QString::fromUtf8("admin_groupbox"));
        admin_groupbox->setGeometry(QRect(10, 60, 521, 321));
        search_groupbox = new QGroupBox(admin_groupbox);
        search_groupbox->setObjectName(QString::fromUtf8("search_groupbox"));
        search_groupbox->setGeometry(QRect(10, 15, 501, 65));
        order_radiobutton = new QRadioButton(search_groupbox);
        order_radiobutton->setObjectName(QString::fromUtf8("order_radiobutton"));
        order_radiobutton->setGeometry(QRect(120, 12, 82, 17));
        order_radiobutton->setChecked(true);
        quality_radiobutton = new QRadioButton(search_groupbox);
        quality_radiobutton->setObjectName(QString::fromUtf8("quality_radiobutton"));
        quality_radiobutton->setGeometry(QRect(220, 12, 82, 17));
        size_radiobutton = new QRadioButton(search_groupbox);
        size_radiobutton->setObjectName(QString::fromUtf8("size_radiobutton"));
        size_radiobutton->setGeometry(QRect(320, 12, 82, 17));
        search_lineedit = new QLineEdit(search_groupbox);
        search_lineedit->setObjectName(QString::fromUtf8("search_lineedit"));
        search_lineedit->setGeometry(QRect(142, 35, 161, 22));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        search_lineedit->setFont(font1);
        search_lineedit->setAlignment(Qt::AlignCenter);
        selection_disp_label = new QLabel(search_groupbox);
        selection_disp_label->setObjectName(QString::fromUtf8("selection_disp_label"));
        selection_disp_label->setGeometry(QRect(44, 35, 91, 22));
        selection_disp_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        search_button = new QPushButton(search_groupbox);
        search_button->setObjectName(QString::fromUtf8("search_button"));
        search_button->setGeometry(QRect(306, 34, 61, 24));
        clear_button = new QPushButton(search_groupbox);
        clear_button->setObjectName(QString::fromUtf8("clear_button"));
        clear_button->setGeometry(QRect(370, 34, 61, 24));
        display_table = new QTableWidget(admin_groupbox);
        if (display_table->columnCount() < 8)
            display_table->setColumnCount(8);
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font2);
        display_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font2);
        display_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font2);
        display_table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font2);
        display_table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font2);
        display_table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font2);
        display_table->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font2);
        display_table->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font2);
        display_table->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        display_table->setObjectName(QString::fromUtf8("display_table"));
        display_table->setGeometry(QRect(10, 84, 501, 230));
        display_table->setAlternatingRowColors(true);
        display_table->verticalHeader()->setDefaultSectionSize(18);
        display_table->verticalHeader()->setMinimumSectionSize(18);
        QWidget::setTabOrder(search_lineedit, search_button);
        QWidget::setTabOrder(search_button, clear_button);
        QWidget::setTabOrder(clear_button, order_radiobutton);
        QWidget::setTabOrder(order_radiobutton, quality_radiobutton);
        QWidget::setTabOrder(quality_radiobutton, size_radiobutton);
        QWidget::setTabOrder(size_radiobutton, oldpass_edit);
        QWidget::setTabOrder(oldpass_edit, password_ok_button);
        QWidget::setTabOrder(password_ok_button, newpass_edit);
        QWidget::setTabOrder(newpass_edit, password_change_button);
        QWidget::setTabOrder(password_change_button, password_cancel_button);
        QWidget::setTabOrder(password_cancel_button, display_table);

        retranslateUi(settings);

        QMetaObject::connectSlotsByName(settings);
    } // setupUi

    void retranslateUi(QDialog *settings)
    {
        settings->setWindowTitle(QApplication::translate("settings", "Settings", 0, QApplication::UnicodeUTF8));
        password_groupbox->setTitle(QApplication::translate("settings", "Change Password", 0, QApplication::UnicodeUTF8));
        password_change_button->setText(QApplication::translate("settings", "Change", 0, QApplication::UnicodeUTF8));
        password_ok_button->setText(QApplication::translate("settings", "OK", 0, QApplication::UnicodeUTF8));
        oldpass_label->setText(QApplication::translate("settings", "Old Password", 0, QApplication::UnicodeUTF8));
        newpass_label->setText(QApplication::translate("settings", "New Password", 0, QApplication::UnicodeUTF8));
        password_cancel_button->setText(QApplication::translate("settings", "Cancel", 0, QApplication::UnicodeUTF8));
        admin_groupbox->setTitle(QApplication::translate("settings", "Admin Menu", 0, QApplication::UnicodeUTF8));
        search_groupbox->setTitle(QApplication::translate("settings", "Search", 0, QApplication::UnicodeUTF8));
        order_radiobutton->setText(QApplication::translate("settings", "Order No", 0, QApplication::UnicodeUTF8));
        quality_radiobutton->setText(QApplication::translate("settings", "Quality", 0, QApplication::UnicodeUTF8));
        size_radiobutton->setText(QApplication::translate("settings", "Size", 0, QApplication::UnicodeUTF8));
        selection_disp_label->setText(QApplication::translate("settings", "Order No :", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        search_button->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        search_button->setWhatsThis(QApplication::translate("settings", "Will search database for the value given in the field", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        search_button->setText(QApplication::translate("settings", "Search", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        clear_button->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        clear_button->setWhatsThis(QApplication::translate("settings", "Clears all fields", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        clear_button->setText(QApplication::translate("settings", "Clear", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = display_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("settings", "Order ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = display_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("settings", "Weight", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = display_table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("settings", "Date", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = display_table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("settings", "Time", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = display_table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("settings", "Quality", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = display_table->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("settings", "Size", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = display_table->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("settings", "Tolerance", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = display_table->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("settings", "Tolerance %", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class settings: public Ui_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
