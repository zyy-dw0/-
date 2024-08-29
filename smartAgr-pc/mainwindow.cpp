#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <stdio.h>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), socket(nullptr), settingWnd(nullptr), monitorWnd(nullptr)
{
    ui->setupUi(this);
    this->setFixedSize(800, 480);

    initSocket();
    initSettingWnd();
}

MainWindow::~MainWindow()
{
    delete settingWnd;
    delete monitorWnd;
    delete ui;
}



// 初始化套接接
void MainWindow::initSocket()
{
    QSettings setting("alg.ini", QSettings::IniFormat);
    setting.beginGroup("server");
    server_ip = setting.value("ip", "").toString();  //;
    server_port = setting.value("port", 10025).toInt();
    setting.endGroup();
    qDebug() << "ip = " << server_ip ;
    qDebug() << "port = " << server_port;
    isConnected = false;

    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::connected, this, &MainWindow::onConnected);
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError()));
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::onReadSocket);

}

QTcpSocket *MainWindow::getSocket()
{
    return this->socket;
}

// 初始化监测界面
void MainWindow::initMonitorWnd()
{
    monitorWnd = new MonitorWindow;
    connect(monitorWnd, &MonitorWindow::sigDevInfoToServer, this, &MainWindow::onDevInfoToServer);
    connect(monitorWnd, &MonitorWindow::sigShowMainWnd, this, &MainWindow::show);
    connect(monitorWnd, &MonitorWindow::sigControlDevice, this, &MainWindow::onControlDevice);
}

void MainWindow::initSettingWnd()
{
    settingWnd = new SettingWindow;
    connect(settingWnd, &SettingWindow::sigShowMainWnd, this, &MainWindow::show);
    connect(settingWnd, &SettingWindow::sigSaveSettings, this, &MainWindow::onSaveSettings);
}

// 连接服务器成功，发数据到服务器
void MainWindow::onConnected()
{
    qDebug() << "connect server ok!";
    if (user_cmd == CmdType::LOGIN_USER || user_cmd == CmdType::REGISTER_USER)
    {
        unsigned char cmd_type = static_cast<unsigned char>(this->user_cmd);
        unsigned char frame[21] = {0};
        frame[0] = 0x7e;
        frame[1] = 21;
        frame[2] = cmd_type;
        frame[6] = 12;  // 数据长度

        for (int i = 0; i < username.size(); ++i)
        {
            frame[7+i] = username.toUtf8().at(i);
        }
        for (int i = 0; i < pwd.size(); ++i)
        {
            frame[13+i] = pwd.toUtf8().at(i);
        }
        setCRC16(frame, 21);
        int wr = socket->write((const char*)frame,21);
        qDebug() << "wr = " << wr;
    }

}

// 网络错误
void MainWindow::onError()
{
    qDebug() << "network error: " << socket->errorString();
    if (socket->state() == QAbstractSocket::UnconnectedState)
    {
        emit sigSetAckDialog(AckStatus::ENETWORK);
    }

}

// 读套接接
void MainWindow::onReadSocket()
{
    while (socket->bytesAvailable() > 0)
    {
        if (!has_head_socket)
        {
            if (socket->bytesAvailable() < 2) // 头都不齐，不读，存着
                return;
            socket->read((char*)frame_socket, 2);
            len_frame_socket = frame_socket[1];
            has_head_socket = true;
        }
        qDebug() << "len_frame_socket = " << len_frame_socket;
        if (socket->bytesAvailable() < len_frame_socket-2) // 不够一帧，存着
            return;

        socket->read((char*)frame_socket+2, len_frame_socket-2);

        CmdType cmd_type = static_cast<CmdType>(frame_socket[2]);
        switch (cmd_type) {
        case CmdType::LOGIN_USER:           // 用户登录
            recvLoginStatus(frame_socket);
            break;
        case CmdType::REGISTER_USER:        // 用户注册
            recvRegisterStatus(frame_socket);
            break;
        case CmdType::QUERY_DEVICE:
            monitorWnd->saveDeviceInfo(frame_socket, len_frame_socket);
            break;
        case CmdType::QUERY_SETTING:
            recvSettings(frame_socket);
            break;
        case CmdType::DOWNLOAD_REALTIME:    // 下载实时数据 aid dtype  value
//            qDebug() << "recv real data: " << zid;
            monitorWnd->recvDatas(frame_socket, len_frame_socket);
            break;
        case CmdType::CHANGE_ZIGBEE_ADDR:   // 保存zigbee地址
            monitorWnd->handleSaveDevStatus(frame_socket, len_frame_socket); // zid, data_type,status
            break;

        default:
            break;
        }
        // 重置数据帧
        memset(frame_socket, 0, sizeof(frame_socket));
        len_frame_socket = 0;
        has_head_socket = false;
    }
}

