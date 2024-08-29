
#ifndef PROTOCOL_H
#define PROTOCOL_H

int checkCRC(unsigned char *BytesFrame,int length);
void setCRC16(unsigned char *BytesFrame, int length);

/*Zigbee设备类型*/
enum DevType
{
    UNKONW_DEVICE=0,    /*未知设备*/
    SENSOR_GY39=10,     /*GY39传感器*/
    SENSOR_CO2,         /*CO2传感器*/
    SENSOR_HUMI,        /*土壤湿度传感器*/

    ACTUATOR_LAMP=50,   /*补光灯执行器*/
    ACTUATOR_FAN,       /*排气扇执行器*/
    ACTUATOR_HUMI,      /*加湿器执行器*/
    ACTUATOR_CURTAIN,   /*遮阳帘执行器*/
    ACTUATOR_ULTRA      /*超声波报警器*/
};

/*报文命令号枚举类型*/
enum CmdType
{
    REGISTER_USER=10,   /*注册用户*/
    LOGIN_USER,         /*登录用户*/
    QUERY_USER,         /*查询用户信息*/
    CHANGE_PSWD,        /*修改用户密码*/
    DELETE_USER,        /*删除用户*/

    UPLOAD_DATA=50,     /*上传实时数据*/   //传感器数据相关
    QUERY_REALTIME,     /*请求实时数据*/
    QUETY_HISTORY,      /*请求历史数据*/
    DOWNLOAD_REALTIME,  /*下传实时数据*/
    DOWNLOAD_HISTORY,   /*下传历史数据*/

    QUERY_DEVICE=100,   /*查询设备信息*/  //设备表相关
    CHANGE_DEVICE_STATE,/*修改设备状态*/
    CHANGE_ZIGBEE_ADDR, /*修改Zigbee地址*/

    CHANGE_SETTING,     /*修改配置*/
    QUERY_SETTING,      /*查询配置*/
};

/*报文数据类型号枚举类型*/
enum DataType
{
    TEMP=10,            /*环境温度*/   //传感器数据相关
    HUMI,               /*环境湿度*/
    HUMI_SOIL,          /*土壤湿度*/
    ILLU,               /*环境光强*/
    CO2,                /*CO2浓度*/

    ZIGBEE_ADDR=50,     /*Zigbee地址*/    //Zigbee相关
    SET_ZIGBEE,         /*设置Zigbee地址*/
    RESET_ZIGBEE,       /*重置Zigbee地址*/

    SET_AMOUNT,         /*设置区域数量与节点数量*/
    LAMP_THRESHOLD,      /*设置补光灯的阈值*/
    FAN_THRESHOLD,
    HUMI_THRESHOLD,
    CURTAIN_THRESHOLD,

    LAMP_STATE=100,     /*补光灯状态*/    //执行器相关
    FAN_STATE,          /*排气扇状态*/
    HUMI_STATE,         /*加湿器状态*/
    CURTAIN_STATE,      /*遮阳帘状态*/
    ULTRA_STATE,        /*超声波报警状态*/

    OLD_PSWD=150,       /*旧密码*/
    NEW_PSWD            /*新密码*/                                                            //账户相关

};


enum AckStatus
{
    ENETWORK,
    ELOGIN,
    EREGISTER,
    OLOGIN,
    OREGISTER
};


/*
数据帧格式
1B(0)		1B(1)		1B(2)		2B(3-4)					1B(5)		1B(6)	 12B(7-18)	    2B(19-20)
包头			帧长		   指令类型		Zigbee节点ID(小端)		数据类型		数据长度	 数据值(小端)	校验
*/

/*
ZIGBEE原始数据帧
1B(0)   1B(1)    1B(2)   2B(3-4)              1B(5)     1B(6)       4B(7-10)      1B(12)    2B(19-20)
包头    帧长      指令类型  Zigbee节点ID(小端)    数据类型   数据长度    数据值(小端)   设备类型   校验
*/

/*
服务器转换原始数据帧
1B(0)   1B(1)    1B(2)   2B(3-4)              1B(5)     1B(6)       4B(7-10)      1B(11)    2B(19-20)
包头    帧长      指令类型  Zigbee节点ID(小端)    数据类型   数据长度    数据值(小端)   区域ID   校验
*/

/*
用户发的控制设备数据帧
1B(0)   1B(1)    1B(2)   2B(3-4)              1B(5)     1B(6)       4B(7-10)      1B(11) 1B(12)    2B(19-20)
包头    帧长      指令类型  Zigbee节点ID(小端)    数据类型   数据长度    数据值(小端)   区域ID  设备类型      校验
*/

/*包头 0x7e
  转义 0x7d
    数据值中字节如果为7e,则 转义成7d5e
    数据值中字节如果为7d,则 转义成7d5d
  解析数据时，如果当前字节为7d，则丢弃，下一个字节+20即可还原原始数据值
*/

#endif

/*


数量表 t_amount
    id INTEGER PRIMARY KEY   AUTOINCREMENT,
    area_num    int         // 区域数量(1-250),默认为9
    node_num    int         // 节点数量(1-65535),默认100

    create table t_amount(id integer primary key autoincrement, area_num int default 9, node_num default 100);

节点信息表  t_device
    zigbee_id   int    // 主键 节点id
    area_id     int         // 区域编号     默认为0表示此节点未添加到区域
    dev_type    int         // 节点设备类型 默认为0表示未知类型
    dev_status  int         // 设备状态     默认为0表示关(针对于执行器)

    create table t_device(zigbee_id int primary key, dev_type int default 0, area_id int default 0, dev_status int default 0);



执行器阈值表  t_threshold
    dev_type    int     // 主键 设备类型
    down_value  int     // 下行值  达到此值，自动打开设备
    up_value    int     // 上行值  达到此值，自动关闭设备

    create table t_threshold(dev_type int primary key, down_value int default 0, up_value int default 0);

*/
