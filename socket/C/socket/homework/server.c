/*************************************************************************
  > File Name: server.c
  > Author: Leoning
  > Mail: 1998ok4nxh@gmail.com 
  > Created Time: 2020年11月22日 星期日 20时19分29秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
	int listenfd;
	if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		return -1;
	}

	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(atoi(argv[1]));

	if (bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
		perror("bind");
		close(listenfd);
		return -1;
	}

	if (listen(listenfd, 5) != 0) {
		perror("listen");
		close(listenfd);
		return -1;
	}

	int clientfd;
	int socklen = sizeof(struct sockaddr_in);
	struct sockaddr_in clientaddr;
	clientfd = accept(listenfd, (struct sockaddr*)&clientaddr, (socklen_t*)&socklen);
	printf("客户端：%s 已经连接\n", inet_ntoa(clientaddr.sin_addr));
	char buffer[1024];
	while(1) {
		int iret;
		memset(buffer, 0, sizeof(buffer));
		iret = recv(clientfd, buffer, sizeof(buffer), 0);
		printf("接收:%s\n", buffer);
		if (!strcmp(buffer, "bye")) {
			iret = send(clientfd, buffer, sizeof(buffer), 0);
			break;
		}
		strcpy(buffer, "已接收，请发送下一条消息!\n");
		iret = send(clientfd, buffer, sizeof(buffer), 0);
	}


	close(listenfd);
	close(clientfd);

	return 0;
}
