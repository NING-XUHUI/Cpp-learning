#include <iostream>
#include <list>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

/**
 * API总结：
 * std::lock(mutex)
 * std::lock_guard<std::muetex> sbguard(mutex,std::adopt_lock)
 * mutex::lock()
 * mutex::unlock()
 */


class A
{
  public:
    //把收到的消息（玩家命令）入到一个队列的线程
    void inMsgRecvQueue()
    {
        for (int i = 0; i < 100000; i++)
        {
            cout << "inMsgRecvQueue()执行，插入一个元素" << i << endl;
            // my_mutex1.lock(); //实际过程中这两个锁头代码不一定挨在一起
            // my_mutex2.lock();
            std::lock(my_mutex1, my_mutex2);  //相当于每个互斥量都被调用.lock
            std::lock_guard<std::mutex> sbguard1(my_mutex1, std::adopt_lock);
            std::lock_guard<std::mutex> sbguard2(my_mutex2, std::adopt_lock);
            msgRecvQueue.push_back(i);  //数字i即为收到的命令，加入队列
                                        // my_mutex2.unlock();
                                        // my_mutex1.unlock();
        }
    }

    bool outMsgLULproc(int &command)
    {
        // std::lock_guard<std::mutex> sbguard(my_mutex); // sbguard随便起的对象名
        // lock_guard构造函数执行了mutex::lock
        //``````````析构函数执行了mutex::unlock
        // my_mutex1.lock();
        // my_mutex2.lock();
        std::lock(my_mutex1, my_mutex2);
        std::lock_guard<std::mutex> sbguard1(my_mutex1, std::adopt_lock);
        std::lock_guard<std::mutex> sbguard2(my_mutex2, std::adopt_lock);
        if (!msgRecvQueue.empty())
        {
            //队列不为空
            command = msgRecvQueue.front();  //返回第一个元素
            msgRecvQueue.pop_front();        //移除首个元素,但不返回
            // my_mutex1.unlock();
            // my_mutex2.unlock();
            //这里就考虑处理数据。。。。。
            return true;
        }
        // my_mutex1.unlock();
        // my_mutex2.unlock();
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
    std::mutex my_mutex2;         //创建另一个互斥量
};

int main()
{

    A myobja;
    std::thread myOutnMsgObj(&A::outMsgRecvQueue,
                             &myobja);  //第二个参数是引用,才能保证线程用的是同一个对象
    std::thread myInMsgObj(&A::inMsgRecvQueue, &myobja);

    myOutnMsgObj.join();
    myInMsgObj.join();

    //保护共享数据，操作时，某个线程将共享数据锁住，其他想操作共享数据但线程必须等待解锁
    //互斥量
    //一：互斥量的基本概念(mutex)
    //互斥量是个类对象。理解成一把锁，多个线程尝试用lock()成员函数来加锁这个锁头,只有一个线程可以锁定成功（成功的标志是lock函数返回了）
    //如果没锁成功，那么流程卡在lock()这里不断尝试去锁
    //互斥量使用要小心，保护数据不多也不少，少了：未达到保护效果，多了：影响效率

    //二：互斥量的使用
    // lock(),unlock()
    //先lock，操作，再unlock
    // lock(),unlock()需要成对使用，有lock必然有unlock
    //不应该也不允许lock与unlock调用次数不对称,否则将导致代码不稳定甚至崩溃
    //有lock无unlock非常难排查
    //为了防止大家unlock，引入一个叫std::lock_guard的类模版，替程序员unlock，保姆角色

    // std::lock_guard直接取代lock()和unlock()，用了lock_guard后，不能再使用lock和unlock

    //死锁：
    //张三：站在北京等李四，不挪窝
    //李四：站在深圳等张三，不挪窝
    //在c++中：
    //比如我有两把锁（死锁产生等条件是至少两个互斥量才能产生）
    //两个线程A，B
    //（1）线程A执行时，这个线程先锁金锁，把金锁lock后，去lock银锁时
    //（2）出现了上下文切换
    //（3）线程B执行了，这个线程先锁银锁，因为银锁未被锁，所以银锁lock成功，线程B要去lock金锁
    // 此时此刻，死锁发生了
    //（4）线程A因为拿不到银锁，流程走不下去，所以金锁无法解开
    //（5）线程B因为拿不到金锁，流程走不下去，所以银锁无法解开
    //大家都站在这里，你等我，我等你

    //死锁演示
    //死锁的一般解决方案
    //只要保证两个互斥量上锁顺序一致，就不会死锁

    // std::lock()
    //一次锁住两个或者两个以上的互斥量（至少两个，无上限）
    //它不存在因为在多个线程中因为锁头顺序问题导致的死锁问题
    // std::lock():如果互斥量中有一个没锁住，他就在那里等待，待所有互斥量都锁住，他才能往下走
    //要么两个互斥量同时锁住，要么两个都没锁住。如果只锁一个，另一个锁失败，他立即将已经锁住的锁解锁，防止死锁

    // std::lock_guard的std::adopt_lock参数
    // std::adopt_lock是个结构体对象，起一个标记作用.作用是表示这个互斥量已经lock(),不需要在std::lock_guard中对对象进行再次lock
    //总结：std::lock()一次锁定多个互斥量，谨慎使用(建议一个一个锁)

    return 0;
}
