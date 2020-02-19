/*
override
 多态行为的基础：基类声明虚函数，派生类声明一个函数覆盖该虚函数；
 覆盖要求：函数签名完全一致。
 函数签名包括：函数名 参数列表 *const*<不可省略>

c++11引入显示函数覆盖，在编译期而非运行期捕获此类错误。在虚函数显示重载中运用
，编译器会检查基类是否存在一虚拟函数，与派生类中带有声明override的虚拟函数，
有相同的函数签名；若不存在，则会报错.

 */

//final

#include<iostream>
using namespace std;

struct Base1 final{};

struct Derived1:Base1{};//编译错误：Base1为final，不允许被继承

struct Base2{
  virtual void f()final;
};

struct Derived2:Base2{
  void f();//编译错误：Base2:：f为final，不允许被覆盖
}

int main(){

  return 0;
} 


