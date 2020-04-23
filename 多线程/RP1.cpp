#include<iostream>
#include<thread>
using namespace std;

void my_print(){
  cout << "我的线程开始了" << endl;

  cout << "我的线程结束了" << endl;
}

class TA{
public:
  int &m_i;
  TA(int &i):m_i(i){}
  void operator()(){
    cout << "m_i" << m_i << endl;
    cout << "m_i" << m_i << endl;
    cout << "m_i" << m_i << endl;
  }
};


int main(){
  //thread mytobj(my_print);
  //mytobj.join();
  //cout << "I love China" << endl;
  int m = 6;
  TA ta(m);
  thread mytobj3(ta);
  mytobj3.join();
  return 0;
}
