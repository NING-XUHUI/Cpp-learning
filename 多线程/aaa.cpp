#include<iostream>
#include<list>
#include<thread>
#include<vector>
using namespace std;

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

int main(){
	A my_a;
	std::thread myOutMsgObj(&A::outMsgRecvQueue,&my_a);//第二个参数是引用，才能保证线程使用的是同一个对象
	std::thread myInMsgObj(&A::inMsgRecvQueue,&my_a);
	
	myOutMsgObj.join();
	myInMsgObj.join();
	return 0;
}