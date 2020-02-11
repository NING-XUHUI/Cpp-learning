#include<iostream>
#include<iomanip>
using namespace std;

int main(){
  int Intteger;
  char s;
  float f1;
  float f2;

  cin>>f1>>Intteger>>s>>f2;

  cout<<setprecision(3)<<s<<" "<<Intteger<<" "<<f1<<" ";
  cout<<setiosflags(ios::fixed|ios::showpoint)<<setprecision(2)<<f2<<endl;

  return 0;
}
