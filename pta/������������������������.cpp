#include<iostream>

using namespace std;

int main(){

  int cm;
  cin>>cm;
  float inch = 0.01*(float)cm*12/(145*0.3048);
  int inch_bit = (int)inch % 12;
  int count = 0;
  int foot_cnt = inch;
  while(foot_cnt > inch_bit){
    foot_cnt -= 12;
    count++;
  }
  cout<<cout<<" "<<inch_bit;

  

  return 0;
}
