#include "mainwindow.h"
#include <QApplication>
#include <QProcess>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;


    int e = a.exec();
    if (e == 111)
    {
        QProcess::startDetached("killall", QStringList("/home/csgec/app-arm"));
        QProcess::startDetached("/home/csgec/app-arm", QStringList("&"));
        return 0;
    }
    return e;
}
