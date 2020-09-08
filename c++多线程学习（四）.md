# c++多线程学习（四）

+ 在上一次学习中，遇到了共享资源同时访问导致的程序崩溃问题
+ 这次学习中，我们使用mutex来解决这一问题
+ 首先写下准备代码

~~~cpp
#include<iostream>
#include<list>
#include<thread>
#include<vector>
using namespace std;
~~~

+ 引入需要使用的头文件

~~~cpp
class A{
public:
	void inMsgRecvQueue()
	{
		for(int i=0;i<100000;i++)
		{
			cout << "inMsgRecvQueue()执行，插入一个元素" << i << endl;
			my_mutex.lock();
			msgRecvQueue.push_back(i);//假设数字i为收到的命令，加入队列
			my_mutex.unlock();
		}
	}
	
	bool outMsgLULproc(int &command)
	{
		my_mutex.lock();
		if(!msgRecvQueue.empty())
		{
			//队列不为空时
			command = msgRecvQueue.front();//返回第一个元素
			msgRecvQueue.pop_front();
			my_mutex.unlock();
			return true;
		}
		my_mutex.unlock();
		return false;
	}
	
	void outMsgRecvQueue()
	{
		int command = 0;
		for (int i = 0;i < 100000;i++)
		{
			bool res = outMsgLULproc(command);
			if(res == true)
			{
				cout << "outMsgRecvQueue()执行，许出一个元素" << command << endl;
			}
			else 
			{
				cout << "outMsgRecvQueue()执行，但是队列为空" << endl;
			}
		}
		cout << "end" << endl;
	}
	
private:
	std::list<int> msgRecvQueue;//容器，存放玩家发送来的命令，这里以int代表命令
	std::mutex my_mutex;//创建一个互斥量
};
~~~

+ 写完线程的入口后，下面进行测试

~~~cpp
int main(){
	A my_a;
	std::thread myOutMsgObj(&A::outMsgRecvQueue,&my_a);//第二个参数是引用，才能保证线程使用的是同一个对象
	std::thread myInMsgObj(&A::inMsgRecvQueue,&my_a);
	
	myOutMsgObj.join();
	myInMsgObj.join();
	return 0;
}
~~~

## 测试结果

![](/Users/ningxuhui/Desktop/a.png)


## 互斥量

### 互斥量的基本概念

+ 互斥量是一个类对象，可以理解为一把锁，多个线程尝试用lock成员函数来加锁这个锁头，只有一个线程可以锁定成功（成功的标志是lock函数返回了）
+ 如果没有锁成功，那么流程将卡在lock()这里不断尝试去锁
+ 互斥量的使用要小心，保护的数据应该不多也不少，多了：影响效率，少了：未能达到保护的效果

### 互斥量的使用

+ lock(),unlock()
+ 先lock，再unlock
+ lock与unlock应该成对使用，有lock，必然有unlock
+ 不应该也不允许lock与unlock的使用次数不对称，否则将导致代码的崩溃与不稳定
+ 有lock却无unlock的问题非常难排查
+ 为了防止大家忘记unlock，引入一个叫做std::lock_guard的类模版，替程序员解锁
