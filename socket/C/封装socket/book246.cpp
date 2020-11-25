/*************************************************************************
    > File Name: book246.cpp
    > Author: Leoning
    > Mail: 1998ok4nxh@gmail.com 
    > Created Time: 2020年11月23日 星期一 14时59分29秒
 ************************************************************************/

#include <iostream>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
using namespace std;

int initServer(int port);

int main(){
	int listenfd = initServer(5051);			// 服务端用于监听的socket
	if (listenfd <= 0) {
		printf("服务端初始化失败，程序退出\n");
		return -1;
	}
	
	// 接收客户端连接
	int clientfd;								// 客户端的socket
	if ((clientfd = accept(listenfd, 0, 0)) <= 0) {
		printf("服务端accept失败，程序退出\n");
		return -1;
	}
	printf("客户端已连接\n");
	// 与客户端通信，接收客户端发过来的报文，回复ok
	char strbuffer[1024];

	while(1) {
		memset(strbuffer, 0, sizeof(strbuffer));
		if (recv(clientfd, strbuffer, sizeof(strbuffer), 0) <= 0) {
			break;
		}
		printf("接收：%s\n", strbuffer);
		strcpy(strbuffer, "ok");
		if (send(clientfd, strbuffer, strlen(strbuffer), 0) <= 0) {
			break;
		}
		printf("发送：%s\n", strbuffer);

	}
	printf("客户端已断开连接\n");
	close(clientfd);
	close(listenfd);
}

int initServer(int port) {
	int listenfd = socket(AF_INET, SOCK_STREAM, 0);

	// 把服务端用于通信的地址和端口绑定到socket上
	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(port);
	if (bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
		perror("bind");
		close(listenfd);
		return -1;
	}

	// 监听模式
	if (listen(listenfd, 5) != 0) {
		perror("listen");
		close(listenfd);
		return -1;
	}
	return listenfd;
}


