#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include "protocol.h"
#include "monitorwindow.h"
#include "settingwindow.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initSocket();
    QTcpSocket *getSocket();
    void initLoginDlg();
    void initMonitorWnd();
    void initSettingWnd();

    void setCRC16(unsigned char *BytesFrame, int length);
    int checkCRC(unsigned char *BytesFrame, int length);
    void recvLoginStatus(unsigned char *data);
    void recvRegisterStatus(unsigned char *data);
    void recvSettings(unsigned char *data);
    void recvSettingAmount(int area_num, int node_num); // area_num, node_num
    void recvSettingZid(int zid, int aid); // zid, aid
    void recvSettingThreshold(int dev_type, int down_value, int up_value); // dev-type, down_value, up_value

    bool analysisSerailDatas(unsigned char *datas, int len);
//    void showDatas();
    void sendDatas(unsigned char *datas, int len);


    void printFrame(unsigned char *frame);
    void querySettings();


    void saveSettingAmount();
    // 保存zid-aid
    void saveSettingZigbee();
    // 保存threshold
    void saveSettingThreshold();
    void saveSettingLampThreshold();
    void saveSettingHumiThreshold();
    void saveSettingFanThreshold();
    void saveSettingCurtainThreshold();

signals:
    void sigSetAckDialog(AckStatus st);

/// [槽函数]
private slots:
    void onCloseApp();
    void onConnected();
    void onError();
    void onReadSocket();
    void onDevInfoToServer(int zid, int aid);

    void onLogin(CmdType user_cmd ,QString username, QString pwd);
    void onRegister(CmdType user_cmd, QString username, QString pwd);

    void onControlDevice(int aid, DevType dev_type, DataType data_type, int status);

    /*
     * @brief 读取系统配置，发送到服务器
    */
    void onSaveSettings();
    void on_btn_monitor_clicked();

    void on_btn_control_clicked();

    void on_btn_setting_clicked();



private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QString server_ip;
    short server_port;
    bool isConnected = false;

    QString username;
    QString pwd;
    CmdType user_cmd;

    MonitorWindow *monitorWnd;
    QMap<QString, int> datas_map;

    SettingWindow *settingWnd;

    bool has_head_socket = false;
    unsigned char frame_socket[256] = {0};
    int len_frame_socket = 0;
};

#endif // MAINWINDOW_H
