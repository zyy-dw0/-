#include "common.h"

int init_network(const char *port)
{
	//创建套接字
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd == -1)
	{
		perror("socket error:");
		exit(-1);
	}
	//设置套接字选项，允许地址重用
	int opt = 1;
	if(setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,(void*)&opt,sizeof(opt)) == -1)
	{
		perror("setsockopt error:");
		exit(-1);
	}
	//准备服务器的地址
	struct sockaddr_in saddr;
	memset(&saddr,0,sizeof(saddr));
	saddr.sin_family = AF_INET;
	saddr.sin_port =htons(atoi(port));
	saddr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	//绑定
	if(bind(sockfd,(struct sockaddr*)&saddr,sizeof(saddr)) == -1 )
	{
		perror("bind error:");
		exit(-1);
	}
	int condf = listen(sockfd,10);
	if(condf == -1)
	{
		perror("listen error");
		exit(1);
	}
	printf("net work init success ！   \n");
	return sockfd;
}


int read_check(int fd,unsigned char *buf,int len)
{
	int read_bytes = 0;
	int r;
	while (read_bytes < len)
	{
		r = read(fd, buf + read_bytes, len - read_bytes);
		if (r > 0)
		{
			read_bytes += r;
		}
		else if (r <= 0)
		{
			perror("read error");
			return -1;
		}
	}
	return read_bytes;
}

