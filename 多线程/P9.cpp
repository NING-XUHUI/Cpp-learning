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

            std::unique_lock<std::mutex> sbguard1(my_mutex1);
            cout << "inMsgRecvQueue()执行，插入一个元素" << i << endl;
            msgRecvQueue.push_back(i);  //数字i即为收到的命令，加入队列
            my_cond.notify_all();       //尝试将wait()线程唤醒
                                        //唤醒之后的事后续研究
        }
    }

    // bool outMsgLULproc(int &command)
    // {
    //     if (!msgRecvQueue.empty())
    //     {
    //         std::unique_lock<std::mutex> sbguard1(my_mutex1);
    //         if (!msgRecvQueue.empty())
    //         {
    //             //队列不为空
    //             command = msgRecvQueue.front();  //返回第一个元素
    //             msgRecvQueue.pop_front();        //移除首个元素,但不返回
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    //把数据从消息队列中取出的线程
    void outMsgRecvQueue()
    {
        int command = 0;
        while (true)
        {
            // wait()用来等一个东西
            //如果第二个参数是true，那么wait直接返回
            //如果第二个参数的（lambda）返回值是false，那么wait()将解锁互斥量，并堵塞到本行，
            //那堵塞到什么时候位置呢？堵到其他某个线程通知notify_one()为止
            //如果wait没有第二个参数，那么就跟第二个参数lambda表达式返回false效果一样
            //也就是解锁互斥量，并堵塞到本行，直到。。。notify_one()为止
            //当其他线程用notify_one()将本wait唤醒，原本是睡眠状态
            //wait恢复后开始干活
            //1.wait（）不断尝试重新获取互斥量锁，如果获取不到，流程依然卡在wait（）等待获取
            //如果获取到，wait（）就走下来,继续执行
            //2.上锁（实际上获取到锁就等于上了锁）
            //如果有第二个参数，就判断这个表达式（或函数）,如果表达式为false，wait有对互斥量进行解锁，休眠，等待唤醒，重复以上
            //如果没有第二个参数，直接往下执行
            std::unique_lock<std::mutex> sbguard1(my_mutex1);
            my_cond.wait(sbguard1, [this] {
                if (!msgRecvQueue.empty())
                    return true;
                return false;
            });
            command = msgRecvQueue.front();
            msgRecvQueue.pop_front();
            cout << "取出元素" << command << " thread: "<<std::this_thread::get_id() << endl;
            sbguard1.unlock();//可选择解锁,提早解锁最好

            //一会再写其他的...
        }  // end while

        //     for (int i = 0; i < 100000; i++)
        //     {
        //         bool res = outMsgLULproc(command);
        //         if (res == true)
        //         {
        //             cout << "outMsgRecvQueue执行，取出一个元素" << command << endl;
        //         }
        //         else
        //         {
        //             cout << "outMsgRecvQueue()执行，但目前消息队列为空" << i << endl;
        //         }
        //     }
        //     cout << "end" << endl;
    }

  private:
    std::list<int> msgRecvQueue;      //容器，专门代表玩家发来的命令
    std::mutex my_mutex1;             //创建一个互斥量。（一个锁）
    std::condition_variable my_cond;  //生成一个条件变量对象
};
int main()
{
    //条件变量std::condition_varible,wait(),notify_one():通知一个线程
    //线程A：等待一个条件满足
    //线程B：专门往消息队列中扔消息（数据）
    // std::conditon_varible是一个与条件相关的类，就是等待一个条件达成
    //这个类是需要和互斥量配合工作，用的时候我们要生成这个类的对象

    //上述代码的深入思考：
    
    //notify_all()
    A myobja;
    std::thread myOutMsgObj(&A::outMsgRecvQueue, &myobja);
    std::thread myOutMsgObj2(&A::outMsgRecvQueue, &myobja);
    std::thread myInMsgObj(&A::inMsgRecvQueue, &myobja);

    myInMsgObj.join();
    myOutMsgObj2.join();
    myOutMsgObj.join();

    return 0;
}
