#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QSerialPort>
#include "logindialog.h"
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
    void initLoginDlg();
    void initMonitorWnd();
    void initSettingWnd();

    void setCRC16(unsigned char *BytesFrame, int length);
    int checkCRC(unsigned char *BytesFrame, int length);
    void recvLoginStatus(unsigned char *data, int len);
    void recvRegisterStatus(unsigned char *data, int len);
    void recvSettings(unsigned char *data, int len);
    void recvSettingAmount(int area_num, int node_num); // area_num, node_num
    void recvSettingZid(int zid, int aid); // zid, aid
    void recvSettingThreshold(int dev_type, int down_value, int up_value); // dev-type, down_value, up_value


    void initSerial();
    bool analysisSerailDatas(unsigned char *datas, int len);


    /*
    @brief 把串口数据显示到本地
    */
    void serialDataToLocal(unsigned char *data, int len);
    /*
    @brief 把串口数据发送到服务器
    */
    void serialDataToServer(unsigned char *data, int len);

    /*
    @brief: 发送 修改设备状态 的指令到 串口 再到 zigbee
    @param: data 收到的数据帧
    @param: len 数据帧总长度
    */
    void changeDeviceState(unsigned char* data, int len);
    void printFrame(unsigned char *data, int len, char sep=' ');

    void saveSettingAmount();
    // 保存zid-aid
    void saveSettingZigbee();
    // 保存threshold
    void saveSettingThreshold();
    void saveSettingLampThreshold();
    void saveSettingHumiThreshold();
    void saveSettingFanThreshold();
    void saveSettingCurtainThreshold();

    void querySettings();
//////////////////////////// 槽函数 /////////////////////////////////////
private slots:
    void onConnected();
    void onError(QAbstractSocket::SocketError err);

    /*
    @brief 从 套接字 读取数据
    */
    void onReadSocket();

    /*
    @brief 从 串口 读取数据
    */
    void onReadSerial();

    void onControlDevice(int zid, DevType dev_type, DataType data_type, int status);
    void onLogin(CmdType user_cmd , QString username, QString pwd, bool online);
    void onRegister(CmdType user_cmd, QString username, QString pwd);
    /*
    @brief 读取本地系统配置，发送到服务器
    */
    void onSaveSettings();

    void on_btn_monitor_clicked();

    void on_btn_control_clicked();

    void on_btn_setting_clicked();



private:
    Ui::MainWindow *ui;
    bool online;
    QTcpSocket *socket;
    QString server_ip;
    short server_port;
    bool isConnected = false;

    LoginDialog *loginDlg;
    QString username;
    QString pwd;
    CmdType user_cmd;

    MonitorWindow *monitorWnd;
    QMap<QString, int> datas_map;

    SettingWindow *settingWnd;

    QSerialPort *serial;

    bool has_head_serial = false;
    unsigned char frame_serial[256] = {0};
    int index_frame_serial = 0;
    int len_frame_serial = 0;

    bool has_head_socket = false;
    unsigned char frame_socket[256] = {0};
    int len_frame_socket = 0;


};

#endif // MAINWINDOW_H
