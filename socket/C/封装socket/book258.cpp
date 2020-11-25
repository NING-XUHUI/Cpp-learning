/*************************************************************************
    > File Name: book258.cpp
    > Author: Leoning
    > Mail: 1998ok4nxh@gmail.com 
    > Created Time: 2020年11月23日 星期一 19时36分28秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
using namespace std;

int main(int argc, char *argv[])
{
	int shmid;				// 共享内存标识符
	
	// 创建共享内存，键值为0x5005,共1024个字节
	if ((shmid = shmget((key_t)0x5005, 1024, 0640|IPC_CREAT)) == -1) {
		printf("shmat(0x5005) failed\n");
		return -1;
	}

	char *ptext = 0;		// 用于指向共享内存的指针

	// 将共享内存连接到当前进程的地址空间，由ptext指针指向他
	ptext = (char*)shmat(shmid, 0, 0);
	
	// 操作本程序的ptext指针，就是操作共享内存
	printf("写入前：%s\n", ptext);
	sprintf(ptext, "本程序的进程号是：%d\n", getpid());
	printf("写入后：%s\n", ptext);

	// 将共享内存从当前进程中分离
	shmdt(ptext);

	// 删除共享内存
	if (shmctl(shmid, IPC_RMID, 0) == -1) {
		printf("shmctl(0x5005) failed\n");
		return -1;
	}

	return 0;
}

