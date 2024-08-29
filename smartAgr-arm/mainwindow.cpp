#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <stdio.h>
#include <QMessageBox>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), monitorWnd(nullptr),  online(false), isConnected(false)
{
    ui->setupUi(this);

    initSettingWnd();
    initSocket();
    initLoginDlg();
    initSerial();
}

// 析构函数
MainWindow::~MainWindow()
{
    delete settingWnd;
    delete socket;
    delete loginDlg;
    delete serial;
    delete ui;
}

// 初始化串口
void MainWindow::initSerial()
{
    serial = new QSerialPort(this);
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::onReadSerial);
    serial->setPortName("/dev/ttySAC1");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setParity(QSerialPort::NoParity);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    bool ok = serial->open(QIODevice::ReadWrite);
    if (!ok)
    {
        qDebug() << "open serial  ttySAC1 error!!";
        return;
    }
    qDebug() << "open serial  ttySAC1 ok";
}
// 初始化套接接
void MainWindow::initSocket()
{
    QSettings setting("alg.ini", QSettings::IniFormat);
    setting.beginGroup("server");
    server_ip = setting.value("ip", "112.74.37.132").toString();  //;
    server_port = setting.value("port", 55555).toInt();
    setting.endGroup();
    isConnected = false;

    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::connected, this, &MainWindow::onConnected);
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError(QAbstractSocket::SocketError)));
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::onReadSocket);

}
// 初始化登录注册界面
void MainWindow::initLoginDlg()
{
    loginDlg = new LoginDialog(this);
    connect(loginDlg, &LoginDialog::sigLogin, this, &MainWindow::onLogin);
    loginDlg->show();
}
// 初始化监测界面
void MainWindow::initMonitorWnd()
{
    monitorWnd = new MonitorWindow(this);
    connect(monitorWnd, &MonitorWindow::sigControlDevice, this, &MainWindow::onControlDevice);
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
void MainWindow::onError(QAbstractSocket::SocketError err)
{
    qDebug() << "network error: " << socket->errorString();
    if (socket->state() == QAbstractSocket::UnconnectedState)
    {
        loginDlg->setAckDialog(AckStatus::ENETWORK);
        return;
    }
    if (err == QAbstractSocket::RemoteHostClosedError)
    {
        qDebug() << "server closed, application auto exit!...";
        QMessageBox::information(this, "提示", "服务器已关闭，请联系管理员或重启使用离线模式！");
        QApplication::exit(1);
    }
}


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

        if (socket->bytesAvailable() < len_frame_socket-2) // 不够一帧，存着
            return;

        socket->read((char*)frame_socket+2, len_frame_socket-2);

        CmdType cmd_type = static_cast<CmdType>(frame_socket[2]);

        switch (cmd_type) {
        case CmdType::LOGIN_USER:           // 用户登录
            recvLoginStatus(frame_socket, len_frame_socket);
            break;
//        case CmdType::REGISTER_USER:        // 用户注册
//            recvRegisterStatus(frame_socket, len_frame_socket);
//            break;
//        case CmdType::DOWNLOAD_REALTIME:    // 下载实时数据 aid dtype  value
//            monitorWnd->recvDatas(frame_socket, len_frame_socket);
//            break;
        case CmdType::CHANGE_DEVICE_STATE:  // 修改设备状态
            changeDeviceState(frame_socket, len_frame_socket);
            break;
        case CmdType::QUERY_SETTING:
            recvSettings(frame_socket, len_frame_socket);
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

void MainWindow::onControlDevice(int zid, DevType dev_type, DataType data_type, int status)
{
    unsigned char frame[21] = {0};
    frame[0] = 0x7e;
    frame[1] = 21;
    frame[3] = zid & 0xff;
    frame[4] = (zid>>8) & 0xff;
    frame[2] = static_cast<unsigned char>( CmdType::CHANGE_DEVICE_STATE);
    frame[5] = static_cast<unsigned char>(data_type);
    frame[6] = 1;
    frame[7] = status;
    frame[12] = static_cast<unsigned char>(dev_type);
    setCRC16(frame, 21);
    changeDeviceState(frame, sizeof(frame));
}


// 接收登录的返回状态，做进一步处理
void MainWindow::recvLoginStatus(unsigned char* data, int len)
{
    if (len < 8)
        return;
    bool state = data[7];
    if (!state)
    {
        // 登录失败
        loginDlg->setAckDialog(AckStatus::ELOGIN);
        socket->disconnectFromHost();
    }
    else
    {
        // 登录成功
        loginDlg->setAckDialog(AckStatus::OLOGIN);
        this->show();
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
void MainWindow::recvRegisterStatus(unsigned char *data, int len)
{
    if (len < 8)
        return;
    bool state = data[7];
    if (!state)
    {
        // 注册失败
        loginDlg->setAckDialog(AckStatus::EREGISTER);
        socket->disconnectFromHost();
    }
    else
    {
        // 注册成功
        loginDlg->setAckDialog(AckStatus::OREGISTER);
        socket->disconnectFromHost();
    }
}

// 接受配置信息
void MainWindow::recvSettings(unsigned char *data, int len)
{
    if (len < 13)
        return;
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
void MainWindow::onLogin(CmdType user_cmd, QString username, QString pwd, bool online)
{
    this->online = online;
    this->username = username;
    this->pwd = pwd;
    this->user_cmd = user_cmd;
    if (online) // 在线模式则尝试连接服务器
    {
        socket->connectToHost(server_ip, server_port);
    }
    else        // 离线模式则本地判断
    {
        if (this->username == "ARM001" && this->pwd == "666666") // 验证成功
        {
            loginDlg->setAckDialog(AckStatus::OLOGIN);
            // 离线模式登录成功则读取配置初始化监控界面，在线模式则需要收到服务器的配置 才初始化 监控界面
            initMonitorWnd();
            this->show();
        }
        else                                                     // 验证失败
        {
            loginDlg->setAckDialog(AckStatus::ELOGIN);
        }
    }

}
// 收到注册请求，连接服务器
void MainWindow::onRegister(CmdType user_cmd, QString username, QString pwd)
{
    this->username = username;
    this->pwd = pwd;
    this->user_cmd = user_cmd;
    socket->connectToHost(server_ip, server_port);
}

// 检测校验位
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

// 设置校验位
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

// 进入监测界面
void MainWindow::on_btn_monitor_clicked()
{
    monitorWnd->myShow(0);
}
// 进入控制界面
void MainWindow::on_btn_control_clicked()
{
    monitorWnd->myShow(1);
}

// 读串口数据
void MainWindow::onReadSerial()
{
    // 从串口接收数据
    bool has_tran = false; // 是否发生转义，如果读到的字节是转义字节0x7d,则置为true
    while (serial->bytesAvailable() > 0)
    {
        char c;
        serial->read(&c, 1);
        if (!has_head_serial) // 没有头，读一个字节，查看当前字节是不是头，如果不是，放弃此字节，读下个，再判断，如此循环，直到读到头
        {
            if (c == 0x7e) // 如果没有头的时候读到一个字节为0x7e,此字节即可数据帧的头
            {
                frame_serial[index_frame_serial++] = c;
                has_head_serial = true;
            }
            else // 不是帧头
            {
                // 丢弃不要，继续读下一个字节
                qDebug() << "not head :c = " << hex << c ;
                continue;
            }
        }
        // 有头，没长度
        else if(has_head_serial && len_frame_serial == 0) // 有头了，如果没有帧长，则头后面的此字节就是帧长
        {
            if (has_tran)
            {
                frame_serial[index_frame_serial++] = c+0x20;
                len_frame_serial = c+0x20;
                has_tran = false;
            }
            else
            {
                if (c == 0x7d)
                {
                    has_tran = true;
                }
                else
                {
                    frame_serial[index_frame_serial++] = c;
                    len_frame_serial = c;
                }
            }
        }
        else // 有头，有帧长
        {
            if (has_tran)
            {
                frame_serial[index_frame_serial++] = c+0x20;
                has_tran = false;
            }
            else
            {
                if (c == 0x7d)
                {
                    has_tran = true;
                }
                else
                {
                    frame_serial[index_frame_serial++] = c;
                }
            }
            // 如果收齐一帧数据
            if (index_frame_serial == len_frame_serial)
            {
                // 处理数据帧
                printFrame(frame_serial, len_frame_serial, '-');
                // 显示到本地界面
                serialDataToLocal(frame_serial, len_frame_serial);
                // 在线模式 则发送到服务器
                serialDataToServer(frame_serial, len_frame_serial);
                // 重置变量
                has_head_serial = false;
                index_frame_serial = 0;
                memset(frame_serial, 0, sizeof(frame_serial));
            }
        }
    }

}


void MainWindow::printFrame(unsigned char *data, int len, char sep)
{
    if (data[12] == DevType::SENSOR_GY39)
    {
        return;
    }
    for (int i = 0; i < len; ++i)
    {
        printf("%02x%c", data[i], sep);
    }
    printf("\n");
}

// 发指令 控制设备(写数据到串口)
void MainWindow::changeDeviceState(unsigned char *data, int len)
{
    qDebug() << "---------------------------------------------";
    printFrame(data, len, '+');
    unsigned char frame[41] = {0}; // 往串口的数据帧定长21字节 ，转义后最长1+40字节
    int j = 1;
    frame[0] = 0x7e;

    for (int i = 1; i < len; ++i)
    {
        if (data[i] == 0x7e)
        {
            frame[j++] = 0x7d;
            frame[j++] = 0x5e;
        }
        else if (data[i] == 0x7d)
        {
            frame[j++] = 0x7d;
            frame[j++] = 0x5d;
        }
        frame[j++] = data[i];
    }
    int wr = serial->write((const char*)frame, j);
    printFrame(frame, j, '+');
    qDebug() << "---------------------" << wr << "------------------------";
}


void MainWindow::serialDataToLocal(unsigned char *data, int len)
{
    if (monitorWnd == nullptr)
        return;
    monitorWnd->recvDatas(data, len);
}


// 发送监测数据到服务器
void MainWindow::serialDataToServer(unsigned char *data, int len)
{
    if (!this->online) // 离线状态，不发数据到服务器
        return;
    if (checkCRC(data, len) == 0)
    {
        qDebug() << "check crc error, dont send to server!";
        return;
    }

    int r = socket->write((const char*)data, len);
    if (r < 0)
    {
        qDebug() << "send error: " << socket->errorString();
    }
}


// 进入系统设置界面
void MainWindow::on_btn_setting_clicked()
{
    this->hide();
    settingWnd->loadSettings();
}

void MainWindow::initSettingWnd()
{
    settingWnd = new SettingWindow(this);
    connect(settingWnd, &SettingWindow::sigShowMainWnd, this, &MainWindow::show);
    connect(settingWnd, &SettingWindow::sigSaveSettings, this, &MainWindow::onSaveSettings);
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

    QMessageBox::information(this, "提示", "配置提交成功！请重启程序，以使配置生效！");
    QApplication::exit(111);
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




