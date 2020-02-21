/*
使用C++标准模版库中的双向队列来实现一个单向的队列。在测试程序中，往队列尾部依次插入5个元素；然后再依次从队列头部出队，直到队列被取空。
*/

#include<iostream>
#include<deque>

using namespace std;
int main(){
  deque<int>iDeque;
  iDeque.push_back(3);
  iDeque.push_back(1);
  iDeque.push_back(4);
  iDeque.push_back(8);
  iDeque.push_back(6);
  while(!iDeque.empty()){
    cout<<"取出元素"<<iDeque.front()<<endl;//获得值
    iDeque.pop_front();//弹出元素
  }

  return 0;
}
