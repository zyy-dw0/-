#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginDialog loginDlg;
    MainWindow w;
    QApplication::connect(&loginDlg, SIGNAL(sigCloseApp()), &w, SLOT(onCloseApp()));
    QApplication::connect(&loginDlg, SIGNAL(sigLogin(CmdType,QString,QString)), &w, SLOT(onLogin(CmdType,QString,QString)));
    QApplication::connect(&loginDlg, SIGNAL(sigRegister(CmdType,QString,QString)), &w, SLOT(onRegister(CmdType,QString,QString)));

    QApplication::connect(&w, SIGNAL(sigSetAckDialog(AckStatus)), &loginDlg, SLOT(onSetAckDialog(AckStatus)));

    loginDlg.show();

    return a.exec();
}
