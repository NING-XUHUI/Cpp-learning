#include <iostream>
#include <thread>

using namespace std;

//自己创建的线程从一个函数开始
// void my_print(){
//     cout << "我的线程开始了" <<endl;

//     cout << "我的线程结束了" <<endl;
// }

class TA{
public:
    int &m_i;
    TA(int &i):m_i(i){ }
    void operator()(){
        // cout << "我的线程开始执行" <<endl;
        // cout << "结束" <<endl;
        cout << "m_i:" << m_i << endl;
        cout << "m_i:" << m_i << endl;
        cout << "m_i:" << m_i << endl;
    }
};

int main()
{
    //    cout << "NB" << endl;//主线程执行，主线程return，则进程结束。
    //自己创建的线程也需要从一个函数开始执行（初始函数）
    //这个函数运行完毕，代表这个线程运行结束
    //此时，一般情况下：如果其他子线程还没有执行完毕，那么这些子线程也会被强行终止
    //所以一般情况下，结论：如果大家想保持子线程（自己用代码创建的线程）运行状态，那么大家就要让主线程一直保持运行
    //不要让主线程执行完毕
    //这条规律有例外，后续
    //一旦detach，不能在join()
    //joinable():返回true或false，判断是否可以jion（）或detach（）

    //其他创建线程的手法
    //类

    // thread mytobj(my_print);
    // mytobj.detach();
    // cout << "I love China" << endl;
    // int myi=6;
    // TA ta(myi);
    // thread mytobj3(ta);
    // mytobj3.join();

    // cout<<"NB"<<endl;
    auto mylambda = [] {
        cout<<"开始"<<endl;
        cout<<"结束"<<endl;
    };
    thread t(mylambda);
    t.join();
    auto a = 0;

    cout << "NB" << endl;
    return 0;
}

