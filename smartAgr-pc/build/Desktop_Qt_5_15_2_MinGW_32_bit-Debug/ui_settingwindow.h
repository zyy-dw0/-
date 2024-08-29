/********************************************************************************
** Form generated from reading UI file 'settingwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGWINDOW_H
#define UI_SETTINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btn_addNode;
    QPushButton *btn_return;
    QPushButton *btn_save;
    QLabel *label_title;
    QSpinBox *spinBox_areaNum;
    QLabel *label_8;
    QLabel *label_21;
    QLabel *label_20;
    QLabel *label_14;
    QLabel *label_12;
    QLabel *label_15;
    QLabel *label_10;
    QListWidget *listWidget_nodeSelect;
    QPushButton *pushButton_2;
    QLabel *label_9;
    QLabel *label_4;
    QListWidget *listWidget_nodeAll;
    QListWidget *listWidget_area;
    QPushButton *btn_removeNode;
    QLabel *label_11;
    QLabel *label_13;
    QLabel *label_19;
    QLabel *label_18;
    QLabel *label_17;
    QLabel *label_16;
    QLabel *label_22;
    QLabel *label_5;
    QSpinBox *spinBox_nodeNum;
    QSpinBox *spinBox_lamp_down;
    QSpinBox *spinBox_lamp_up;
    QSpinBox *spinBox_humi_up;
    QSpinBox *spinBox_humi_down;
    QSpinBox *spinBox_curtain_up;
    QSpinBox *spinBox_curtain_down;
    QSpinBox *spinBox_fan_up;
    QSpinBox *spinBox_fan_down;

    void setupUi(QMainWindow *SettingWindow)
    {
        if (SettingWindow->objectName().isEmpty())
            SettingWindow->setObjectName(QString::fromUtf8("SettingWindow"));
        SettingWindow->resize(800, 480);
        SettingWindow->setStyleSheet(QString::fromUtf8("QLabel\n"
"{	\n"
"	font: 9pt \"Arial\";\n"
"}\n"
"QLabel#label_title\n"
"{\n"
"	\n"
"	font: 28pt \"\346\245\267\344\275\223\";\n"
"}\n"
"QWidget#centralwidget\n"
"{\n"
"	background-color:  rgb(200, 255, 170);\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"	border-radius:10px;\n"
"	border-width:1px;\n"
"	border-style:solid;\n"
"	background-color:  rgb(150, 200, 150);	\n"
"}\n"
""));
        centralwidget = new QWidget(SettingWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btn_addNode = new QPushButton(centralwidget);
        btn_addNode->setObjectName(QString::fromUtf8("btn_addNode"));
        btn_addNode->setGeometry(QRect(260, 210, 60, 23));
        QFont font;
        font.setPointSize(15);
        btn_addNode->setFont(font);
        btn_return = new QPushButton(centralwidget);
        btn_return->setObjectName(QString::fromUtf8("btn_return"));
        btn_return->setGeometry(QRect(590, 390, 90, 40));
        QFont font1;
        font1.setPointSize(12);
        btn_return->setFont(font1);
        btn_save = new QPushButton(centralwidget);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));
        btn_save->setGeometry(QRect(590, 330, 90, 40));
        btn_save->setFont(font1);
        label_title = new QLabel(centralwidget);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setGeometry(QRect(0, 0, 800, 70));
        QFont font2;
        font2.setPointSize(28);
        font2.setBold(false);
        font2.setItalic(false);
        label_title->setFont(font2);
        label_title->setAlignment(Qt::AlignCenter);
        spinBox_areaNum = new QSpinBox(centralwidget);
        spinBox_areaNum->setObjectName(QString::fromUtf8("spinBox_areaNum"));
        spinBox_areaNum->setGeometry(QRect(90, 80, 51, 30));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(false);
        spinBox_areaNum->setFont(font3);
        spinBox_areaNum->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_areaNum->setMinimum(1);
        spinBox_areaNum->setMaximum(999);
        spinBox_areaNum->setValue(9);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(480, 150, 70, 30));
        label_21 = new QLabel(centralwidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(340, 130, 70, 30));
        QFont font4;
        font4.setPointSize(9);
        font4.setBold(false);
        font4.setItalic(false);
        label_21->setFont(font4);
        label_21->setAlignment(Qt::AlignCenter);
        label_20 = new QLabel(centralwidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(20, 130, 70, 30));
        label_20->setFont(font4);
        label_20->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(740, 190, 54, 30));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(740, 150, 54, 30));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(740, 270, 54, 30));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(480, 230, 70, 30));
        listWidget_nodeSelect = new QListWidget(centralwidget);
        listWidget_nodeSelect->setObjectName(QString::fromUtf8("listWidget_nodeSelect"));
        listWidget_nodeSelect->setGeometry(QRect(320, 170, 100, 190));
        listWidget_nodeSelect->setFont(font1);
        listWidget_nodeSelect->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 240, 50, 23));
        pushButton_2->setFont(font);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(480, 190, 70, 30));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 80, 70, 30));
        label_4->setFont(font4);
        listWidget_nodeAll = new QListWidget(centralwidget);
        listWidget_nodeAll->setObjectName(QString::fromUtf8("listWidget_nodeAll"));
        listWidget_nodeAll->setGeometry(QRect(160, 170, 100, 190));
        listWidget_nodeAll->setFont(font1);
        listWidget_nodeAll->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        listWidget_area = new QListWidget(centralwidget);
        listWidget_area->setObjectName(QString::fromUtf8("listWidget_area"));
        listWidget_area->setGeometry(QRect(10, 170, 80, 192));
        listWidget_area->setFont(font1);
        listWidget_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        btn_removeNode = new QPushButton(centralwidget);
        btn_removeNode->setObjectName(QString::fromUtf8("btn_removeNode"));
        btn_removeNode->setGeometry(QRect(260, 270, 60, 23));
        btn_removeNode->setFont(font);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(480, 270, 70, 30));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(740, 230, 54, 30));
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(630, 280, 21, 16));
        label_19->setAlignment(Qt::AlignCenter);
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(630, 240, 21, 16));
        label_18->setAlignment(Qt::AlignCenter);
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(630, 200, 21, 16));
        label_17->setAlignment(Qt::AlignCenter);
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(630, 160, 21, 16));
        label_16->setAlignment(Qt::AlignCenter);
        label_22 = new QLabel(centralwidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(170, 130, 70, 30));
        label_22->setFont(font4);
        label_22->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(160, 80, 70, 30));
        label_5->setFont(font4);
        spinBox_nodeNum = new QSpinBox(centralwidget);
        spinBox_nodeNum->setObjectName(QString::fromUtf8("spinBox_nodeNum"));
        spinBox_nodeNum->setGeometry(QRect(230, 80, 51, 30));
        spinBox_nodeNum->setFont(font3);
        spinBox_nodeNum->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_nodeNum->setMinimum(1);
        spinBox_nodeNum->setMaximum(999);
        spinBox_nodeNum->setValue(100);
        spinBox_lamp_down = new QSpinBox(centralwidget);
        spinBox_lamp_down->setObjectName(QString::fromUtf8("spinBox_lamp_down"));
        spinBox_lamp_down->setGeometry(QRect(560, 150, 70, 30));
        spinBox_lamp_down->setFont(font3);
        spinBox_lamp_down->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_lamp_down->setMinimum(1);
        spinBox_lamp_down->setMaximum(9999);
        spinBox_lamp_down->setValue(10);
        spinBox_lamp_up = new QSpinBox(centralwidget);
        spinBox_lamp_up->setObjectName(QString::fromUtf8("spinBox_lamp_up"));
        spinBox_lamp_up->setGeometry(QRect(660, 150, 70, 30));
        spinBox_lamp_up->setFont(font3);
        spinBox_lamp_up->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_lamp_up->setMinimum(1);
        spinBox_lamp_up->setMaximum(9999);
        spinBox_lamp_up->setValue(50);
        spinBox_humi_up = new QSpinBox(centralwidget);
        spinBox_humi_up->setObjectName(QString::fromUtf8("spinBox_humi_up"));
        spinBox_humi_up->setGeometry(QRect(660, 190, 70, 30));
        spinBox_humi_up->setFont(font3);
        spinBox_humi_up->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_humi_up->setMinimum(1);
        spinBox_humi_up->setMaximum(100);
        spinBox_humi_up->setValue(50);
        spinBox_humi_down = new QSpinBox(centralwidget);
        spinBox_humi_down->setObjectName(QString::fromUtf8("spinBox_humi_down"));
        spinBox_humi_down->setGeometry(QRect(560, 190, 70, 30));
        spinBox_humi_down->setFont(font3);
        spinBox_humi_down->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_humi_down->setMinimum(1);
        spinBox_humi_down->setMaximum(100);
        spinBox_humi_down->setValue(30);
        spinBox_curtain_up = new QSpinBox(centralwidget);
        spinBox_curtain_up->setObjectName(QString::fromUtf8("spinBox_curtain_up"));
        spinBox_curtain_up->setGeometry(QRect(660, 230, 70, 30));
        spinBox_curtain_up->setFont(font3);
        spinBox_curtain_up->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_curtain_up->setMinimum(1);
        spinBox_curtain_up->setMaximum(9999);
        spinBox_curtain_up->setValue(2000);
        spinBox_curtain_down = new QSpinBox(centralwidget);
        spinBox_curtain_down->setObjectName(QString::fromUtf8("spinBox_curtain_down"));
        spinBox_curtain_down->setGeometry(QRect(560, 230, 70, 30));
        spinBox_curtain_down->setFont(font3);
        spinBox_curtain_down->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_curtain_down->setMinimum(1);
        spinBox_curtain_down->setMaximum(9999);
        spinBox_curtain_down->setValue(1000);
        spinBox_fan_up = new QSpinBox(centralwidget);
        spinBox_fan_up->setObjectName(QString::fromUtf8("spinBox_fan_up"));
        spinBox_fan_up->setGeometry(QRect(660, 270, 70, 30));
        spinBox_fan_up->setFont(font3);
        spinBox_fan_up->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_fan_up->setMinimum(1);
        spinBox_fan_up->setMaximum(9999);
        spinBox_fan_up->setValue(500);
        spinBox_fan_down = new QSpinBox(centralwidget);
        spinBox_fan_down->setObjectName(QString::fromUtf8("spinBox_fan_down"));
        spinBox_fan_down->setGeometry(QRect(560, 270, 70, 30));
        spinBox_fan_down->setFont(font3);
        spinBox_fan_down->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_fan_down->setMinimum(1);
        spinBox_fan_down->setMaximum(9999);
        spinBox_fan_down->setValue(100);
        SettingWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(spinBox_areaNum, spinBox_nodeNum);
        QWidget::setTabOrder(spinBox_nodeNum, spinBox_lamp_down);
        QWidget::setTabOrder(spinBox_lamp_down, spinBox_lamp_up);
        QWidget::setTabOrder(spinBox_lamp_up, spinBox_humi_down);
        QWidget::setTabOrder(spinBox_humi_down, spinBox_humi_up);
        QWidget::setTabOrder(spinBox_humi_up, spinBox_curtain_down);
        QWidget::setTabOrder(spinBox_curtain_down, spinBox_curtain_up);
        QWidget::setTabOrder(spinBox_curtain_up, spinBox_fan_down);
        QWidget::setTabOrder(spinBox_fan_down, spinBox_fan_up);
        QWidget::setTabOrder(spinBox_fan_up, listWidget_area);
        QWidget::setTabOrder(listWidget_area, pushButton_2);
        QWidget::setTabOrder(pushButton_2, listWidget_nodeAll);
        QWidget::setTabOrder(listWidget_nodeAll, btn_addNode);
        QWidget::setTabOrder(btn_addNode, listWidget_nodeSelect);
        QWidget::setTabOrder(listWidget_nodeSelect, btn_removeNode);
        QWidget::setTabOrder(btn_removeNode, btn_save);
        QWidget::setTabOrder(btn_save, btn_return);

        retranslateUi(SettingWindow);

        QMetaObject::connectSlotsByName(SettingWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SettingWindow)
    {
        SettingWindow->setWindowTitle(QCoreApplication::translate("SettingWindow", "\346\231\272\346\205\247\345\206\234\344\270\232\350\256\276\347\275\256\347\225\214\351\235\242", nullptr));
        btn_addNode->setText(QCoreApplication::translate("SettingWindow", ">>>", nullptr));
        btn_return->setText(QCoreApplication::translate("SettingWindow", "\350\277\224\345\233\236", nullptr));
        btn_save->setText(QCoreApplication::translate("SettingWindow", "\344\277\235\345\255\230", nullptr));
        label_title->setText(QCoreApplication::translate("SettingWindow", "\346\231\272\346\205\247\345\206\234\344\270\232\347\263\273\347\273\237\350\256\276\347\275\256\347\225\214\351\235\242", nullptr));
        label_8->setText(QCoreApplication::translate("SettingWindow", "\350\241\245\345\205\211\347\201\257\351\230\210\345\200\274", nullptr));
        label_21->setText(QCoreApplication::translate("SettingWindow", "\345\267\262\351\200\211\346\213\251\350\212\202\347\202\271", nullptr));
        label_20->setText(QCoreApplication::translate("SettingWindow", "\351\200\211\346\213\251\345\214\272\345\237\237", nullptr));
        label_14->setText(QCoreApplication::translate("SettingWindow", "%", nullptr));
        label_12->setText(QCoreApplication::translate("SettingWindow", "lux", nullptr));
        label_15->setText(QCoreApplication::translate("SettingWindow", "\302\272C ", nullptr));
        label_10->setText(QCoreApplication::translate("SettingWindow", "\351\201\256\351\230\263\345\270\230\351\230\210\345\200\274", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SettingWindow", ">>>", nullptr));
        label_9->setText(QCoreApplication::translate("SettingWindow", "\345\212\240\346\271\277\345\231\250\351\230\210\345\200\274", nullptr));
        label_4->setText(QCoreApplication::translate("SettingWindow", "\345\214\272\345\237\237\346\225\260\351\207\217", nullptr));
        btn_removeNode->setText(QCoreApplication::translate("SettingWindow", "<<<", nullptr));
        label_11->setText(QCoreApplication::translate("SettingWindow", "\346\216\222\346\260\224\346\211\207\351\230\210\345\200\274", nullptr));
        label_13->setText(QCoreApplication::translate("SettingWindow", "lux", nullptr));
        label_19->setText(QCoreApplication::translate("SettingWindow", "-", nullptr));
        label_18->setText(QCoreApplication::translate("SettingWindow", "-", nullptr));
        label_17->setText(QCoreApplication::translate("SettingWindow", "-", nullptr));
        label_16->setText(QCoreApplication::translate("SettingWindow", "-", nullptr));
        label_22->setText(QCoreApplication::translate("SettingWindow", "\346\211\200\346\234\211\350\212\202\347\202\271", nullptr));
        label_5->setText(QCoreApplication::translate("SettingWindow", "\350\212\202\347\202\271\346\225\260\351\207\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingWindow: public Ui_SettingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGWINDOW_H
