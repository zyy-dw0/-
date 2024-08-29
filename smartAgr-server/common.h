#ifndef COMMON_H
#define COMMON_H

/*
@brief 项目所有头文件的包装
*/
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <pthread.h>
#include <signal.h>

#include <sqlite3.h>
#include "protocol.h"
#include "network.h"
#include "database.h"
#include "control.h"

#endif



/*
@brief:
@param:
@param:
@param:
@return:
*/

/*
	printf("%s: %d\n", __FUNCTION__, __LINE__);
*/
