/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        MainWindow->setStyleSheet(QLatin1String("QWidget#centralWidget\n"
"{\n"
"	border-image: url(:/images/main-bg.jpg);\n"
"}\n"
"QPushButton#btn_monitor,QPushButton#btn_control,QPushButton#btn_setting\n"
"{\n"
"	border-radius: 75px;\n"
"	border-width: 1px;\n"
"	border-style:solid;\n"
"	background-color: rgb(170, 255, 255);\n"
"}\n"
"QPushButton#btn_logo\n"
"{\n"
"	\n"
"	border-image: url(:/images/logo.png);\n"
"}\n"
"QPushButton#btn_monitor:pressed,QPushButton#btn_control:pressed,QPushButton#btn_setting:pressed\n"
"{\n"
"	\n"
"	background-color: rgb(85, 255, 0);\n"
"}\n"
"QMessageBox\n"
"{\n"
"	background-color: rgb(170, 255, 255);\n"
"}\n"
"QMessageBox QPushButton\n"
"{\n"
"	background-color: transparent;\n"
"	color:blue;\n"
"	border-style: solid;\n"
"	border-width:1px;\n"
"	width:50px;\n"
"	height:25px;\n"
"}\n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 10, 681, 80));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        btn_monitor = new QPushButton(centralWidget);
        btn_monitor->setObjectName(QStringLiteral("btn_monitor"));
        btn_monitor->setGeometry(QRect(150, 180, 150, 150));
        btn_monitor->setFocusPolicy(Qt::NoFocus);
        btn_control = new QPushButton(centralWidget);
        btn_control->setObjectName(QStringLiteral("btn_control"));
        btn_control->setGeometry(QRect(490, 180, 150, 150));
        btn_control->setFocusPolicy(Qt::NoFocus);
        btn_setting = new QPushButton(centralWidget);
        btn_setting->setObjectName(QStringLiteral("btn_setting"));
        btn_setting->setGeometry(QRect(320, 180, 150, 150));
        btn_setting->setFocusPolicy(Qt::NoFocus);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\347\211\251\350\201\224\347\275\221\346\231\272\346\205\247\345\206\234\344\270\232\347\263\273\347\273\237", Q_NULLPTR));
        btn_monitor->setText(QApplication::translate("MainWindow", "\347\216\257\345\242\203\347\233\221\346\265\213", Q_NULLPTR));
        btn_control->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\346\216\247\345\210\266", Q_NULLPTR));
        btn_setting->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\350\256\276\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