// 发送zid与区域id到服务器，设置或取消设置
void MainWindow::onDevInfoToServer(int zid, int aid)
{
    DataType dtype = DataType::SET_ZIGBEE;
    if (zid < 0)
    { // 如果zid为负，表示此节点不再绑定到某区域，区域值用0表示
        aid = 0;
        zid = qAbs(zid);
        dtype = DataType::RESET_ZIGBEE;
    }
    qDebug() << "ready send zid_aid: " << zid << "_" << aid;
    if (socket->isValid())
    {
        unsigned char frame[21] = {0};
        frame[0] = 0x7e;    // 包头
        frame[1] = 21;
        frame[2] = static_cast<unsigned char>(CmdType::CHANGE_ZIGBEE_ADDR); // 指令类型
        frame[3] = zid & 0xff;      // zid
        frame[4] = (zid>>8) & 0xff;
        frame[5] = static_cast<unsigned char>(dtype); // 数据类型
        frame[6] = 0x04;            // 数据长度 4
        frame[7] = aid & 0xff;      // 区域id
        frame[8] = (aid>>8) & 0xff;
        frame[9] = (aid>>16) & 0xff;
        frame[10] = (aid>>24) & 0xff;
        setCRC16(frame, 21);
        socket->write((const char*)frame, 21);

        printFrame(frame);
    }
}



void MainWindow::printFrame(unsigned char* frame)
{
    QByteArray arr((const char*)frame, 21);
    qDebug() << arr;
}

// 接收登录的返回状态，做进一步处理
void MainWindow::recvLoginStatus(unsigned char* data)
{
    bool state = data[7];
    if (!state)
    {
        // 登录失败
        emit sigSetAckDialog(AckStatus::ELOGIN);
        socket->disconnectFromHost();
    }
    else
    {
        // 登录成功
        this->show();
        emit sigSetAckDialog(AckStatus::OLOGIN);
        // 登录成功后，从服务器配置信息
        querySettings();
    }
}

// 登录成功后，从服务器查询设备信息
void MainWindow::querySettings()
{
    unsigned char frame[21] = {0};
    frame[0] = 0x7e;
    frame[1] = 21;
    frame[2] = static_cast<unsigned char>(CmdType::QUERY_SETTING); // 指令类型
    setCRC16(frame, 21);
    socket->write((const char*)frame, 21);
}



// 接收注册的返回状态，做进一步处理
void MainWindow::recvRegisterStatus(unsigned char *data)
{
    bool state = data[7];
    if (!state)
    {
        // 注册失败
        emit sigSetAckDialog(AckStatus::EREGISTER);
        socket->disconnectFromHost();
    }
    else
    {
        // 注册成功
        emit sigSetAckDialog(AckStatus::OREGISTER);
        socket->disconnectFromHost();
    }
}

// 接受配置信息
void MainWindow::recvSettings(unsigned char *data)
{
    DataType data_type = static_cast<DataType>(data[5]);
    switch (data_type) {
    case DataType::SET_AMOUNT:
        recvSettingAmount(data[7], data[8]|data[9]<<8); // area_num, node_num
        initMonitorWnd(); // 接受到数量的配置信息后，再初始化监控界面
        break;
    case DataType::SET_ZIGBEE:
        recvSettingZid(data[3]|data[4]<<8, data[11]); // zid, aid
        break;
    case DataType::LAMP_THRESHOLD:
    case DataType::HUMI_THRESHOLD:
    case DataType::FAN_THRESHOLD:
    case DataType::CURTAIN_THRESHOLD:
        recvSettingThreshold(data[12], data[7]|data[8]<<8, data[9]|data[10]<<8); // dev-type, down_value, up_value
        break;
    default:
        break;
    }
}

