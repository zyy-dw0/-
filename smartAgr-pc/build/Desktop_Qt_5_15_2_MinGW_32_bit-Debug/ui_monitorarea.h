/********************************************************************************
** Form generated from reading UI file 'monitorarea.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONITORAREA_H
#define UI_MONITORAREA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MonitorArea
{
public:
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page_monitor;
    QLabel *label_10;
    QLabel *label_16;
    QLabel *label_14;
    QLabel *label_8;
    QPushButton *btn_to_control;
    QLabel *label_zids;
    QLabel *label_12;
    QLabel *label_temp;
    QLabel *label_humi;
    QLabel *label_lux;
    QLabel *label_co2;
    QLabel *label_humi_soil;
    QPushButton *btn_aid;
    QWidget *page_control;
    QPushButton *switch_lamp;
    QPushButton *switch_humi;
    QPushButton *switch_curtain_positive;
    QPushButton *switch_fan;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *btn_aid_2;
    QPushButton *btn_to_monitor;
    QPushButton *switch_curtain_reverse;
    QLabel *label;
    QLabel *label_6;

    void setupUi(QWidget *MonitorArea)
    {
        if (MonitorArea->objectName().isEmpty())
            MonitorArea->setObjectName(QString::fromUtf8("MonitorArea"));
        MonitorArea->resize(260, 210);
        MonitorArea->setStyleSheet(QString::fromUtf8("QPushButton#switch_lamp,QPushButton#switch_humi,QPushButton#switch_fan,QPushButton#switch_curtain_positive,QPushButton#switch_curtain_reverse\n"
"{\n"
"	background-color: rgb(220, 220, 180);\n"
"	border-style: solid;\n"
"	border-radius: 25px;\n"
"	border-width: 2px;\n"
"	border-color:rgb(255, 255, 0);\n"
"\n"
"\n"
"}\n"
"QWidget#page_monitor,QWidget#page_control\n"
"{\n"
"		\n"
"	background-color: rgb(200, 255, 170);\n"
"	border-color: rgb(85, 0, 0);\n"
"	border-width:1px;\n"
"	border-style:solid;\n"
"\n"
"}\n"
"\n"
"QPushButton#btn_aid,QPushButton#btn_aid_2\n"
"{\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgb(0, 0, 127);\n"
"	background-color: transparent;\n"
"	border-radius:10px;\n"
"}\n"
"QPushButton#btn_aid:pressed,QPushButton#btn_aid_2:pressed\n"
"{\n"
"	\n"
"	background-color: rgb(150, 255, 80);\n"
"}\n"
""));
        horizontalLayout = new QHBoxLayout(MonitorArea);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(MonitorArea);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page_monitor = new QWidget();
        page_monitor->setObjectName(QString::fromUtf8("page_monitor"));
        label_10 = new QLabel(page_monitor);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 48, 100, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font.setPointSize(10);
        label_10->setFont(font);
        label_16 = new QLabel(page_monitor);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 164, 100, 31));
        label_16->setFont(font);
        label_14 = new QLabel(page_monitor);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 90, 100, 31));
        label_14->setFont(font);
        label_8 = new QLabel(page_monitor);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 10, 100, 31));
        label_8->setFont(font);
        btn_to_control = new QPushButton(page_monitor);
        btn_to_control->setObjectName(QString::fromUtf8("btn_to_control"));
        btn_to_control->setGeometry(QRect(210, 150, 40, 50));
        QFont font1;
        font1.setPointSize(32);
        btn_to_control->setFont(font1);
        btn_to_control->setFocusPolicy(Qt::NoFocus);
        btn_to_control->setStyleSheet(QString::fromUtf8("border-image: url(:/images/add.ico);"));
        label_zids = new QLabel(page_monitor);
        label_zids->setObjectName(QString::fromUtf8("label_zids"));
        label_zids->setGeometry(QRect(210, 79, 50, 81));
        label_zids->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);"));
        label_zids->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(page_monitor);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 130, 100, 31));
        label_12->setFont(font);
        label_temp = new QLabel(page_monitor);
        label_temp->setObjectName(QString::fromUtf8("label_temp"));
        label_temp->setGeometry(QRect(100, 10, 80, 31));
        label_temp->setFont(font);
        label_humi = new QLabel(page_monitor);
        label_humi->setObjectName(QString::fromUtf8("label_humi"));
        label_humi->setGeometry(QRect(100, 48, 80, 31));
        label_humi->setFont(font);
        label_lux = new QLabel(page_monitor);
        label_lux->setObjectName(QString::fromUtf8("label_lux"));
        label_lux->setGeometry(QRect(100, 90, 80, 31));
        label_lux->setFont(font);
        label_co2 = new QLabel(page_monitor);
        label_co2->setObjectName(QString::fromUtf8("label_co2"));
        label_co2->setGeometry(QRect(100, 164, 80, 31));
        label_co2->setFont(font);
        label_humi_soil = new QLabel(page_monitor);
        label_humi_soil->setObjectName(QString::fromUtf8("label_humi_soil"));
        label_humi_soil->setGeometry(QRect(100, 130, 80, 31));
        label_humi_soil->setFont(font);
        btn_aid = new QPushButton(page_monitor);
        btn_aid->setObjectName(QString::fromUtf8("btn_aid"));
        btn_aid->setGeometry(QRect(200, 2, 50, 30));
        btn_aid->setFocusPolicy(Qt::NoFocus);
        stackedWidget->addWidget(page_monitor);
        page_control = new QWidget();
        page_control->setObjectName(QString::fromUtf8("page_control"));
        switch_lamp = new QPushButton(page_control);
        switch_lamp->setObjectName(QString::fromUtf8("switch_lamp"));
        switch_lamp->setGeometry(QRect(20, 150, 50, 50));
        switch_lamp->setFocusPolicy(Qt::NoFocus);
        switch_lamp->setStyleSheet(QString::fromUtf8(""));
        switch_humi = new QPushButton(page_control);
        switch_humi->setObjectName(QString::fromUtf8("switch_humi"));
        switch_humi->setGeometry(QRect(100, 150, 50, 50));
        switch_humi->setFocusPolicy(Qt::NoFocus);
        switch_humi->setStyleSheet(QString::fromUtf8(""));
        switch_curtain_positive = new QPushButton(page_control);
        switch_curtain_positive->setObjectName(QString::fromUtf8("switch_curtain_positive"));
        switch_curtain_positive->setGeometry(QRect(60, 70, 50, 50));
        switch_curtain_positive->setFocusPolicy(Qt::NoFocus);
        switch_curtain_positive->setStyleSheet(QString::fromUtf8(""));
        switch_fan = new QPushButton(page_control);
        switch_fan->setObjectName(QString::fromUtf8("switch_fan"));
        switch_fan->setGeometry(QRect(180, 150, 50, 50));
        switch_fan->setFocusPolicy(Qt::NoFocus);
        switch_fan->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(page_control);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 40, 40, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font2.setPointSize(14);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(page_control);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(25, 117, 40, 30));
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(page_control);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(105, 120, 40, 30));
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(page_control);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(185, 120, 40, 30));
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignCenter);
        btn_aid_2 = new QPushButton(page_control);
        btn_aid_2->setObjectName(QString::fromUtf8("btn_aid_2"));
        btn_aid_2->setGeometry(QRect(200, 2, 60, 40));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(18);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        btn_aid_2->setFont(font3);
        btn_aid_2->setFocusPolicy(Qt::NoFocus);
        btn_aid_2->setFlat(true);
        btn_to_monitor = new QPushButton(page_control);
        btn_to_monitor->setObjectName(QString::fromUtf8("btn_to_monitor"));
        btn_to_monitor->setGeometry(QRect(10, 0, 40, 50));
        btn_to_monitor->setFont(font1);
        btn_to_monitor->setFocusPolicy(Qt::NoFocus);
        btn_to_monitor->setStyleSheet(QString::fromUtf8("border-image: url(:/images/add.ico);"));
        switch_curtain_reverse = new QPushButton(page_control);
        switch_curtain_reverse->setObjectName(QString::fromUtf8("switch_curtain_reverse"));
        switch_curtain_reverse->setGeometry(QRect(150, 70, 50, 50));
        switch_curtain_reverse->setFocusPolicy(Qt::NoFocus);
        switch_curtain_reverse->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(page_control);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 50, 20, 12));
        label->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(page_control);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(140, 50, 20, 12));
        label_6->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page_control);

        horizontalLayout->addWidget(stackedWidget);


        retranslateUi(MonitorArea);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MonitorArea);
    } // setupUi

    void retranslateUi(QWidget *MonitorArea)
    {
        MonitorArea->setWindowTitle(QCoreApplication::translate("MonitorArea", "Form", nullptr));
        label_10->setText(QCoreApplication::translate("MonitorArea", "\347\251\272\346\260\224\346\271\277\345\272\246", nullptr));
        label_16->setText(QCoreApplication::translate("MonitorArea", "CO2\346\265\223\345\272\246", nullptr));
        label_14->setText(QCoreApplication::translate("MonitorArea", "\345\205\211\347\205\247\345\274\272\345\272\246", nullptr));
        label_8->setText(QCoreApplication::translate("MonitorArea", "\347\251\272\346\260\224\346\270\251\345\272\246", nullptr));
#if QT_CONFIG(tooltip)
        btn_to_control->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        btn_to_control->setText(QString());
        label_zids->setText(QCoreApplication::translate("MonitorArea", "<html><head/><body><p align=\"justify\"><br/></p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("MonitorArea", "\345\234\237\345\243\244\346\271\277\345\272\246", nullptr));
        label_temp->setText(QCoreApplication::translate("MonitorArea", "-\342\204\203", nullptr));
        label_humi->setText(QCoreApplication::translate("MonitorArea", "-%", nullptr));
        label_lux->setText(QCoreApplication::translate("MonitorArea", "-lux", nullptr));
        label_co2->setText(QCoreApplication::translate("MonitorArea", "-ppm", nullptr));
        label_humi_soil->setText(QCoreApplication::translate("MonitorArea", "-%", nullptr));
        btn_aid->setText(QCoreApplication::translate("MonitorArea", "1\345\214\272", nullptr));
        switch_lamp->setText(QString());
        switch_humi->setText(QString());
        switch_curtain_positive->setText(QString());
        switch_fan->setText(QString());
        label_2->setText(QCoreApplication::translate("MonitorArea", "\345\270\230", nullptr));
        label_3->setText(QCoreApplication::translate("MonitorArea", "\347\201\257", nullptr));
        label_4->setText(QCoreApplication::translate("MonitorArea", "\346\260\264", nullptr));
        label_5->setText(QCoreApplication::translate("MonitorArea", "\351\243\216", nullptr));
        btn_aid_2->setText(QCoreApplication::translate("MonitorArea", "1\345\214\272", nullptr));
#if QT_CONFIG(tooltip)
        btn_to_monitor->setToolTip(QCoreApplication::translate("MonitorArea", "\350\256\276\347\275\256\350\212\202\347\202\271", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_to_monitor->setText(QString());
        switch_curtain_reverse->setText(QString());
        label->setText(QCoreApplication::translate("MonitorArea", "+", nullptr));
        label_6->setText(QCoreApplication::translate("MonitorArea", "-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MonitorArea: public Ui_MonitorArea {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONITORAREA_H
