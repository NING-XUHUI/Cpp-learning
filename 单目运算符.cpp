#include<iostream>
using namespace std;

class Clock{
public:
  Clock(int hour = 0,int minute = 0,int second = 0);
  void show()const;
  //前置单目运算符重载
  Clock& operator++();
  //后置单目运算符重载
  Clock& operator++(int);
private:
  int hour,minute,second;
};

Clock::Clock(int hour,int minute,int second){
  if(0 <= hour && hour < 24 && 0 <= minute && minute < 60 && 0 <= second && second < 60){
    this->hour = hour;
    this->minute = minute;
    this->second = second;
  }else
    cout<<"Time Error !"<<endl;
}

void Clock::show()const{
  cout<<hour<<":"<<minute<<":"<<second<<endl;
}

Clock&Clock::operator++(){
  second++;
  if(second >= 60){
    second -= 60;minute++;
    if(minute >= 60){
      minute-= 60;hour = (hour + 1)%24;}
  }
  return *this;//返回的是加1之后的时间
}

Clock Clock::operator++(int){
  Clock old = *this;
  ++(*this);
  return old;//返回的是加1之前的时间
}

int main(){
  Clock myClock(23,59,59);
  cout<<"First time output:";//23 59 59
  myClock.show();
  cout<<"Show myClock++:";//23 59 59
  (myClock++).show();
  cout<<"Show ++myClock:";0 0 1
  (++myClock).show();

  return 0;
}


/*
前置单目运算符，重载函数没有形参
后置++运算符，重载函数需要有一个int形参
操作数是是时钟类对象
实现时间增加一秒
 */
