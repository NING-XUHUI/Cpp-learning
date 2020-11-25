/*************************************************************************
  > File Name: client.c
  > Author: Leoning
  > Mail: 1998ok4nxh@gmail.com 
  > Created Time: 2020年11月22日 星期日 20时42分48秒
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
	int sockfd;
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		return -1;
	}

	struct hostent* h;
	if ((h = gethostbyname(argv[1])) == 0) {
		printf("gethostbyname failed\n");
		close(sockfd);
		return -1;
	}

	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(argv[2]));
	memcpy(&servaddr.sin_addr, h->h_addr, h->h_length);
	if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
		perror("connect");
		close(sockfd);
		return -1;
	}

	char buffer[1024];
	printf("开始发送\n");
	while(1) {
		int iret;
		memset(buffer, 0, sizeof(buffer));
		scanf("%s", buffer);
		iret = send(sockfd, buffer, sizeof(buffer), 0);
		memset(buffer, 0, sizeof(buffer));
		iret = recv(sockfd, buffer, sizeof(buffer), 0);
		if (!strcmp(buffer, "bye")) {
			break;
		} else {
			printf("%s\n", buffer);
		}
	}

	close(sockfd);


	return 0;
}
