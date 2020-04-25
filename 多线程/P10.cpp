#include <future>
#include <iostream>
#include <list>
#include <mutex>
#include <string>
#include <vector>
using namespace std;

// class A
// {

//   public:
//     int mythread(int mypar)  //线程入口函数
//     {
//         cout << mypar << endl;
//         cout << "mythread()start"
//              << " thread_id: " << std::this_thread::get_id() << endl;
//         std::chrono::milliseconds dura(5000);  //五秒
//         std::this_thread::sleep_for(dura);     //休息
//         cout << "mythread()end"
//              << "thread_id" << std::this_thread::get_id() << endl;
//         return 5;
//     }
// };

// int mythread(int mypar)  //线程入口函数
// {
//     cout << mypar << endl;
//     cout << "mythread()start"
//          << " thread_id: " << std::this_thread::get_id() << endl;
//     std::chrono::milliseconds dura(5000);  //五秒
//     std::this_thread::sleep_for(dura);     //休息
//     cout << "mythread()end"
//          << "thread_id" << std::this_thread::get_id() << endl;
//     return 5;
// }

// vector<std::packaged_task<int(int)>> mytasks;

void mythread(std::promise<int> &tmpp, int calc)
{
    //做一系列复杂操作
    calc++;
    calc *= 10;
    //做其他运算
    std::chrono::milliseconds dura(5000);  //五秒钟
    std::this_thread::sleep_for(dura);
    //模拟计算时间

    //计算结束
    int res = calc;       //保存结果
    tmpp.set_value(res);  //结果我保存到了tmpp对象中
    return;
}

void mythread2(std::future<int> &tmpp)
{
    auto res = tmpp.get();
    cout << res << endl;
    return;
}

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
    //我们通过额外享std::nstnc()传递一个参数，该参数类型是std::launch类型，来达到特殊的目的
    // std::launch::deferred:表示线程入口函数调用被延迟到std::future的wait或get被调用时才执行
    //如果wait或get没有被调用，那么线程会执行吗？答案：不会，实际上根本就没创建
    // std::deferred:延迟调用，并未创建新线程，是在主线程中调用的线程入口函数
    // std::launch::async，在调用async的时候就开始创建线程
    // async()函数，默认用的标记就是std::launch::async()
    // A a;
    // int par = 12;

    // cout << "main"
    //      << " thread_id:" << std::this_thread::get_id() << endl;
    // std::future<int> res = std::async(std::launch::deferred, &A::mythread, &a,
    //                                   par);  //创建一个线程并执行，绑定关系,流程不卡在这里
    // cout << "continue....." << endl;

    // int def = 0;
    // cout << res.get() << endl;  //卡在这里等待mythread执行完，完毕，拿到结果
    // //只能调用一次，不能多次，否则异常
    // cout << "I Love China" << endl;

    // std::packaged_task
    // 打包任务，把任务包装起来
    // 是个类模版，他的模版参数是各种可调用对象；通过std::packaged_task把各种可调用对象包装起来
    // 方便将来作为线程入口函数来调用。
    // packaged_task包装起来的可调用对象还可以直接调用，所以这个角度来讲，packaged_task对象，也是一个可调用对象

    // cout << "main"
    //      << " thread_id:" << std::this_thread::get_id() << endl;

    // std::packaged_task<int(int)> mypt([](int mypar) {
    //     cout << mypar << endl;
    //     cout << "mythread()start"
    //          << " thread_id: " << std::this_thread::get_id() << endl;
    //     std::chrono::milliseconds dura(5000);  //五秒
    //     std::this_thread::sleep_for(dura);     //休息
    //     cout << "mythread(`)end"
    //          << "thread_id" << std::this_thread::get_id() << endl;
    //     return 5;
    // });

    // std::thread t1(std::ref(mypt), 1);  //线程直接开始执行,1是入口函数的参数
    // t1.join();                          //等待线程执行完毕
    // std::future<int> res = mypt.get_future();  // std::future对象里含有线程入口函数的返回结果
    // cout << res.get() << endl;
    // cout << "I love china" << endl;
    // mypt(111);
    // std::future<int> res = mypt.get_future();
    // cout << res.get()<<endl;

    // mytasks.push_back(std::move(mypt));  //容器，移动，mypt为空
    // std::packaged_task<int(int)> mypt2;
    // auto iter = mytasks.begin();
    // mypt2     = std::move(*iter);
    // mytasks.erase(iter);  //删除，迭代器失效，后续代码不可继续使用
    // mypt2(2);
    // std::future<int> res = mypt2.get_future();
    // cout << res.get() << endl;

    // std::promise,类模版
    //我们可以在某个线程中给他赋值，然后可以在其他线程中，把这个值取出来
    //总结：通过promise保存一个值，在将来某个时刻，通过future来得到这个值

    std::promise<int> myprom;  //声明一个promise对象，保存的值为int
    std::thread t1(mythread, std::ref(myprom), 180);
    t1.join();  //使用了thread，就要使用join或detach
    //获取结果
    std::future<int> fu1 = myprom.get_future();
    // cout << fu1.get() << endl;
    std::thread t2(mythread2, std::ref(fu1));
    t2.join();
    cout << "I love china" << endl;
    return 0;

    //小结：
    //到底怎么用，什么时候用？
    //我们学习这些东西的目的，并不是都要用到这些到实际开发中
    //相反，如果我们能够用最少的东西写出一个稳定高效的多线程程序，更值得赞赏
    //我们为了成长，必须要阅读一些高手的代码，从而实现自己代码的积累，我们的技术才会大幅度提升
    //为我们将来能够读懂高手的代码做铺垫
}