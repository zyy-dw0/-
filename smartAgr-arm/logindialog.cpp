#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <QSettings>
#include "keyboardwindow.h"
#include <QDebug>
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->btn_toregister->hide();
    ui->stackedWidget->setCurrentWidget(ui->page_login);
    ui->edit_lusername->installEventFilter(this);
    ui->edit_lpwd->installEventFilter(this);
    ui->edit_server_ip->installEventFilter(this);
    ui->edit_server_port->installEventFilter(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::setAckDialog(AckStatus status)
{
    switch (status) {
    case AckStatus::ELOGIN:
        QMessageBox::information(this, "提示", "登录失败，请重试");
        ui->btn_login->setEnabled(true);
        break;
    case AckStatus::OLOGIN:
        this->close();
        break;
    case AckStatus::ENETWORK:
        QMessageBox::information(this, "提示", "网络错误，请联系网络管理员！");
        ui->btn_login->setEnabled(true);
        ui->btn_register->setEnabled(true);
        break;
    case AckStatus::EREGISTER:
        QMessageBox::information(this, "提示", "注册失败，请重试!");
        ui->btn_register->setEnabled(true);
        break;
    case AckStatus::OREGISTER:
        QMessageBox::information(this, "提示", "注册成功，可以返回登录了！");
        ui->btn_register->setEnabled(true);
        on_btn_rcancle_clicked();
        ui->stackedWidget->setCurrentWidget(ui->page_login);
        break;
    default:
        break;
    }
}


void LoginDialog::on_btn_cancle_clicked()
{
    ui->edit_lusername->clear();
    ui->edit_lpwd->clear();
}

// 登录按钮
void LoginDialog::on_btn_login_clicked()
{
    QString username = ui->edit_lusername->text();
    QString pwd = ui->edit_lpwd->text();

    if (username.size()>6 || username.isEmpty() || pwd.size()>6 || pwd.isEmpty())
    {
        QMessageBox::warning(this, "提示", "用户名或密码不能为空，且长度不能超过6！");
        return;
    }
    ui->btn_login->setEnabled(false);
    bool online = ui->radio_online->isChecked()? true : false;
    emit sigLogin(CmdType::LOGIN_USER, username, pwd, online);
}

void LoginDialog::on_btn_tologin_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_login);
}

void LoginDialog::on_btn_toregister_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_register);
}

// 注册按钮
void LoginDialog::on_btn_register_clicked()
{
    QString username = ui->edit_rusername->text();
    QString pwd = ui->edit_rpwd->text();
    QString pwd2 = ui->edit_rpwd_2->text();

    if (username.size()>6 || username.isEmpty() || pwd.size()>6 || pwd.isEmpty())
    {
        QMessageBox::warning(this, "提示", "用户名或密码不能为空，且长度不能超过6！");
        return;
    }
    if (pwd2 != pwd)
    {
        QMessageBox::warning(this, "提示", "两次密码不一致，请重试！");
        return;
    }
    ui->btn_register->setEnabled(false);

    emit sigRegister(CmdType::REGISTER_USER, username, pwd);
}

void LoginDialog::on_btn_rcancle_clicked()
{
    ui->edit_rusername->clear();
    ui->edit_rpwd->clear();
    ui->edit_rpwd_2->clear();
}




bool LoginDialog::eventFilter(QObject *watched, QEvent *event)
{
    QLineEdit *edit = qobject_cast<QLineEdit*>(watched);
    if ((edit != 0) && (event->type() == QEvent::MouseButtonPress))
    {
        KeyBoardWindow &kb = KeyBoardWindow::getKeyBoard();
        kb.setParent(this);
        if (edit->y() >= 240)
            kb.move(0, 0);
        else
            kb.move(0, 300);

        kb.show();
    }

    return QDialog::eventFilter(watched, event);
}





void LoginDialog::on_btn_scancle_clicked()
{
    ui->edit_server_ip->clear();
    ui->edit_server_port->clear();
}

void LoginDialog::on_btn_sreturn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_login);
}

void LoginDialog::on_btn_save_server_clicked()
{
    QString ip = ui->edit_server_ip->text();
    QString port = ui->edit_server_port->text();
    QSettings setting("alg.ini", QSettings::IniFormat);
    setting.beginGroup("server");
    setting.setValue("ip", ip);
    setting.setValue("port", port);
    setting.endGroup();
    QMessageBox::information(this, "提示", "设置完成，请重启程序，以使配置生效！");
    QApplication::exit(0);
}

void LoginDialog::on_btn_to_setserver_clicked()
{
    QSettings setting("alg.ini", QSettings::IniFormat);
    setting.beginGroup("server");
    QString ip = setting.value("ip").toString();
    QString port = setting.value("port").toString();
    setting.endGroup();

    if (!ip.isEmpty() && !port.isEmpty())
    {
        ui->edit_server_ip->setText(ip);
        ui->edit_server_port->setText(port);
    }

    ui->stackedWidget->setCurrentWidget(ui->page_server);
}




