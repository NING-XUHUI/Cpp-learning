/*************************************************************************
  > File Name: server_biz.cpp
  > Author: Leoning
  > Mail: 1998ok4nxh@gmail.com 
  > Created Time: 2020年11月28日 星期六 13时59分19秒
 ************************************************************************/

#include "../freeplus/freecplus/_freecplus.h"

CLogFile logfile;
CTcpServer TcpServer;		// 创建服务端对象

// 程序退出时调用的函数
// void FathEXIT(int sig);		// 父进程退出
// void ChldEXIT(int sig);		// 子进程退出

// 处理业务的主函数
bool _main(const char *strrecvbuffer, char *strsendbuffer);

// 身份验证业务处理函数
bool biz001(const char *strrecvbuffer, char *strsendbuffer);

int main(int argc, char *argv[])
{
	if (argc != 3) {
		printf("invalid input\n");
		return -1;
	}
	if (TcpServer.InitServer(5000) == false) {
		printf("客户端初始化失败\n");
	}
	char strrecvbuffer[1024];
	char strsendbuffer[1024];

	while (true){
		TcpServer.Accept();
		if (fork() > 0) {
			continue;
		}
		
		while (true) {
			memset(strrecvbuffer, 0, sizeof(strrecvbuffer));
			memset(strsendbuffer, 0, sizeof(strsendbuffer));

			if (TcpServer.Read(strrecvbuffer, 80) == false) break;
			logfile.Write("接收:%s\n", strrecvbuffer);

			// 处理主业务函数
			if (_main(strrecvbuffer, strsendbuffer) == false) return -1; 

			logfile.Write("发送：%s\n", strsendbuffer);

			if (TcpServer.Write(strsendbuffer) == false) break;
		}
		logfile.Write("客户端已断开\n");
		exit(0);
	}
}

bool _main(const char* strrecvbuffer, char* strsendbuffer) {
	int ibizcode = -1;
	GetXMLBuffer(strrecvbuffer, "bizcode", &ibizcode);

	switch (ibizcode) {
		case 1: 
			biz001(strrecvbuffer, strsendbuffer); break;
		default:
			logfile.Write("非法报文:%s\n", strrecvbuffer); return false;
	}
	return true;
}

bool biz001(const char* strrecvbuffer, char* strsendbuffer) {
	char username[51];
	char password[51];
	memset(username, 0, sizeof(username));
	memset(password, 0, sizeof(password));

	GetXMLBuffer(strrecvbuffer, "username", username, 50);
	GetXMLBuffer(strrecvbuffer, "password", password, 50);

	if ((strcmp(username, "wucz") == 0) && (strcmp(password, "p@ssw0rd") == 0)) {
		return true;
	}

	return false;
}

