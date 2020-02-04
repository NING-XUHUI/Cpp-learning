#include<iostream>
#include<cmath>
using namespace std;

class SavingsAccount{
private:
  int id;//账号
  double balance;//余额
  double rate;//存款的年利率
  int lastDate;//上次变更余额的时期
  double accumulation;//余额按日累加之和

  void record(int date,double amount);

  double accumulation(int date)const{
    return accumulation + balance * (date - lastDate);
  }
public:
  //构造函数
  SavingsAccount(int date,int id,double rate);
  int getId(){return id;}
  double getBalance(){return balance;}
  double getRate(){return rate;}
  //存入现金
  void deposit(int date,double amount);
  //取出现金
  void withdraw(int date,double amount);
  //结算利息，每年1月1日调用一次该函数
  void settle(int date);
  //显示账户信息
  void show();
  
};

SavingsAccount::SavingsAccount(int date,int id,double rate):id(id),balance(0),rate(rate),lastDate(date),accumulation(0){
  cout<<date<<"\t#"<<id<<"is created"<<endl;
}

void SavingsAccount::record(int date,double amount){
  accumulation = accumulation(date);
  lastDate = date;
  amount = floor(amount * 100 + 0.5) / 100;
  balance += amount;
  
}


void SavingsAccount::settle(int date){
  double interest = accumulation(date)* rate / 365;
  if(interest != 0)
    record(date,interest);
  accumulation = 0;
}

void SavingsAccount::show(){
  cout<<"#"<<id<<"\tBalance"<<balance;
}


int main(){
  
  return 0;
}

