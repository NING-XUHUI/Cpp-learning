#include<iostream>
using namespace std;

class RECT{
public:
  double x,y;//长方形的长和宽
  RECT(double x1,double y1):x(x1),y(y1){}//构造函数
  virtual double area();//虚函数，计算长方形面积
  double peri();//计算长方形的周长
  virtual int isSquare();//虚函数，判断是否为正方形，是返回1，否则返回0
};

double RECT::area(){
  return x*y;
}

double RECT::peri(){
  return 2*(x + y);
}

int RECT::isSquare(){
  if(x == y)
    cout<<"是正方形"<<endl;
    return 1;
  return 0;
}

class CUB:public RECT{
public:
  double height;//长方体的高
  CUB(double x1,double y1,double h1):RECT(x1,y1),height(h1){}//构造函数，用h、x、y分别初始化h和基类成员
  double volume();//计算体积
  double area();//面积
  int isSquare();//判断是否为正方体
};

double CUB::volume(){
  return x*y*height;
}

double CUB::area(){
  return 2*(x*y + x*height + y*height);
}

int CUB::isSquare(){
  if(x == y && x == height)
    cout<<"是正方体"<<endl;
    return 1;

  return 0;
}

int main(){

  CUB b(1,2,3);

  RECT *re = &b;

  cout<<"体积为："<<b.volume()<<endl;
  cout<<"表面积为:"<<re->area()<<endl;
  re->isSquare();

  return 0;
} 
