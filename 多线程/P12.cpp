#include <future>
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

// std::atomic<int> g_mycout(0);
// void mythread()
// {
//     for (int i = 0; i < 1000000; i++)
//     {
//         // g_mycout+=1;
//         // g_mycout++;
//         g_mycout = g_mycout + 1;  //结果不对
//     }
// }

int mythread()
{
    cout << "mythread()start "
         << "threadid: " << std::this_thread::get_id() << endl;
    return 1;
}

int main(int argc, char const *argv[])
{

    // 1.原子操作续谈
    //一般原子操作，针对++，--，+=，-=，*=，｜=，&=等是支持的，其他的可能不支持。

    // thread mytobj1(mythread);
    // thread mytobj2(mythread);
    // mytobj1.join();
    // mytobj2.join();
    // cout << "两个线程都执行完毕，最终的g_mycout的结果是" << g_mycout << endl;

    // 2.std::async深入谈
    // std::async用来创建一个异步任务
    cout << "main()start "
         << "threadid: " << std::this_thread::get_id() << endl;
    std::future<int> result = std::async(mythread);
    cout << result.get() << endl;
    //延迟调用参数std::launch::deferred,以及std::launch::async强制创建一个线程
    // std::thread()如果系统资源紧张，可能创建线程会失败，如果失败，那么执行std::thread的时候整个程序会崩溃
    // std::async我们一般不叫创建线程，虽然它能够创建，我们叫它创建一个异步任务
    // std::async和std::thread最明显的不同，就是async有时候不创建新线程
    // a)如果你用std::launch::deferred来调用async，他不会创建这个线程，知道get或wait
    // b)std::launch::async:强制这个异步任务在新线程上执行，系统必须要创建新的线程
    // c)同时使用以上两个参数｜，或者关系，async的行为可能是a，也可能是b
    // d)我们不带额外参数；只给async函数一个线程入口函数名
    // P10错误：默认值是c
    // 就是系统会自行决定系统会异步(创建新线程)还是同步方式执行
    //自行决定是什么意思？系统如何决定是异步还是同步呢？
    //若系统资源限制：
    // std::thread创建会崩溃
    // std::async一般不会报异常,如果系统资源紧张，async不带参数的调用就不会创建新线程，而是延迟调用（取决于谁调用get（））

    // std::async不确定性问题的解决
    //问题焦点在于不带参数的写法的异步任务到底有没有被执行

    return 0;
}
