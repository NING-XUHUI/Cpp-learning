#include <iostream>
#include <list>
#include <mutex>
#include <thread>
#include <vector>
using namespace std;

class A
{
  public:
    std::unique_lock<std::mutex> rtn_unique_lock(){
        std::unique_lock<std::mutex> tmpguard(my_mutex1);
        return tmpguard;
    }
    void inMsgRecvQueue()
    {
        for (int i = 0; i < 100000; i++)
        {
            cout << "inMsgRecvQueue()执行，插入一个元素" << i << endl;
            // std::lock_guard<std::mutex> sbguard1(my_mutex1);
            // my_mutex1.lock();  //先lock，后续才能用adopt_lock
            // std::unique_lock<std::mutex> sbguard(my_mutex1, std::try_to_lock);
            // if (sbguard.owns_lock())
            // {
            //拿到了锁
            // std::unique_lock<std::mutex> sbguard(my_mutex1,std::defer_lock);//没有加锁的mutex
            // sbguard.lock();//咱们不用自己unlock
            //有一些非共享代码要处理
            // sbguard.unlock();
            // sbguard.lock();
            //std::unique_lock<std::mutex> sbguard1(my_mutex1);
            //std::unique_lock<std::mutex> sbguard2(std::move(sbguard1));
            //std::mutex *ptx = sbguard1.release();
            // if(sbguard.try_lock() == true)
            std::unique_lock<std::mutex> sbguard1 = rtn_unique_lock();
            msgRecvQueue.push_back(i);  //数字i即为收到的命令，加入队列
            //}
            // else{
            //未拿到锁
            //  cout << "inMsgRecvQueue()执行，但没有拿到锁，干点别的事" << i << endl;
            //}                        // my_mutex2.unlock();
            // my_mutex1.unlock();
            //ptx->unlock();//对mutex的解锁负责
        }
    }

    bool outMsgLULproc(int &command)
    {
        std::unique_lock<std::mutex> sbguard(my_mutex1);

        // std::chrono::milliseconds dura(200);
        // std::this_thread::sleep_for(dura);  //休息20秒

        if (!msgRecvQueue.empty())
        {
            //队列不为空
            command = msgRecvQueue.front();  //返回第一个元素
            msgRecvQueue.pop_front();        //移除首个元素,但不返回
            return true;
        }
        return false;
    }
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

    A myobja;
    std::thread myOutnMsgObj(&A::outMsgRecvQueue,
                             &myobja);  //第二个参数是引用,才能保证线程用的是同一个对象
    std::thread myInMsgObj(&A::inMsgRecvQueue, &myobja);
    myOutnMsgObj.join();
    myInMsgObj.join();

    // unique_lock取代lock_guard
    // unique_lock是个类模版，工作中，一般lock_guard（推荐使用）lock_guard取代了mutex的lock和unlock
    // unique_lock比lock_guard灵活，但效率差一点，占用内存多一点
    // unique_lock的第二个参数

    // std::adopt_lock:表示这个互斥量已经被lock了（你必须提前把互斥量lock，否则会报异常）
    //该标记的效果就是“假设调用方线程已经拥有了互斥所有权（已经lock）”
    //通知lock_guard不需要在构造函数中lock这个互斥量了
    // unique_lock也可以带这个标记，含义相同
    //前提是自己先lock

    // std::try_to_lock
    //我们会尝试用mutex的lock去锁定mutex，但如果未锁定成功，我也会立即返回，并不会阻塞
    //用这个标记的前提，是自己不能先去lock

    // std::defer_lock
    //用这个的前提是，自己不能先lock，否则回报异常
    //意思就是并没有给mutex加锁：初始化了一个没有加锁的mutex

    //引出unique_lock的重要成员函数
    // lock()加锁
    // unlock()解锁
    // try_lock()尝试加锁，如果拿不到锁，返回false，反之，true
    //返回他所管理的mutex对象指针，并释放所有权unique_lock和mutex不再有关系
    // unlock与release的区别，不要混淆
    //如果原来mutex对象处于加锁状态，你有责任接管过来并负责解锁(release返回原mutex的指针)
    //为什么有时候需要unlock，因为你lock锁住的代码越少，执行越快，整个程序运行效率越高
    //有人也把锁头锁住的代码多少称为锁的 粒度，粒度一般用粗细表示
    //锁住的代码少，粒度细，执行效率高
    //锁住的代码多，粒度粗，执行效率高
    //学会尽量选择合适粒度的代码进行保护
    //选择合适的粒度，是高级程序员实力的体现

    //unique_lock所有权的传递 mutex，
    //所有权概念
    //sbguard1拥有my_metex的所有权
    //sbguard1可以把自己对mutex的所有权转移给其他unique_lock对象
    //所以unique_lock对象的mutex的所有权是属于可以转移，但是不能复制。(复制所有权是非法的)


    //所有权转移：
    //1.std::move()
    //2.rtn_unique_lock()
    return 0;
}
