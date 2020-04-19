#include <iostream>
#include <thread>
using namespace std;

class A {
public:
  int m_i;
  //类型转换构造函数
  A(int a) : m_i(a) {
    cout << "A::A(int a)" << std::this_thread::get_id() << endl;
  }
  A(const A &a) : m_i(a.m_i) {
    cout << "A::A(const A& a)" << std::this_thread::get_id() << endl;
  }
  ~A() { cout << "A::~A()" << std::this_thread::get_id() << endl; }
};

// void my_print(const int&i,const string& pmyprint){
//     cout << i << endl;//实际是值传递,即使detach，子线程中依然安全
//     cout << pmyprint.c_str() << endl;//指针绝对有问题
// }

void my_print(const int i, const A &my_A) { cout << &my_A << endl; }

int main() {
  // int mvar = 1;
  // int &myvar = myvar;
  // char mybuf[] = "this is a test";
  // //thread mythread(my_print,mvar,mybuf);
  //事实1:只要以临时构造的A类对象作为参数传递给线程，哪呢就一定能保证子线程的运行安全
  //总结：1）若传递int这种简单数据类型，建议都是值传递
  // 2)
  // 如果传递类对象，避免隐式类型转换.全部都在创建线程这一行构建出临时对象，如何在函数参数里用引用来接，否则系统还会多构造一个
  //终极结论：
  //     3）不是用detach（），只用join（）

  //线程id:id是个数字，每个线程（主、子）都对应一个数字且均不相同
  //可以用c++标准库函数获取线程id std::this_thread::get_id()
  //

  // // mythread.join();
  //     thread
  //     mythread(my_print,mvar,string(mybuf));//这样可以保证mybuf一定存在
  // mythread.join();

  int mvar = 1;
  int mysecondpar = 12;
  thread mytobj(my_print, mvar, A(mysecondpar)); //希望mysecondpar转换为A类对象
  //在创建线程的同时构造临时对象的方法传递参数是可行的
  // mytobj.join();
  mytobj.detach();
  cout << "i love china" << endl;

  return 0;
}
