/*
顺序容器的插入迭代器
  用于向容器头部、尾部或中间指定位置插入元素的迭代器
  包括前插迭代器、后插迭代器和任意位置插入迭代器
例如：
  list<int>s;
  back_inserter iter(s);
  *(iter++) = 5;//通过iter把5插入s末尾
*/
/*
顺序容器的适配器
以顺序容器为基础构建一些常用的数据结构，是对顺序容器的封装
  栈stack：最先压入的元素最后被弹出
  队列queue：最先压入的元素最先被弹出
  优先级队列priority_queue：最“大”的元素最先被弹出
 */

#include<stack>
#include<iostream>
using namespace std;

int main(){
  stack<char> s;
  string str;
  cin>>str;//从键盘输入一个字符串
  //将字符串的每个元素顺序压入栈中
  for(string::iterator iter = str.begin();iter != str.end();++iter){
    s.push(*iter);
  }
  //将栈中的元素顺序弹出并输出
  while(!s.empty()){
    cout<<s.top();
    s.pop();
  }
  cout<<endl;
  return 0;
} 
