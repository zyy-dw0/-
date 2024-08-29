#include "common.h"

using namespace std;

pthread_mutex_t mutx = PTHREAD_MUTEX_INITIALIZER;
std::vector<int> clnt_socks;


void handle_signal(int signo)
{
	if (signo == SIGPIPE)
	{
		printf("catch SIGPIPE ....\n");
	}
}



// 处理客户端
void* handle_clnt(void *arg)
{
	// int clnt_sock = (int)arg;
	int clnt_sock = *(int*)arg;
	
	printf("%d online....\n", clnt_sock);
	
	int ret;
	while (true)
	{
		unsigned char data[256] = {0};			// 由于帧长只有一个字节，所有缓冲区256足够
		ret = read_check(clnt_sock, data, 2); 	// 先读固定的头(帧头 帧长度)
		if (ret <= 0) // 出错，退出循环
		{
			break;
		}
		int len = data[1]; 				// 取出帧长
		// printf("head len: %x  %x\n", data[0], data[1]);
		
		ret = read_check(clnt_sock, data+2, len-2); 	// 根据长度，读一帧数据	
		if (ret <= 0) // 出错，退出循环
		{
			break;
		}
		if (checkCRC(data, len) == 0)					// 如果检验失败，丢弃此帧数据
		{
			printf("检验失败...\n");
        	continue;
		}
		// 一切正常，开始处理
		CmdType cmd_type = static_cast<CmdType>(data[2]);
        switch (cmd_type)
        {
        	// 如果是注册请求
        	case CmdType::REGISTER_USER:
        		request_register(clnt_sock, data, 21);
        		break;
        	// 如果是登录请求
        	case CmdType::LOGIN_USER:
        		request_login(clnt_sock, data, 21);
        		break;
        	// 如果是arm端上传的节点数据
        	case CmdType::UPLOAD_DATA:
        		recv_arm_data(clnt_sock, data, 21);
        		break;
        	// 保存PC端设置的zigbee地址到数据库
        	case CmdType::CHANGE_ZIGBEE_ADDR:
        		save_zigbee_addr(clnt_sock, data, 21);
        		break;
        	// 查询设备信息
        	// case CmdType::QUERY_DEVICE:
        	// 	query_device(clnt_sock);
        	// 	break;
        	// 控制设备指令
        	case CmdType::CHANGE_DEVICE_STATE:
        		control_device(clnt_sock, data, 21);
        		break;	
			// 修改配置信息
			case CmdType::CHANGE_SETTING:
				change_setting(data, len);
				break;
			// 查询配置信息
			case CmdType::QUERY_SETTING:
				query_setting(clnt_sock);
				break;
        	default:
        	break;
        }
	}
	//读到0个字节，表示客户下线，退出循环
    //客户下线，移除其socket
    removeSocket(clnt_sock);
    printf("%d off line~~\n",clnt_sock);
    return NULL;
}

/*
	@brief: PC设置某节点到某区域，或从某区域移除某节点时，保存节点与区域的关联
	@param: clnt_sock 客户端套接字
	@param: data 收到的数据帧
	@param: len 数据帧总长
*/
void save_zigbee_addr(int clnt_sock, unsigned char* data, int len)
{
	int zid = data[3] | data[4]<<8;
	int aid = data[7] | data[8]<<8 | data[9]<<16 | data[10]<<24;
	printf("recv: %d_%d\n", zid, aid);
	bool ok = db_save_zigbee_addr(zid, aid);
	unsigned char ack_value = ok?1:0;
	
	// 构造一帧数据，回复PC客户端
	unsigned char cmd_type = static_cast<unsigned char>(CmdType::CHANGE_ZIGBEE_ADDR);
	unsigned char frame[21] = {0};
	frame[0] = 0x7e;		// 包头
	frame[1] = 21;
	frame[2] = cmd_type;	// 指令类型
	frame[3] = data[3];	// zid,再发回去
	frame[4] = data[4];
	frame[5] = data[5];	// 数据类型，set/unset,使用收到的值
	frame[6] = 1;			// 数据长度
	frame[7] = ack_value;	// 0表示失败，1表示成功
	setCRC16(frame, 21);
	int wr = send(clnt_sock, frame, sizeof(frame), MSG_NOSIGNAL);
	if (wr == EPIPE)
	{
		// 移除该套接字
		printf("修改zigbee地址时，%d 已断开，关闭该套接字！\n", clnt_sock);
		removeSocket(clnt_sock);
		pthread_exit(NULL);
	}
	printf("wr = %d\n", wr);
}

