#include <future>
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

// int mythread(int &m)
// {
//     cout << "mythread()start "
//          << "thread_id :" << std::this_thread::get_id() << endl;
//     std::chrono::milliseconds dura(5000);
//     std::this_thread::sleep_for(dura);
//     cout << "mtthread()end "
//          << "thread_id :" << std::this_thread::get_id() << endl;
//     return 5;
// }
// void mythread2(std::future<int> &tmpf)
// {
//     cout << "mythread2()start"
//          << " thread_id :" << std::this_thread::get_id() << endl;
//     auto result = tmpf.get();
//     cout << "mythread2 result = " << result << endl;
// }

// int g_mycout = 0;  //全局量
// std::atomic<int> g_mycout(0);
std::atomic<bool> g_ifend(false);  //线程退出标记,原子操作，防止读写乱套
void mythread()
{
    std::chrono::milliseconds dura(1000);
    while (g_ifend == false)
    {
        //系统没要求程序退出，本线程可以干自己想干的事情
        cout << "thread_id :" << std::this_thread::get_id() << "运行中" << endl;
        std::this_thread::sleep_for(dura);
    }
    cout << "thread_id :" << std::this_thread::get_id() << "运行结束" << endl;
}
//我们封装了一个类型为int的对象（值）,我们可以像操作一个int类型一样来操作这个对象
// std::mutex mymutex;
//线程入口
// void mythread()
// {
//     for (int i = 0; i < 1000000; i++)
//     {
//         // mymutex.lock();
//         g_mycout++;//对应的操作是原子操作，不会被打断
//         // mymutex.unlock();
//     }
// }

int main(int argc, char const *argv[])
{
    // std::future的其他函数
    // std::shared_future
    cout << "main"
         << " thread_id :" << std::this_thread::get_id() << endl;
    // std::future<int> result = std::async(std::launch::deferred, mythread);
    //     cout << "continue......!" << endl;
    //     int def = 0;
    //     //     cout << result.get() << endl;
    //     //枚举类型
    //     std::future_status status = result.wait_for(std::chrono::seconds(6));
    //     if (status == std::future_status::timeout)
    //     //想等待1秒，希望你返回，但是你没有返回，那么超时
    //     {
    //         //超时表示线程还没执行完；
    //         cout << "超时，线程没有执行完" << endl;
    //     }
    //     else if (status == std::future_status::ready)
    //     {
    //         cout << "线程成功执行，返回" << endl;
    //         cout << result.get() << endl;
    //     }
    //     else if (status == std::future_status::deferred)
    //     {
    //         //如果async的第一个参数被设置为deferred，则本条件成立
    //         cout << "线程被延迟执行" << endl;
    //         cout << result.get() << endl;
    //     }
    //     std::packaged_task<int(int)> mypt(mythread);
    //     std::thread t1(std::ref(mypt), 1);
    //     t1.join();
    //     std::future<int> result = mypt.get_future();
    //     std::thread t2(mythread2, std::ref(result));
    //     t2.join();

    //三原子操作std::atomic
    //原子操作概念引出范例
    //互斥量：多线程编程中，保护共享数据：锁，操作共享数据，开锁
    //有两个线程，对一个变量进行操作，这个线程读这个变量，另一个线程往变量中写值。
    //读线程
    // int tmp = atomvalue
    //写线程
    // atomavalue = 0;
    //可以把原子操作理解成不需要互斥量加锁（无锁）技术的多线程并发编程方式
    //也可以理解成：原子操作是在多线程中不会被打断的程序执行片段
    //原子操作比互斥量效率上更好
    //互斥量的加锁一般是针对一个代码段，而原子操作针对的一般都是一个变量，而不是一个代码段
    //原子操作一般都是指“不可分割操作”，要么是完成，要么是不完成，不可能出现半完成（被编译成汇编后）
    // std::atomic是一个类模版。其实是用来封装某个类型的值的

    //基本atomic用法对象

    //     thread mytobj1(mythread);
    //     thread mytobj2(mythread);

    //     mytobj2.join();
    //     mytobj1.join();
    //     cout << " 线程执行完毕：" << g_mycout << endl;

    //     cout << "NB" << endl;

    thread mytobj1(mythread);
    thread mytobj2(mythread);
    std::chrono::milliseconds dura(5000);
    std::this_thread::sleep_for(dura);
    g_ifend = true;
    mytobj1.join();
    mytobj2.join();

    cout << "程序执行完毕" << endl;

    return 0;
}
