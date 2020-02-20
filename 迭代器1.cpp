/*
迭代器是算法和容器的桥梁
  迭代器用作访问容器中的元素
  算法不直接操作容器中的数据。而是通过迭代器间接操作
算法和容器独立
  增加新的算法，无需影响容器的实现
  增加新的容器，原有的算法也能适用
 */

/*输入流迭代器
输入流迭代器
  istream_iterator<T>
  以输入流如cin为参数构造
  可用*(p++)获得下一个输入的元素
输出流迭代器
  ostream_iterator<T>
  构造时需要提供输出流如cout
  可用(*p++) = x将x输出到输出流
二者都属于适配器
  适配器是用来为已有对象提供新的接口的对象
  输入流适配器和输出流适配器为流对象提供了迭代器的接口
 */

#include<iostream>
#include<iterator>
#include<algorithm>
using namespace std;

//求平方函数
double square(double x){
  return x*x;
}

int main(){
  //从标准输入读入若干个实数，分别将他们的平方输出
  transform(istream_iterator<double>(cin),istream_iterator<double>(),ostream_iterator<double>(cout,"\t"),square);//输入流结束C-d
  cout<<endl;
  return 0;
} 
