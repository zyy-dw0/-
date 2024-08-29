#ifndef MONITORAREA_H
#define MONITORAREA_H

#include <QWidget>

#include "protocol.h"

namespace Ui {
class MonitorArea;
}

class MonitorArea : public QWidget
{
    Q_OBJECT

public:
    explicit MonitorArea( QWidget *parent = 0);
    ~MonitorArea();

    void setDatas(QMap<QString, int> &map);
    void clearDatas();

    void setAreaId(int aid);
    void setZid(int zid);
    void unsetZid(int zid);
    void showDatas(DataType dtype, int value);
    void areaIDBackgroundDim();
    void setCurrentPageID(int page_id);


    /*
    @brief 收到执行器的状态信息，再改变当前执行器的状态与样式
    @param dev_type 设备类型
    @param state 设备状态 1为开 0为关
    */
    void setControllerState(DevType dev_type, int state);

signals:
    void sigControlDevice(int aid, DevType dev_type, DataType data_type,int status);
private slots:

    void on_btn_aid_clicked();

    void on_btn_aid_2_clicked();

    void on_switch_lamp_clicked();

    void on_switch_fan_clicked();
    void on_switch_humi_clicked();
    void on_btn_to_control_clicked();
    void on_btn_to_monitor_clicked();

    void on_switch_curtain_positive_clicked();
    void on_switch_curtain_reverse_clicked();
private:
    Ui::MonitorArea *ui;

    int area_id; // 每个区域在创建时都必须 设置一个ID
    QString aid_high_style;
    QString aid_dim_style;

    QString switch_on_style;
    QString switch_off_style;

    // 执行器状态
    bool state_lamp = false;
    bool state_humi = false;
    bool state_fan = false;
    int state_curtain = 0;

};

#endif // MONITORAREA_H
