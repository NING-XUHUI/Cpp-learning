/*************************************************************************
  > File Name: server.cpp
  > Author: Leoning
  > Mail: 1998ok4nxh@gmail.com 
  > Created Time: 2020年11月18日 星期三 20时13分29秒
 ************************************************************************/

/**服务端的工作流程
 * 1) 创建服务端的socket
 * 2) 把服务端用于通信的地址和端口绑定到socket上
 * 3) 把socket设置为监听模式
 * 4) 接受客户端连接
 * 5) 与客户端通信，接收客户端发过来的报文后，回复处理结果
 * 6) 不断的重复第5步，直到客户端断开连接
 * 7) 关闭socket，释放资源
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
	// 判断传入参数是否正确
	if (argc != 2) {
		printf("Using./server port\nExample:./server 5005\n\n");
		return -1;
	}

	// 第一步：创建服务端的socket
	int listenfd;
	if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		return -1;
	}

	// 第二步：把服务端用于通信的地址和端口绑定到listenfd上
	struct sockaddr_in servaddr;			// 服务端地址信息的数据结构
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;			// 协议族，在socket编程中只能是AF_INET
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);	// 任意ip地址
	// servaddr.sin_addr.s_addr = inet_addr("192.168.190.134");	// 指定ip地址
	servaddr.sin_port = htons(atoi(argv[1]));		// 指定通信端口
	if (bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
		perror("bind");
		return -1;
	}

	// 第三步：把socket设置为监听模式
	if (listen(listenfd, 5) != 0) {
		perror("listen");
		close(listenfd);
		return -1;
	}

	// 第四步：接受客户端的连接
	int clientfd;										// 客户端的socket
	int socklen = sizeof(struct sockaddr_in);			// struct sockaddr_in的大小
	struct sockaddr_in clientaddr;						// 客户端的地址信息
	clientfd = accept(listenfd, (struct sockaddr *)&clientaddr, (socklen_t *)&socklen);
	printf("客户端(%s)已经连接。\n",inet_ntoa(clientaddr.sin_addr));
	
	// 第五步：与客户端通信，接收客户端发过来的报文后，回复ok
	char buffer[1024];
	while(1) {
		int iret;
		if ((iret = recv(clientfd, buffer, sizeof(buffer), 0)) <= 0) {		// 接受客户端的请求报文
			printf("iret=%d\n", iret);
			break;
		}
		printf("接收：%s\n", buffer);

		strcpy(buffer, "ok");
		if ((iret = send(clientfd, buffer, strlen(buffer), 0)) <= 0) {		// 向客户端发送响应结果
			perror("send");
			break;
		}
		printf("发送：%s\n", buffer);
	}

	// 第六步：关闭socket，释放资源
	close(listenfd);
	close(clientfd);

}
