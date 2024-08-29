#ifndef NETWORK_H
#define NETWORK_H

// 网络初始化
int init_network(const char *port);

// 读套接字
int read_check(int fd,unsigned char *buf,int len);

#endif