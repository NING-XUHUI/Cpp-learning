#include <iostream>
#include <list>
#include <mutex>
#include <string>
#include <thread>
using namespace std;

std::mutex resource_mutex;
std::once_flag g_flag;  //这是个系统定义的标记

class MyCAS  //这是一个单例类
{
    static void createInstance()
    {
        std::chrono::milliseconds dura(2000);
        std::this_thread::sleep_for(dura);
        m_instance = new MyCAS();
        cout << "createinstance被执行" << endl;
        static CGarhuishou cl;
    }

  private:
    MyCAS() {}  //私有化构造函数
  private:
    static MyCAS *m_instance;  //静态成员变量
  public:
    static MyCAS *getInstance()
    {
        //提高效率
        // if (m_instance != NULL)条件成立，则肯定表示m_instance已经被new过了
        // if (m_instance == NULL)条件成立，不代表m_instance一定没被new过
        // if (m_instance == NULL)  //双层锁定,双重检查
        // {
        //     std::unique_lock<std::mutex> mymutex(resource_mutex);  //自动加锁
        //     if (m_instance == NULL)
        //     {
        //     }
        // }
        std::call_once(
            g_flag, createInstance);  //两个线程都执行到这一步，其中一个线程要等另外一个线程执行完毕
        cout << "call_once执行完毕" << endl;
        return m_instance;
    }

    class CGarhuishou  //类中套类,用来释放对象
    {
      public:
        ~CGarhuishou()
        {
            if (MyCAS::m_instance)
            {
                delete MyCAS::m_instance;
                MyCAS::m_instance = NULL;
            }
        }
    };

    void func() { cout << "测试" << endl; }
};

//类静态变量初始化
MyCAS *MyCAS::m_instance = NULL;

//线程入口
void mythread()
{
    cout << "我的线程开始执行" << endl;
    MyCAS *p_a = MyCAS::getInstance();  //可能出现问题
    //p_a->func();
    cout << "我的线程执行结束" << endl;
}

int main()
{
    //设计模式
    //设计模式：代码的一些写法：程序灵活，维护起来方便，但别人接管阅读十分痛苦
    //用设计模式理念写出来的代码很晦涩
    //将项目的开发经验，模块划分经验，总结整理成设计模式（现有开发需求，后有理论总结和整理）
    //但是在中国，不太一样，拿着一个程序或项目往设计模式上套：一个小小的项目，非要弄几个设计模式，本末倒置
    //设计模式有他独特的优点，需要活学活用，不要深陷其中，生搬硬态

    //单例模式
    //使用频率较高
    //单例：整个项目中，有某个或某些特殊的类，属于该类的对象，我只能创建1个，多了创建不了。
    //单例类
    // MyCAS *pa = MyCAS::getInstance();
    // pa->func();

    //单例模式共享数据问题分析，解决
    //面临的问题：需要在我们自己创建的线程中来创建MyCAS这个单例类对象，这种线程可能不止一个（最少两个）
    //我们可能面临getinstance互斥
    //如下两个线程，虽然是同一个入口函数，但是这两个线程，所以这里会有两个流程（同时执行这个函数）

    // std::call_once();c++11,该函数的第二个是一个函数名a
    //该函数的功能是保证函数a()只被调用一次
    //具备互斥量这种能力，而且效率上，比互斥量消耗的资源更少
    //需要与一个标记结合使用std::once_flag;
    // call_once()就是通过这个标记决定对应的函数a是否执行，callonce执行成功后，该标记则变为已调用状态
    //只要这个标记被设为已调用状态，那么对应的函数a就不会再被执行了

    std::thread mytObj1(mythread);
    std::thread mytObj2(mythread);
    
    mytObj1.join();
    mytObj2.join();
    return 0;
}