void MainWindow::recvSettingAmount(int area_num, int node_num)
{
    QSettings setting("alg.ini", QSettings::IniFormat);
    setting.beginGroup("amount");
    setting.setValue("area_num", area_num);
    setting.setValue("node_num", node_num);
    setting.endGroup();
}

void MainWindow::recvSettingZid(int zid, int aid)
{
    QSettings setting("alg.ini", QSettings::IniFormat);
    setting.beginGroup("zid-aid");
    setting.setValue(QString::number(zid), aid);
    setting.endGroup();
}

void MainWindow::recvSettingThreshold(int dev_type, int down_value, int up_value)
{
    QSettings setting("alg.ini", QSettings::IniFormat);
    setting.beginGroup("threshold");
    switch (dev_type) {
    case DevType::ACTUATOR_LAMP:
        setting.setValue("lamp_down", down_value);
        setting.setValue("lamp_up", up_value);
        break;
    case DevType::ACTUATOR_HUMI:
        setting.setValue("humi_down", down_value);
        setting.setValue("humi_up", up_value);
        break;

    case DevType::ACTUATOR_FAN:
        setting.setValue("fan_down", down_value);
        setting.setValue("fan_up", up_value);
        break;

    case DevType::ACTUATOR_CURTAIN:
        setting.setValue("curtain_down", down_value);
        setting.setValue("curtain_up", up_value);
        break;

    default:
        break;
    }
    setting.endGroup();
}

// 收到登录请求，连接服务器
void MainWindow::onLogin(CmdType user_cmd, QString username, QString pwd)
{
    this->username = username;
    this->pwd = pwd;
    this->user_cmd = user_cmd;
    socket->connectToHost(server_ip, server_port);

}

// 接收到界面的注册请求
void MainWindow::onRegister(CmdType user_cmd, QString username, QString pwd)
{
    this->username = username;
    this->pwd = pwd;
    this->user_cmd = user_cmd;
    socket->connectToHost(server_ip, server_port);
}

// 检测校验
int MainWindow::checkCRC(unsigned char *BytesFrame,int length)
{
    int Preset_Value = 0xFFFF;
    int Polynomial = 0xA001;
    for (int i = 0; i < length - 2; i++)
    {
        Preset_Value ^= (BytesFrame[i] & 0xff);
        for (int j = 0; j < 8; j++)
        {
            if ((Preset_Value & 0x0001) != 0)
            {
                Preset_Value = (Preset_Value >> 1) ^ Polynomial;
            }
            else
            {
                Preset_Value = (Preset_Value >> 1);
            }
        }
    }
    unsigned char retH = (unsigned char) ((Preset_Value & 0xFF00) >> 8);
    unsigned char retL = (unsigned char) (Preset_Value & 0xFF);
    if (retL == BytesFrame[length - 2] && retH == BytesFrame[length - 1])
        return 1;
    else
        return 0;
}
// 设置校验
void MainWindow::setCRC16(unsigned char *BytesFrame, int length)
{
    int Preset_Value = 0xFFFF;
    int Polynomial = 0xA001;
    for (int i = 0; i < length - 2; i++)
    {
        Preset_Value ^= (BytesFrame[i] & 0xff);
        for (int j = 0; j < 8; j++)
        {
            if ((Preset_Value & 0x0001) != 0)
            {
                Preset_Value = (Preset_Value >> 1) ^ Polynomial;
            }
            else
            {
                Preset_Value = (Preset_Value >> 1);
            }
        }
    }
    BytesFrame[length - 2] = (unsigned char) (Preset_Value & 0xFF);
    BytesFrame[length - 1] = (unsigned char) ((Preset_Value & 0xFF00) >> 8);
}

// 显示监测界面
void MainWindow::on_btn_monitor_clicked()
{
    monitorWnd->myShow(0);
    this->hide();
}





// 发送到数据服务器
void MainWindow::sendDatas(unsigned char *datas, int len)
{
    if (socket->isValid())
    {
        setCRC16(datas, len);
        for (int i = 0; i < 21; i++)
        {
            printf("%x ", datas[i]);
        }
        printf("\n");
        int r = socket->write((const char*)datas, len);
//        qDebug() << "send bytes: " << r;
        if (r <= 0)
        {
            qDebug() << "send error: " << socket->errorString();
        }
    }
}


