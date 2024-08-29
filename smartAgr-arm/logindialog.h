#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "protocol.h"
#include <QLineEdit>

namespace Ui {
class LoginDialog;
}

enum AckStatus
{
    ENETWORK,
    ELOGIN,
    EREGISTER,
    OLOGIN,
    OREGISTER
};

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();



    void setAckDialog(AckStatus status);
signals:
    void sigLogin(CmdType cmd_type, QString username, QString pwd, bool online);
    void sigRegister(CmdType cmd_type, QString username, QString pwd);

private slots:
    void on_btn_cancle_clicked();

    void on_btn_login_clicked();

    void on_btn_tologin_clicked();

    void on_btn_toregister_clicked();

    void on_btn_register_clicked();

    void on_btn_rcancle_clicked();



    void on_btn_scancle_clicked();
    void on_btn_sreturn_clicked();
    void on_btn_save_server_clicked();
    void on_btn_to_setserver_clicked();
private:
    Ui::LoginDialog *ui;


    // QObject interface
public:
    virtual bool eventFilter(QObject *watched, QEvent *event) override;
};

#endif // LOGINDIALOG_H
