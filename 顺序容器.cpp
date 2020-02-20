/*
顺序容器
STL中的顺序容器
 向量
 双端队列
 列表
 单向链表
 数组
元素线性排列，可以随时在指定位置插入元素和删除元素
必须符合Assignable这一概念(即具有公有的复制构造函数并可以用“=”赋值)
array对象的大小固定，forward_list有特殊的添加和删除操作
*/

/*
顺序容器的接口（不包含单向链表和数组）
构造函数
复制函数
 assign
插入函数/
 insert，push_front(支队list和deque),push_back,emplace,emplace_front
删除函数
  erase,clear,pop_front(只对list和deque)，pop_back,emplace_back
首尾元素的直接访问
 front,back
改变大小
 resize
*/

#include<iostream>
#include<list>
#include<deque>

using namespace std;

template<class T>
void printContainer(const char* msg,const T& s){
  cout<<msg<<":";
  copy(s.begin(),s.end(),ostream_iterator<int>(cout," "));
  cout<<endl;
}

int main(){
  deque<int>s;
  for(int i = 0;i < 10;i++){
    int x;
    cin>>x;
    s.push_back(x);
  }
  printContainer("deque at first",s);
  //用s容器的内容的逆序构造列表容器l
  list<int>l(s.rbegin(),s.rend());
  printContainer("list at first",l);

  //将列表容器l的每相邻两个元素颠倒
  list<int>::iterator iter = l.begin();
  while(iter != l.end()){
    int v = *iter;
    iter = l.erase(iter);
    l.insert(++iter,v);
  }

  printContainer("list at last",l);
  //用列表容器l的内容给s赋值，将s输出
  s.assign(l.begin(),l.end());
  printContainer("deque at last",s);

  return 0;
}
