/*************************************************************************
  > File Name: book261.cpp
  > Author: Leoning
  > Mail: 1998ok4nxh@gmail.com 
  > Created Time: 2020年11月23日 星期一 20时24分07秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <signal.h>
using namespace std;

class CTcpServer {
	public:
		int m_clientfd;
		int m_listenfd;

		CTcpServer();

		bool InitServer(int port);
		bool Accept();

		int Send(const void* buf, const int buflen);
		int Recv(void *buf, const int buflen);

		// void CloseClient();
		// void CloseListen();
		~CTcpServer();
};

CTcpServer TcpServer;

// SIGINT/SIGTERM
void EXIT(int sig) {
	printf("程序退出，信号=%d\n", sig);
	close(TcpServer.m_listenfd);		// 手动关闭m_listenfd
	exit(0);
}

void *pth_main(void *arg);

int main(int argc, char *argv[])
{
	// 忽略全部的信号
	for (int ii=0; ii < 50; ii++) signal(ii, SIG_IGN);	

	// 设置SIGINT/SIGTERM的处理函数
	signal(SIGINT, EXIT);
	signal(SIGTERM, EXIT);

	if (TcpServer.InitServer(5000) == false) {
		printf("服务器初始化失败，程序退出\n");
		return -1;
	}
	printf("服务器初始化成功\n");
	while(1) {
		if (TcpServer.Accept() == false) continue;

		pthread_t pthid;		// 创建一个线程，与新连接上来的客户端通信
		if (pthread_create(&pthid, NULL, pth_main, (void*)((long)TcpServer.m_clientfd)) != 0) {
			printf("创建线程失败，程序退出\n");
			return -1;
		}
		printf("与客户端通信的线程已经创建\n");
	}
}

CTcpServer::CTcpServer() {
	m_listenfd = m_clientfd = 0;
}

CTcpServer::~CTcpServer() {
	if (m_listenfd != 0) close(m_listenfd);
	if (m_clientfd != 0) close(m_clientfd);
}

bool CTcpServer::InitServer(int port) {
	if (m_listenfd != 0) {
		close(m_listenfd);
		m_listenfd = 0;
	}
	m_listenfd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(m_listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
		close(m_listenfd);
		m_listenfd = 0;
		return false;
	}
	if (listen(m_listenfd, 5) != 0) {
		close(m_listenfd);
		m_listenfd = 0;
		return false;
	}
	return true;
}

bool CTcpServer::Accept() {
	if ((m_clientfd = accept(m_listenfd, 0, 0)) <= 0) return false;
	return true;
}

int CTcpServer::Send(const void *buf, const int buflen) {
	return send(m_clientfd, buf, buflen, 0);
}

int CTcpServer::Recv(void *buf, const int buflen) {
	return recv(m_clientfd, buf, buflen, 0);
}


void *pth_main(void *arg) {
	int clientfd = (long) arg;		// arg参数为新客户端的socket
	char buffer[1024];
	while(1) {
		memset(buffer, 0, sizeof(buffer));
		if (recv(clientfd, buffer, sizeof(buffer), 0) <= 0) break;
		printf("接收：%s\n", buffer);
		strcpy(buffer, "ok");
		if (send(clientfd, buffer, strlen(buffer), 0) <= 0) break;
		printf("发送：%s\n", buffer);
	}
	printf("客户端断开连接\n");
	close(clientfd);
	pthread_exit(0);
}





