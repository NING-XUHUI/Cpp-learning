/*************************************************************************
    > File Name: book245.cpp
    > Author: Leoning
    > Mail: 1998ok4nxh@gmail.com 
    > Created Time: 2020年11月23日 星期一 14时45分38秒
 ************************************************************************/

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
using namespace std;

int connect2Sercer(const char *serverip, const int port);

int main() {
	// 向服务器发起连接请求
	int sockfd = connect2Sercer("118.89.50.198", 5051);
	if (sockfd < 0) {
		printf("连接服务器失败，程序推出\n");
		return -1;
	}
	char strbuffer[1024];
	
	// 与服务端通信，发送一个报文等待回复，然后发送下一个报文
	for (int ii = 0; ii < 10; ii++) {
		memset(strbuffer, 0, sizeof(strbuffer));
		sprintf(strbuffer, "这是第%d个超级女生，编号%03d。", ii+1, ii+1);
		if (send(sockfd, strbuffer, strlen(strbuffer), 0) <= 0) {
			break;
		}
		printf("接收：%s\n", strbuffer);
	}
	close(sockfd);
}

int connect2Sercer(const char *serverip, const int port) {
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	struct hostent* h;
	if ((h = gethostbyname(serverip)) == 0) {
		perror("gethostbyname");
		close(sockfd);
		return -1;
	}

	// 把服务器的地址和端口转换为数据结构
	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	memcpy(&servaddr.sin_addr, h->h_addr, h->h_length);

	// 向服务器发起连接请求
	if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
		perror("connect");
		close(sockfd);
		return -1;
	}

	return sockfd;
}



