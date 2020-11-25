/*************************************************************************
    > File Name: book248.cpp
    > Author: Leoning
    > Mail: 1998ok4nxh@gmail.com 
    > Created Time: 2020年11月23日 星期一 17时21分22秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>

using namespace std;

class CTcpServer {
public:
	int m_listenfd;
	int m_clientfd;

	CTcpServer();

	bool InitServer(int port);

	bool Accept();

	// 向对端发送报文
	int Send(const void *buf, const int buflen);

	// 接收对端发送的报文
	int Recv(void *buf, const int buflen);

	~CTcpServer();
};

int main() {

	CTcpServer TcpServer;

	if (TcpServer.InitServer(5000) == false) {
		printf("TcpServer.InitServer failed, exit...\n");
		return -1;
	}
	
	if (TcpServer.Accept() == false) {
		printf("TcpServer.Accept() failed, exit...\n");
		return -1;
	}
	printf("客户端已连接\n");
	char strbuffer[1024];

	while(1) {
		memset(strbuffer, 0, sizeof(strbuffer));
		if (TcpServer.Recv(strbuffer, sizeof(strbuffer)) <= 0) break;
		printf("接收：%s\n", strbuffer);

		strcpy(strbuffer, "ok");
		if (TcpServer.Send(strbuffer, strlen(strbuffer)) <= 0) break;
		printf("发送：%s\n", strbuffer);
	}

	printf("客户端已断开连接\n");
}

CTcpServer::CTcpServer() {
	m_listenfd = m_clientfd = 0;
}

CTcpServer::~CTcpServer() {
	if (m_listenfd != 0) close(m_listenfd);
	if (m_clientfd != 0) close(m_clientfd);
}

bool CTcpServer::InitServer(int port) {
	m_listenfd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	// bind
	if (bind(m_listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
		close(m_listenfd);
		m_listenfd = 0;
		return false;
	}
	
	// listen
	if (listen(m_listenfd, 5) != 0) {
		close(m_listenfd);
		m_listenfd = 0;
		return false;
	}
	return true;
}

bool CTcpServer::Accept() {
	if ((m_clientfd = accept(m_listenfd, 0, 0)) <= 0) {
		return false;
	}
	return true;
}

int CTcpServer::Send(const void *buf, const int buflen) {
	return send(m_clientfd, buf, buflen, 0);
}

int CTcpServer::Recv(void *buf, const int buflen) {
	return recv(m_clientfd, buf, buflen, 0);
}
