/********************************************************************************
** Form generated from reading UI file 'monitorarea.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONITORAREA_H
#define UI_MONITORAREA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QWidget *MonitorArea)
    {
        if (MonitorArea->objectName().isEmpty())
            MonitorArea->setObjectName(QStringLiteral("MonitorArea"));
        MonitorArea->resize(260, 210);
        MonitorArea->setStyleSheet(QString::fromUtf8("QPushButton#switch_lamp,QPushButton#switch_humi,QPushButton#switch_fan,QPushButton#switch_curtain_positive,QPushButton#switch_curtain_reverse\n"
"{\n"
"	border-image: url(:/images/switch_off.png);\n"
"}\n"
"\n"
"/*{\n"
"	background-color: rgb(120, 120, 220);\n"
"	border-style: solid;\n"
"	border-radius: 25px;\n"
"	border-width: 2px;\n"
"	border-color:rgb(255, 255, 0);\n"
"\n"
"\n"
"}\n"
"*/\n"
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
"	font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
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
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(MonitorArea);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        page_monitor = new QWidget();
        page_monitor->setObjectName(QStringLiteral("page_monitor"));
        label_10 = new QLabel(page_monitor);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 48, 100, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font.setPointSize(10);
        label_10->setFont(font);
        label_16 = new QLabel(page_monitor);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 164, 100, 31));
        label_16->setFont(font);
        label_14 = new QLabel(page_monitor);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 90, 100, 31));
        label_14->setFont(font);
        label_8 = new QLabel(page_monitor);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 10, 100, 31));
        label_8->setFont(font);
        btn_to_control = new QPushButton(page_monitor);
        btn_to_control->setObjectName(QStringLiteral("btn_to_control"));
        btn_to_control->setGeometry(QRect(210, 150, 40, 50));
        QFont font1;
        font1.setPointSize(32);
        btn_to_control->setFont(font1);
        btn_to_control->setFocusPolicy(Qt::NoFocus);
        btn_to_control->setStyleSheet(QStringLiteral("border-image: url(:/images/add.ico);"));
        label_zids = new QLabel(page_monitor);
        label_zids->setObjectName(QStringLiteral("label_zids"));
        label_zids->setGeometry(QRect(180, 79, 70, 81));
        QFont font2;
        font2.setPointSize(8);
        label_zids->setFont(font2);
        label_zids->setStyleSheet(QStringLiteral("color: rgb(0, 0, 127);"));
        label_zids->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(page_monitor);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 130, 100, 31));
        label_12->setFont(font);
        label_temp = new QLabel(page_monitor);
        label_temp->setObjectName(QStringLiteral("label_temp"));
        label_temp->setGeometry(QRect(100, 10, 80, 31));
        label_temp->setFont(font);
        label_humi = new QLabel(page_monitor);
        label_humi->setObjectName(QStringLiteral("label_humi"));
        label_humi->setGeometry(QRect(100, 48, 80, 31));
        label_humi->setFont(font);
        label_lux = new QLabel(page_monitor);
        label_lux->setObjectName(QStringLiteral("label_lux"));
        label_lux->setGeometry(QRect(100, 90, 80, 31));
        label_lux->setFont(font);
        label_co2 = new QLabel(page_monitor);
        label_co2->setObjectName(QStringLiteral("label_co2"));
        label_co2->setGeometry(QRect(100, 164, 80, 31));
        label_co2->setFont(font);
        label_humi_soil = new QLabel(page_monitor);
        label_humi_soil->setObjectName(QStringLiteral("label_humi_soil"));
        label_humi_soil->setGeometry(QRect(100, 130, 80, 31));
        label_humi_soil->setFont(font);
        btn_aid = new QPushButton(page_monitor);
        btn_aid->setObjectName(QStringLiteral("btn_aid"));
        btn_aid->setGeometry(QRect(172, 2, 80, 40));
        btn_aid->setFocusPolicy(Qt::NoFocus);
        stackedWidget->addWidget(page_monitor);
        page_control = new QWidget();
        page_control->setObjectName(QStringLiteral("page_control"));
        switch_lamp = new QPushButton(page_control);
        switch_lamp->setObjectName(QStringLiteral("switch_lamp"));
        switch_lamp->setGeometry(QRect(30, 140, 40, 40));
        switch_lamp->setFocusPolicy(Qt::NoFocus);
        switch_lamp->setStyleSheet(QStringLiteral(""));
        switch_humi = new QPushButton(page_control);
        switch_humi->setObjectName(QStringLiteral("switch_humi"));
        switch_humi->setGeometry(QRect(110, 140, 40, 40));
        switch_humi->setFocusPolicy(Qt::NoFocus);
        switch_humi->setStyleSheet(QStringLiteral(""));
        switch_curtain_positive = new QPushButton(page_control);
        switch_curtain_positive->setObjectName(QStringLiteral("switch_curtain_positive"));
        switch_curtain_positive->setGeometry(QRect(70, 60, 40, 40));
        switch_curtain_positive->setFocusPolicy(Qt::NoFocus);
        switch_curtain_positive->setStyleSheet(QStringLiteral(""));
        switch_fan = new QPushButton(page_control);
        switch_fan->setObjectName(QStringLiteral("switch_fan"));
        switch_fan->setGeometry(QRect(190, 140, 40, 40));
        switch_fan->setFocusPolicy(Qt::NoFocus);
        switch_fan->setStyleSheet(QStringLiteral(""));
        label_2 = new QLabel(page_control);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 30, 40, 30));
        label_2->setFont(font);
        label_3 = new QLabel(page_control);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 110, 40, 30));
        label_3->setFont(font);
        label_4 = new QLabel(page_control);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(110, 110, 40, 30));
        label_4->setFont(font);
        label_5 = new QLabel(page_control);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(190, 110, 40, 30));
        label_5->setFont(font);
        btn_aid_2 = new QPushButton(page_control);
        btn_aid_2->setObjectName(QStringLiteral("btn_aid_2"));
        btn_aid_2->setGeometry(QRect(210, 2, 50, 40));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(16);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        btn_aid_2->setFont(font3);
        btn_aid_2->setFocusPolicy(Qt::NoFocus);
        btn_aid_2->setFlat(true);
        btn_to_monitor = new QPushButton(page_control);
        btn_to_monitor->setObjectName(QStringLiteral("btn_to_monitor"));
        btn_to_monitor->setGeometry(QRect(3, -7, 40, 50));
        btn_to_monitor->setFont(font1);
        btn_to_monitor->setFocusPolicy(Qt::NoFocus);
        btn_to_monitor->setStyleSheet(QStringLiteral("border-image: url(:/images/add.ico);"));
        switch_curtain_reverse = new QPushButton(page_control);
        switch_curtain_reverse->setObjectName(QStringLiteral("switch_curtain_reverse"));
        switch_curtain_reverse->setGeometry(QRect(150, 60, 40, 40));
        switch_curtain_reverse->setFocusPolicy(Qt::NoFocus);
        switch_curtain_reverse->setStyleSheet(QStringLiteral(""));
        label_6 = new QLabel(page_control);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(100, 35, 30, 20));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font4.setPointSize(8);
        label_6->setFont(font4);
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(page_control);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(130, 34, 30, 20));
        label_7->setFont(font4);
        label_7->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page_control);

        horizontalLayout->addWidget(stackedWidget);


        retranslateUi(MonitorArea);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MonitorArea);
    } // setupUi

    void retranslateUi(QWidget *MonitorArea)
    {
        MonitorArea->setWindowTitle(QApplication::translate("MonitorArea", "Form", Q_NULLPTR));
        label_10->setText(QApplication::translate("MonitorArea", "\347\251\272\346\260\224\346\271\277\345\272\246", Q_NULLPTR));
        label_16->setText(QApplication::translate("MonitorArea", "CO2\346\265\223\345\272\246", Q_NULLPTR));
        label_14->setText(QApplication::translate("MonitorArea", "\345\205\211\347\205\247\345\274\272\345\272\246", Q_NULLPTR));
        label_8->setText(QApplication::translate("MonitorArea", "\347\251\272\346\260\224\346\270\251\345\272\246", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btn_to_control->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btn_to_control->setText(QString());
        label_zids->setText(QApplication::translate("MonitorArea", "<html><head/><body><p align=\"justify\"><br/></p></body></html>", Q_NULLPTR));
        label_12->setText(QApplication::translate("MonitorArea", "\345\234\237\345\243\244\346\271\277\345\272\246", Q_NULLPTR));
        label_temp->setText(QApplication::translate("MonitorArea", "-\342\204\203", Q_NULLPTR));
        label_humi->setText(QApplication::translate("MonitorArea", "-%", Q_NULLPTR));
        label_lux->setText(QApplication::translate("MonitorArea", "-lux", Q_NULLPTR));
        label_co2->setText(QApplication::translate("MonitorArea", "-ppm", Q_NULLPTR));
        label_humi_soil->setText(QApplication::translate("MonitorArea", "-%", Q_NULLPTR));
        btn_aid->setText(QApplication::translate("MonitorArea", "1\345\214\272", Q_NULLPTR));
        switch_lamp->setText(QString());
        switch_humi->setText(QString());
        switch_curtain_positive->setText(QString());
        switch_fan->setText(QString());
        label_2->setText(QApplication::translate("MonitorArea", "<html><head/><body><p align=\"center\">\345\270\230</p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("MonitorArea", "<html><head/><body><p align=\"center\">\347\201\257</p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("MonitorArea", "<html><head/><body><p align=\"center\">\346\260\264</p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("MonitorArea", "<html><head/><body><p align=\"center\">\351\243\216</p></body></html>", Q_NULLPTR));
        btn_aid_2->setText(QApplication::translate("MonitorArea", "1\345\214\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btn_to_monitor->setToolTip(QApplication::translate("MonitorArea", "\350\256\276\347\275\256\350\212\202\347\202\271", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btn_to_monitor->setText(QString());
        switch_curtain_reverse->setText(QString());
        label_6->setText(QApplication::translate("MonitorArea", "+", Q_NULLPTR));
        label_7->setText(QApplication::translate("MonitorArea", "-", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MonitorArea: public Ui_MonitorArea {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONITORAREA_H
