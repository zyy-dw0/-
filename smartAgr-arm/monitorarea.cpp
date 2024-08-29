#include "monitorarea.h"
#include "ui_monitorarea.h"
#include <QDebug>
#include <QSettings>
#include <QMessageBox>

MonitorArea::MonitorArea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonitorArea)
{
    ui->setupUi(this);
    this->resize(260,210);

    QSettings setting("alg.ini", QSettings::IniFormat);
    setting.beginGroup("threshold");
    this->lamp_down = setting.value("lamp_down").toInt();
    this->lamp_up = setting.value("lamp_up").toInt();
    this->humi_down = setting.value("humi_down").toInt();
    this->humi_up = setting.value("humi_up").toInt();
    this->fan_down = setting.value("fan_down").toInt();
    this->fan_up = setting.value("fan_up").toInt();
    this->curtain_down = setting.value("curtain_down").toInt();
    this->curtain_up = setting.value("curtain_up").toInt();
    this->isAuto = setting.value("auto").toBool();
    setting.endGroup();

    aid_high_style = "background-color: rgb(255, 255, 127);border-radius:10px;color: rgb(0, 0, 127);font: 20pt '微软雅黑';";
    aid_dim_style = "background-color: rgb(200, 255, 170);;border-radius:10px;color: rgb(0, 0, 127);font: 16pt '微软雅黑';";

//    switch_on_style = "background-color: rgb(255, 255, 0); border-color:rgb(170, 170, 127); border-style: solid;border-radius: 25px;border-width: 2px;";
    switch_off_style = "	border-image: url(:/images/switch_off.png);";
    switch_on_style = "	border-image: url(:/images/switch_on.png);";
//    switch_off_style = "background-color: rgb(220, 220, 180);; border-color:rgb(255, 255, 0); border-style: solid;border-radius: 25px;border-width: 2px;";
}

MonitorArea::~MonitorArea()
{
    delete ui;
}


void MonitorArea::showDatas(DataType dtype, int value)
{
    switch (dtype) {
    case DataType::TEMP:
        ui->label_temp->setText(QString("%1 ℃").arg(value));
        // 如果温度达到警戒值， 自动开/关排气风扇
        autoControlFan(value);
        break;
    case DataType::HUMI:
        ui->label_humi->setText(QString("%1 %").arg(value));
        break;
    case DataType::HUMI_SOIL:
        ui->label_humi_soil->setText(QString("%1 %").arg(value));
        // 如果湿度达到警戒值，自动开/关加湿器
        autoControlHumi(value);
        break;
    case DataType::ILLU:
        ui->label_lux->setText(QString("%1 lux").arg(value/100));
        // 如果光照值达到警戒值， 自动开/关遮阳帘(补光灯)
        autoControlLamp(value/100);
        autoControlCurtain(value/100);
        break;
    case DataType::CO2:
        ui->label_co2->setText(QString("%1 ppm").arg(value));
        break;
    default:
        break;
    }
    // 接收到数据时，高亮显示区域编号
    ui->btn_aid->setStyleSheet(aid_high_style);
}


void MonitorArea::autoControlHumi(int value)
{
    if (!this->isAuto)
        return;

    bool state;
    if (value <= humi_down)
        state = true;
    else if (value >= humi_up)
        state = false;
    else
        return;

    // 根据aid与dev-type从配置文件中查询ZID
    int zid = queryZid(DevType::ACTUATOR_HUMI);
    if (zid == 0)
    {
        qDebug() << "not found zid....";
        return;
    }
    // 发信号给主窗体，让主窗体把控制数据帧发给服务器
    emit sigControlDevice(zid, DevType::ACTUATOR_HUMI, DataType::HUMI_SOIL, state); // 开启状态为true,发送关闭指令为false
}

void MonitorArea::autoControlFan(int value)
{
    if (!this->isAuto)
        return;
    bool state;
    if (value <= fan_down)
        state = false;
    else if (value >= fan_up)
        state = true;
    else
        return;

    // 根据aid与dev-type从配置文件中查询ZID
    int zid = queryZid(DevType::ACTUATOR_FAN);
    if (zid == 0)
    {
        qDebug() << "not found zid....";
        return;
    }
    // 发信号给主窗体，让主窗体把控制数据帧发给服务器
    emit sigControlDevice(zid, DevType::ACTUATOR_FAN, DataType::FAN_STATE, state); // 开启状态为true,发送关闭指令为false
}

