#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QListWidgetItem>

namespace Ui {
class SettingWindow;
}

class SettingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SettingWindow(QWidget *parent = 0);
    ~SettingWindow();


    /*
    @brief 从配置文件中查找指定节点的区域编号
    @return 指定节点已设置则返回区域编号，否则返回0
    */
    int areaId(int node);

    void saveAmount();

    void saveThreshold();

    void loadSettings();

signals:
    void sigShowMainWnd();
    void sigSaveSettings();
private slots:
    void on_btn_return_clicked();

    void on_btn_addNode_clicked();

    void on_btn_removeNode_clicked();

    void on_listWidget_area_itemClicked(QListWidgetItem *item);

    void on_btn_save_clicked();

    void on_checkBox_auto_clicked();

private:
    Ui::SettingWindow *ui;
    QSettings *settings;

    // QObject interface
public:
    virtual bool eventFilter(QObject *watched, QEvent *event) override;
};

#endif // SETTINGWINDOW_H
