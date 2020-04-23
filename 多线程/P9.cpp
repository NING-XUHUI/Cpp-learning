#include <iostream>
#include <list>
#include <thread>

using namespace std;

class A
{
  public:
    //把收到的消息（玩家命令）入到一个队列的线程
    void inMsgRecvQueue()
    {
        for (int i = 0; i < 100000; i++)
        {
            cout << "inMsgRecvQueue()执行，插入一个元素" << i << endl;
            std::unique_lock<std::mutex> sbguard1(my_mutex1);
            msgRecvQueue.push_back(i);  //数字i即为收到的命令，加入队列
        }
    }

    bool outMsgLULproc(int &command)
    {
        if (!msgRecvQueue.empty())
        {
            std::unique_lock<std::mutex> sbguard1(my_mutex1);
            if (!msgRecvQueue.empty())
            {
                //队列不为空
                command = msgRecvQueue.front();  //返回第一个元素
                msgRecvQueue.pop_front();        //移除首个元素,但不返回
                return true;
            }
        }
        return false;
    }
    //把数据从消息队列中取出的线程
    void outMsgRecvQueue()
    {
        int command = 0;
        for (int i = 0; i < 100000; i++)
        {
            bool res = outMsgLULproc(command);
            if (res == true)
            {
                cout << "outMsgRecvQueue执行，取出一个元素" << command << endl;
            }
            else
            {
                cout << "outMsgRecvQueue()执行，但目前消息队列为空" << i << endl;
            }
        }
        cout << "end" << endl;
    }

  private:
    std::list<int> msgRecvQueue;  //容器，专门代表玩家发来的命令
    std::mutex my_mutex1;         //创建一个互斥量。（一个锁）
};
int main()
{
    //条件变量std::condition_varible,wait(),notify_one()
    //线程A：等待一个条件满足
    //线程B：专门往消息队列中扔消息（数据）

    A myobja;
    std::thread myOutMsgObj(&A::outMsgRecvQueue, &myobja);
    std::thread myInMsgObj(&A::inMsgRecvQueue, &myobja);
    myInMsgObj.join();
    myOutMsgObj.join();

    return 0;
}