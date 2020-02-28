#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char hello[] = "hello world";

  struct sockaddr_in sa;
  int SocketFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

  if (-1 == SocketFD) {
    perror("cannot create socket");
    exit(EXIT_FAILURE);
  }

  memset(&sa, 0, sizeof(sa)); //结构体数据全部为0

  sa.sin_family = AF_INET;
  sa.sin_port = htons(2222); //监听端口2222
  sa.sin_addr.s_addr = htons(INADDR_ANY);

  if (-1 == bind(SocketFD, (struct sockaddr *)&sa, sizeof(sa))) {
    perror("bind failed");
    close(SocketFD); //若调用失败，需要将其释放
    exit(EXIT_FAILURE);
  }

  if (-1 == listen(SocketFD, 10)) { // 10是控制监听队列,但具体多少由系统决定
    perror("listen failed");
    close(SocketFD);
    exit(EXIT_FAILURE);
  }

  for (;;) {
    int ConnectFD = accept(SocketFD, NULL, NULL);
    if (0 > ConnectFD) {
      perror("accept failed");
      close(SocketFD);
      exit(EXIT_FAILURE);
    }

    int writeSize = 0;
    size_t totalWrite = 0;
    while (totalWrite < sizeof(hello)) {
      writeSize =
          write(ConnectFD, hello + totalWrite, sizeof(hello) - totalWrite);
      if (-1 == writeSize) {
        perror("write failed");
        close(ConnectFD);
        close(SocketFD);
        exit(EXIT_FAILURE);
      }
      totalWrite += writeSize;
    }
    if (-1 == shutdown(ConnectFD, SHUT_RDWR)) {
      perror("shutdown failed");
      close(ConnectFD);
      close(SocketFD);
      exit(EXIT_FAILURE);
    }
    close(ConnectFD);
  }
  close(SocketFD);

  return EXIT_SUCCESS;
}
