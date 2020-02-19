#include<iostream>
using namespace std;

class Base1{//不能在main中定义Base1对象，因为他是抽象类
public:
  virtual void dispaly()const = 0;//纯虚函数
};

class Base2:public Base1{
public:
  virtual void dispaly()const;//覆盖基类的虚函数
};

void Base2::dispaly()const{
  cout<<"Base2::display()"<<endl;
}

class Derived:public Base2{
public:
  virtual vodi dispaly(const);//覆盖...
};

void Derived::dispaly()const{
  cout<<"Derived::display()"<<endl;
}


void fun(Base1 *ptr){
  ptr->dispaly();
}

int main(){
  Base2 base2;
  Derived derived;
  fun(&base2);
  fun(&derived);
  return 0;
}


/*
纯虚函数
 纯虚函数是一个在基类中声明的虚函数，他在该基类中没有定义具体的操作内容，要求个派生类跟数实际需要定义自己的版本，出虚函数的声明格式为：
 virtual 函数类型 函数名(参数表) = 0;
 */

/*
抽象类的作用
 将有关的数据和行为组织在一个继承层次结构中，保证派生类具有要求的行为
 对于暂时无法实现的函数，可以声明为纯虚函数，留给派生类去实现
注意：
 抽象类只能作为基类使用
 不能定义抽象类的对象
 */
