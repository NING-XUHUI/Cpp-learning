/*************************************************************************
    > File Name: book254.cpp
    > Author: Leoning
    > Mail: 1998ok4nxh@gmail.com 
    > Created Time: 2020年11月22日 星期日 20时06分00秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
using namespace std;

int ii = 10;

int main() {
	int jj = 20;
	if (fork() > 0) {
		ii = 11;
		jj = 21;
		sleep(1);
		printf("父进程：ii=%d,jj=%d\n",ii,jj);
	} else {
		ii = 12;
		jj = 22;
		sleep(1);
		printf("子进程：ii=%d,jj=%d\n",ii,jj);
	}
}

