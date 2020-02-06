#include<iostream>

using namespace std;


void swap(int &i,int &j){
  int t;
  t = i;
  i = j;
  j = t;
}

void sort(int *p,int n){

  for(int i = 0;i<n-1;i++){
    for(int j = 0;j<i;j++){
      if(p[j]>p[i]){
	swap(p[i],p[j]);
      }
    }
  }
}




int main(){

  int n,r;
  cin>>n>>r;

  int p[n];
  for(int i = 0;i<n;i++){
    cin>>p[i];
  }

  sort(p,n);

  cout<<p[r-1];
  
  


  
  return 0;
}