void MonitorArea::autoControlLamp(int value)
{
    if (!this->isAuto)
        return;

    bool state;
    if (value <= lamp_down)
        state = true;
    else if (value >= lamp_up)
        state = false;
    else
        return;

    // 根据aid与dev-type从配置文件中查询ZID
    int zid = queryZid(DevType::ACTUATOR_LAMP);
    if (zid == 0)
    {
        qDebug() << "not found zid....";
        return;
    }
    // 发信号给主窗体，让主窗体把控制数据帧发给服务器
    emit sigControlDevice(zid, DevType::ACTUATOR_LAMP, DataType::LAMP_STATE, state); // 开启状态为true,发送关闭指令为false
}

void MonitorArea::autoControlCurtain(int value)
{
//    if (!this->isAuto)
        return;

    bool state;
    if (value <= curtain_down)
        state = false;
    else if (value >= curtain_up)
        state = true;
    else
        return;

    // 根据aid与dev-type从配置文件中查询ZID
    int zid = queryZid(DevType::ACTUATOR_CURTAIN);
    if (zid == 0)
    {
        qDebug() << "not found zid....";
        return;
    }
    // 发信号给主窗体，让主窗体把控制数据帧发给服务器
    emit sigControlDevice(zid, DevType::ACTUATOR_CURTAIN, DataType::CURTAIN_STATE, state); // 开启状态为true,发送关闭指令为false
}


void MonitorArea::setControllerState(DevType dev_type, int state)
{
    switch (dev_type) {
    case DevType::ACTUATOR_LAMP:
        state_lamp = state;
        ui->switch_lamp->setStyleSheet(state ? switch_on_style: switch_off_style);
        break;
    case DevType::ACTUATOR_HUMI:
        state_humi = state;
        ui->switch_humi->setStyleSheet(state ? switch_on_style: switch_off_style);
        break;
    case DevType::ACTUATOR_FAN:
        state_fan = state;
        ui->switch_fan->setStyleSheet(state ? switch_on_style: switch_off_style);
        break;
    case DevType::ACTUATOR_CURTAIN:
        state_curtain = state;
        if (state_curtain == 1)
        {
            ui->switch_curtain_positive->setStyleSheet(switch_on_style); // 正转亮时
            ui->switch_curtain_reverse->setStyleSheet(switch_off_style); // 反转灭
//            ui->switch_curtain_reverse->setEnabled(false);               // 禁用反转
        }
        else if (state_curtain == 2)
        {
            ui->switch_curtain_reverse->setStyleSheet(switch_on_style);     // 反转亮时
            ui->switch_curtain_positive->setStyleSheet(switch_off_style);   // 正转灭
//            ui->switch_curtain_positive->setEnabled(false);                 // 禁用正转
        }
        else
        {
//            ui->switch_curtain_positive->setEnabled(true);
//            ui->switch_curtain_reverse->setEnabled(true);
            ui->switch_curtain_positive->setStyleSheet(switch_off_style);
            ui->switch_curtain_reverse->setStyleSheet(switch_off_style);
        }
        break;
    default:
        break;
    }
}


void MonitorArea::clearDatas()
{
    ui->label_temp->setText(" - ℃");
    ui->label_humi->setText(" - %");
    ui->label_humi_soil->setText(" - %");
    ui->label_lux->setText(" - lux");
    ui->label_co2->setText(" - ppm");

}

void MonitorArea::areaIDBackgroundDim()
{
    ui->btn_aid->setStyleSheet(aid_dim_style);
}

void MonitorArea::setCurrentPageID(int page_id)
{
    ui->stackedWidget->setCurrentIndex(page_id);
    QSettings setting("alg.ini", QSettings::IniFormat);
    setting.beginGroup("zid-aid");
    QStringList keys = setting.allKeys();
    QString zids;
    int cnt = 0;
    for (int i = 0; i < keys.size(); ++i)
    {
        QString zid = keys.at(i);
        int aid = setting.value(zid).toInt();
        if (aid == this->area_id)
        {
            cnt++;
            zids += zid;
            if (cnt%3 == 0)
                zids += "\n";
            else
                zids += ",";
        }
    }
    zids.chop(1);
    ui->label_zids->setText(zids);
    ui->label_zids->setAlignment(Qt::AlignCenter);
}

