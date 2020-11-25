/*************************************************************************
    > File Name: book257.cpp
    > Author: Leoning
    > Mail: 1998ok4nxh@gmail.com 
    > Created Time: 2020年11月23日 星期一 19时27分26秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

using namespace std;

void EXIT(int sig) {
	printf("收到了信号%d,程序退出\n", sig);
	exit(0);					// 程序退出
}

int main(int argc, char *argv[])
{
	for (int ii = 0; ii < 100; ii++) {
		signal(ii, SIG_IGN);	// 屏蔽全部的信号
	}
	signal(SIGINT, EXIT);
	signal(SIGTERM, EXIT);		// 设置sigint和sigterm的处理函数
	while(1) {					// 死循环
		sleep(10);
	}
	return 0;
}

