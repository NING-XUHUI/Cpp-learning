#include <future>
#include <iostream>
#include <list>
#include <mutex>
#include <string>
using namespace std;


class A{

public:
int mythread(int mypar)  //线程入口函数
{
    cout << mypar << endl;
    cout << "mythread()start"
         << " thread_id: " << std::this_thread::get_id() << endl;
    std::chrono::milliseconds dura(5000);  //五秒
    std::this_thread::sleep_for(dura);     //休息
    cout << "mythread()end"
         << "thread_id" << std::this_thread::get_id() << endl;
    return 5;
}

};

int main(int argc, const char **argv)
{
    // 1.std::async、std::future创建后台任务并返回值
    //希望线程返回一个结果
    // std::async是个函数模版，用来启动一个异步任务，启动该任务后，返回一个std::future对象
    //什么是启动一个异步任务？
    //就是自动创建一个线程并开始执行对应的线程入口函数，他返回一个std::future
    //这个std::future对象里面就含有线程入口函数所返回的结果（线程返回结果），我们可以调用future对象
    //的get函数，获取该返回值
    // std::future提供了一种访问异步操作结果的机制，就是这个结果你没有办法马上拿到，但可以在
    //线程执行完毕的时候，你就能够拿到这个结果。所以：future会保存一个值，在将来的某个时刻可以拿到。

    //下列程序通过get函数等待线程执行结束并返回结果s
    A a;
    int par = 12;

    cout << "main"
         << " thread_id:" << std::this_thread::get_id() << endl;
    std::future<int> res = std::async(&A::mythread,&a,par );  //创建一个线程并执行，绑定关系,流程不卡在这里
    cout << "continue....." << endl;
    int def = 0;
    cout << res.get() << endl;  //卡在这里等待mythread执行完，完毕，拿到结果
    //只能调用一次，不能多次，否则异常
    cout << "I Love China" << endl;

    return 0;
}