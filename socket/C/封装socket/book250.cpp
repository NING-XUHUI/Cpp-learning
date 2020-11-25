/*************************************************************************
  > File Name: book250.cpp
  > Author: Leoning
  > Mail: 1998ok4nxh@gmail.com 
  > Created Time: 2020年11月23日 星期一 17时50分04秒
 ************************************************************************/

#include<iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

using namespace std;

class CTcpServer {
	public:
		int m_listenfd;
		int m_clientfd;

		CTcpServer();
		bool InitServer(int port);
		bool Accept();

		int Send(const void *buf, const int buflen);
		int Recv(void *buf, const int buflen);

		void CloseClient();
		void CloseListen();

		~CTcpServer();
};

CTcpServer TcpServer;

int main(int argc, char *argv[])
{
	// signal(SIGCHLD, SIG_IGN);
	if (TcpServer.InitServer(5000) == false) {
		printf("服务端初始化失败，程序退出\n");
		return -1;
	}

	while(1) {
		if (TcpServer.Accept() == false) continue;

		if (fork() > 0) {
			TcpServer.CloseClient();
			continue;
		}
		// 子进程负责与客户端通信，指导可以客户端断开连接
		TcpServer.CloseListen();

		printf("客户端已连接\n");

		// 与客户端通信
		char strbuffer[1024];

		while(1) {
			memset(strbuffer, 0, sizeof(strbuffer));
			if (TcpServer.Recv(strbuffer, sizeof(strbuffer)) <= 0) break;
			printf("接收：%s\n", strbuffer);

			strcpy(strbuffer, "ok");
			if (TcpServer.Send(strbuffer, strlen(strbuffer)) <= 0) break;
			printf("发送：%s\n", strbuffer);
		}
		printf("客户端断开连接\n");
		return 0;
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

void CTcpServer::CloseClient() {
	if (m_clientfd != 0) {
		close(m_clientfd);
		m_clientfd = 0;
	}
}

void CTcpServer::CloseListen() {
	if (m_listenfd != 0) {
		close(m_listenfd);
		m_listenfd = 0;
	}
}

