#include <iostream>
#include <list>
#include <thread>
#include <vector>
using namespace std;

// vector<int> g_v = {1, 2, 3}; //共享数据
/**
 * @brief 线程入口函数
 */
// void myprint(int inum) {
//   // cout << "myprint线程开始了 线程编号:" << inum <<endl;
//   // cout << "myprint线程结束了 线程编号:" << inum <<endl;
//   cout << "id为" << std::this_thread::get_id() << "的线程打印g_v的值" <<
//   g_v[0]
//        << g_v[1] << g_v[2] << endl;
// }

class A {
public:
  //把收到的消息（玩家命令）入到一个队列的线程
  void inMsgRecvQueue() {
    for (int i = 0; i < 100000; i++) {
      cout << "inMsgRecvQueue()执行，插入一个元素" << i << endl;
      msgRecvQueue.push_back(i); //数字i即为收到的命令，加入队列
    }
  }
  //把数据从消息队列中取出的线程
  void outMsgRecvQueue() {
    for (int i = 0; i < 100000; i++) {
      if (!msgRecvQueue.empty()) {
        //队列不为空
        int command = msgRecvQueue.front(); //返回第一个元素
        msgRecvQueue.pop_front();           //移除首个元素,但不返回
        cout << command << endl;
        //这里就考虑处理数据。。。。。

      } else {
        //队列为空
        cout << "outMsgRecvQueue()执行，但目前消息队列为空" << i << endl;
      }
    }
    cout << "end" << endl;
  }

private:
  std::list<int> msgRecvQueue; //容器，专门代表玩家发来的命令
};

int main() {
  // //1.创建和等待多个线程
  //   vector<thread> mythreads;
  //   // //创建十个线程,入口统一使用myprint
  //   // //1.多个线程执行顺序是乱的，跟操作系统内部对线程的运行调度机制有关
  //   //
  //   //2.主线程等待所有子线程运行结束，最后主线程结束，推荐join写法，更易写出稳定程序
  //   //
  //   //3.把thread对象放入容器中管理，看起来像个thread数组，这对我们依稀创建大量线程并对其管理很方便

  //   for (int i = 0; i < 10; i++) {
  //     mythreads.push_back(thread(myprint, i)); //创建10个线程并开始执行
  //   }
  //   for (auto iter = mythreads.begin(); iter != mythreads.end(); iter++) {
  //     iter->join();
  //   }

  // cout<<"主线程结束，退出"<<endl;

  //数据共享问题分析
  // 1.只读数据,是安全稳定的，不需要特殊处理手段，直接读即可。
  // 2.有读有写:2个线程写，8个线程读，如果没有特殊处理，程序将崩溃
  //简单不崩溃处理：读的时候不能写，写的时候不能读。2个线程不能同时写，8个线程不能同时读
  //写的动作分10小步：由于任务切换，导致各种诡异事情发生（最可能的就是程序崩溃）
  // 3.其他案例
  // 数据共享：
  // 北京--深圳 火车 ，是个售票窗口卖票，1号2号窗口同时订99号座位

  //共享数据的保护案例代码
  //网络游戏服务器：两个自己创建的线程，线程1收集玩家命令。并把命令数据写到队列中。
  //线程2从队列中取出玩家发来的命令，解析，然后执行玩家需要的动作。
  // vector,list.list:频繁的顺序插入和删除数据时效率高，vector对随机插入和删除数据效率高

  //用成员函数作为线程入口
  //代码化解决问题：c++解决多线程保护共享数据但第一个概念“互斥量”⭐️

  A myobja;
  std::thread myOutnMsgObj(
      &A::outMsgRecvQueue,
      &myobja); //第二个参数是引用,才能保证线程用的是同一个对象
  std::thread myInMsgObj(&A::inMsgRecvQueue, &myobja);

  myOutnMsgObj.join();
  myInMsgObj.join();

  return 0;
}
