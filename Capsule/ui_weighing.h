/********************************************************************************
** Form generated from reading UI file 'weighing.ui'
**
** Created: Wed Nov 6 16:29:06 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEIGHING_H
#define UI_WEIGHING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_weighing
{
public:
    QComboBox *batchidcombobox;
    QPushButton *okbutton;
    QLabel *batchidlabel;
    QGroupBox *activebatchgroup;
    QTextEdit *weightdisplayedit;
    QPushButton *stopbutton;
    QPushButton *startbutton;
    QLabel *timelabel;
    QLabel *timeupdatelabel;
    QLabel *datelabel;
    QLabel *dateupdatelabel;
    QLabel *starttime;
    QLabel *starttimelabel;
    QLabel *stoptime;
    QLabel *stoptimelabel;
    QLabel *label;
    QPushButton *endbatch;
    QLabel *para_1;
    QLabel *para_2;
    QLabel *para_3;
    QLabel *para_4;
    QLabel *para_5;
    QLabel *para_6;
    QLabel *para_7;
    QLabel *para_8;
    QLabel *para_9;
    QLabel *para_10;
    QLabel *fillweightlabel;
    QLabel *tareweightlabel;
    QLabel *tolerancelabel31_2;
    QLabel *tolerancelabel21;
    QLabel *tolerancelabel11;
    QLabel *value_1;
    QLabel *value_2;
    QLabel *value_3;
    QLabel *value_4;
    QLabel *value_5;
    QLabel *value_6;
    QLabel *value_7;
    QLabel *value_8;
    QLabel *value_9;
    QLabel *value_10;
    QLabel *fillweight;
    QLabel *tareweight;
    QLabel *tolerance31;
    QLabel *tolerance21;
    QLabel *tolerance11;
    QLabel *currentweight;
    QLabel *label_2;
    QLabel *lastweight;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *tolerance12;
    QLabel *tolerancelabel22;
    QLabel *tolerance22;
    QLabel *tolerancelabel32;
    QLabel *tolerancelabel12;
    QLabel *tolerance32;
    QLabel *messagelabel;
    QLabel *ltt3;
    QLabel *ltt2;
    QLabel *ltt1;
    QLabel *gtt1;
    QLabel *gtt2;
    QLabel *gtt3;
    QLineEdit *countedit;
    QLabel *label_6;
    QLabel *loggedinlabel;
    QLabel *currentuser;
    QLabel *loggedinatlabel;
    QLabel *loggedintime;
    QPushButton *lockbutton;

    void setupUi(QDialog *weighing)
    {
        if (weighing->objectName().isEmpty())
            weighing->setObjectName(QString::fromUtf8("weighing"));
        weighing->setEnabled(true);
        weighing->resize(630, 555);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/images/capsules.png"), QSize(), QIcon::Normal, QIcon::Off);
        weighing->setWindowIcon(icon);
        batchidcombobox = new QComboBox(weighing);
        batchidcombobox->setObjectName(QString::fromUtf8("batchidcombobox"));
        batchidcombobox->setGeometry(QRect(172, 10, 171, 22));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font.setPointSize(8);
        batchidcombobox->setFont(font);
        okbutton = new QPushButton(weighing);
        okbutton->setObjectName(QString::fromUtf8("okbutton"));
        okbutton->setGeometry(QRect(347, 9, 61, 24));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial Unicode MS"));
        okbutton->setFont(font1);
        batchidlabel = new QLabel(weighing);
        batchidlabel->setObjectName(QString::fromUtf8("batchidlabel"));
        batchidlabel->setGeometry(QRect(112, 10, 51, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font2.setBold(true);
        font2.setWeight(75);
        batchidlabel->setFont(font2);
        batchidlabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        activebatchgroup = new QGroupBox(weighing);
        activebatchgroup->setObjectName(QString::fromUtf8("activebatchgroup"));
        activebatchgroup->setEnabled(true);
        activebatchgroup->setGeometry(QRect(10, 30, 611, 508));
        weightdisplayedit = new QTextEdit(activebatchgroup);
        weightdisplayedit->setObjectName(QString::fromUtf8("weightdisplayedit"));
        weightdisplayedit->setGeometry(QRect(440, 28, 161, 470));
        weightdisplayedit->setFont(font1);
        weightdisplayedit->setFocusPolicy(Qt::NoFocus);
        weightdisplayedit->setAutoFormatting(QTextEdit::AutoNone);
        weightdisplayedit->setAcceptRichText(false);
        weightdisplayedit->setTextInteractionFlags(Qt::NoTextInteraction);
        stopbutton = new QPushButton(activebatchgroup);
        stopbutton->setObjectName(QString::fromUtf8("stopbutton"));
        stopbutton->setEnabled(true);
        stopbutton->setGeometry(QRect(299, 20, 65, 25));
        stopbutton->setFont(font1);
        startbutton = new QPushButton(activebatchgroup);
        startbutton->setObjectName(QString::fromUtf8("startbutton"));
        startbutton->setGeometry(QRect(232, 20, 65, 25));
        startbutton->setFont(font1);
        timelabel = new QLabel(activebatchgroup);
        timelabel->setObjectName(QString::fromUtf8("timelabel"));
        timelabel->setGeometry(QRect(25, 82, 91, 16));
        timelabel->setFont(font2);
        timelabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        timeupdatelabel = new QLabel(activebatchgroup);
        timeupdatelabel->setObjectName(QString::fromUtf8("timeupdatelabel"));
        timeupdatelabel->setGeometry(QRect(119, 82, 100, 16));
        timeupdatelabel->setFont(font2);
        timeupdatelabel->setStyleSheet(QString::fromUtf8("color: rgb(252, 9, 0);"));
        timeupdatelabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        datelabel = new QLabel(activebatchgroup);
        datelabel->setObjectName(QString::fromUtf8("datelabel"));
        datelabel->setGeometry(QRect(25, 62, 91, 16));
        datelabel->setFont(font2);
        datelabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dateupdatelabel = new QLabel(activebatchgroup);
        dateupdatelabel->setObjectName(QString::fromUtf8("dateupdatelabel"));
        dateupdatelabel->setGeometry(QRect(119, 62, 100, 16));
        dateupdatelabel->setFont(font2);
        dateupdatelabel->setStyleSheet(QString::fromUtf8("color: rgb(252, 9, 0);"));
        dateupdatelabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        starttime = new QLabel(activebatchgroup);
        starttime->setObjectName(QString::fromUtf8("starttime"));
        starttime->setGeometry(QRect(119, 112, 100, 16));
        starttime->setFont(font2);
        starttime->setStyleSheet(QString::fromUtf8("color: rgb(8, 139, 24);"));
        starttime->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        starttimelabel = new QLabel(activebatchgroup);
        starttimelabel->setObjectName(QString::fromUtf8("starttimelabel"));
        starttimelabel->setGeometry(QRect(25, 112, 91, 16));
        starttimelabel->setFont(font2);
        starttimelabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        stoptime = new QLabel(activebatchgroup);
        stoptime->setObjectName(QString::fromUtf8("stoptime"));
        stoptime->setGeometry(QRect(330, 112, 100, 16));
        stoptime->setFont(font2);
        stoptime->setStyleSheet(QString::fromUtf8("color: rgb(252, 9, 0);"));
        stoptime->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        stoptimelabel = new QLabel(activebatchgroup);
        stoptimelabel->setObjectName(QString::fromUtf8("stoptimelabel"));
        stoptimelabel->setGeometry(QRect(236, 112, 91, 16));
        stoptimelabel->setFont(font2);
        stoptimelabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label = new QLabel(activebatchgroup);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(440, 10, 161, 20));
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        endbatch = new QPushButton(activebatchgroup);
        endbatch->setObjectName(QString::fromUtf8("endbatch"));
        endbatch->setEnabled(true);
        endbatch->setGeometry(QRect(366, 20, 65, 25));
        endbatch->setFont(font1);
        para_1 = new QLabel(activebatchgroup);
        para_1->setObjectName(QString::fromUtf8("para_1"));
        para_1->setGeometry(QRect(16, 142, 100, 16));
        para_1->setFont(font2);
        para_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        para_2 = new QLabel(activebatchgroup);
        para_2->setObjectName(QString::fromUtf8("para_2"));
        para_2->setGeometry(QRect(16, 162, 100, 16));
        para_2->setFont(font2);
        para_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        para_3 = new QLabel(activebatchgroup);
        para_3->setObjectName(QString::fromUtf8("para_3"));
        para_3->setGeometry(QRect(16, 182, 100, 16));
        para_3->setFont(font2);
        para_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        para_4 = new QLabel(activebatchgroup);
        para_4->setObjectName(QString::fromUtf8("para_4"));
        para_4->setGeometry(QRect(16, 202, 100, 16));
        para_4->setFont(font2);
        para_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        para_5 = new QLabel(activebatchgroup);
        para_5->setObjectName(QString::fromUtf8("para_5"));
        para_5->setGeometry(QRect(16, 222, 100, 16));
        para_5->setFont(font2);
        para_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        para_6 = new QLabel(activebatchgroup);
        para_6->setObjectName(QString::fromUtf8("para_6"));
        para_6->setGeometry(QRect(16, 242, 100, 16));
        para_6->setFont(font2);
        para_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        para_7 = new QLabel(activebatchgroup);
        para_7->setObjectName(QString::fromUtf8("para_7"));
        para_7->setGeometry(QRect(16, 262, 100, 16));
        para_7->setFont(font2);
        para_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        para_8 = new QLabel(activebatchgroup);
        para_8->setObjectName(QString::fromUtf8("para_8"));
        para_8->setGeometry(QRect(16, 282, 100, 16));
        para_8->setFont(font2);
        para_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        para_9 = new QLabel(activebatchgroup);
        para_9->setObjectName(QString::fromUtf8("para_9"));
        para_9->setGeometry(QRect(16, 302, 100, 16));
        para_9->setFont(font2);
        para_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        para_10 = new QLabel(activebatchgroup);
        para_10->setObjectName(QString::fromUtf8("para_10"));
        para_10->setGeometry(QRect(16, 322, 100, 16));
        para_10->setFont(font2);
        para_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        fillweightlabel = new QLabel(activebatchgroup);
        fillweightlabel->setObjectName(QString::fromUtf8("fillweightlabel"));
        fillweightlabel->setGeometry(QRect(16, 357, 100, 16));
        fillweightlabel->setFont(font2);
        fillweightlabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tareweightlabel = new QLabel(activebatchgroup);
        tareweightlabel->setObjectName(QString::fromUtf8("tareweightlabel"));
        tareweightlabel->setGeometry(QRect(16, 373, 100, 16));
        tareweightlabel->setFont(font2);
        tareweightlabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tolerancelabel31_2 = new QLabel(activebatchgroup);
        tolerancelabel31_2->setObjectName(QString::fromUtf8("tolerancelabel31_2"));
        tolerancelabel31_2->setGeometry(QRect(16, 400, 100, 16));
        tolerancelabel31_2->setFont(font2);
        tolerancelabel31_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tolerancelabel21 = new QLabel(activebatchgroup);
        tolerancelabel21->setObjectName(QString::fromUtf8("tolerancelabel21"));
        tolerancelabel21->setGeometry(QRect(16, 416, 100, 16));
        tolerancelabel21->setFont(font2);
        tolerancelabel21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tolerancelabel11 = new QLabel(activebatchgroup);
        tolerancelabel11->setObjectName(QString::fromUtf8("tolerancelabel11"));
        tolerancelabel11->setGeometry(QRect(16, 432, 100, 16));
        tolerancelabel11->setFont(font2);
        tolerancelabel11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        value_1 = new QLabel(activebatchgroup);
        value_1->setObjectName(QString::fromUtf8("value_1"));
        value_1->setGeometry(QRect(119, 142, 100, 16));
        value_1->setFont(font2);
        value_1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        value_2 = new QLabel(activebatchgroup);
        value_2->setObjectName(QString::fromUtf8("value_2"));
        value_2->setGeometry(QRect(119, 162, 100, 16));
        value_2->setFont(font2);
        value_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        value_3 = new QLabel(activebatchgroup);
        value_3->setObjectName(QString::fromUtf8("value_3"));
        value_3->setGeometry(QRect(119, 182, 100, 16));
        value_3->setFont(font2);
        value_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        value_4 = new QLabel(activebatchgroup);
        value_4->setObjectName(QString::fromUtf8("value_4"));
        value_4->setGeometry(QRect(119, 202, 100, 16));
        value_4->setFont(font2);
        value_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        value_5 = new QLabel(activebatchgroup);
        value_5->setObjectName(QString::fromUtf8("value_5"));
        value_5->setGeometry(QRect(119, 222, 100, 16));
        value_5->setFont(font2);
        value_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        value_6 = new QLabel(activebatchgroup);
        value_6->setObjectName(QString::fromUtf8("value_6"));
        value_6->setGeometry(QRect(119, 242, 100, 16));
        value_6->setFont(font2);
        value_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        value_7 = new QLabel(activebatchgroup);
        value_7->setObjectName(QString::fromUtf8("value_7"));
        value_7->setGeometry(QRect(119, 262, 100, 16));
        value_7->setFont(font2);
        value_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        value_8 = new QLabel(activebatchgroup);
        value_8->setObjectName(QString::fromUtf8("value_8"));
        value_8->setGeometry(QRect(119, 282, 100, 16));
        value_8->setFont(font2);
        value_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        value_9 = new QLabel(activebatchgroup);
        value_9->setObjectName(QString::fromUtf8("value_9"));
        value_9->setGeometry(QRect(119, 302, 100, 16));
        value_9->setFont(font2);
        value_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        value_10 = new QLabel(activebatchgroup);
        value_10->setObjectName(QString::fromUtf8("value_10"));
        value_10->setGeometry(QRect(119, 322, 100, 16));
        value_10->setFont(font2);
        value_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        fillweight = new QLabel(activebatchgroup);
        fillweight->setObjectName(QString::fromUtf8("fillweight"));
        fillweight->setGeometry(QRect(119, 357, 121, 16));
        fillweight->setFont(font2);
        fillweight->setStyleSheet(QString::fromUtf8("color: rgb(8, 139, 24);"));
        fillweight->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        tareweight = new QLabel(activebatchgroup);
        tareweight->setObjectName(QString::fromUtf8("tareweight"));
        tareweight->setGeometry(QRect(119, 373, 121, 16));
        tareweight->setFont(font2);
        tareweight->setStyleSheet(QString::fromUtf8("color: rgb(252, 9, 0);"));
        tareweight->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        tolerance31 = new QLabel(activebatchgroup);
        tolerance31->setObjectName(QString::fromUtf8("tolerance31"));
        tolerance31->setGeometry(QRect(119, 400, 181, 16));
        tolerance31->setFont(font2);
        tolerance31->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        tolerance21 = new QLabel(activebatchgroup);
        tolerance21->setObjectName(QString::fromUtf8("tolerance21"));
        tolerance21->setGeometry(QRect(119, 416, 181, 16));
        tolerance21->setFont(font2);
        tolerance21->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        tolerance11 = new QLabel(activebatchgroup);
        tolerance11->setObjectName(QString::fromUtf8("tolerance11"));
        tolerance11->setGeometry(QRect(119, 432, 181, 16));
        tolerance11->setFont(font2);
        tolerance11->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        currentweight = new QLabel(activebatchgroup);
        currentweight->setObjectName(QString::fromUtf8("currentweight"));
        currentweight->setGeometry(QRect(360, 480, 49, 20));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font3.setPointSize(8);
        font3.setBold(true);
        font3.setWeight(75);
        currentweight->setFont(font3);
        currentweight->setStyleSheet(QString::fromUtf8("color: rgb(85, 0, 255);"));
        currentweight->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(activebatchgroup);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(290, 480, 71, 20));
        label_2->setFont(font3);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lastweight = new QLabel(activebatchgroup);
        lastweight->setObjectName(QString::fromUtf8("lastweight"));
        lastweight->setGeometry(QRect(359, 458, 49, 20));
        lastweight->setFont(font3);
        lastweight->setStyleSheet(QString::fromUtf8("color: rgb(252, 9, 0);"));
        lastweight->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(activebatchgroup);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(411, 479, 21, 20));
        label_3->setFont(font3);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_4 = new QLabel(activebatchgroup);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(411, 457, 21, 20));
        label_4->setFont(font3);
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_5 = new QLabel(activebatchgroup);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(290, 458, 71, 20));
        label_5->setFont(font3);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tolerance12 = new QLabel(activebatchgroup);
        tolerance12->setObjectName(QString::fromUtf8("tolerance12"));
        tolerance12->setGeometry(QRect(119, 448, 181, 16));
        tolerance12->setFont(font2);
        tolerance12->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        tolerancelabel22 = new QLabel(activebatchgroup);
        tolerancelabel22->setObjectName(QString::fromUtf8("tolerancelabel22"));
        tolerancelabel22->setGeometry(QRect(16, 464, 100, 16));
        tolerancelabel22->setFont(font2);
        tolerancelabel22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tolerance22 = new QLabel(activebatchgroup);
        tolerance22->setObjectName(QString::fromUtf8("tolerance22"));
        tolerance22->setGeometry(QRect(119, 464, 181, 16));
        tolerance22->setFont(font2);
        tolerance22->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        tolerancelabel32 = new QLabel(activebatchgroup);
        tolerancelabel32->setObjectName(QString::fromUtf8("tolerancelabel32"));
        tolerancelabel32->setGeometry(QRect(16, 480, 100, 16));
        tolerancelabel32->setFont(font2);
        tolerancelabel32->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tolerancelabel12 = new QLabel(activebatchgroup);
        tolerancelabel12->setObjectName(QString::fromUtf8("tolerancelabel12"));
        tolerancelabel12->setGeometry(QRect(16, 448, 100, 16));
        tolerancelabel12->setFont(font2);
        tolerancelabel12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tolerance32 = new QLabel(activebatchgroup);
        tolerance32->setObjectName(QString::fromUtf8("tolerance32"));
        tolerance32->setGeometry(QRect(119, 480, 181, 16));
        tolerance32->setFont(font2);
        tolerance32->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        messagelabel = new QLabel(activebatchgroup);
        messagelabel->setObjectName(QString::fromUtf8("messagelabel"));
        messagelabel->setGeometry(QRect(340, 430, 91, 17));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font4.setPointSize(8);
        font4.setBold(true);
        font4.setItalic(false);
        font4.setWeight(75);
        messagelabel->setFont(font4);
        messagelabel->setStyleSheet(QString::fromUtf8("color: rgb(8, 139, 24);"));
        messagelabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ltt3 = new QLabel(activebatchgroup);
        ltt3->setObjectName(QString::fromUtf8("ltt3"));
        ltt3->setGeometry(QRect(360, 230, 46, 13));
        ltt2 = new QLabel(activebatchgroup);
        ltt2->setObjectName(QString::fromUtf8("ltt2"));
        ltt2->setGeometry(QRect(360, 250, 46, 13));
        ltt1 = new QLabel(activebatchgroup);
        ltt1->setObjectName(QString::fromUtf8("ltt1"));
        ltt1->setGeometry(QRect(360, 270, 46, 13));
        gtt1 = new QLabel(activebatchgroup);
        gtt1->setObjectName(QString::fromUtf8("gtt1"));
        gtt1->setGeometry(QRect(360, 290, 46, 13));
        gtt2 = new QLabel(activebatchgroup);
        gtt2->setObjectName(QString::fromUtf8("gtt2"));
        gtt2->setGeometry(QRect(360, 310, 46, 13));
        gtt3 = new QLabel(activebatchgroup);
        gtt3->setObjectName(QString::fromUtf8("gtt3"));
        gtt3->setGeometry(QRect(360, 330, 46, 13));
        countedit = new QLineEdit(activebatchgroup);
        countedit->setObjectName(QString::fromUtf8("countedit"));
        countedit->setGeometry(QRect(128, 21, 51, 23));
        countedit->setFont(font1);
        label_6 = new QLabel(activebatchgroup);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(22, 21, 101, 23));
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        loggedinlabel = new QLabel(weighing);
        loggedinlabel->setObjectName(QString::fromUtf8("loggedinlabel"));
        loggedinlabel->setGeometry(QRect(10, 538, 71, 16));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font5.setBold(false);
        font5.setItalic(true);
        font5.setWeight(50);
        loggedinlabel->setFont(font5);
        currentuser = new QLabel(weighing);
        currentuser->setObjectName(QString::fromUtf8("currentuser"));
        currentuser->setGeometry(QRect(83, 538, 131, 16));
        currentuser->setFont(font4);
        currentuser->setStyleSheet(QString::fromUtf8("color: rgb(252, 9, 0);"));
        loggedinatlabel = new QLabel(weighing);
        loggedinatlabel->setObjectName(QString::fromUtf8("loggedinatlabel"));
        loggedinatlabel->setGeometry(QRect(467, 538, 71, 16));
        loggedinatlabel->setFont(font5);
        loggedintime = new QLabel(weighing);
        loggedintime->setObjectName(QString::fromUtf8("loggedintime"));
        loggedintime->setGeometry(QRect(540, 538, 81, 16));
        loggedintime->setFont(font4);
        loggedintime->setStyleSheet(QString::fromUtf8("color: rgb(8, 139, 24);"));
        lockbutton = new QPushButton(weighing);
        lockbutton->setObjectName(QString::fromUtf8("lockbutton"));
        lockbutton->setGeometry(QRect(410, 9, 111, 24));
        lockbutton->setFont(font1);
        lockbutton->setStyleSheet(QString::fromUtf8("color: rgb(212, 0, 3);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/images/lock.png"), QSize(), QIcon::Normal, QIcon::Off);
        lockbutton->setIcon(icon1);
        lockbutton->setIconSize(QSize(17, 17));
        QWidget::setTabOrder(batchidcombobox, okbutton);
        QWidget::setTabOrder(okbutton, lockbutton);
        QWidget::setTabOrder(lockbutton, countedit);
        QWidget::setTabOrder(countedit, startbutton);
        QWidget::setTabOrder(startbutton, stopbutton);
        QWidget::setTabOrder(stopbutton, endbatch);

        retranslateUi(weighing);

        QMetaObject::connectSlotsByName(weighing);
    } // setupUi

    void retranslateUi(QDialog *weighing)
    {
        weighing->setWindowTitle(QApplication::translate("weighing", "Weighing Menu", 0, QApplication::UnicodeUTF8));
        okbutton->setText(QApplication::translate("weighing", "OK", 0, QApplication::UnicodeUTF8));
        batchidlabel->setText(QApplication::translate("weighing", "Batch ID", 0, QApplication::UnicodeUTF8));
        activebatchgroup->setTitle(QApplication::translate("weighing", "Active Batch ", 0, QApplication::UnicodeUTF8));
        stopbutton->setText(QApplication::translate("weighing", "Stop", 0, QApplication::UnicodeUTF8));
        startbutton->setText(QApplication::translate("weighing", "Start", 0, QApplication::UnicodeUTF8));
        timelabel->setText(QApplication::translate("weighing", "Time :", 0, QApplication::UnicodeUTF8));
        timeupdatelabel->setText(QString());
        datelabel->setText(QApplication::translate("weighing", " Date :", 0, QApplication::UnicodeUTF8));
        dateupdatelabel->setText(QString());
        starttime->setText(QString());
        starttimelabel->setText(QApplication::translate("weighing", "Start Time :", 0, QApplication::UnicodeUTF8));
        stoptime->setText(QString());
        stoptimelabel->setText(QApplication::translate("weighing", "Stop Time :", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("weighing", "Weights", 0, QApplication::UnicodeUTF8));
        endbatch->setText(QApplication::translate("weighing", "End Batch", 0, QApplication::UnicodeUTF8));
        para_1->setText(QString());
        para_2->setText(QString());
        para_3->setText(QString());
        para_4->setText(QString());
        para_5->setText(QString());
        para_6->setText(QString());
        para_7->setText(QString());
        para_8->setText(QString());
        para_9->setText(QString());
        para_10->setText(QString());
        fillweightlabel->setText(QApplication::translate("weighing", "Fill Weight :", 0, QApplication::UnicodeUTF8));
        tareweightlabel->setText(QApplication::translate("weighing", "Tare Weight :", 0, QApplication::UnicodeUTF8));
        tolerancelabel31_2->setText(QApplication::translate("weighing", "T3 -  :", 0, QApplication::UnicodeUTF8));
        tolerancelabel21->setText(QApplication::translate("weighing", "T2 -  :", 0, QApplication::UnicodeUTF8));
        tolerancelabel11->setText(QApplication::translate("weighing", "T1 -  :", 0, QApplication::UnicodeUTF8));
        value_1->setText(QString());
        value_2->setText(QString());
        value_3->setText(QString());
        value_4->setText(QString());
        value_5->setText(QString());
        value_6->setText(QString());
        value_7->setText(QString());
        value_8->setText(QString());
        value_9->setText(QString());
        value_10->setText(QString());
        fillweight->setText(QString());
        tareweight->setText(QString());
        tolerance31->setText(QString());
        tolerance21->setText(QString());
        tolerance11->setText(QString());
        currentweight->setText(QString());
        label_2->setText(QApplication::translate("weighing", "Cr. Wt :", 0, QApplication::UnicodeUTF8));
        lastweight->setText(QString());
        label_3->setText(QApplication::translate("weighing", "gm", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("weighing", "gm", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("weighing", "Lst. Wt :", 0, QApplication::UnicodeUTF8));
        tolerance12->setText(QString());
        tolerancelabel22->setText(QApplication::translate("weighing", "T2 + :", 0, QApplication::UnicodeUTF8));
        tolerance22->setText(QString());
        tolerancelabel32->setText(QApplication::translate("weighing", "T3 + :", 0, QApplication::UnicodeUTF8));
        tolerancelabel12->setText(QApplication::translate("weighing", "T1 + :", 0, QApplication::UnicodeUTF8));
        tolerance32->setText(QString());
        messagelabel->setText(QString());
        ltt3->setText(QString());
        ltt2->setText(QString());
        ltt1->setText(QString());
        gtt1->setText(QString());
        gtt2->setText(QString());
        gtt3->setText(QString());
        label_6->setText(QApplication::translate("weighing", "No. Of Samples", 0, QApplication::UnicodeUTF8));
        loggedinlabel->setText(QApplication::translate("weighing", "Logged in as :", 0, QApplication::UnicodeUTF8));
        currentuser->setText(QString());
        loggedinatlabel->setText(QApplication::translate("weighing", "Logged in at :", 0, QApplication::UnicodeUTF8));
        loggedintime->setText(QString());
        lockbutton->setText(QApplication::translate("weighing", "Lock Session", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class weighing: public Ui_weighing {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEIGHING_H
