#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Using./server port\nExample:./server 5005\n\n");
        return -1;
    }
    
    // 创建服务端的socket
    int listenfd;
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return -1;
    }
    
    // 把服务端用于通信的地址和端口绑定到listenfd上
    struct sockaddr_in servaddr;                    // 服务端地址信息的数据结构
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;                  // 协议族，在socket编程中只能是AF_INET
    servaddr.sin_port = htons(atoi(argv[1]));       // 指定通信端口号
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);   // 任意ip地址
    //servaddr.sin_addr.s_addr = inet_addr("xxx,xxx,xxx,xxx");
    
    if (bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        perror("bind");
        return -1;
    }
    
    // 把socket设置为监听模式
    if (listen(listenfd, 5) != 0) {
        perror("listen");
        close(listenfd);
        return -1;
    }
    
    
}
