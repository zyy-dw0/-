#include "common.h"


// 主函数
int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <server-port>\n", argv[0]);
		return 1;
	}
	signal(SIGPIPE, handle_signal);
	init_database(); 						// 初始化数据库
	int serv_sock = init_network(argv[1]);	// 初始化网络

	while (true)
	{
		//.接受连接
		int clnt_sock = accept(serv_sock, NULL, NULL);//阻塞函数，如果没有连接，则等待
		if (clnt_sock == -1)
		{
			perror("accept error");
			exit(1);
		}
		
		// 创建新线程处理连接
		pthread_t  tid;
		pthread_create(&tid,NULL,handle_clnt,(void*)&clnt_sock);
        pthread_detach(tid);
	}

	close(serv_sock);
	return 0;
}