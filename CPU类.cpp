/*
例题一：
    声明一个CPU类，包含等级（rank）、频率（frequency）、电压（voltage）等属性，有两个公有成员函数run、stop。
    其中：
    rank为枚举类型CPU_Rank，声明为enum CPU_Rank{P1=1,P2,P3,P4,P5,P6,P7},frequency为单位是MHz的整型数，voltage为浮点型的电压值。

    注意不同访问属性的成员访问方式，并观察构造函数和析构函数的调用顺序。
*/



#include<iostream>

using namespace std;

enum CPU_Rank{P1 = 1,P2,P3,P4,P5,P6,P7};

class CPU{
private:
  CPU_Rank rank;
  int frequency;
  float voltage;
public:
    CPU(CPU_Rank r,int f,float v){
    rank = r;
    frequency = f;
    voltage = v;
    cout<<"构造类一个CPU！"<<endl;
  }
  ~CPU(){cout<<"析构了一个CPU！"<<endl;}
  CPU_Rank getRank()const{return rank;}
  int getFrequency()const{return frequency;}
  float getVoltage()const{return voltage;}

  void setRank(CPU_Rank r){rank = r;}
  void setFrequency(int f){frequency = f;}
  void setVoltage(float v){voltage = v;}

  void Run(){cout<<"CPU开始运行！"<<endl;}
  void Stop(){cout<<"CPU停止运行！"<<endl;}
  
};

int main(){
  CPU a(P6,300,2.8);
  a.Run();
  a.Stop();

  return 0;
}
