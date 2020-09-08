# C++多线程学习（三）
## 问题：
### 创建和等待多个线程
* vector< thread > mythreads;
* 创建是个线程，入口统一使用myprint
	1. 多个线程的执行顺序是乱的，跟操作系统的内部对线程的运行调度机制有关
	2. 主线程等待所有子线程运行结束，最后主线程结束，推荐使用join()，更易写出稳定程序
	3. 把thread对象放入容器中管理，看起来像个thread数组，这对我们依次创建大量线程并对其管理很是方便。
	
### 共享数据保护
* 数据共享问题分析
	1. 只读数据，是安全稳定的，不需要特殊处理的手段，直接读即可。
	2. 有读有写：两个线程写，八个线程读，如果没有特殊手段处理，程序将崩溃。
		* 简单不崩溃处理：读的时候不能写，写的时候不能读，两个线程不能同时写，8个线程不能同时读。
		* 写的动作分10步：由于频繁任务切换，将导致各种无法预期的事情发生。
	3. 典型案例：
		* 北京--深圳 火车车票，在售票窗口，1号窗口和2号窗口同时订下99号座位。
		* 网络游戏服务器：两个自己创建的线程，线程1负责收集玩家命令，并将命令写入队列。线程2负责从队列中取出玩家的命令，解析并进行处理。
* vector,list: list适合频繁的顺序插入和删除数据，vector适合随机插入和删除数据。
* 用成员函数作为线程入口
* c++解决多线程数据共享问题的第一个概念mutex（互斥量）

# 代码

## 类

~~~cpp
class A{
public:
	//把收到的消息（玩家命令）放入一个队列的线程
	void inMsgRecvQueue(){
		for(int i = 0;i < 100000;i++){
			cout << "inMsgRecvQueue()执行,插入一个元素" << i << endl;
			msgRecvQueue.push_back(i);
			//假设数字i即为玩家命令，将其入列
		}
	}
	//把数据从消息队列中取出的线程
	void outMsgRecvQueue(){
		for (int i = 0;i < 100000; i++){
			if(!msgRecvQueue.empty()){
				//队列如果不为空
			}
		}
	}	
};
~~~ 

## main

~~~cpp
#include <iostream>
#include <thread>
#include <list>
using namespace std;

int main(){
	A myobja;
  	std::thread myOutnMsgObj(&A::outMsgRecvQueue,&myobja); 
  	//第二个参数是引用,才能保证线程用的是同一个对象
	std::thread myInMsgObj(&A::inMsgRecvQueue, &myobja);

  	myOutnMsgObj.join();
  	myInMsgObj.join();
  	
  	reuturn 0;
 }
~~~

![](a.png)

显然这样出现了错误，就是因为两个线程，一个在读，一个在写。那么该如何解决共享数据的保护问题呢？
