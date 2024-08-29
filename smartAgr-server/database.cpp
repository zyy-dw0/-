#include "common.h"


static sqlite3* db;

void init_database()
{
	int r = sqlite3_open("./alg.db", &db);
	if (r != SQLITE_OK)
	{
		fprintf(stderr, "open db error: %s\n", sqlite3_errmsg(db));
		throw sqlite3_errmsg(db);
	}

	const char *sql = "create table if not exists t_user(username text primary key, passwd text not null, perm int default 0);";
	sqlite3_exec(db, sql, NULL, NULL, NULL);	
	sql = "create table if not exists t_device(zigbee_id int primary key, dev_type int default 0,area_id int default 0, dev_status int default 0);";
	sqlite3_exec(db, sql, NULL, NULL, NULL);

	sql = "create table if not exists t_amount(arm_id integer primary key, area_num int default 9, node_num default 100);";
	sqlite3_exec(db, sql, NULL, NULL, NULL);
	sql = "insert into t_amount(arm_id, area_num, node_num)values(1, 9, 100);";
	sqlite3_exec(db, sql, NULL, NULL, NULL);

	sql = "create table if not exists t_threshold(dev_type int primary key, down_value int default 0, up_value int default 0);";	
	sqlite3_exec(db, sql, NULL, NULL, NULL);
}

bool db_register( char*username,  char*passwd)
{
	char sql[1024] = {0};
	sprintf(sql, "insert into t_user(username, passwd) values ('%s', '%s');", username, passwd);
	printf("reg sql: %s\n", sql);

	char *errmsg;
	int r = sqlite3_exec(db, sql, NULL, NULL, &errmsg);
	if (r != SQLITE_OK)
	{
		fprintf(stderr, "insert error: %s\n", errmsg);
		sqlite3_free(errmsg);
		return false;
	}
	return true;
}

bool db_login( char*username,  char*passwd)
{
	char sql[1024] = {0};
	sprintf(sql, "select username, passwd from t_user where username='%s' and passwd='%s';", username, passwd);
	char *errmsg;
	bool ok = false;
	int r = sqlite3_exec(db, sql, callback_login, (void*)&ok, &errmsg);
	if (r != SQLITE_OK)
	{
		fprintf(stderr, "insert error: %s\n", errmsg);
		sqlite3_free(errmsg);
		return ok;
	}
	return ok;
}

bool db_query_zid(int zid)
{
	char sql[1024] = {0};
	sprintf(sql, "select zigbee_id from t_device where zigbee_id=%d;", zid);
	char *errmsg;
	bool ok = false;
	int r = sqlite3_exec(db, sql, callback_query_zid, (void*)&ok, &errmsg);
	if (r != SQLITE_OK)
	{
		fprintf(stderr, "insert error: %s\n", errmsg);
		sqlite3_free(errmsg);
		exit(-1);
	}
	return ok;
}
int callback_query_zid(void*arg, int cnt, char**values, char **header)
{
	*(bool*)arg = true;
	return 0;
}

void db_query_zids(int aid, int dev_type, std::vector<int> &zids)
{
	char sql[1024] = {0};
	sprintf(sql, "select zigbee_id from t_device where area_id=%d and dev_type=%d;", aid, dev_type);
	printf("sql = %s\n", sql);
	char *errmsg;
	int r = sqlite3_exec(db, sql, callback_query_zids, (void*)&zids, &errmsg);
	if (r != SQLITE_OK)
	{
		fprintf(stderr, "insert error: %s\n", errmsg);
		sqlite3_free(errmsg);
		exit(-1);
	}
}
int callback_query_zids(void*arg, int cnt, char**values, char **header)
{
	int zid = atoi(values[0]);
	printf("%s, %d\n", __FUNCTION__, zid);
	static_cast<std::vector<int>* >(arg)->push_back(zid);
	return 0;
}

bool db_save_zigbee_addr(int zid, int aid)
{
	// 查询是否有该节点的记录
	bool ok = db_query_zid(zid);
	
	char sql[1024] = {0};
	char *errmsg;
	if (ok)	// 如果有，则修改
	{
		sprintf(sql, "update t_device set area_id=%d where zigbee_id=%d;", aid, zid);	
	}
	// 如果没有，则添加
	else
	{
		sprintf(sql, "insert into t_device(zigbee_id,area_id) values(%d, %d);", zid, aid);	
	}
	
	int r = sqlite3_exec(db, sql, NULL, NULL, &errmsg);
	if (r != SQLITE_OK)
	{
		fprintf(stderr, "save zigbee addr error: %s\n", errmsg);
		sqlite3_free(errmsg);
		return false;
	}
	return true;	
}

void db_save_zigbee_type(int zid, int dev_type)
{
	// 查询是否有该节点的记录
	bool ok = db_query_zid(zid);
	
	char sql[1024] = {0};
	char *errmsg;
	if (ok)	// 如果有，则修改
	{
		sprintf(sql, "update t_device set dev_type=%d where zigbee_id=%d;", dev_type, zid);	
	}
	// 如果没有，则添加
	else
	{
		sprintf(sql, "insert into t_device(zigbee_id,dev_type) values(%d, %d);",zid, dev_type);	
	}
	
	int r = sqlite3_exec(db, sql, NULL, NULL, &errmsg);
	if (r != SQLITE_OK)
	{
		fprintf(stderr, "save zigbee dev_type error: %s\n", errmsg);
		sqlite3_free(errmsg);
		exit(1);
	}
}


