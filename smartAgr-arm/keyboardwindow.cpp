#include "keyboardwindow.h"
#include "ui_keyboardwindow.h"

KeyBoardWindow::KeyBoardWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KeyBoardWindow)
{
    ui->setupUi(this);
    ui->btn_shift->setCheckable(true);
    connect(ui->buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(onButtonClicked(int)));
}

KeyBoardWindow::~KeyBoardWindow()
{
    delete ui;
}


void KeyBoardWindow::onButtonClicked(int id)
{
    QAbstractButton *btn = ui->buttonGroup->button(id);
    QLineEdit* edit = qobject_cast<QLineEdit*>(QApplication::focusWidget());
    if (edit == 0)
        return;

    if (btn->objectName() == ui->btn_backup->objectName())
    {
        edit->backspace();
    }
    else
    {
        edit->insert(btn->text());
    }
}



void KeyBoardWindow::on_btn_shift_clicked(bool checked)
{
    QList<QAbstractButton*> btn_list = ui->buttonGroup->buttons();
    if (checked)
    {
        for (int i = 0; i < btn_list.size(); ++i)
        {
            btn_list.at(i)->setText(btn_list.at(i)->text().toUpper());
        }
    }
    else
    {
        for (int i = 0; i < btn_list.size(); ++i)
        {
            btn_list.at(i)->setText(btn_list.at(i)->text().toLower());
        }
    }

}


void KeyBoardWindow::on_btn_hide_clicked()
{
    this->hide();
}


