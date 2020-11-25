/*************************************************************************
  > File Name: client.c
  > Author: Leoning
  > Mail: 1998ok4nxh@gmail.com 
  > Created Time: 2020年11月21日 星期六 12时58分07秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {
	if (argc != 3) {
		printf("参数错误，请输入ip地址和端口号\n");
		return -1;
	}

	// 1
	int clientfd;
	if ((clientfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		return -1;
	}

	// 2
	struct hostent* h;
	if ((h = gethostbyname(argv[1])) == 0) {
		printf("gethostbyname failed\n");
		return -1;
	}

	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(argv[2]));
	memcpy(&servaddr.sin_addr, h->h_addr, h->h_length);
	if (connect(clientfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
		perror("connect");
		close(clientfd);
		return -1;
	}

	char buffer[1024];
	while(1){
		int iret;
		printf(">>>>>");
		scanf("%s",buffer);
		memset(buffer, 0, sizeof(buffer));
		if ((iret = send(clientfd, buffer, sizeof(buffer), 0)) <= 0){
			continue;
		}
		printf("我：%s", buffer);
		

		memset(buffer, 0, sizeof(buffer));
		if ((iret = recv(clientfd, buffer, sizeof(buffer), 0)) <= 0) {
			continue;
		}
		printf("%s\n",buffer);
	}
	close(clientfd);

}