void MainWindow::on_btn_control_clicked()
{
    monitorWnd->myShow(1);
    this->hide();
}



void MainWindow::onControlDevice(int aid, DevType dev_type, DataType data_type, int status)
{

    qDebug() << aid << ", " << (int) dev_type << ", " << status;
    unsigned char frame[21] = {0};
    frame[0] = 0x7e;
    frame[1] = 21;
    frame[2] = static_cast<unsigned char>( CmdType::CHANGE_DEVICE_STATE);
    frame[5] = static_cast<unsigned char>(data_type);
    frame[6] = 1;
    frame[7] = status;
    frame[11] = aid;
    frame[12] = static_cast<unsigned char>(dev_type);
    setCRC16(frame, 21);
    socket->write((const char*)&frame, 21);
    qDebug() << __FUNCTION__ << ": " << __LINE__;


}

// 提交配置信息到服务器
void MainWindow::onSaveSettings()
{
    // 保存amount
    saveSettingAmount();
    // 保存zid-aid
    saveSettingZigbee();
    // 保存threshold
    saveSettingThreshold();

    QMessageBox::information(this, "提示", "配置提交成功！请重启程序，以让配置生效！");
    QApplication::exit();
}


// 进入 系统设置 界面
void MainWindow::on_btn_setting_clicked()
{
    this->hide();
    settingWnd->loadSettings();
}

// 数量设置提交
void MainWindow::saveSettingAmount()
{
    QSettings setting("alg.ini", QSettings::IniFormat);
    setting.beginGroup("amount");
    int area_num = setting.value("area_num").toInt();
    int node_num = setting.value("node_num").toInt();
    setting.endGroup();

    unsigned char frame[21] = {0};
    frame[0] = 0x7e;
    frame[1] = 21;
    frame[2] = static_cast<unsigned char>(CmdType::CHANGE_SETTING); // 指令类型
    frame[5] = static_cast<unsigned char>(DataType::SET_AMOUNT);    // 数据类型
    frame[6] = 3;                                                   // 数据长度
    frame[7] = area_num;                                            // 区域数量(1B)
    frame[8] = node_num & 0xff;                                     // 节点数量(2B)
    frame[9] = (node_num>>8) & 0xff;
    setCRC16(frame, sizeof(frame));
    socket->write((const char*)frame, sizeof(frame));
}

// zid-aid设置提交
void MainWindow::saveSettingZigbee()
{
    QSettings setting("alg.ini", QSettings::IniFormat);
    setting.beginGroup("zid-aid");
    QStringList zids = setting.allKeys();


    unsigned char frame[21] = {0};
    frame[0] = 0x7e;
    frame[1] = 21;
    frame[2] = static_cast<unsigned char>(CmdType::CHANGE_SETTING); // 指令类型
    frame[5] = static_cast<unsigned char>(DataType::SET_ZIGBEE);    // 数据类型

    for (int i = 0; i < zids.size(); ++i)
    {
        QString zid = zids.at(i);
        int aid = setting.value(zid).toInt();
        frame[3] = zid.toInt() & 0xff;
        frame[4] = (zid.toInt()>>8) & 0xff;
        frame[11] = aid;
        setCRC16(frame, sizeof(frame));
        socket->write((const char*)frame, sizeof(frame));
    }

    setting.endGroup();
}

// 阈值设置提交
void MainWindow::saveSettingThreshold()
{
    saveSettingLampThreshold();
    saveSettingHumiThreshold();
    saveSettingFanThreshold();
    saveSettingCurtainThreshold();
}

