/*************************************************************************
    > File Name: book247.cpp
    > Author: Leoning
    > Mail: 1998ok4nxh@gmail.com 
    > Created Time: 2020年11月23日 星期一 15时20分24秒
 ************************************************************************/

#include <iostream>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

using namespace std;

// TCP客户端类
class CTcpClient{
public:
	int m_sockfd;
	CTcpClient();

	// 向服务器发起连接，serverip服务端ip，port通信端口
	bool Connect2Server(const char *serverip, const int port);
	// 向对端发送报文
	int Send(const void *buf, const int buflen);
	int Recv(void *buf, const int buflen);
	
	~CTcpClient();
};

int main() {
	CTcpClient TcpClient;

	// 向服务器发起连接请求
	if (TcpClient.Connect2Server("127.0.0.1", 5000)==false) {
		printf("TcpClient.Connect2Server failed, exit...\n");
		return -1;
	}
	char strbuffer[1024];
	
	for (int ii = 0; ii < 50; ii++) {
		memset(strbuffer, 0, sizeof(strbuffer));
		sprintf(strbuffer, "这是第%d个超级女生，编号%03d\n", ii+1, ii+1);
		if (TcpClient.Send(strbuffer, strlen(strbuffer)) <= 0) break;
		printf("发送：%s\n", strbuffer);
		
		memset(strbuffer, 0, sizeof(strbuffer));
		if (TcpClient.Recv(strbuffer, sizeof(strbuffer)) <= 0) break;
		printf("接收：%s\n", strbuffer);

		sleep(2);
	}
}

CTcpClient::CTcpClient() {
	m_sockfd = 0;			// 构造函数初始化m_sockfd
}

CTcpClient::~CTcpClient() {
	if (m_sockfd != 0) close(m_sockfd);
}

bool CTcpClient::Connect2Server(const char*serverip, const int port) {
	m_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	struct hostent* h;
	if ((h=gethostbyname(serverip)) == 0) {
		printf("gethostbyname failed");
		close(m_sockfd);
		m_sockfd = 0;
		return false;
	}

	// 把服务器的地址和端口转换为数据结构
	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	memcpy(&servaddr.sin_addr, h->h_addr, h->h_length);
	
	// 向服务器发起连接请求
	if (connect(m_sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
		close(m_sockfd);
		m_sockfd = 0;
		return false;
	}
	return true;
}

int CTcpClient::Send(const void *buf, const int buflen) {
	return send(m_sockfd, buf, buflen, 0);
}

int CTcpClient::Recv(void *buf, const int buflen) {
	return recv(m_sockfd, buf, buflen, 0);
}

