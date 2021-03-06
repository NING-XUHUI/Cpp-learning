
//指向函数的指针
/*定义形式
存储类型 数据类型（*函数指针名）（）；
含义：
函数指针指向的是程序代码存储区
用途：
函数回调
通过函数指针调用的函数：
1.例如将函数的指针作为参数传给一个函数，是的在处理相似时间的时候可以灵活的使用不同的方法
2.调用者不关心谁是被调用者
3.需要知道存在一个具有特定原型和限制条件的被调用函数
*/

#include<iostream>

using namespace std;

int compute(int a,int b,int(*func)(int ,int))
{return func(a,b);}

int max(int a,int b){
  return ((a > b) ? a : b);
}

int min(int a,int b){
  return ((a < b) ? a : b);
}

int sum(int a,int b){
  return a+b;
}
int main()
{
  int a,b,res;
  cout<<"请输入整数a：";cin>>a;
  cout<<"请输入整数b：";cin>>b;

  res = compute(a,b,&max);
  cout<<"Max:"<<res<<endl;
  res = compute(a,b,&min);
  cout<<"Min:"<<res<<endl;
  res = compute(a,b,&sum);
  cout<<"Sum:"<<res<<endl;

  return 0;
}