// 补光灯的阈值提交
void MainWindow::saveSettingLampThreshold()
{
    QSettings setting("alg.ini", QSettings::IniFormat);
    setting.beginGroup("threshold");
    int lamp_down = setting.value("lamp_down").toInt();
    int lamp_up = setting.value("lamp_up").toInt();
    setting.endGroup();

    unsigned char frame[21] = {0};
    frame[0] = 0x7e;
    frame[1] = 21;
    frame[2] = static_cast<unsigned char>(CmdType::CHANGE_SETTING);     // 指令类型
    frame[5] = static_cast<unsigned char>(DataType::LAMP_THRESHOLD);    // 数据类型
    frame[6] = 4;
    frame[7] = lamp_down & 0xff;        // 下行值 2B
    frame[8] = (lamp_down>>8) & 0xff;
    frame[9] = lamp_up & 0xff;          // 上行值 2B
    frame[10] = (lamp_up>>8) & 0xff;
    frame[12] = static_cast<unsigned char>(DevType::ACTUATOR_LAMP);     // 设备类型
    setCRC16(frame, sizeof(frame));
    socket->write((const char*)frame, sizeof(frame));

}

// 加湿器的阈值提交
void MainWindow::saveSettingHumiThreshold()
{
    QSettings setting("alg.ini", QSettings::IniFormat);
    setting.beginGroup("threshold");
    int humi_down = setting.value("humi_down").toInt();
    int humi_up = setting.value("humi_up").toInt();
    setting.endGroup();

    unsigned char frame[21] = {0};
    frame[0] = 0x7e;
    frame[1] = 21;
    frame[2] = static_cast<unsigned char>(CmdType::CHANGE_SETTING);     // 指令类型
    frame[5] = static_cast<unsigned char>(DataType::HUMI_THRESHOLD);    // 数据类型
    frame[6] = 4;
    frame[7] = humi_down & 0xff;        // 下行值 2B
    frame[8] = (humi_down>>8) & 0xff;
    frame[9] = humi_up & 0xff;          // 上行值 2B
    frame[10] = (humi_up>>8) & 0xff;
    frame[12] = static_cast<unsigned char>(DevType::ACTUATOR_HUMI);     // 设备类型
    setCRC16(frame, sizeof(frame));
    socket->write((const char*)frame, sizeof(frame));
}

void MainWindow::saveSettingFanThreshold()
{
    QSettings setting("alg.ini", QSettings::IniFormat);
    setting.beginGroup("threshold");
    int fan_down = setting.value("fan_down").toInt();
    int fan_up = setting.value("fan_up").toInt();
    setting.endGroup();

    unsigned char frame[21] = {0};
    frame[0] = 0x7e;
    frame[1] = 21;
    frame[2] = static_cast<unsigned char>(CmdType::CHANGE_SETTING);     // 指令类型
    frame[5] = static_cast<unsigned char>(DataType::FAN_THRESHOLD);    // 数据类型
    frame[6] = 4;
    frame[7] = fan_down & 0xff;        // 下行值 2B
    frame[8] = (fan_down>>8) & 0xff;
    frame[9] = fan_up & 0xff;          // 上行值 2B
    frame[10] = (fan_up>>8) & 0xff;
    frame[12] = static_cast<unsigned char>(DevType::ACTUATOR_FAN);     // 设备类型
    setCRC16(frame, sizeof(frame));
    socket->write((const char*)frame, sizeof(frame));
}

void MainWindow::saveSettingCurtainThreshold()
{
    QSettings setting("alg.ini", QSettings::IniFormat);
    setting.beginGroup("threshold");
    int curtain_down = setting.value("curtain_down").toInt();
    int curtain_up = setting.value("curtain_up").toInt();
    setting.endGroup();

    unsigned char frame[21] = {0};
    frame[0] = 0x7e;
    frame[1] = 21;
    frame[2] = static_cast<unsigned char>(CmdType::CHANGE_SETTING);     // 指令类型
    frame[5] = static_cast<unsigned char>(DataType::CURTAIN_THRESHOLD);    // 数据类型
    frame[6] = 4;
    frame[7] = curtain_down & 0xff;        // 下行值 2B
    frame[8] = (curtain_down>>8) & 0xff;
    frame[9] = curtain_up & 0xff;          // 上行值 2B
    frame[10] = (curtain_up>>8) & 0xff;
    frame[12] = static_cast<unsigned char>(DevType::ACTUATOR_CURTAIN);     // 设备类型
    setCRC16(frame, sizeof(frame));
    socket->write((const char*)frame, sizeof(frame));
}

void MainWindow::onCloseApp()
{
    qDebug() << "on close app";
    this->close();
    qApp->exit(0);;

}


