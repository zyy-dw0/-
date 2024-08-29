#ifndef DATABASE_H
#define DATABASE_H

#include "common.h"
// 数据库初始化
void init_database();

// 用户注册
bool db_register( char*uername,  char*passwd);

// 用户登录 
bool db_login( char*uername,  char*passwd);
int callback_login(void *arg, int cnt, char** values, char** header);

// 查询指定的zid是否存在
bool db_query_zid(int zid);
int callback_query_zid(void*arg, int cnt, char**values, char **header);

// 保存节点地址(即区域ID)
bool db_save_zigbee_addr(int zid, int aid);

/*
@brief: 保存节点类型
@param: zid 节点ID
@param:	dev_type 设备类型
@note:  如果保存失败，如可能是数据库表被删除了，属于严重错误，则退出进程
*/
void db_save_zigbee_type(int zid, int dev_type);

// 查询指定的zid所在的区域id
int db_query_aid(int zid);
int callback_query_aid(void*arg, int cnt, char**values, char **header);


/*
@brief 查找指定区域内的指定类型的设备zid
@param aid 区域ID
@param dev_type 设备类型
@param zids 向量容器引用，用来保存查到的同区域类的同类型的节点ID(考虑到可能有多个的情况)
@note:  
*/
void db_query_zids(int aid, int dev_type, std::vector<int> &zids);
int callback_query_zids(void*arg, int cnt, char**values, char **header);

/*
@brief 保存区域数量与节点数量
*/
void db_save_amount(int area_num, int node_num);

/*
@brief 保存设备阈值
@param dev_type 设备类型
@param down_value 下行值，达到该值则开启执行器
@param up_value 上行值，达到该值则关闭执行器
*/
void db_save_threshold(int dev_type, int down_value, int up_value); 

// 查询指定的设备类型是否存在
bool db_query_dev_type(int dev_type);
int callback_query_dev_type(void*arg, int cnt, char**values, char**header);


/*
@brief 查询区域数量与节点数量
@param stream 字符串流引用，查到的结果值以字符串的形式保存，多个值以空格隔开
*/
void db_query_amount(std::stringstream &stream);
int callback_query_amount(void*arg, int cnt, char**values, char**header);

// 查询节点与区域的对应关系
void db_query_zid_aid(std::stringstream &stream);
int callback_query_zid_aid(void*arg, int cnt, char**values, char**header);

// 查询执行器的阈值
void db_query_threshold(std::stringstream &stream);
int callback_query_threshold(void*arg, int cnt, char**values, char**header);
#endif