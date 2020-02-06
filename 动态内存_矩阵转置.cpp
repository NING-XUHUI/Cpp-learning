#include<iostream>

using namespace std;

void swap(int &a,int &b){
  int temp = a;
  a = b;
  b = temp;
}

int main(){

  int **a;
  a = new int*[3];
  for(int i = 0;i<3;i++)
    a[i] = new int[3];

  ...
  
  return 0;
}
