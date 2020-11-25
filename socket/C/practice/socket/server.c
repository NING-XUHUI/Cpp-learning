/*************************************************************************
  > File Name: server.c
  > Author: Leoning
  > Mail: 1998ok4nxh@gmail.com 
  > Created Time: 2020年11月21日 星期六 12时38分30秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printf("参数错误，请加上端口号\n");
		return -1;
	}

	// 1 
	int listenfd;
	if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		return -1;
	}

	// 2
	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	// servaddr.sin_addr.s_addr = inet_addr("xxx,xxx,xxx,xxx");
	servaddr.sin_port = htons(atoi(argv[1]));
	if(bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
		perror("bind");
		return -1;
	}

	// 3
	if (listen(listenfd, 5) != 0) {
		perror("listen");
		close(listenfd);
		return -1;
	}

	// 4
	int clientfd;
	int socklen = sizeof(struct sockaddr_in);
	struct sockaddr_in clientaddr;

	clientfd = accept(listenfd, (struct sockaddr*)&clientaddr, (socklen_t*)&socklen);
	printf("客户端%s已经连接\n",inet_ntoa(clientaddr.sin_addr));

	char buffer[1024];
	while(1) {
		int iret;
		if ((iret = recv(clientfd, buffer, sizeof(buffer), 0)) <= 0){
			continue;
		}
//		printf("%s\n", buffer);
		
		if ((iret = send(clientfd, buffer, strlen(buffer), 0)) <= 0) {
			perror("send");
			continue;
		}		
	}
	close(listenfd);
	close(clientfd);
}

