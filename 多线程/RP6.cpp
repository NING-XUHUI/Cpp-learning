#include <iostream>
#include <thread>
#include <vector>
#include <list>
#include <mutex>
using namespace std;

class A{
public:
  void inMsgRecvQueue(){
    for(int i = 0;i < 10000;i++){
      cout << "inMsgRecvQueue执行，插入一个元素" << i << endl;
      mymutex1.lock();
      msgRecvQueue.push_back(i);
      mymutex1.unlock();
    }
  }
  void outMsgRecvQueue(){
    for(int i = 0;i < 10000;i++){
      mymutex1.lock();

      if(!msgRecvQueue.empty()){
        int command = msgRecvQueue.front();
        msgRecvQueue.pop_front();
        mymutex1.unlock();
        cout << command << endl;

      }else{
        cout << "outMsgRecvQueue执行，但是目前消息队列为空" << i << endl;
      }
    }
    cout << "end" << endl;
  }
private:
  std::list<int> msgRecvQueue;
  std::mutex mymutex1;
};


int main()
{
  A myobja;
  std::thread myOutMsgObj(&A::outMsgRecvQueue,&myobja);
  std::thread myInMsgObj(&A::inMsgRecvQueue,&myobja);
  myInMsgObj.join();
  myOutMsgObj.join();
  return 0;
}
