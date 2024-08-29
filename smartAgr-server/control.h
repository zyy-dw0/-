#ifndef CONTROL_H
#define CONTROL_H

#include "common.h"

/*
@brief 打印数据帧
@param data 数据帧
@param len 数据帧的长度
*/
void printFrame(unsigned char*data, int len);

/*
@brief 线程入口函数,处理客户端连接
@param arg 套接字描述符
@return NULL
*/
void* handle_clnt(void *arg);

/*	
@brief: 收到从ARM端发来的实时数据或节点状态，从数据库中提取节点对应的区域ID，加到数据值后，再转发给所有在线用户
@param: clnt_sock 客户套接字
@param: data 数据帧
@param: len 数据帧总长		
*/
void recv_arm_data(int clnt_sock, unsigned char*data, int len);

// 注册请求
void request_register(int clnt_sock, unsigned char*data, int len);

// 登录请求
void request_login(int clnt_sock, unsigned char*data, int len);

// 处理信号
void handle_signal(int signo);

//客户下线，移除其socket
void removeSocket(int clnt_sock);

// 保存PC节点的设置
void save_zigbee_addr(int clnt_sock, unsigned char* data, int len);
// 保存zigbee节点类型
void save_zigbee_type(unsigned char*data, int len);

// 查询设备信息
void query_device(int clnt_sock);

// 控制设备
void control_device(int clnt_sock, unsigned char* data, int len);

// 修改配置
void change_setting(unsigned char*data, int len);

// 查询配置
void query_setting(int clnt_sock);

// 查询区域数量、节点数量
void query_setting_amount(int clnt_sock);

// 查询节点ID与区域ID的对应关系
void query_setting_zid_aid(int clnt_sock);

// 查询执行器的域值
void query_setting_threshold(int clnt_sock);

// 根据设备类型获取数据类型
int threshold_data_type(int dev_type);


#endif