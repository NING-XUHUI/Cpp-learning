#include<iostream>

using namespace std;

int main(){

  int N,U,D;
  int min = 0;
  cin>>N>>U>>D;

  int pa = 0;

  while(pa != N){
    pa += U;
    min++;
    if(pa >= N)
      break;

    
    pa -= D;
    min++;
  }

  cout<<min;
  

  return 0;
}
