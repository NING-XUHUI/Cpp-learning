#include<iostream>

using namespace std;

int main(){

  int ball[3];
  for(int i = 0;i < 3;i++)
    cin>>ball[i];

  auto n = ball[0];
  for(int j = 1;j < 3;j++)
    n = n^ball[j];
    int a = ball[0],b = ball[1],c=ball[2];
    if(n == a)
      cout<<"A";
    else if(n == b)
      cout<<"B";
    else
      cout<<"C";
  
  return 0;
}
