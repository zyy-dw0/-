#ifndef MONITORWINDOW_H
#define MONITORWINDOW_H

#include <QMainWindow>
#include <QMultiMap>
#include <QTimer>
#include <QStandardItemModel>
#include <QLayout>
#include "monitorarea.h"

#include "protocol.h"


namespace Ui {
class MonitorWindow;
}

class MonitorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MonitorWindow(QWidget *parent = 0);
    ~MonitorWindow();

    void initMonitorArea();
    void initTimer();
    void initRealDataModel();
    void initDevInfoModel();

    void showDatas(QMap<QString, int> &datas_map);
    void recvDatas(unsigned char *data, int len);

    void saveDeviceInfo(unsigned char *data, int len);

    void handleSaveDevStatus(unsigned char *data, int len);
    // 设置实时(列表视图)模型数据
    void setRealModelDatas(int aid, DataType dtype, int value);

    void myShow(int page_id);
signals:
    void sigDevInfoToServer(int zid, int aid);
    void sigShowMainWnd();
    void sigControlDevice(int aid, DevType dev_type, DataType data_type,int status);

private slots:
    void onTimingClearData();
    void onSetNode(int aid, int zid);
    void onSetAreaZids(int aid, QString zids);
    void on_btn_return_clicked();

    void on_btn_down_clicked();

    void on_btn_up_clicked();

    void on_btn_grid_clicked();

    void on_btn_list_clicked();

private:
    Ui::MonitorWindow *ui;

    MonitorArea* areas;
    int area_num;
    int cur_aid;         // 每次只操作一个区域，用一个变量保存即可
    QTimer *timer_detect_realData;


    QStandardItemModel *model_realData; // sensor_real_datas model
    QStandardItemModel *model_devInfo;  // dev info
};

#endif // MONITORWINDOW_H
