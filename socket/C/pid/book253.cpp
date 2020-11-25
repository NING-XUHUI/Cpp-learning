/*************************************************************************
    > File Name: book253.cpp
    > Author: Leoning
    > Mail: 1998ok4nxh@gmail.com 
    > Created Time: 2020年11月22日 星期日 19时59分37秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;

void fatchfunc() {
	printf("我是老子，我喜欢孩子他娘\n");
}

void childfunc() {
	printf("我是儿子，我喜欢西施\n");
}

int main() {
	if (fork() > 0) {
		printf("这是父进程，将调用fatchfunc().\n");
		fatchfunc();
	} else {
		printf("这是子进程，将调用childfunc().\n");
		childfunc();
	}

	sleep(1);
	printf("父子进程执行完自己的函数后，都会来到这里。%d\n", getpid());
	return 0;
}

