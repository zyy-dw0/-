/********************************************************************************
** Form generated from reading UI file 'settingwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGWINDOW_H
#define UI_SETTINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
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
    QLineEdit *edit_areaNnum;
    QLineEdit *edit_nodeNnum;
    QLineEdit *edit_lamp_down;
    QLineEdit *edit_lamp_up;
    QLineEdit *edit_humi_up;
    QLineEdit *edit_humi_down;
    QLineEdit *edit_curtain_up;
    QLineEdit *edit_curtain_down;
    QLineEdit *edit_fan_up;
    QLineEdit *edit_fan_down;
    QCheckBox *checkBox_auto;

    void setupUi(QMainWindow *SettingWindow)
    {
        if (SettingWindow->objectName().isEmpty())
            SettingWindow->setObjectName(QStringLiteral("SettingWindow"));
        SettingWindow->resize(800, 480);
        SettingWindow->setStyleSheet(QLatin1String("QLabel\n"
"{	\n"
"	font: 9pt \"Arial\";\n"
"}\n"
"QLabel#label_title\n"
"{\n"
"	font: 18pt \"Arial\";\n"
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
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        btn_addNode = new QPushButton(centralwidget);
        btn_addNode->setObjectName(QStringLiteral("btn_addNode"));
        btn_addNode->setGeometry(QRect(276, 240, 50, 40));
        QFont font;
        font.setPointSize(15);
        btn_addNode->setFont(font);
        btn_return = new QPushButton(centralwidget);
        btn_return->setObjectName(QStringLiteral("btn_return"));
        btn_return->setGeometry(QRect(540, 380, 90, 50));
        QFont font1;
        font1.setPointSize(12);
        btn_return->setFont(font1);
        btn_save = new QPushButton(centralwidget);
        btn_save->setObjectName(QStringLiteral("btn_save"));
        btn_save->setGeometry(QRect(660, 380, 90, 50));
        btn_save->setFont(font1);
        label_title = new QLabel(centralwidget);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(0, 0, 800, 70));
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(false);
        font2.setItalic(false);
        label_title->setFont(font2);
        label_title->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(470, 150, 80, 30));
        label_8->setAlignment(Qt::AlignCenter);
        label_21 = new QLabel(centralwidget);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(330, 130, 110, 30));
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(false);
        font3.setItalic(false);
        label_21->setFont(font3);
        label_21->setAlignment(Qt::AlignCenter);
        label_20 = new QLabel(centralwidget);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(10, 130, 80, 30));
        label_20->setFont(font3);
        label_20->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(740, 200, 54, 40));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(740, 150, 54, 40));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(740, 295, 54, 40));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(470, 250, 80, 30));
        label_10->setAlignment(Qt::AlignCenter);
        listWidget_nodeSelect = new QListWidget(centralwidget);
        listWidget_nodeSelect->setObjectName(QStringLiteral("listWidget_nodeSelect"));
        listWidget_nodeSelect->setGeometry(QRect(330, 170, 110, 270));
        listWidget_nodeSelect->setFont(font1);
        listWidget_nodeSelect->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(104, 280, 50, 40));
        pushButton_2->setFont(font);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(470, 200, 80, 30));
        label_9->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 80, 70, 30));
        label_4->setFont(font3);
        label_4->setAlignment(Qt::AlignCenter);
        listWidget_nodeAll = new QListWidget(centralwidget);
        listWidget_nodeAll->setObjectName(QStringLiteral("listWidget_nodeAll"));
        listWidget_nodeAll->setGeometry(QRect(160, 170, 110, 270));
        listWidget_nodeAll->setFont(font1);
        listWidget_nodeAll->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        listWidget_area = new QListWidget(centralwidget);
        listWidget_area->setObjectName(QStringLiteral("listWidget_area"));
        listWidget_area->setGeometry(QRect(10, 170, 90, 270));
        listWidget_area->setFont(font1);
        listWidget_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        btn_removeNode = new QPushButton(centralwidget);
        btn_removeNode->setObjectName(QStringLiteral("btn_removeNode"));
        btn_removeNode->setGeometry(QRect(276, 320, 50, 40));
        btn_removeNode->setFont(font);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(470, 300, 80, 30));
        label_11->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(740, 246, 54, 40));
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(634, 310, 21, 16));
        label_19->setAlignment(Qt::AlignCenter);
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(634, 260, 21, 16));
        label_18->setAlignment(Qt::AlignCenter);
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(634, 210, 21, 16));
        label_17->setAlignment(Qt::AlignCenter);
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(634, 160, 21, 16));
        label_16->setAlignment(Qt::AlignCenter);
        label_22 = new QLabel(centralwidget);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(160, 130, 110, 30));
        label_22->setFont(font3);
        label_22->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(150, 80, 80, 30));
        label_5->setFont(font3);
        label_5->setAlignment(Qt::AlignCenter);
        edit_areaNnum = new QLineEdit(centralwidget);
        edit_areaNnum->setObjectName(QStringLiteral("edit_areaNnum"));
        edit_areaNnum->setGeometry(QRect(80, 80, 60, 30));
        edit_nodeNnum = new QLineEdit(centralwidget);
        edit_nodeNnum->setObjectName(QStringLiteral("edit_nodeNnum"));
        edit_nodeNnum->setGeometry(QRect(230, 80, 70, 30));
        edit_lamp_down = new QLineEdit(centralwidget);
        edit_lamp_down->setObjectName(QStringLiteral("edit_lamp_down"));
        edit_lamp_down->setGeometry(QRect(560, 150, 70, 30));
        edit_lamp_up = new QLineEdit(centralwidget);
        edit_lamp_up->setObjectName(QStringLiteral("edit_lamp_up"));
        edit_lamp_up->setGeometry(QRect(660, 150, 70, 30));
        edit_humi_up = new QLineEdit(centralwidget);
        edit_humi_up->setObjectName(QStringLiteral("edit_humi_up"));
        edit_humi_up->setGeometry(QRect(660, 200, 70, 30));
        edit_humi_down = new QLineEdit(centralwidget);
        edit_humi_down->setObjectName(QStringLiteral("edit_humi_down"));
        edit_humi_down->setGeometry(QRect(560, 200, 70, 30));
        edit_curtain_up = new QLineEdit(centralwidget);
        edit_curtain_up->setObjectName(QStringLiteral("edit_curtain_up"));
        edit_curtain_up->setGeometry(QRect(660, 250, 70, 30));
        edit_curtain_down = new QLineEdit(centralwidget);
        edit_curtain_down->setObjectName(QStringLiteral("edit_curtain_down"));
        edit_curtain_down->setGeometry(QRect(560, 250, 70, 30));
        edit_fan_up = new QLineEdit(centralwidget);
        edit_fan_up->setObjectName(QStringLiteral("edit_fan_up"));
        edit_fan_up->setGeometry(QRect(660, 300, 70, 30));
        edit_fan_down = new QLineEdit(centralwidget);
        edit_fan_down->setObjectName(QStringLiteral("edit_fan_down"));
        edit_fan_down->setGeometry(QRect(560, 300, 70, 30));
        checkBox_auto = new QCheckBox(centralwidget);
        checkBox_auto->setObjectName(QStringLiteral("checkBox_auto"));
        checkBox_auto->setGeometry(QRect(660, 80, 130, 30));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(false);
        checkBox_auto->setFont(font4);
        checkBox_auto->setChecked(false);
        SettingWindow->setCentralWidget(centralwidget);

        retranslateUi(SettingWindow);

        QMetaObject::connectSlotsByName(SettingWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SettingWindow)
    {
        SettingWindow->setWindowTitle(QApplication::translate("SettingWindow", "MainWindow", Q_NULLPTR));
        btn_addNode->setText(QApplication::translate("SettingWindow", ">>>", Q_NULLPTR));
        btn_return->setText(QApplication::translate("SettingWindow", "\350\277\224\345\233\236", Q_NULLPTR));
        btn_save->setText(QApplication::translate("SettingWindow", "\344\277\235\345\255\230", Q_NULLPTR));
        label_title->setText(QApplication::translate("SettingWindow", "\346\231\272\346\205\247\345\206\234\344\270\232\347\263\273\347\273\237\350\256\276\347\275\256\347\225\214\351\235\242", Q_NULLPTR));
        label_8->setText(QApplication::translate("SettingWindow", "\350\241\245\345\205\211\347\201\257\351\230\210\345\200\274", Q_NULLPTR));
        label_21->setText(QApplication::translate("SettingWindow", "\345\267\262\350\256\276\347\275\256\350\212\202\347\202\271", Q_NULLPTR));
        label_20->setText(QApplication::translate("SettingWindow", "\351\200\211\346\213\251\345\214\272\345\237\237", Q_NULLPTR));
        label_14->setText(QApplication::translate("SettingWindow", "%", Q_NULLPTR));
        label_12->setText(QApplication::translate("SettingWindow", "lux", Q_NULLPTR));
        label_15->setText(QApplication::translate("SettingWindow", "\342\204\203", Q_NULLPTR));
        label_10->setText(QApplication::translate("SettingWindow", "\351\201\256\351\230\263\345\270\230\351\230\210\345\200\274", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("SettingWindow", ">>>", Q_NULLPTR));
        label_9->setText(QApplication::translate("SettingWindow", "\345\212\240\346\271\277\345\231\250\351\230\210\345\200\274", Q_NULLPTR));
        label_4->setText(QApplication::translate("SettingWindow", "\345\214\272\345\237\237\346\225\260\351\207\217", Q_NULLPTR));
        btn_removeNode->setText(QApplication::translate("SettingWindow", "<<<", Q_NULLPTR));
        label_11->setText(QApplication::translate("SettingWindow", "\346\216\222\346\260\224\346\211\207\351\230\210\345\200\274", Q_NULLPTR));
        label_13->setText(QApplication::translate("SettingWindow", "lux", Q_NULLPTR));
        label_19->setText(QApplication::translate("SettingWindow", "-", Q_NULLPTR));
        label_18->setText(QApplication::translate("SettingWindow", "-", Q_NULLPTR));
        label_17->setText(QApplication::translate("SettingWindow", "-", Q_NULLPTR));
        label_16->setText(QApplication::translate("SettingWindow", "-", Q_NULLPTR));
        label_22->setText(QApplication::translate("SettingWindow", "\346\234\252\350\256\276\347\275\256\350\212\202\347\202\271", Q_NULLPTR));
        label_5->setText(QApplication::translate("SettingWindow", "\350\212\202\347\202\271\346\225\260\351\207\217", Q_NULLPTR));
        edit_areaNnum->setText(QString());
        edit_nodeNnum->setText(QString());
        edit_lamp_down->setText(QString());
        edit_lamp_up->setText(QString());
        edit_humi_up->setText(QString());
        edit_humi_down->setText(QString());
        edit_curtain_up->setText(QString());
        edit_curtain_down->setText(QString());
        edit_fan_up->setText(QString());
        edit_fan_down->setText(QString());
        checkBox_auto->setText(QApplication::translate("SettingWindow", "\350\207\252\345\212\250\346\216\247\345\210\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SettingWindow: public Ui_SettingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGWINDOW_H
