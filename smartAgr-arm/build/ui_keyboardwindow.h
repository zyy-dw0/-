/********************************************************************************
** Form generated from reading UI file 'keyboardwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYBOARDWINDOW_H
#define UI_KEYBOARDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KeyBoardWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *btn_a;
    QPushButton *btn_b;
    QPushButton *btn_c;
    QPushButton *btn_d;
    QPushButton *btn_e;
    QPushButton *btn_f;
    QPushButton *btn_g;
    QPushButton *btn_7;
    QPushButton *btn_8;
    QPushButton *btn_9;
    QPushButton *btn_h;
    QPushButton *btn_i;
    QPushButton *btn_j;
    QPushButton *btn_k;
    QPushButton *btn_l;
    QPushButton *btn_m;
    QPushButton *btn_n;
    QPushButton *btn_4;
    QPushButton *btn_5;
    QPushButton *btn_6;
    QPushButton *btn_o;
    QPushButton *btn_p;
    QPushButton *btn_q;
    QPushButton *btn_r;
    QPushButton *btn_s;
    QPushButton *btn_t;
    QPushButton *btn_u;
    QPushButton *btn_1;
    QPushButton *btn_2;
    QPushButton *btn_3;
    QPushButton *btn_shift;
    QPushButton *btn_v;
    QPushButton *btn_w;
    QPushButton *btn_x;
    QPushButton *btn_y;
    QPushButton *btn_z;
    QPushButton *btn_hide;
    QPushButton *btn_backup;
    QPushButton *btn_0;
    QPushButton *btn_dot;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *KeyBoardWindow)
    {
        if (KeyBoardWindow->objectName().isEmpty())
            KeyBoardWindow->setObjectName(QStringLiteral("KeyBoardWindow"));
        KeyBoardWindow->resize(800, 180);
        KeyBoardWindow->setWindowOpacity(0);
        KeyBoardWindow->setStyleSheet(QLatin1String("QWidget#centralwidget\n"
"{\n"
"	background-color: rgb(190, 186, 255);\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"	border-radius: 3px;	\n"
"	border-style: 1px;\n"
"	background-color: rgb(220, 220, 220);\n"
"	height:35px;\n"
"	width:72px;\n"
"	font: 12pt \"Arial\";\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	\n"
"	background-color: rgb(113, 243, 57);\n"
"}\n"
""));
        centralwidget = new QWidget(KeyBoardWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btn_a = new QPushButton(centralwidget);
        buttonGroup = new QButtonGroup(KeyBoardWindow);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(btn_a);
        btn_a->setObjectName(QStringLiteral("btn_a"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        btn_a->setFont(font);
        btn_a->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_a, 0, 0, 1, 1);

        btn_b = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_b);
        btn_b->setObjectName(QStringLiteral("btn_b"));
        btn_b->setFont(font);
        btn_b->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_b, 0, 1, 1, 1);

        btn_c = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_c);
        btn_c->setObjectName(QStringLiteral("btn_c"));
        btn_c->setFont(font);
        btn_c->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_c, 0, 2, 1, 1);

        btn_d = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_d);
        btn_d->setObjectName(QStringLiteral("btn_d"));
        btn_d->setFont(font);
        btn_d->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_d, 0, 3, 1, 1);

        btn_e = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_e);
        btn_e->setObjectName(QStringLiteral("btn_e"));
        btn_e->setFont(font);
        btn_e->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_e, 0, 4, 1, 1);

        btn_f = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_f);
        btn_f->setObjectName(QStringLiteral("btn_f"));
        btn_f->setFont(font);
        btn_f->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_f, 0, 5, 1, 1);

        btn_g = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_g);
        btn_g->setObjectName(QStringLiteral("btn_g"));
        btn_g->setFont(font);
        btn_g->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_g, 0, 6, 1, 1);

        btn_7 = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_7);
        btn_7->setObjectName(QStringLiteral("btn_7"));
        btn_7->setFont(font);
        btn_7->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_7, 0, 7, 1, 1);

        btn_8 = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_8);
        btn_8->setObjectName(QStringLiteral("btn_8"));
        btn_8->setFont(font);
        btn_8->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_8, 0, 8, 1, 1);

        btn_9 = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_9);
        btn_9->setObjectName(QStringLiteral("btn_9"));
        btn_9->setFont(font);
        btn_9->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_9, 0, 9, 1, 1);

        btn_h = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_h);
        btn_h->setObjectName(QStringLiteral("btn_h"));
        btn_h->setFont(font);
        btn_h->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_h, 1, 0, 1, 1);

        btn_i = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_i);
        btn_i->setObjectName(QStringLiteral("btn_i"));
        btn_i->setFont(font);
        btn_i->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_i, 1, 1, 1, 1);

        btn_j = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_j);
        btn_j->setObjectName(QStringLiteral("btn_j"));
        btn_j->setFont(font);
        btn_j->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_j, 1, 2, 1, 1);

        btn_k = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_k);
        btn_k->setObjectName(QStringLiteral("btn_k"));
        btn_k->setFont(font);
        btn_k->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_k, 1, 3, 1, 1);

        btn_l = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_l);
        btn_l->setObjectName(QStringLiteral("btn_l"));
        btn_l->setFont(font);
        btn_l->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_l, 1, 4, 1, 1);

        btn_m = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_m);
        btn_m->setObjectName(QStringLiteral("btn_m"));
        btn_m->setFont(font);
        btn_m->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_m, 1, 5, 1, 1);

        btn_n = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_n);
        btn_n->setObjectName(QStringLiteral("btn_n"));
        btn_n->setFont(font);
        btn_n->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_n, 1, 6, 1, 1);

        btn_4 = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_4);
        btn_4->setObjectName(QStringLiteral("btn_4"));
        btn_4->setFont(font);
        btn_4->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_4, 1, 7, 1, 1);

        btn_5 = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_5);
        btn_5->setObjectName(QStringLiteral("btn_5"));
        btn_5->setFont(font);
        btn_5->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_5, 1, 8, 1, 1);

        btn_6 = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_6);
        btn_6->setObjectName(QStringLiteral("btn_6"));
        btn_6->setFont(font);
        btn_6->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_6, 1, 9, 1, 1);

        btn_o = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_o);
        btn_o->setObjectName(QStringLiteral("btn_o"));
        btn_o->setFont(font);
        btn_o->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_o, 2, 0, 1, 1);

        btn_p = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_p);
        btn_p->setObjectName(QStringLiteral("btn_p"));
        btn_p->setFont(font);
        btn_p->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_p, 2, 1, 1, 1);

        btn_q = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_q);
        btn_q->setObjectName(QStringLiteral("btn_q"));
        btn_q->setFont(font);
        btn_q->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_q, 2, 2, 1, 1);

        btn_r = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_r);
        btn_r->setObjectName(QStringLiteral("btn_r"));
        btn_r->setFont(font);
        btn_r->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_r, 2, 3, 1, 1);

        btn_s = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_s);
        btn_s->setObjectName(QStringLiteral("btn_s"));
        btn_s->setFont(font);
        btn_s->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_s, 2, 4, 1, 1);

        btn_t = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_t);
        btn_t->setObjectName(QStringLiteral("btn_t"));
        btn_t->setFont(font);
        btn_t->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_t, 2, 5, 1, 1);

        btn_u = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_u);
        btn_u->setObjectName(QStringLiteral("btn_u"));
        btn_u->setFont(font);
        btn_u->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_u, 2, 6, 1, 1);

        btn_1 = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_1);
        btn_1->setObjectName(QStringLiteral("btn_1"));
        btn_1->setFont(font);
        btn_1->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_1, 2, 7, 1, 1);

        btn_2 = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_2);
        btn_2->setObjectName(QStringLiteral("btn_2"));
        btn_2->setFont(font);
        btn_2->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_2, 2, 8, 1, 1);

        btn_3 = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_3);
        btn_3->setObjectName(QStringLiteral("btn_3"));
        btn_3->setFont(font);
        btn_3->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_3, 2, 9, 1, 1);

        btn_shift = new QPushButton(centralwidget);
        btn_shift->setObjectName(QStringLiteral("btn_shift"));
        btn_shift->setFont(font);
        btn_shift->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_shift, 3, 0, 1, 1);

        btn_v = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_v);
        btn_v->setObjectName(QStringLiteral("btn_v"));
        btn_v->setFont(font);
        btn_v->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_v, 3, 1, 1, 1);

        btn_w = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_w);
        btn_w->setObjectName(QStringLiteral("btn_w"));
        btn_w->setFont(font);
        btn_w->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_w, 3, 2, 1, 1);

        btn_x = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_x);
        btn_x->setObjectName(QStringLiteral("btn_x"));
        btn_x->setFont(font);
        btn_x->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_x, 3, 3, 1, 1);

        btn_y = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_y);
        btn_y->setObjectName(QStringLiteral("btn_y"));
        btn_y->setFont(font);
        btn_y->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_y, 3, 4, 1, 1);

        btn_z = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_z);
        btn_z->setObjectName(QStringLiteral("btn_z"));
        btn_z->setFont(font);
        btn_z->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_z, 3, 5, 1, 1);

        btn_hide = new QPushButton(centralwidget);
        btn_hide->setObjectName(QStringLiteral("btn_hide"));
        btn_hide->setFont(font);
        btn_hide->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_hide, 3, 6, 1, 1);

        btn_backup = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_backup);
        btn_backup->setObjectName(QStringLiteral("btn_backup"));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(20);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        btn_backup->setFont(font1);
        btn_backup->setFocusPolicy(Qt::NoFocus);
        btn_backup->setStyleSheet(QStringLiteral("font: 20pt \"Arial\";"));

        gridLayout->addWidget(btn_backup, 3, 7, 1, 1);

        btn_0 = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_0);
        btn_0->setObjectName(QStringLiteral("btn_0"));
        btn_0->setFont(font);
        btn_0->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn_0, 3, 8, 1, 1);

        btn_dot = new QPushButton(centralwidget);
        buttonGroup->addButton(btn_dot);
        btn_dot->setObjectName(QStringLiteral("btn_dot"));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(20);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(9);
        btn_dot->setFont(font2);
        btn_dot->setFocusPolicy(Qt::NoFocus);
        btn_dot->setStyleSheet(QStringLiteral("font: 75 20pt \"Arial\";"));

        gridLayout->addWidget(btn_dot, 3, 9, 1, 1);

        KeyBoardWindow->setCentralWidget(centralwidget);

        retranslateUi(KeyBoardWindow);

        QMetaObject::connectSlotsByName(KeyBoardWindow);
    } // setupUi

    void retranslateUi(QMainWindow *KeyBoardWindow)
    {
        KeyBoardWindow->setWindowTitle(QApplication::translate("KeyBoardWindow", "MainWindow", Q_NULLPTR));
        btn_a->setText(QApplication::translate("KeyBoardWindow", "a", Q_NULLPTR));
        btn_b->setText(QApplication::translate("KeyBoardWindow", "b", Q_NULLPTR));
        btn_c->setText(QApplication::translate("KeyBoardWindow", "c", Q_NULLPTR));
        btn_d->setText(QApplication::translate("KeyBoardWindow", "d", Q_NULLPTR));
        btn_e->setText(QApplication::translate("KeyBoardWindow", "e", Q_NULLPTR));
        btn_f->setText(QApplication::translate("KeyBoardWindow", "f", Q_NULLPTR));
        btn_g->setText(QApplication::translate("KeyBoardWindow", "g", Q_NULLPTR));
        btn_7->setText(QApplication::translate("KeyBoardWindow", "7", Q_NULLPTR));
        btn_8->setText(QApplication::translate("KeyBoardWindow", "8", Q_NULLPTR));
        btn_9->setText(QApplication::translate("KeyBoardWindow", "9", Q_NULLPTR));
        btn_h->setText(QApplication::translate("KeyBoardWindow", "h", Q_NULLPTR));
        btn_i->setText(QApplication::translate("KeyBoardWindow", "i", Q_NULLPTR));
        btn_j->setText(QApplication::translate("KeyBoardWindow", "j", Q_NULLPTR));
        btn_k->setText(QApplication::translate("KeyBoardWindow", "k", Q_NULLPTR));
        btn_l->setText(QApplication::translate("KeyBoardWindow", "l", Q_NULLPTR));
        btn_m->setText(QApplication::translate("KeyBoardWindow", "m", Q_NULLPTR));
        btn_n->setText(QApplication::translate("KeyBoardWindow", "n", Q_NULLPTR));
        btn_4->setText(QApplication::translate("KeyBoardWindow", "4", Q_NULLPTR));
        btn_5->setText(QApplication::translate("KeyBoardWindow", "5", Q_NULLPTR));
        btn_6->setText(QApplication::translate("KeyBoardWindow", "6", Q_NULLPTR));
        btn_o->setText(QApplication::translate("KeyBoardWindow", "o", Q_NULLPTR));
        btn_p->setText(QApplication::translate("KeyBoardWindow", "p", Q_NULLPTR));
        btn_q->setText(QApplication::translate("KeyBoardWindow", "q", Q_NULLPTR));
        btn_r->setText(QApplication::translate("KeyBoardWindow", "r", Q_NULLPTR));
        btn_s->setText(QApplication::translate("KeyBoardWindow", "s", Q_NULLPTR));
        btn_t->setText(QApplication::translate("KeyBoardWindow", "t", Q_NULLPTR));
        btn_u->setText(QApplication::translate("KeyBoardWindow", "u", Q_NULLPTR));
        btn_1->setText(QApplication::translate("KeyBoardWindow", "1", Q_NULLPTR));
        btn_2->setText(QApplication::translate("KeyBoardWindow", "2", Q_NULLPTR));
        btn_3->setText(QApplication::translate("KeyBoardWindow", "3", Q_NULLPTR));
        btn_shift->setText(QApplication::translate("KeyBoardWindow", "shift", Q_NULLPTR));
        btn_v->setText(QApplication::translate("KeyBoardWindow", "v", Q_NULLPTR));
        btn_w->setText(QApplication::translate("KeyBoardWindow", "w", Q_NULLPTR));
        btn_x->setText(QApplication::translate("KeyBoardWindow", "x", Q_NULLPTR));
        btn_y->setText(QApplication::translate("KeyBoardWindow", "y", Q_NULLPTR));
        btn_z->setText(QApplication::translate("KeyBoardWindow", "z", Q_NULLPTR));
        btn_hide->setText(QApplication::translate("KeyBoardWindow", "Enter", Q_NULLPTR));
        btn_backup->setText(QApplication::translate("KeyBoardWindow", "\342\206\220", Q_NULLPTR));
        btn_0->setText(QApplication::translate("KeyBoardWindow", "0", Q_NULLPTR));
        btn_dot->setText(QApplication::translate("KeyBoardWindow", ".", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class KeyBoardWindow: public Ui_KeyBoardWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYBOARDWINDOW_H
