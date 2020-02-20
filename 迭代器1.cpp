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

/*迭代器支持的操作
  迭代器是泛化的指针，提供了类似指针的操作（诸如++、*、-》、运算符）
  输入迭代器
    可以用来从序列中读取数据，如输入流迭代器
  输出流迭代器
    允许向序列写入数据，如输出流迭代器
  前向迭代器
    既是输入迭代器也是输出迭代器，并且可以对序列进行单向的遍历
  双向迭代器
    与前向迭代器相似，但是在两个方向上都可以对数据遍历
  随机访问迭代器
    也是双向迭代器，但能够在序列中的任意两个位置之间进行跳转，
  如指针、适用vector的begin（）、end（）函数得到的迭代器

 */

/*迭代器的区间
  两个迭代器表示一个区间:[p1,p2)
  STL算法常以迭代器的区间作为输入，传递输入数据
  合法的区间
    p1进过n次(n>0)自增(++)操作后满足p1==p2
  区间包含p1，但不包含p2
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
