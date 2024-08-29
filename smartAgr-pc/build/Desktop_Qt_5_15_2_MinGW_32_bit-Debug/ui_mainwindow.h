/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *btn_monitor;
    QPushButton *btn_control;
    QPushButton *btn_setting;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 480);
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget#centralWidget\n"
"{\n"
"border-image: url(:/images/main-bg.jpg);\n"
"}\n"
"QPushButton#btn_monitor,QPushButton#btn_control,QPushButton#btn_setting\n"
"{\n"
"	border-radius: 75px;\n"
"	border-width: 1px;\n"
"	border-style:solid;\n"
"	background-color: rgb(170, 255, 255);\n"
"	\n"
"	font: 20pt \"\346\245\267\344\275\223\";\n"
"}\n"
"QPushButton#btn_logo\n"
"{\n"
"	\n"
"	border-image: url(:/images/logo.png);\n"
"}\n"
"\n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 0, 751, 91));
        QFont font;
        font.setPointSize(48);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        btn_monitor = new QPushButton(centralWidget);
        btn_monitor->setObjectName(QString::fromUtf8("btn_monitor"));
        btn_monitor->setGeometry(QRect(160, 160, 150, 150));
        btn_monitor->setFocusPolicy(Qt::NoFocus);
        btn_control = new QPushButton(centralWidget);
        btn_control->setObjectName(QString::fromUtf8("btn_control"));
        btn_control->setGeometry(QRect(520, 160, 150, 150));
        btn_control->setFocusPolicy(Qt::NoFocus);
        btn_setting = new QPushButton(centralWidget);
        btn_setting->setObjectName(QString::fromUtf8("btn_setting"));
        btn_setting->setGeometry(QRect(340, 160, 150, 150));
        btn_setting->setFocusPolicy(Qt::NoFocus);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\346\231\272\346\205\247\345\206\234\344\270\232\344\270\273\351\241\265", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\347\211\251\350\201\224\347\275\221\346\231\272\346\205\247\345\206\234\344\270\232\347\263\273\347\273\237", nullptr));
        btn_monitor->setText(QCoreApplication::translate("MainWindow", "\347\216\257\345\242\203\347\233\221\346\265\213", nullptr));
        btn_control->setText(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\346\216\247\345\210\266", nullptr));
        btn_setting->setText(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
