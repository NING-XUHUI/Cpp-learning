/*************************************************************************
  > File Name: book259.cpp
  > Author: Leoning
  > Mail: 1998ok4nxh@gmail.com 
  > Created Time: 2020年11月23日 星期一 19时46分02秒
 ************************************************************************/

#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
using namespace std;

class CSEM {
	private:
		union semun {			// 用于信号灯操作的共同体
			int val;
			struct semid_ds *buf;
			unsigned short *arry;
		};

		int sem_id;				// 信号灯描述符
	public:
		bool init(key_t key);	// 如果信号灯已经存在，获取信号灯，如果不存在，则创建并初始化
		bool wait();			// 等待信号灯挂出
		bool post();			// 挂出信号灯
		bool destory();			// 销毁信号灯
};

int main(int argc, char *argv[])
{
	CSEM sem;

	// 初始化信号灯
	if (sem.init(0x5000) == false) {
		printf("sem.init failed\n");
		return -1;
	}
	printf("sem.init ok\n");

	// 等待信号等挂出，等待成功后，将持有锁
	if (sem.wait() == false) {
		printf("sem.wait failed.\n");
		return -1;
	}
	printf("sem.wait ok\n");

	sleep(50);				// 在sleep过程中，运行其他的本程序将等待锁

	// 挂出信号灯，释放锁
	if (sem.post() == false) {
		printf("sem.post failed\n");
		return -1;
	}
	printf("sem.post ok\n");

	// 销毁信号灯
	// if (sem.destory() == false) {
	//		printf("sem.destory failed\n");
	//		return -1;
	// }
	// printf("sem.destory ok\n");
	//
}

bool CSEM::init(key_t key) {
	// 获取信号灯
	if ((sem_id = semget(key, 1, 0640)) == -1) {
		// 如果信号灯不存在，创建他
		if (errno == 2) {
			if ((sem_id = semget(key, 1, 0640|IPC_CREAT)) == -1) {
				perror("init 1 semget()");
				return false;
			}
			// 信号灯创建成功后，还需要把它初始化为可用状态
			union semun sem_union;
			sem_union.val = 1;
			if (semctl(sem_id, 0, SETVAL, sem_union) < 0) {
				perror("init semctl()");
				return false;
			}
		} else {
			perror("init 2 semget()");
			return false;
		}
	}
	return true;
}

bool CSEM::destory() {
	if (semctl(sem_id, 0, IPC_RMID) == -1) {
		perror("destory semctl()");
		return false;
	}
	return true;
}

bool CSEM::post() {
	struct sembuf sem_b;
	sem_b.sem_num = 0;
	sem_b.sem_op = 1;
	sem_b.sem_flg = SEM_UNDO;
	if (semop(sem_id, &sem_b, 1) == -1) {
		perror("post semop()");
		return false;
	}
	return true;
}

bool CSEM::wait() {
	struct sembuf sem_b;
	sem_b.sem_num = 0;
	sem_b.sem_op = -1;
	sem_b.sem_flg = SEM_UNDO;
	if (semop(sem_id, &sem_b, 1) == -1) {
		perror("wait semop()");
			return false;
	}
	return true;
}