// 保存zigbee节点设备类型
void save_zigbee_type(unsigned char* data, int len)
{
	int zid = data[3] | data[4]<<8;
	DataType data_type = static_cast<DataType>(data[5]);
	int dev_type = dev_type = static_cast<int>(data[12]);
	db_save_zigbee_type(zid, dev_type);
}


/*
	@brief: 用户下线，从socket在线列表中移除其socket
	@param: clnt_sock 客户端套接字
*/
void removeSocket(int clnt_sock)
{
	//客户下线，移除其socket
    pthread_mutex_lock(&mutx);
    for (auto it = clnt_socks.begin(); it != clnt_socks.end(); ) 
    {
        if (*it == clnt_sock) 
        {
            it = clnt_socks.erase(it);
        } 
        else 
        {
            ++it;
        }
    }
    pthread_mutex_unlock(&mutx);
    close(clnt_sock);
}

/*
	@brief: PC端登录成功后，发会指令查询设备信息，以显示设置好的节点到区域界面
*/
void query_device(int clnt_sock)
{
	// db_query_device(clnt_sock);
}

/*
	@brief: 收到从用户发来的控制设备指令，转发给所有登录用户
*/
void control_device(int clnt_sock, unsigned char* data, int len)
{
	// 数据帧中有aid, dev_type, status,再需要根据aid,dev_type从数据查找zid
	int aid = data[11];
	int dev_type = data[12];
	std::vector<int> zids; // 可能一个区域有多个同类型的执行器，一起(逐个的)关闭/打开
	db_query_zids(aid, dev_type, zids);

	for (int i = 0; i < zids.size(); ++i)
	{
		int zid = zids.at(i);
		printf("control_device zid = %d\n", zid);
		// 用户发来的修改设备状态的数据帧中没有zid,需要加上，其它字段值保持不变
		data[3] = zid & 0xff;		// zigbee id
		data[4] = zid>>8 & 0xff;
		// 再发所有登录用户
		// printFrame(data, 21);
		pthread_mutex_lock(&mutx);
		int wr;
		for (int i = 0; i < clnt_socks.size(); ++i)
		{
			wr = send(clnt_socks.at(i), data, len, MSG_NOSIGNAL);
			if (wr == EPIPE)
			{
				// 移除该套接字
				printf("转发采集数据时，%d 已断开，关闭该套接字！\n", clnt_socks.at(i));
				removeSocket(clnt_socks.at(i));
			}
		}
		pthread_mutex_unlock(&mutx);
	}
}


void printFrame(unsigned char*data, int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%02x ", data[i]);
	}
	printf("\n");
}


void recv_arm_data(int clnt_sock, unsigned char*data, int len)
{
	// printFrame(data, len);
	int zid = data[3] | data[4]<<8;
	
	// 先保存节点类型
	save_zigbee_type(data, len);

	// 根据zid查询aid,并返回
	int aid = db_query_aid(zid);
	
	// 把区域id添加到数据值的后面，再转发
	data[11] = (unsigned char)aid;
	
	// 发送给所有登录用户
	data[2] = static_cast<char>(CmdType::DOWNLOAD_REALTIME);
	setCRC16(data, len);
	
	pthread_mutex_lock(&mutx);
	int wr;
	for (int i = 0; i < clnt_socks.size(); ++i)
	{
		wr = send(clnt_socks.at(i), data, len, MSG_NOSIGNAL);
		if (wr == EPIPE)
		{
			// 移除该套接字
			printf("转发采集数据时，%d 已断开，关闭该套接字！\n", clnt_socks.at(i));
			removeSocket(clnt_socks.at(i));
		}
	}
	pthread_mutex_unlock(&mutx);
}


