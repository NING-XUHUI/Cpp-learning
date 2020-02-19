/*
声明一个车基类，有run、stop等成员函数，由此派生出自行车类、汽车类，从两个类中派生出摩托车类，他们都有run、stop等函数。
 */


#include<iostream>
using namespace std;

class Vehicle{
public:
  int MaxSpeed;
  int Weight;
  //void Run(){cout<<"vehicle run!"<<endl;}
  //void Stop(){cout<<"vehicle stop!"<<endl;}
  virtual void Run(){cout<<"vehicle run!"<<endl;}
  virtual void Stop(){cout<<"vehicle stop!"<<endl;}
};

class Bicycle:virtual public Vehicle{
public:
  int Height;
  void RUn(){cout<<"bicycle run!"<<endl;}
  void Stop(){cout<<"bicycle stop!"<<endl;}
};

class Motorcar:virtual public Vehicle{
public:
  int SeatNum;
  void Run(){cout<<"Motorcar run!"<<endl;}
  void Stop(){cout<<"Motorcar stop!"<<endl;}
};

class Motorcycle:public Bicycle,public Motorcar{
public:
  void Run(){cout<<"Motorcycle run!"<<endl;}
  vodi Stop(){cout<<"Motorcycle stop!"<<endl;}
};


int main(){
  Vehicle v;
  v.Run();
  v.Stop();
  Bicycle b;
  b.Run();
  b.Stop();
  Motorcar m;
  m.Run();
  m.Stop();
  Motorcycle mc;
  mc.Run();
  mc.Stop();
  Vehicle* vp = &v;
  vp->Run();
  vp->Stop();
  vp = &b;
  vp->Run();
  vp->Stop();
  vp = &m;
  vp->Run();
  vp->Stop();
  vp = &mc;
  vp->Run();
  vp->Stop();

  return 0;
}







