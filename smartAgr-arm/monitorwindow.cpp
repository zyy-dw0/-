#include "monitorwindow.h"
#include "ui_monitorwindow.h"
#include <QDebug>
#include <QSettings>

MonitorWindow::MonitorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MonitorWindow)
{
    ui->setupUi(this);
    QSettings setting("alg.ini", QSettings::IniFormat);
    setting.beginGroup("amount");
    this->area_num = setting.value("area_num").toInt();
    qDebug() << "area_num = " << this->area_num;

    ui->stackedWidget->setCurrentWidget(ui->page_grid);
    setting.endGroup();
    ui->page_grid->setMinimumHeight(210*this->area_num);
    ui->page_list->setMinimumHeight(210*this->area_num);

    initModel();
    initMonitorArea();
    initTimer();
}

MonitorWindow::~MonitorWindow()
{
    delete []areas;
    delete ui;
}
// 定时暗淡区域ID背景
void MonitorWindow::initTimer()
{
    timer_detect_realData = new QTimer(this);
    connect(timer_detect_realData, &QTimer::timeout, this, &MonitorWindow::onTimingClearData);
    timer_detect_realData->setInterval(1000*10);
    timer_detect_realData->start();
}

// 返回主页面
void MonitorWindow::on_btn_return_clicked()
{
    this->hide();
}


// 初始化监测区域
void MonitorWindow::initMonitorArea()
{
    areas = new MonitorArea[area_num];
    int offset_x = 10;
    int offset_y = 0;
    for (int i = 0; i < area_num; ++i)
    {
        connect(&areas[i], &MonitorArea::sigControlDevice, this, &MonitorWindow::sigControlDevice);
        areas[i].setAreaId(i+1); // 区域ID从1开始计
        areas[i].setParent(ui->page_grid);
        areas[i].move(offset_x + (i%3)*260, offset_y + (i/3)*210);
    }

}

void MonitorWindow::initModel()
{
    model_realData = new QStandardItemModel(this);
    QStringList header;
    header << "区域" << "空气温度(℃)" << "空气湿度(%)" << "土壤湿度(%)" << "光照强度(lux)" << "CO2浓度(ppm)";
    model_realData->setHorizontalHeaderLabels(header);

    for (int i = 0; i < area_num; ++i) // 一个区域一行，几个区域就是几行
    {
        for (int j = 0; j < header.size(); ++j) // 列数由表头的字段数决定
        {
            model_realData->setItem(i, j, new QStandardItem);
            model_realData->item(i, j)->setTextAlignment(Qt::AlignCenter);
        }
        model_realData->item(i, 0)->setText(QString("%1 区").arg(i+1));

    }


    ui->tableView->setModel(model_realData);
    ui->tableView->verticalHeader()->hide();

}

// 设置每个区域页码，然后再显示再显示本界面
void MonitorWindow::myShow(int page_id)
{
    for (int i = 0; i < area_num; ++i)
    {
        areas[i].setCurrentPageID(page_id);
    }

    this->show();
}


void MonitorWindow::setRealModelDatas(int aid, DataType dtype, int value)
{
//    model : aid  temp  humi  humi_soil  lux  co2
    int row = aid - 1; // // aid决定表格的行号,aid从1计算, 行号从0开始计算
    if (row < 0)
        return;

    switch (dtype) {
    case DataType::TEMP:
        model_realData->item(row, 1)->setText(QString("%1").arg(value));
        break;
    case DataType::HUMI:
        model_realData->item(row, 2)->setText(QString("%1").arg(value));
        break;
    case DataType::HUMI_SOIL:
        model_realData->item(row, 3)->setText(QString("%1").arg(value));
        break;
    case DataType::ILLU:
        model_realData->item(row, 4)->setText(QString("%1").arg(value/100));
        break;
    case DataType::CO2:
        model_realData->item(row, 5)->setText(QString("%1").arg(value));
        break;

    default:
        break;
    }
}

// 下翻，界面上移，Y坐标减少
void MonitorWindow::on_btn_down_clicked()
{
    if (ui->stackedWidget->currentWidget() == ui->page_grid)
    {
        int cur_y = ui->page_grid->y();
        ui->page_grid->move(0, cur_y - 210);
    }
    if (ui->stackedWidget->currentWidget() == ui->page_list)
    {
        ui->page_list->move(0, ui->page_list->y()-210);
    }

}

// 上翻， 界面下移，Y坐标增加
void MonitorWindow::on_btn_up_clicked()
{
    if (ui->stackedWidget->currentWidget() == ui->page_grid)
    {
        int cur_y = ui->page_grid->y();
        if (cur_y < 0)
            ui->page_grid->move(0, cur_y + 210);
    }
    if (ui->stackedWidget->currentWidget() == ui->page_list)
    {
        int cur_y = ui->page_list->y();
        if (cur_y < 0)
            ui->page_list->move(0, ui->page_list->y()+210);
    }
}

// 网格界面
void MonitorWindow::on_btn_grid_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_grid);
}

// 列表界面
void MonitorWindow::on_btn_list_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_list);
}

int MonitorWindow::queryAid(int zid)
{
    QSettings setting("alg.ini", QSettings::IniFormat);
    setting.beginGroup("zid-aid");
    int aid = setting.value(QString::number(zid), 0).toInt();
    setting.endGroup();

    return aid;
}
void MonitorWindow::saveDeviceType(int zid, int dev_type)
{
    QSettings setting("alg.ini", QSettings::IniFormat);
    setting.beginGroup("zid-type");
    setting.setValue(QString::number(zid), dev_type);
    setting.endGroup();
}

// 接收到串口的 实时数据，显示到监测界面，同时写入列表界面
void MonitorWindow::recvDatas(unsigned char *data, int len)
{
    if (len < 21)
        return;
    DataType data_type = static_cast<DataType>(data[5]);
    int value = data[7]|data[8]<<8|data[9]<<16|data[10]<<24;
    DevType dev_type = static_cast<DevType>(data[12]);
    int zid = data[3] | data[4]<<8;

    int aid = queryAid(zid); // 收到串口原始数据包，根据zid查找aid
    saveDeviceType(zid, dev_type); // 保存节点类型到配置文件


    if (aid >= 1 && aid <= area_num)
    {
        switch (data_type) {
        case DataType::TEMP:
        case DataType::HUMI:
        case DataType::HUMI_SOIL:
        case DataType::ILLU:
        case DataType::CO2:
            areas[aid-1].showDatas(data_type, value);
            setRealModelDatas(aid, data_type, value);
            break;
        case DataType::LAMP_STATE:
        case DataType::FAN_STATE:
        case DataType::HUMI_STATE:
        case DataType::CURTAIN_STATE:
            areas[aid-1].setControllerState(dev_type, value);
            break;
        default:
            break;
        }
    }
}


// 定时设置区域ID背景暗淡，因为收到数据时高亮，可达到闪烁的效果
void MonitorWindow::onTimingClearData()
{
    for (int i = 0; i < area_num; ++i)
    {
        areas[i].areaIDBackgroundDim();
    }
}