void request_register(int clnt_sock, unsigned char*data, int len)
{
	char username[7] = {0};
	char passwd[7] = {0};
	strncpy(username, (const char*)data+7, 6);
	strncpy(passwd, (const char*)data+13, 6);
	printf("username: %s, passwd: %s\n", username, passwd);
	if (strlen(username) >= 0 && strlen(username) <=6 && strlen(passwd)>=0 && strlen(passwd)<=6)
	{
		bool ok = db_register(username, passwd);
		unsigned char ack_value = ok?1:0;

		// 构造一帧数据
		unsigned char cmd_type = static_cast<unsigned char>(CmdType::REGISTER_USER);
		unsigned char frame[21] = {0};
		frame[0] = 0x7e;		// 包头
		frame[1] = 21;
		frame[2] = cmd_type;	// 指令类型
		frame[6] = 1;			// 数据长度
		frame[7] = ack_value;	// 0表示失败，1表示成功
		setCRC16(frame, 21);
		int wr = send(clnt_sock, frame, sizeof(frame), MSG_NOSIGNAL);
		if (wr == EPIPE)
		{
			// 移除该套接字
			printf("注册时，%d 已断开，关闭该套接字！\n", clnt_sock);
			removeSocket(clnt_sock);
			pthread_exit(NULL);
		}
		printf("wr = %d\n", wr);
	}
	
}


// 登录工作
//1B(1)			1B(2)			2B(3-4)				1B(5)		1B(6)	12B(7-18)	2B(19-20)
//命令类型		arm-id		Zigbee节点ID(小端)		数据类型		数据长度	数据值(小端)	校验
void request_login(int clnt_sock, unsigned char*data, int len)
{
	char username[7] = {0};
	char passwd[7] = {0};
	strncpy(username, (const char*)data+7, 6);
	strncpy(passwd, (const char*)data+13, 6);
	printf("username: %s, passwd: %s\n", username, passwd);
	if (strlen(username) >= 0 && strlen(username) <=6 && strlen(passwd)>=0 && strlen(passwd)<=6)
	{
		bool ok = db_login(username, passwd);
		if (ok)
		{
			pthread_mutex_lock(&mutx);
	        clnt_socks.push_back(clnt_sock);
	        pthread_mutex_unlock(&mutx);
		}
		unsigned char ack_value = ok?1:0;

		// 构造一帧数据
		unsigned char cmd_type = static_cast<unsigned char>(CmdType::LOGIN_USER);
		unsigned char frame[21] = {0};
		frame[0] = 0x7e;
		frame[1] = 21;
		frame[2] = cmd_type;
		frame[6] = 1;
		frame[7] = ack_value;
		setCRC16(frame, 21);
		printf("request_login clnt_sock: %d\n", clnt_sock);
		int wr = send(clnt_sock, frame, sizeof(frame), MSG_NOSIGNAL);
		if (wr == EPIPE)
		{
			// 移除该套接字
			printf("登录时，%d 已断开，关闭该套接字！\n", clnt_sock);
			removeSocket(clnt_sock);
		}
		printf("wr = %d\n", wr);
	}

}


int checkCRC(unsigned char *BytesFrame,int length)
{
    int Preset_Value = 0xFFFF;
    int Polynomial = 0xA001;
    for (int i = 0; i < length - 2; i++)
    {
        Preset_Value ^= (BytesFrame[i] & 0xff);
        for (int j = 0; j < 8; j++)
        {
            if ((Preset_Value & 0x0001) != 0)
            {
                Preset_Value = (Preset_Value >> 1) ^ Polynomial;
            }
            else
            {
                Preset_Value = (Preset_Value >> 1);
            }
        }
    }
    unsigned char retH = (unsigned char) ((Preset_Value & 0xFF00) >> 8);
    unsigned char retL = (unsigned char) (Preset_Value & 0xFF);
    if (retL == BytesFrame[length - 2] && retH == BytesFrame[length - 1])
        return 1;
    else
        return 0;
}

void setCRC16(unsigned char *BytesFrame, int length)
{
    int Preset_Value = 0xFFFF;
    int Polynomial = 0xA001;
    for (int i = 0; i < length - 2; i++)
    {
        Preset_Value ^= (BytesFrame[i] & 0xff);
        for (int j = 0; j < 8; j++)
        {
            if ((Preset_Value & 0x0001) != 0)
            {
                Preset_Value = (Preset_Value >> 1) ^ Polynomial;
            }
            else
            {
                Preset_Value = (Preset_Value >> 1);
            }
        }
    }
    BytesFrame[length - 2] = (unsigned char) (Preset_Value & 0xFF);
    BytesFrame[length - 1] = (unsigned char) ((Preset_Value & 0xFF00) >> 8);
}


