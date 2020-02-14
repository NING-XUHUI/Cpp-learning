#include<iostream>

using namespace std;
class Base1{
public:
  Base1(int i){cout<<"Constructing Base1."<<i<<endl;}
  ~Base1(){cout<<"Destructing Base1."<<endl;}
};

class Base2{
public:
  Base2(int j){cout<<"Constructing Base2."<<j<<endl;}
  ~Base2(){cout<<"Destructing Base2."<<endl;}
};

class Base3{
public:
  Base3(){cout<<"Constructing Base3."<<endl;}
  ~Base3(){cout<<"Destructing Base3."<<endl;}
};

class Derived:public Base2,public Base1,public Base3{//构造先按照继承顺序调用构造函数
public:
  Derived(int a,int b,int c,int d):Base1(a),member2(d),member1(c),Base2(b){}//构造顺序与此顺序无关
private:
  Base1 member1;
  Base2 member2;
  Base3 member3;
  //基类构造函数调用完毕后，再依次调用成员的构造函数
};

int main(){
  Derived obj(1,2,3,4);
  return 0;
}
//析够顺序与构造顺序相反