int callback_login(void *arg, int cnt, char** values, char** header)
{
	*(bool*)arg = true;
	return 0;
}



int db_query_aid(int zid)
{
	char sql[1024] = {0};
	sprintf(sql, "select area_id from t_device where zigbee_id=%d;", zid);
	char *errmsg;
	int aid = 0;
	int r = sqlite3_exec(db, sql, callback_query_aid, (void*)&aid, &errmsg);
	if (r != SQLITE_OK)
	{
		fprintf(stderr, "select aid error: %s\n", errmsg);
		sqlite3_free(errmsg);
		exit(-1);
	}
	return aid;
}
int callback_query_aid(void*arg, int cnt, char**values, char **header)
{
	*(int*)arg = atoi(values[0]);
	return 0;
}



/*
@brief 修改域数量与节点数量
*/
void db_save_amount(int area_num, int node_num)
{
	char sql[1024] = {0};
	sprintf(sql, "update t_amount set area_num=%d, node_num=%d where arm_id=1;", area_num, node_num);
	
	char *errmsg;
	int ret = sqlite3_exec(db, sql, NULL, NULL, &errmsg);	
	if (ret != SQLITE_OK)
	{
		fprintf(stderr, "update amount error: %s\n", errmsg);
		sqlite3_free(errmsg);
		exit(-1);
	}
	printf("db_save_amount success!!\n");
}

/*
@brief 保存设备阈值
*/
void db_save_threshold(int dev_type, int down_value, int up_value)
{
	// 查询指定的设备类型是否存在
	bool exist= db_query_dev_type(dev_type);
	char sql[100] = {0};
	// 存在则修改
	if (exist)
	{
		sprintf(sql, "update t_threshold set down_value=%d, up_value=%d where dev_type=%d;",down_value, up_value, dev_type);
	}	
	// 不存在则添加
	else
	{
		sprintf(sql, "insert into t_threshold(dev_type, down_value, up_value)values(%d, %d, %d);", dev_type, down_value, up_value);
	}
	char*errmsg;
	int ret = sqlite3_exec(db, sql, NULL, NULL, &errmsg);
	if (ret != SQLITE_OK)
	{
		fprintf(stderr, "db_save_threshold error: %s\n", errmsg);
		sqlite3_free(errmsg);
		exit(-1);
	}
}

bool db_query_dev_type(int dev_type)
{
	char sql[100] = {0};
	sprintf(sql, "select dev_type from t_threshold where dev_type=%d;", dev_type);
	bool exist = false;
	char*errmsg;
	int ret = sqlite3_exec(db, sql, callback_query_dev_type, (void*)&exist, &errmsg);
	if (ret != SQLITE_OK)
	{
		fprintf(stderr, "query dev type error: %s\n", errmsg);
		sqlite3_free(errmsg);
		exit(-1);
	}
	return exist;
}

int callback_query_dev_type(void*arg, int cnt, char**values, char**header)
{
	*(bool*)arg = true;
	return 0;
}



void db_query_amount(std::stringstream &stream)
{
	const char *sql = "select area_num, node_num from t_amount where arm_id=1;";
	char *errmsg;
	int ret = sqlite3_exec(db, sql, callback_query_amount, (void*)&stream, &errmsg);
	if (ret != SQLITE_OK)
	{
		fprintf(stderr, "query amount error: %s\n", errmsg);
		sqlite3_free(errmsg);
		exit(-1);
	}
}

int callback_query_amount(void*arg, int cnt, char**values, char**header)
{
	(*(std::stringstream*)arg) << values[0] << " " << values[1];
	return 0;
}


void db_query_zid_aid(std::stringstream &stream)
{
	const char *sql = "select zigbee_id, area_id from t_device where zigbee_id > 0;";
	char *errmsg;
	int ret = sqlite3_exec(db, sql, callback_query_zid_aid, (void*)&stream, &errmsg);
	if (ret != SQLITE_OK)
	{
		fprintf(stderr, "query zid_aid error: %s\n", errmsg);
		sqlite3_free(errmsg);
		exit(-1);
	}
}

int callback_query_zid_aid(void*arg, int cnt, char**values, char**header)
{
	(*(std::stringstream*)arg) << values[0] << " " << values[1] << " ";
	return 0;	
}



void db_query_threshold(std::stringstream &stream)
{
	const char *sql = "select dev_type, down_value, up_value from t_threshold;";
	char *errmsg;
	int ret = sqlite3_exec(db, sql, callback_query_threshold, (void*)&stream, &errmsg);
	if (ret != SQLITE_OK)
	{
		fprintf(stderr, "db_query_threshold error: %s\n", errmsg);
		sqlite3_free(errmsg);
		exit(-1);
	}	
}
int callback_query_threshold(void*arg, int cnt, char**values, char**header)
{
	(*(std::stringstream*)arg) << values[0] << " " << values[1] << " " << values[2] << " ";
	return 0;
}