// 修改配置
void change_setting(unsigned char*data, int len)
{
	DataType data_type = static_cast<DataType>(data[5]);
	switch(data_type)
	{
		case DataType::SET_AMOUNT:
			db_save_amount(data[7], data[8]|data[9]<<8); // area_num, node_num
		break;

		case DataType::SET_ZIGBEE:
			db_save_zigbee_addr(data[3]|data[4]<<8, data[11]);// zid, aid
		break;

		case DataType::LAMP_THRESHOLD:
		case DataType::FAN_THRESHOLD:
		case DataType::HUMI_THRESHOLD:
		case DataType::CURTAIN_THRESHOLD:
			db_save_threshold(data[12], data[7]|data[8]<<8, data[9]|data[10]<<8); // dev-type, down_value, up_value
		break;

		default:
		break;
	}
}

// 查询配置
void query_setting(int clnt_sock)
{
	// 查询amount
	query_setting_amount(clnt_sock);
	
	// 查询zid-aid
	query_setting_zid_aid(clnt_sock);
	
	// 查询threshold
	query_setting_threshold(clnt_sock);
}

void query_setting_amount(int clnt_sock)
{
	std::stringstream stream;
	db_query_amount(stream);
	int area_num, node_num;
	stream >> area_num >> node_num;
	unsigned char frame[21] = {0};
	frame[0] = 0x7e;
	frame[1] = 21;
	frame[2] = CmdType::QUERY_SETTING;
	frame[5] = DataType::SET_AMOUNT;
	frame[6] = 3;
	frame[7] = area_num;
	frame[8] = node_num & 0xff;
	frame[9] = (node_num>>8) & 0xff;
	setCRC16(frame, sizeof(frame));
	send(clnt_sock, frame, sizeof(frame), MSG_NOSIGNAL);
}


void query_setting_zid_aid(int clnt_sock)
{
	std::stringstream stream;
	db_query_zid_aid(stream);
	int zid, aid;
	unsigned char frame[21] = {0};
	frame[0] = 0x7e;
	frame[1] = 21;
	frame[2] = CmdType::QUERY_SETTING;
	frame[5] = DataType::SET_ZIGBEE;
	while (true)
	{
		stream >> zid >> aid;
		if (stream.fail())
		{
			break;
		}
		frame[3] = zid & 0xff;
		frame[4] = (zid>>8) & 0xff;
		frame[11] = aid;
		setCRC16(frame, sizeof(frame));
		send(clnt_sock, frame, sizeof(frame), MSG_NOSIGNAL);
	}
}


void query_setting_threshold(int clnt_sock)
{
	std::stringstream stream;
	db_query_threshold(stream);
	int dev_type, down_value, up_value;
	unsigned char frame[21] = {0};
	frame[0] = 0x7e;
	frame[1] = 21;
	frame[2] = CmdType::QUERY_SETTING;
	frame[6] = 4;
	while (true)
	{
		stream >> dev_type >> down_value >> up_value;
		if (stream.fail())
		{
			break;
		}
		frame[5] = threshold_data_type(dev_type);
		frame[7] = down_value & 0xff;
		frame[8] = (down_value>>8) & 0xff;
		frame[9] = up_value & 0xff;
		frame[10] = (up_value>>8) & 0xff;
		frame[12] = dev_type;
		setCRC16(frame, sizeof(frame));
		send(clnt_sock, frame, sizeof(frame), MSG_NOSIGNAL);
	}
}

int threshold_data_type(int dev_type)
{
	switch (dev_type)
	{
		case DevType::ACTUATOR_LAMP:
			return DataType::LAMP_THRESHOLD;
		case DevType::ACTUATOR_HUMI:
			return DataType::HUMI_THRESHOLD;
		case DevType::ACTUATOR_FAN:
			return DataType::FAN_THRESHOLD;
		case DevType::ACTUATOR_CURTAIN:
			return DataType::CURTAIN_THRESHOLD;
		default:
			return 0;
	}
}

