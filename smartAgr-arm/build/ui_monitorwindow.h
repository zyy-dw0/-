/********************************************************************************
** Form generated from reading UI file 'monitorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONITORWINDOW_H
#define UI_MONITORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MonitorWindow
{
public:
    QWidget *centralwidget;
    QFrame *line;
    QStackedWidget *stackedWidget;
    QWidget *page_grid;
    QWidget *page_list;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QPushButton *btn_list;
    QLabel *label_title;
    QPushButton *btn_return;
    QPushButton *btn_grid;
    QPushButton *btn_up;
    QPushButton *btn_down;

    void setupUi(QMainWindow *MonitorWindow)
    {
        if (MonitorWindow->objectName().isEmpty())
            MonitorWindow->setObjectName(QStringLiteral("MonitorWindow"));
        MonitorWindow->resize(800, 480);
        MonitorWindow->setStyleSheet(QLatin1String("QHeaderView\n"
"{\n"
"	font: 9pt \"Arial\";\n"
"}\n"
"QWidget#centralwidget\n"
"{\n"
"	\n"
"	border-image: url(:/images/monitor-bg.jpg);\n"
"}\n"
"QPushButton#btn_return\n"
"{\n"
"	border-image: url(:/images/home.png);\n"
"	height: 40px;\n"
"}\n"
"QPushButton#btn_up\n"
"{\n"
"	border-image: url(:/images/arrow_up.png);\n"
"	width: 40px;\n"
"}\n"
"QPushButton#btn_down\n"
"{	\n"
"	border-image: url(:/images/arrow_down.png);\n"
"	width: 40px;\n"
"}\n"
"QPushButton#btn_list\n"
"{\n"
"	\n"
"	border-image: url(:/images/list.png);\n"
"	width: 30px;\n"
"}\n"
"QPushButton#btn_grid\n"
"{\n"
"	width: 30px;\n"
"	border-image: url(:/images/grid.png);\n"
"}"));
        centralwidget = new QWidget(MonitorWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 50, 800, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 59, 800, 840));
        stackedWidget->setFocusPolicy(Qt::NoFocus);
        page_grid = new QWidget();
        page_grid->setObjectName(QStringLiteral("page_grid"));
        stackedWidget->addWidget(page_grid);
        page_list = new QWidget();
        page_list->setObjectName(QStringLiteral("page_list"));
        verticalLayout_2 = new QVBoxLayout(page_list);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(page_list);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout_2->addWidget(tableView);

        stackedWidget->addWidget(page_list);
        btn_list = new QPushButton(centralwidget);
        btn_list->setObjectName(QStringLiteral("btn_list"));
        btn_list->setGeometry(QRect(60, 10, 40, 40));
        btn_list->setMaximumSize(QSize(80, 16777215));
        btn_list->setFocusPolicy(Qt::NoFocus);
        label_title = new QLabel(centralwidget);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(160, 10, 430, 33));
        QFont font;
        font.setPointSize(15);
        label_title->setFont(font);
        label_title->setAlignment(Qt::AlignCenter);
        btn_return = new QPushButton(centralwidget);
        btn_return->setObjectName(QStringLiteral("btn_return"));
        btn_return->setGeometry(QRect(709, 1, 80, 58));
        btn_return->setMaximumSize(QSize(200, 16777215));
        btn_return->setFocusPolicy(Qt::NoFocus);
        btn_grid = new QPushButton(centralwidget);
        btn_grid->setObjectName(QStringLiteral("btn_grid"));
        btn_grid->setGeometry(QRect(10, 10, 40, 40));
        btn_grid->setMaximumSize(QSize(80, 16777215));
        btn_grid->setFocusPolicy(Qt::NoFocus);
        btn_up = new QPushButton(centralwidget);
        btn_up->setObjectName(QStringLiteral("btn_up"));
        btn_up->setGeometry(QRect(570, 4, 50, 50));
        QFont font1;
        font1.setPointSize(12);
        btn_up->setFont(font1);
        btn_up->setFocusPolicy(Qt::NoFocus);
        btn_down = new QPushButton(centralwidget);
        btn_down->setObjectName(QStringLiteral("btn_down"));
        btn_down->setGeometry(QRect(630, 4, 50, 50));
        btn_down->setFont(font1);
        btn_down->setFocusPolicy(Qt::NoFocus);
        MonitorWindow->setCentralWidget(centralwidget);

        retranslateUi(MonitorWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MonitorWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MonitorWindow)
    {
        MonitorWindow->setWindowTitle(QApplication::translate("MonitorWindow", "MainWindow", Q_NULLPTR));
        btn_list->setText(QString());
        label_title->setText(QApplication::translate("MonitorWindow", "\346\231\272\346\205\247\345\206\234\344\270\232\347\233\221\346\265\213\347\225\214\351\235\242", Q_NULLPTR));
        btn_return->setText(QString());
        btn_grid->setText(QString());
        btn_up->setText(QString());
        btn_down->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MonitorWindow: public Ui_MonitorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONITORWINDOW_H
