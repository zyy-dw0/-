#include "monitorarea.h"
#include "ui_monitorarea.h"
#include <QDebug>
#include <QSettings>


MonitorArea::MonitorArea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonitorArea)
{
    ui->setupUi(this);

    this->setFixedSize(260, 210);

    aid_high_style = "background-color: rgb(255, 255, 127);border-radius:10px;color: rgb(0, 0, 127);font: 24pt '微软雅黑';";
    aid_dim_style = "background-color: rgb(200, 255, 170);;border-radius:10px;color: rgb(0, 0, 127);font: 18pt '微软雅黑';";

    switch_on_style = "background-color: rgb(255, 255, 0); border-color:rgb(170, 170, 127); border-style: solid;border-radius: 25px;border-width: 2px;";
    switch_off_style = "background-color: rgb(220, 220, 180);; border-color:rgb(255, 255, 0); border-style: solid;border-radius: 25px;border-width: 2px;";
}

MonitorArea::~MonitorArea()
{
    delete ui;
}

void MonitorArea::showDatas(DataType dtype, int value)
{
    switch (dtype)
    {
    case DataType::TEMP:
        ui->label_temp->setText(QString("%1 ℃").arg(value));
        break;
    case DataType::HUMI:
        ui->label_humi->setText(QString("%1 %").arg(value));
        break;
    case DataType::HUMI_SOIL:
        ui->label_humi_soil->setText(QString("%1 %").arg(value));
        break;
    case DataType::ILLU:
        ui->label_lux->setText(QString("%1 lux").arg(value/100));
        break;
    case DataType::CO2:
        ui->label_co2->setText(QString("%1 ppm").arg(value));
        break;
    default:
        break;
    }
    ui->btn_aid->setStyleSheet(aid_high_style);
}


void MonitorArea::areaIDBackgroundDim()
{
    ui->btn_aid->setStyleSheet(aid_dim_style);
}


void MonitorArea::clearDatas()
{
    ui->label_temp->setText(" - ℃");
    ui->label_humi->setText(" - %");
    ui->label_humi_soil->setText(" - %");
    ui->label_lux->setText(" - lux");
    ui->label_co2->setText(" - ppm");
}

// 设置当前区域的id
void MonitorArea::setAreaId(int aid)
{
    this->area_id = aid;
    ui->btn_aid->setText(QString("%1区").arg(this->area_id));    // 监测页面
    ui->btn_aid_2->setText(QString("%1区").arg(this->area_id));  // 控制页面
}

// 设置当前区域的节点编号
void MonitorArea::setZid(int zid)
{
    QString zids = ui->label_zids->text();
    if (zids.contains(QString::number(zid))) // 已存在则不添加
    {
        return;
    }
    ui->label_zids->setText(zids+ " " +QString::number(zid));
    ui->btn_aid->setStyleSheet(aid_high_style);

}

// 移除当前区域的节点编号
void MonitorArea::unsetZid(int zid)
{
    QString cur_txt = ui->label_zids->text();
    QString res_txt = cur_txt.remove(QString(" %1").arg(qAbs(zid)));
    qDebug() << "remove node: " << qAbs(zid) << " result: " << res_txt;
    ui->label_zids->setText(res_txt);
    if (res_txt.isEmpty()) // 如果zids标签为空，表示此区域没有设置节点，背景暗淡下来
    {
        ui->btn_aid->setStyleSheet("background-color: rgb(170, 170, 127);;border-radius:30px;color: rgb(0, 0, 127);font: 24pt '微软雅黑';");
    }
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
    ui->label_zids->setAlignment(Qt::AlignJustify);


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
        qDebug() << "state_curtain = " << state_curtain;
        if (state_curtain == 1)
        {
            ui->switch_curtain_positive->setStyleSheet(switch_on_style);
            ui->switch_curtain_reverse->setStyleSheet(switch_off_style);
        }
        else if (state_curtain == 2)
        {
            ui->switch_curtain_reverse->setStyleSheet(switch_on_style);
            ui->switch_curtain_positive->setStyleSheet(switch_off_style);
        }
        else
        {
            ui->switch_curtain_positive->setStyleSheet(switch_off_style);
            ui->switch_curtain_reverse->setStyleSheet(switch_off_style);
        }
        break;
    default:
        break;
    }

}

// 点击翻页
void MonitorArea::on_btn_aid_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_control);
}


void MonitorArea::on_btn_aid_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_monitor);
}


// 开关灯
void MonitorArea::on_switch_lamp_clicked()
{
    // 发信号给主窗体，让主窗体把控制数据帧发给服务器
    emit sigControlDevice(this->area_id, DevType::ACTUATOR_LAMP, DataType::LAMP_STATE, !state_lamp); // 开启状态为true,发送关闭指令为false
}

// 开关加湿器
void MonitorArea::on_switch_humi_clicked()
{
    // 发信号给主窗体，让主窗体把控制数据帧发给服务器
    emit sigControlDevice(this->area_id, DevType::ACTUATOR_HUMI, DataType::HUMI_STATE , !state_humi); // true表示开，false表示关
}

// 开关风扇
void MonitorArea::on_switch_fan_clicked()
{
    // 发信号给主窗体，让主窗体把控制数据帧发给服务器
    emit sigControlDevice(this->area_id, DevType::ACTUATOR_FAN, DataType::FAN_STATE, !state_fan); // true表示开，false表示关
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
    // 发信号给主窗体，让主窗体把控制数据帧发给服务器
    emit sigControlDevice(this->area_id, DevType::ACTUATOR_CURTAIN, DataType::CURTAIN_STATE, state_curtain==1?0:1);
}

// 遮阳帘 电机反转
void MonitorArea::on_switch_curtain_reverse_clicked()
{
    // 发信号给主窗体，让主窗体把控制数据帧发给服务器
    emit sigControlDevice(this->area_id, DevType::ACTUATOR_CURTAIN, DataType::CURTAIN_STATE, state_curtain==2?0:2);
}


