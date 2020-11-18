/*************************************************************************
    > File Name: client.cpp
    > Author: Leoning
    > Mail: 1998ok4nxh@gmail.com 
    > Created Time: 2020年11月18日 星期三 20时40分45秒
 ************************************************************************/

/**客户端的工作流程
 * 1) 创建客户端socket
 * 2) 向服务器发送连接请求
 * 3) 与服务器通信，发送一个报文后等待回复，然后发送下一个报文
 * 4) 不断重复第三步，指导全部的数据都被发送完
 * 5) 关闭socket，释放资源
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
	
	// 查看参数是否正确
	if (argc != 3) {
		printf("Using:./client ip port\nExample:./client 127.0.0.1 5005\n\n");
		return -1;
	}
	
	// 第一步：创建客户端socket
	int sockfd;
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		return -1;
	}

	// 第二步：向服务器发送连接请求
	struct hostent* h;
	if ((h = gethostbyname(argv[1])) == 0) {				// 指定服务端的ip地址
		printf("gethostbyname failed.\n");
		close(sockfd);
		return -1;
	}
	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(argv[2]));				// 指定服务端的通信端口
	memcpy(&servaddr.sin_addr, h->h_addr, h->h_length);
	if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
		perror("connect");
		close(sockfd);
		return -1;
	}

	char buffer[1024];
	// 第三步：与服务器通信，发送一个报文后等待回复，然后再发下一个报文
	for (int ii = 0; ii < 3; ii++) {
		int iret;
		memset(buffer, 0, sizeof(buffer));
		sprintf(buffer, "这是第%d个超级女生，编号%03d。", ii+1, ii+1);
		if ((iret = send(sockfd, buffer, strlen(buffer), 0)) <= 0) {
			perror("send");
			break;
		}
		printf("发送：%s\n", buffer);

		memset(buffer, 0, sizeof(buffer));
		if ((iret = recv(sockfd, buffer, sizeof(buffer), 0)) <= 0) {
			printf("iret=%d\n", iret);
			break;
		}
		printf("接收：%s\n", buffer);
	}
	close(sockfd);
}
