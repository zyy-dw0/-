#include "settingwindow.h"
#include "ui_settingwindow.h"
#include <QDebug>
#include <QMessageBox>

SettingWindow::SettingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 480);
    settings = new QSettings("alg.ini", QSettings::IniFormat);
    settings->setIniCodec("UTF-8");
}


int SettingWindow::areaId(int node)
{
    settings->beginGroup("zid-aid");
    int aid = settings->value(QString::number(node), "0").toInt();
    settings->endGroup();
    return aid;
}

void SettingWindow::saveAmount()
{
    settings->beginGroup("amount");
    settings->setValue("area_num", ui->spinBox_areaNum->value());
    settings->setValue("node_num", ui->spinBox_nodeNum->value());
    settings->endGroup();
}


void SettingWindow::saveThreshold()
{
    settings->beginGroup("threshold");
    settings->setValue("lamp_down", ui->spinBox_lamp_down->value());
    settings->setValue("lamp_up", ui->spinBox_lamp_up->value());

    settings->setValue("humi_down", ui->spinBox_humi_down->value());
    settings->setValue("humi_up", ui->spinBox_humi_up->value());

    settings->setValue("fan_down", ui->spinBox_fan_down->value());
    settings->setValue("fan_up", ui->spinBox_fan_up->value());

    settings->setValue("curtain_down", ui->spinBox_curtain_down->value());
    settings->setValue("curtain_up", ui->spinBox_curtain_up->value());
    settings->endGroup();
}

// 加载配置，并显示
void SettingWindow::loadSettings()
{
    settings->beginGroup("amount");
    int area_num = settings->value("area_num").toInt();
    int node_num = settings->value("node_num").toInt();
    settings->endGroup();

    ui->spinBox_areaNum->setValue(area_num);
    ui->spinBox_nodeNum->setValue(node_num);
    ui->listWidget_area->clear();
    for (int i = 1; i <= area_num; ++i)
    {
        ui->listWidget_area->addItem(QString("%1区").arg(i)); // 区域编号从1开始算
    }

    // 设置节点 选择 总表
    ui->listWidget_nodeAll->clear();
    for (int i = 1; i <= node_num; ++i)
    {
        if(areaId(i) == 0) // 如果节点未设置，则添加到总表
            ui->listWidget_nodeAll->addItem(QString("节点%1").arg(i));
    }

    /////////////////////////////////////////////////////////////

    settings->beginGroup("threshold");
    int lamp_down = settings->value("lamp_down").toInt();
    int lamp_up = settings->value("lamp_up").toInt();
    ui->spinBox_lamp_down->setValue(lamp_down);
    ui->spinBox_lamp_up->setValue(lamp_up);

    int humi_down = settings->value("humi_down").toInt();
    int humi_up = settings->value("humi_up").toInt();
    ui->spinBox_humi_down->setValue(humi_down);
    ui->spinBox_humi_up->setValue(humi_up);

    int fan_down = settings->value("fan_down").toInt();
    int fan_up = settings->value("fan_up").toInt();
    ui->spinBox_fan_down->setValue(fan_down);
    ui->spinBox_fan_up->setValue(fan_up);

    int curtain_down = settings->value("curtain_down").toInt();
    int curtain_up = settings->value("curtain_up").toInt();
    ui->spinBox_curtain_down->setValue(curtain_down);
    ui->spinBox_curtain_up->setValue(curtain_up);

    settings->endGroup();

    this->show();
}



SettingWindow::~SettingWindow()
{
    delete ui;
}

void SettingWindow::on_btn_return_clicked()
{
    emit sigShowMainWnd();
    this->close();
}


// 添加节点
void SettingWindow::on_btn_addNode_clicked()
{
    if (!ui->listWidget_nodeAll->currentIndex().isValid())
        return;

    QString txt = ui->listWidget_nodeAll->currentItem()->text();
    ui->listWidget_nodeSelect->addItem(txt);

    int row = ui->listWidget_nodeAll->currentRow();
    ui->listWidget_nodeAll->takeItem(row);

    // 写入配置文件  1=1 2=1  3=1
    QString zid = txt.remove("节点");
    QString aid = ui->listWidget_area->currentItem()->text().remove("区");
    settings->beginGroup("zid-aid");
    settings->setValue(zid, aid);
    settings->endGroup();
}

// 移除节点
void SettingWindow::on_btn_removeNode_clicked()
{
    if (!ui->listWidget_nodeSelect->currentIndex().isValid())
        return;

    int row = ui->listWidget_nodeSelect->currentRow();
    QString txt = ui->listWidget_nodeSelect->currentItem()->text();
    QListWidgetItem* item = ui->listWidget_nodeSelect->takeItem(row);
    delete item;

    ui->listWidget_nodeAll->insertItem(0, txt);


    // 写入配置文件  1=0 2=0  3=0
    QString zid = txt.remove("节点");
    QString aid = "0";
    settings->beginGroup("zid-aid");
    settings->setValue(zid, aid);
    settings->endGroup();

}


// 点击某区域时，查找此区域的节点，显示到选择列表
void SettingWindow::on_listWidget_area_itemClicked(QListWidgetItem *item)
{
    ui->listWidget_nodeSelect->clear();
    QString aid = item->text().remove("区");
    settings->beginGroup("zid-aid");
    QStringList keys = settings->allKeys();
    for (int i = 0; i < keys.size(); ++i)
    {
        QString key = keys.at(i);
        if (settings->value(key) == aid) // 如果节点的值与aid相同，则显示到界面
        {
            ui->listWidget_nodeSelect->addItem(QString("节点%1").arg(key));
        }
    }
    settings->endGroup();
}


// 保存配置到本地，及上传到服务器
void SettingWindow::on_btn_save_clicked()
{

    saveAmount();
    saveThreshold();

    emit sigSaveSettings(); // 发信号给主窗体，让主窗体读取配置发送到服务器
}


