#include<iostream>

using namespace std;

int main(){

  int array[3] = {1,2,3};

  for(int &e:array){
    e += 2;
    cout<<e<<endl;
  }

  return 0;
}
