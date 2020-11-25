/*************************************************************************
    > File Name: book252.cpp
    > Author: Leoning
    > Mail: 1998ok4nxh@gmail.com 
    > Created Time: 2020年11月22日 星期日 19时39分55秒
 ************************************************************************/

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
using namespace std;

int main() {
	printf("本程序的进程编号是：%d\n", getpid());

	int ipid = fork();
	
	sleep(1);
	printf("pid=%d\n", ipid);
	
	if (ipid!=0) printf("父进程编号是：%d\n", getpid());
	else printf("子进程编号是：%d\n", getpid());

	sleep(30);
}
