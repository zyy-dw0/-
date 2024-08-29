/********************************************************************************
** Form generated from reading UI file 'monitorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONITORWINDOW_H
#define UI_MONITORWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MonitorWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_grid;
    QPushButton *btn_list;
    QSpacerItem *horizontalSpacer;
    QLabel *label_title;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_up;
    QPushButton *btn_down;
    QPushButton *btn_return;
    QFrame *line;
    QStackedWidget *stackedWidget;
    QWidget *page_grid;
    QWidget *page_list;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;

    void setupUi(QMainWindow *MonitorWindow)
    {
        if (MonitorWindow->objectName().isEmpty())
            MonitorWindow->setObjectName(QString::fromUtf8("MonitorWindow"));
        MonitorWindow->resize(901, 700);
        MonitorWindow->setStyleSheet(QString::fromUtf8("QHeaderView\n"
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
"}\n"
"\n"
""));
        centralwidget = new QWidget(MonitorWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_grid = new QPushButton(centralwidget);
        btn_grid->setObjectName(QString::fromUtf8("btn_grid"));
        btn_grid->setMinimumSize(QSize(0, 35));
        btn_grid->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(btn_grid);

        btn_list = new QPushButton(centralwidget);
        btn_list->setObjectName(QString::fromUtf8("btn_list"));
        btn_list->setMinimumSize(QSize(0, 35));
        btn_list->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(btn_list);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_title = new QLabel(centralwidget);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        QFont font;
        font.setPointSize(24);
        label_title->setFont(font);
        label_title->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_title);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btn_up = new QPushButton(centralwidget);
        btn_up->setObjectName(QString::fromUtf8("btn_up"));
        btn_up->setMinimumSize(QSize(0, 35));
        QFont font1;
        font1.setPointSize(12);
        btn_up->setFont(font1);

        horizontalLayout_2->addWidget(btn_up);

        btn_down = new QPushButton(centralwidget);
        btn_down->setObjectName(QString::fromUtf8("btn_down"));
        btn_down->setMinimumSize(QSize(0, 35));
        btn_down->setFont(font1);

        horizontalLayout_2->addWidget(btn_down);

        btn_return = new QPushButton(centralwidget);
        btn_return->setObjectName(QString::fromUtf8("btn_return"));
        btn_return->setMinimumSize(QSize(0, 35));
        btn_return->setMaximumSize(QSize(200, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/home.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_return->setIcon(icon);
        btn_return->setIconSize(QSize(40, 40));

        horizontalLayout_2->addWidget(btn_return);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout_3);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page_grid = new QWidget();
        page_grid->setObjectName(QString::fromUtf8("page_grid"));
        stackedWidget->addWidget(page_grid);
        page_list = new QWidget();
        page_list->setObjectName(QString::fromUtf8("page_list"));
        verticalLayout_2 = new QVBoxLayout(page_list);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(page_list);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_2->addWidget(tableView);

        stackedWidget->addWidget(page_list);

        verticalLayout->addWidget(stackedWidget);

        MonitorWindow->setCentralWidget(centralwidget);

        retranslateUi(MonitorWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MonitorWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MonitorWindow)
    {
        MonitorWindow->setWindowTitle(QCoreApplication::translate("MonitorWindow", "\346\231\272\346\205\247\345\206\234\344\270\232\347\233\221\346\216\247\351\241\265", nullptr));
#if QT_CONFIG(tooltip)
        btn_grid->setToolTip(QCoreApplication::translate("MonitorWindow", "\347\275\221\346\240\274\346\230\276\347\244\272", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_grid->setText(QString());
#if QT_CONFIG(tooltip)
        btn_list->setToolTip(QCoreApplication::translate("MonitorWindow", "\345\210\227\350\241\250\346\230\276\347\244\272", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_list->setText(QString());
        label_title->setText(QCoreApplication::translate("MonitorWindow", "\346\231\272\346\205\247\345\206\234\344\270\232\347\233\221\346\265\213\346\216\247\345\210\266\351\241\265\351\235\242", nullptr));
#if QT_CONFIG(tooltip)
        btn_up->setToolTip(QCoreApplication::translate("MonitorWindow", "\344\270\212\347\277\273", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_up->setText(QString());
#if QT_CONFIG(tooltip)
        btn_down->setToolTip(QCoreApplication::translate("MonitorWindow", "\344\270\213\347\277\273", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_down->setText(QString());
#if QT_CONFIG(tooltip)
        btn_return->setToolTip(QCoreApplication::translate("MonitorWindow", "\350\277\224\345\233\236\344\270\273\351\241\265", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_return->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MonitorWindow: public Ui_MonitorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONITORWINDOW_H
