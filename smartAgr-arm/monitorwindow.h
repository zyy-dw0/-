#ifndef MONITORWINDOW_H
#define MONITORWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QTimer>
#include "monitorarea.h"


namespace Ui {
class MonitorWindow;
}

class MonitorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MonitorWindow(QWidget *parent = 0);
    ~MonitorWindow();

    void initTimer();
    void initMonitorArea();
    void initModel();
//    int getAreaId(int zid);
    void myShow(int page_id);
    void setRealModelDatas(int aid, DataType dtype, int value);
    // 接收串口发来的实时数据
    void recvDatas(unsigned char *data, int len);

    int queryAid(int zid);
    void saveDeviceType(int zid, int dev_type);
signals:
    void sigControlDevice(int aid, DevType dev_type, DataType data_type, int status); //传递MonitorArea的信号
private slots:

    void onTimingClearData();
//    void onSetZid(int aid, int zid);
//    void onRemoveZid(int aid, int zid);

    void on_btn_return_clicked();

    void on_btn_down_clicked();

    void on_btn_up_clicked();

    void on_btn_grid_clicked();

    void on_btn_list_clicked();

private:
    Ui::MonitorWindow *ui;
    MonitorArea* areas;
    int area_num;

    QStandardItemModel *model_realData;

    QTimer *timer_detect_realData;
};

#endif // MONITORWINDOW_H
