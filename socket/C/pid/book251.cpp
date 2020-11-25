/*************************************************************************
    > File Name: p1.cpp
    > Author: Leoning
    > Mail: 1998ok4nxh@gmail.com 
    > Created Time: 2020年11月22日 星期日 19时33分20秒
 ************************************************************************/

#include<iostream>
using namespace std;

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	printf("本程序的进程编号是：%d\n", getpid());
	sleep(30);
}

