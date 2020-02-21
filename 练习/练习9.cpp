#include<iostream>
using namespace std;

class Base{
protected:
  char name[8];//姓名
  int num;//存放分数或论文数
public:
  Base();
  void print();//功能函数，输出数据成员
  virtual int Isgood() = 0;//纯虚函数
};

Base::Base(){
  cin>>name;
}

void Base::print(){
  cout<<name<<endl;
}

class Student:public Base{
public:
  Student():Base(){cin>>Base::num;}
  int Isgood();
};

int Student::Isgood(){
  if(num > 90)
    return 1;

  return 0;
}

class Teacher:public Base{
public:
  Teacher():Base(){cin>>Base::num;}
  int Isgood();
};

int Teacher::Isgood(){
  if(num > 3)
    return 1;

  return 0;
}

int main(){
  Student s[3];

  for(Student ss:s){
    if(ss.Isgood())
      ss.print();
  }

  return 0;
} 
