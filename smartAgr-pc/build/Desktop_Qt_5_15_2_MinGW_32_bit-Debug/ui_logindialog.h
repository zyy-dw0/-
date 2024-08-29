/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page_login;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_lpwd;
    QLineEdit *edit_lpwd;
    QPushButton *btn_login;
    QPushButton *btn_cancle;
    QPushButton *btn_toregister;
    QLabel *label_title;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_lusername;
    QLineEdit *edit_lusername;
    QPushButton *btn_to_setserver;
    QWidget *page_register;
    QLabel *label_title_2;
    QLabel *label_logo_2;
    QPushButton *btn_register;
    QPushButton *btn_rcancle;
    QPushButton *btn_tologin;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QLineEdit *edit_rpwd_2;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLineEdit *edit_rpwd;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *edit_rusername;
    QWidget *page_server;
    QLabel *label_ip;
    QLineEdit *edit_server_ip;
    QPushButton *btn_save_server;
    QLineEdit *edit_server_port;
    QLabel *label_port;
    QPushButton *btn_scancle;
    QPushButton *btn_sreturn;
    QLabel *label_logo_7;
    QLabel *label_title_7;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(800, 480);
        LoginDialog->setStyleSheet(QString::fromUtf8("/*\345\255\246\346\240\241LOGO*/\n"
"QLabel#label_logo,QLabel#label_logo_2,QLabel#label_logo_7\n"
"{\n"
"	border-image: url(:/images/logo.png);\n"
"}\n"
"/*\347\231\273\345\275\225\346\250\241\345\235\227\347\232\204\347\225\214\351\235\242\345\233\276\347\211\207*/\n"
"QWidget#page_login,QWidget#page_register,QWidget#page_server\n"
"{\n"
"	border-image: url(:/images/logon-bg.jpg);\n"
"}\n"
"/*\346\255\243\345\270\270\346\214\211\351\222\256\347\232\204\347\212\266\346\200\201*/\n"
"QPushButton#btn_login,QPushButton#btn_cancle,QPushButton#btn_register,QPushButton#btn_rcancle,QPushButton#btn_tologin,QPushButton#btn_save_server,QPushButton#btn_scancle,QPushButton#btn_sreturn\n"
"{\n"
"	border-radius: 10px;\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"	background-color: rgb(210, 255, 238);\n"
"}\n"
"\n"
"/*\346\226\207\346\234\254\346\241\206\346\240\267\345\274\217*/\n"
"QLineEdit\n"
"{\n"
"	border-radius: 5px;\n"
"}\n"
"/*\346\240\207\347\255\276\344\270\216\345\260\217\346\214\211\351\222\256\347\232\204"
                        "\345\255\227\344\275\223\351\253\230\344\272\256*/\n"
"QLabel#label_lusername, QLabel#label_lpwd, QPushButton#btn_toregister,QPushButton#btn_to_setserver,QLabel#label_ip,QLabel#label_port\n"
"{\n"
"	color: rgb(210, 255, 238);\n"
"}\n"
"\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213*/\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: rgb(210, 155, 138);\n"
"}\n"
"\n"
"\n"
""));
        verticalLayout = new QVBoxLayout(LoginDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(LoginDialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page_login = new QWidget();
        page_login->setObjectName(QString::fromUtf8("page_login"));
        layoutWidget = new QWidget(page_login);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(240, 225, 321, 50));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_lpwd = new QLabel(layoutWidget);
        label_lpwd->setObjectName(QString::fromUtf8("label_lpwd"));
        QFont font;
        font.setPointSize(15);
        label_lpwd->setFont(font);
        label_lpwd->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(label_lpwd);

        edit_lpwd = new QLineEdit(layoutWidget);
        edit_lpwd->setObjectName(QString::fromUtf8("edit_lpwd"));
        edit_lpwd->setFont(font);
        edit_lpwd->setFocusPolicy(Qt::StrongFocus);
        edit_lpwd->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(edit_lpwd);

        btn_login = new QPushButton(page_login);
        btn_login->setObjectName(QString::fromUtf8("btn_login"));
        btn_login->setGeometry(QRect(290, 320, 110, 50));
        btn_login->setFont(font);
        btn_cancle = new QPushButton(page_login);
        btn_cancle->setObjectName(QString::fromUtf8("btn_cancle"));
        btn_cancle->setGeometry(QRect(450, 320, 110, 50));
        btn_cancle->setFont(font);
        btn_toregister = new QPushButton(page_login);
        btn_toregister->setObjectName(QString::fromUtf8("btn_toregister"));
        btn_toregister->setGeometry(QRect(720, 450, 80, 30));
        QFont font1;
        btn_toregister->setFont(font1);
        btn_toregister->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        btn_toregister->setFlat(true);
        label_title = new QLabel(page_login);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setGeometry(QRect(120, 20, 610, 110));
        QFont font2;
        font2.setPointSize(32);
        label_title->setFont(font2);
        label_title->setAlignment(Qt::AlignCenter);
        layoutWidget1 = new QWidget(page_login);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(240, 160, 321, 50));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_lusername = new QLabel(layoutWidget1);
        label_lusername->setObjectName(QString::fromUtf8("label_lusername"));
        label_lusername->setFont(font);

        horizontalLayout->addWidget(label_lusername);

        edit_lusername = new QLineEdit(layoutWidget1);
        edit_lusername->setObjectName(QString::fromUtf8("edit_lusername"));
        edit_lusername->setFont(font);

        horizontalLayout->addWidget(edit_lusername);

        btn_to_setserver = new QPushButton(page_login);
        btn_to_setserver->setObjectName(QString::fromUtf8("btn_to_setserver"));
        btn_to_setserver->setGeometry(QRect(720, 420, 80, 30));
        btn_to_setserver->setFont(font1);
        btn_to_setserver->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        btn_to_setserver->setFlat(true);
        stackedWidget->addWidget(page_login);
        page_register = new QWidget();
        page_register->setObjectName(QString::fromUtf8("page_register"));
        label_title_2 = new QLabel(page_register);
        label_title_2->setObjectName(QString::fromUtf8("label_title_2"));
        label_title_2->setGeometry(QRect(190, 10, 480, 100));
        label_title_2->setFont(font2);
        label_title_2->setAlignment(Qt::AlignCenter);
        label_logo_2 = new QLabel(page_register);
        label_logo_2->setObjectName(QString::fromUtf8("label_logo_2"));
        label_logo_2->setGeometry(QRect(10, 10, 140, 140));
        btn_register = new QPushButton(page_register);
        btn_register->setObjectName(QString::fromUtf8("btn_register"));
        btn_register->setGeometry(QRect(310, 300, 110, 40));
        btn_register->setFont(font);
        btn_rcancle = new QPushButton(page_register);
        btn_rcancle->setObjectName(QString::fromUtf8("btn_rcancle"));
        btn_rcancle->setGeometry(QRect(460, 300, 110, 40));
        btn_rcancle->setFont(font);
        btn_tologin = new QPushButton(page_register);
        btn_tologin->setObjectName(QString::fromUtf8("btn_tologin"));
        btn_tologin->setGeometry(QRect(720, 420, 80, 30));
        btn_tologin->setFont(font1);
        btn_tologin->setFlat(true);
        layoutWidget2 = new QWidget(page_register);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(230, 222, 341, 36));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        horizontalLayout_3->addWidget(label_7);

        edit_rpwd_2 = new QLineEdit(layoutWidget2);
        edit_rpwd_2->setObjectName(QString::fromUtf8("edit_rpwd_2"));
        edit_rpwd_2->setFont(font);
        edit_rpwd_2->setFocusPolicy(Qt::StrongFocus);
        edit_rpwd_2->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(edit_rpwd_2);

        layoutWidget3 = new QWidget(page_register);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(230, 180, 341, 36));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(80, 0));
        label_6->setFont(font);

        horizontalLayout_4->addWidget(label_6);

        edit_rpwd = new QLineEdit(layoutWidget3);
        edit_rpwd->setObjectName(QString::fromUtf8("edit_rpwd"));
        edit_rpwd->setFont(font);
        edit_rpwd->setFocusPolicy(Qt::StrongFocus);
        edit_rpwd->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(edit_rpwd);

        layoutWidget4 = new QWidget(page_register);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(230, 140, 341, 36));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(80, 0));
        label_5->setFont(font);

        horizontalLayout_5->addWidget(label_5);

        edit_rusername = new QLineEdit(layoutWidget4);
        edit_rusername->setObjectName(QString::fromUtf8("edit_rusername"));
        edit_rusername->setFont(font);

        horizontalLayout_5->addWidget(edit_rusername);

        stackedWidget->addWidget(page_register);
        page_server = new QWidget();
        page_server->setObjectName(QString::fromUtf8("page_server"));
        label_ip = new QLabel(page_server);
        label_ip->setObjectName(QString::fromUtf8("label_ip"));
        label_ip->setGeometry(QRect(220, 179, 120, 33));
        label_ip->setMinimumSize(QSize(80, 0));
        label_ip->setFont(font);
        label_ip->setAlignment(Qt::AlignCenter);
        edit_server_ip = new QLineEdit(page_server);
        edit_server_ip->setObjectName(QString::fromUtf8("edit_server_ip"));
        edit_server_ip->setGeometry(QRect(346, 181, 253, 29));
        edit_server_ip->setFont(font);
        edit_server_ip->setFocusPolicy(Qt::StrongFocus);
        edit_server_ip->setEchoMode(QLineEdit::Normal);
        btn_save_server = new QPushButton(page_server);
        btn_save_server->setObjectName(QString::fromUtf8("btn_save_server"));
        btn_save_server->setGeometry(QRect(350, 320, 100, 50));
        btn_save_server->setFont(font);
        edit_server_port = new QLineEdit(page_server);
        edit_server_port->setObjectName(QString::fromUtf8("edit_server_port"));
        edit_server_port->setGeometry(QRect(346, 240, 253, 29));
        edit_server_port->setFont(font);
        label_port = new QLabel(page_server);
        label_port->setObjectName(QString::fromUtf8("label_port"));
        label_port->setGeometry(QRect(220, 239, 120, 33));
        label_port->setMinimumSize(QSize(80, 0));
        label_port->setFont(font);
        label_port->setAlignment(Qt::AlignCenter);
        btn_scancle = new QPushButton(page_server);
        btn_scancle->setObjectName(QString::fromUtf8("btn_scancle"));
        btn_scancle->setGeometry(QRect(500, 320, 100, 50));
        btn_scancle->setFont(font);
        btn_sreturn = new QPushButton(page_server);
        btn_sreturn->setObjectName(QString::fromUtf8("btn_sreturn"));
        btn_sreturn->setGeometry(QRect(680, 410, 80, 30));
        btn_sreturn->setFont(font1);
        btn_sreturn->setFlat(true);
        label_logo_7 = new QLabel(page_server);
        label_logo_7->setObjectName(QString::fromUtf8("label_logo_7"));
        label_logo_7->setGeometry(QRect(10, 20, 140, 140));
        label_title_7 = new QLabel(page_server);
        label_title_7->setObjectName(QString::fromUtf8("label_title_7"));
        label_title_7->setGeometry(QRect(200, 20, 480, 110));
        label_title_7->setFont(font2);
        label_title_7->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page_server);

        verticalLayout->addWidget(stackedWidget);

        QWidget::setTabOrder(edit_lusername, edit_lpwd);
        QWidget::setTabOrder(edit_lpwd, btn_login);
        QWidget::setTabOrder(btn_login, btn_cancle);
        QWidget::setTabOrder(btn_cancle, btn_toregister);
        QWidget::setTabOrder(btn_toregister, edit_rusername);
        QWidget::setTabOrder(edit_rusername, edit_rpwd);
        QWidget::setTabOrder(edit_rpwd, edit_rpwd_2);
        QWidget::setTabOrder(edit_rpwd_2, btn_register);
        QWidget::setTabOrder(btn_register, btn_rcancle);
        QWidget::setTabOrder(btn_rcancle, btn_tologin);

        retranslateUi(LoginDialog);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "\346\231\272\346\205\247\345\206\234\344\270\232\347\231\273\345\275\225", nullptr));
        label_lpwd->setText(QCoreApplication::translate("LoginDialog", "\345\257\206\347\240\201", nullptr));
        edit_lpwd->setText(QCoreApplication::translate("LoginDialog", "666666", nullptr));
        btn_login->setText(QCoreApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
        btn_cancle->setText(QCoreApplication::translate("LoginDialog", "\345\217\226\346\266\210", nullptr));
        btn_toregister->setText(QCoreApplication::translate("LoginDialog", "\346\267\273\345\212\240\346\226\260\347\224\250\346\210\267", nullptr));
        label_title->setText(QCoreApplication::translate("LoginDialog", "\347\211\251\350\201\224\347\275\221\346\231\272\346\205\247\345\206\234\344\270\232\347\263\273\347\273\237", nullptr));
        label_lusername->setText(QCoreApplication::translate("LoginDialog", "\347\224\250\346\210\267", nullptr));
        edit_lusername->setText(QCoreApplication::translate("LoginDialog", "admin", nullptr));
        btn_to_setserver->setText(QCoreApplication::translate("LoginDialog", "\346\234\215\345\212\241\345\231\250\350\256\276\347\275\256", nullptr));
        label_title_2->setText(QCoreApplication::translate("LoginDialog", "\346\271\226\345\215\227\347\247\221\346\212\200\345\255\246\351\231\242\n"
"\347\211\251\350\201\224\347\275\221\346\231\272\346\205\247\345\206\234\344\270\232\347\263\273\347\273\237", nullptr));
        label_logo_2->setText(QString());
        btn_register->setText(QCoreApplication::translate("LoginDialog", "\346\263\250\345\206\214", nullptr));
        btn_rcancle->setText(QCoreApplication::translate("LoginDialog", "\345\217\226\346\266\210", nullptr));
        btn_tologin->setText(QCoreApplication::translate("LoginDialog", "\350\277\224\345\233\236", nullptr));
        label_7->setText(QCoreApplication::translate("LoginDialog", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        label_6->setText(QCoreApplication::translate("LoginDialog", "\345\257\206\347\240\201", nullptr));
        label_5->setText(QCoreApplication::translate("LoginDialog", "\347\224\250\346\210\267", nullptr));
        label_ip->setText(QCoreApplication::translate("LoginDialog", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", nullptr));
        edit_server_ip->setText(QCoreApplication::translate("LoginDialog", "47.98.153.253", nullptr));
        btn_save_server->setText(QCoreApplication::translate("LoginDialog", "\347\241\256\345\256\232", nullptr));
        edit_server_port->setText(QCoreApplication::translate("LoginDialog", "10025", nullptr));
        label_port->setText(QCoreApplication::translate("LoginDialog", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", nullptr));
        btn_scancle->setText(QCoreApplication::translate("LoginDialog", "\345\217\226\346\266\210", nullptr));
        btn_sreturn->setText(QCoreApplication::translate("LoginDialog", "\350\277\224\345\233\236", nullptr));
        label_logo_7->setText(QString());
        label_title_7->setText(QCoreApplication::translate("LoginDialog", "\346\271\226\345\215\227\347\247\221\346\212\200\345\255\246\351\231\242\n"
"\347\211\251\350\201\224\347\275\221\346\231\272\346\205\247\345\206\234\344\270\232\347\263\273\347\273\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
