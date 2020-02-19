#include<iostream>
using namespace std;

class Base{
public:
  virtual void f();
  virtual void g();
private:
  int i;
};

class Derived:public Base{
public:
  virtual void f();//覆盖了Base的函数
  virtual void h();
private:
  int j;
};

int main(){

  return 0;
}