void MonitorArea::setAreaId(int aid)
{
    this->area_id = aid;
    ui->btn_aid->setText(QString("%1区").arg(this->area_id));    // 监测页面
    ui->btn_aid_2->setText(QString("%1区").arg(this->area_id));  // 控制页面
}


void MonitorArea::removeZid(int zid)
{
    QString zids = ui->label_zids->text();
    qDebug() << "zids: " << zids;
    qDebug() <<  zids.remove(QString(" %1").arg(zid));
    ui->label_zids->setText(zids.remove(QString(" %1").arg(zid)));
}


void MonitorArea::on_btn_aid_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_control);
}

void MonitorArea::on_btn_aid_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_monitor);
}


int MonitorArea::queryZid(DevType dev_type)
{
    QSettings setting("alg.ini", QSettings::IniFormat);
    setting.beginGroup("zid-type");
    QString zids = ui->label_zids->text().replace('\n', ',');
    QStringList list = zids.split(",", QString::SkipEmptyParts);
    qDebug() << "zid list: " << list;
    for (int i = 0; i < list.size(); ++i)
    {
        QString zid = list.at(i);
        if (setting.value(zid).toInt() == dev_type)
        {
            return zid.toInt();
        }
    }
    return 0;
}

// 开关灯
void MonitorArea::on_switch_lamp_clicked()
{
    // 根据aid与dev-type从配置文件中查询ZID
    int zid = queryZid(DevType::ACTUATOR_LAMP);
    if (zid == 0)
    {
        QMessageBox::information(this, "提示", "本区域没有补光灯！");
        return;
    }
    // 发信号给主窗体，让主窗体把控制数据帧发给服务器
    emit sigControlDevice(zid, DevType::ACTUATOR_LAMP, DataType::LAMP_STATE, !state_lamp); // 开启状态为true,发送关闭指令为false
}

// 开关加湿器
void MonitorArea::on_switch_humi_clicked()
{
    int zid = queryZid(DevType::ACTUATOR_HUMI);
    if (zid == 0)
    {
        QMessageBox::information(this, "提示", "本区域没有加湿器！");
        return;
    }
    // 发信号给主窗体，让主窗体把控制数据帧发给服务器
    emit sigControlDevice(zid, DevType::ACTUATOR_HUMI, DataType::HUMI_STATE , !state_humi); // true表示开，false表示关
}

// 开关风扇
void MonitorArea::on_switch_fan_clicked()
{
    int zid = queryZid(DevType::ACTUATOR_FAN);
    if (zid == 0)
    {
        QMessageBox::information(this, "提示", "本区域没有排气风扇！");
        return;
    }
    // 发信号给主窗体，让主窗体把控制数据帧发给服务器
    emit sigControlDevice(zid, DevType::ACTUATOR_FAN, DataType::FAN_STATE, !state_fan); // true表示开，false表示关
}


void MonitorArea::on_btn_to_control_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_control);
}

void MonitorArea::on_btn_to_monitor_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_monitor);
}


// 遮阳帘 电机正转
void MonitorArea::on_switch_curtain_positive_clicked()
{
    int zid = queryZid(DevType::ACTUATOR_CURTAIN);
    if (zid == 0)
    {
        QMessageBox::information(this, "提示", "本区域没有设置遮阳帘！");
        return;
    }
    // 发信号给主窗体，让主窗体把控制数据帧发给服务器
    emit sigControlDevice(zid, DevType::ACTUATOR_CURTAIN, DataType::CURTAIN_STATE, state_curtain == 1 ? 0 : 1);
}

// 遮阳帘 电机反转
void MonitorArea::on_switch_curtain_reverse_clicked()
{
    int zid = queryZid(DevType::ACTUATOR_CURTAIN);
    if (zid == 0)
    {
        QMessageBox::information(this, "提示", "本区域没有设置遮阳帘！");
        return;
    }
    // 发信号给主窗体，让主窗体把控制数据帧发给服务器
    emit sigControlDevice(zid, DevType::ACTUATOR_CURTAIN, DataType::CURTAIN_STATE, state_curtain == 2 ? 0 : 2);
}
