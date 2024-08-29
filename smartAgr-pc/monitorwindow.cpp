#include "monitorwindow.h"
#include "ui_monitorwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QSettings>

MonitorWindow::MonitorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MonitorWindow)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowMaximized);
    ui->stackedWidget->setCurrentWidget(ui->page_grid);

    QSettings setting("alg.ini", QSettings::IniFormat);
    setting.beginGroup("amount");
    this->area_num = setting.value("area_num").toInt();
    qDebug() << "area_num = " << this->area_num;
    setting.endGroup();
    ui->page_grid->setMinimumHeight(210*4);
    ui->page_grid->setMaximumHeight(area_num/4*210); // 根据区域数量设置页面的高度，否则界面显示会不完整

    initRealDataModel();
    initDevInfoModel();

    initMonitorArea();
    initTimer();        // 定时暗淡区域ID背景，必须先初始化监测区域

}

MonitorWindow::~MonitorWindow()
{
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

// 定时设置区域ID背景暗淡，因为收到数据时高亮，可达到闪烁的效果
void MonitorWindow::onTimingClearData()
{
    for (int i = 0; i < area_num; ++i)
    {
        areas[i].areaIDBackgroundDim();
    }
}

// 返回主页面
void MonitorWindow::on_btn_return_clicked()
{
    this->hide();
    emit sigShowMainWnd();
}

// 初始化监测区域
void MonitorWindow::initMonitorArea()
{
    QHBoxLayout *hbox = new QHBoxLayout(ui->page_grid);
    QGridLayout *glayout = new QGridLayout;
    areas = new MonitorArea[area_num];

    for (int i = 0; i < area_num; ++i)
    {
        // 显示添加节点界面点，得从设备信息模型中查询当前区域的节点ID，以显示到当前区域
        connect(&areas[i], &MonitorArea::sigControlDevice, this, &MonitorWindow::sigControlDevice);
        areas[i].setAreaId(i+1); // 区域ID从1开始计
        glayout->addWidget(&areas[i],i/4, i%4);
    }
    hbox->addLayout(glayout);
    hbox->setAlignment(glayout, Qt::AlignHCenter | Qt::AlignTop);

}

// 初始化实时数据模型
void MonitorWindow::initRealDataModel()
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

// 初始化设备信息模型
void MonitorWindow::initDevInfoModel()
{
    model_devInfo = new QStandardItemModel(this);
    QStringList header;
    header << "节点" << "类型" << "区域" << "状态" ;
    model_devInfo->setHorizontalHeaderLabels(header);
    model_devInfo->setColumnCount(header.size());
}



// 接收服务器数据显示到 网格与列表 视图
void MonitorWindow::recvDatas(unsigned char *data, int len)
{
    int aid = data[11];
    DataType data_type = static_cast<DataType>(data[5]);
    int value = data[7]|data[8]<<8|data[9]<<16|data[10]<<24;
    DevType dev_type = static_cast<DevType>(data[12]);
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

// 添加实时数据到列表模型
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

// 保存查询到的设备信息
void MonitorWindow::saveDeviceInfo(unsigned char*data, int len)
{
    int zid = data[3] | data[4]<<8;
    int state = data[7];
    int aid = data[11];
    int dev_type = data[12];

    qDebug() << zid << " : " << dev_type << " : " << aid;
    QList<QStandardItem*> items_row;

    items_row.append(new QStandardItem(QString::number(zid)));
    items_row.append(new QStandardItem(QString::number(dev_type)));
    items_row.append(new QStandardItem(QString::number(aid)));
    items_row.append(new QStandardItem(QString::number(state)));

    qDebug() << __FILE__ " : " << __FUNCTION__ << " : " << __LINE__;
    model_devInfo->appendRow(items_row);
    if (aid > 0 && aid < area_num) // 把zid显示到相应的区域标签上，能直观的看到该区域设置了哪些节点
    {
        areas[aid-1].setZid(zid);

    }
    qDebug() << "DEV INFO ROW: " << model_devInfo->rowCount();
}

// 设置节点到区域
void MonitorWindow::onSetNode(int aid, int zid)
{

    // 传递数据到主界面，由主界面保存到服务器
    cur_aid = aid;
    emit sigDevInfoToServer(zid, aid);
    // 保存成功再显示到本地
}

//
void MonitorWindow::onSetAreaZids(int aid, QString zids)
{
//    addNodeDlg->setAreaIdAndZids(aid, zids);
}

// 处理设置节点的结果
void MonitorWindow::handleSaveDevStatus(unsigned char* data, int len)
{
    if (len < 8)
        return;
    int zid = data[3] | data[4]<<8;
    DataType dtype = static_cast<DataType>( data[5]);
    bool state = data[7];

    switch (dtype) {
    case DataType::SET_ZIGBEE:
        if (state) // 设置成功
        {
            areas[cur_aid-1].setZid(zid); // 区域ID是从1算的，做为下标时，是从0算的
        }
        else // status == false  设置失败
        {
            QMessageBox::critical(this, "错误", QString("设置 节点%1 失败！").arg(zid));
        }
        break;
    case DataType::RESET_ZIGBEE:
        if (state) // 重置成功
        {
            areas[cur_aid-1].unsetZid(zid);
        }
        else        // 重置失败
        {
            QMessageBox::critical(this, "错误", QString("移除 节点%1 失败！").arg(zid));
        }
        break;
    default:
        break;
    }


}

// 下翻，界面上移，Y坐标减少
void MonitorWindow::on_btn_down_clicked()
{
    int cur_y = ui->page_grid->y();
    ui->page_grid->move(0, cur_y - 220);
}

// 上翻， 界面下移，Y坐标增加
void MonitorWindow::on_btn_up_clicked()
{
    int cur_y = ui->page_grid->y();
    if (cur_y < 0)
        ui->page_grid->move(0, cur_y + 220);
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


// 设置每个区域页码，然后再显示再显示本界面
void MonitorWindow::myShow(int page_id)
{
    for (int i = 0; i < area_num; ++i)
    {
        areas[i].setCurrentPageID(page_id);
    }

    this->show();
}









