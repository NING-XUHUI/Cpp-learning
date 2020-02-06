#include<iostream>

using namespace std;

class Array{
private:
  int *p,k;
  float *s;
public:
  Array(int *ptr,int n);
  int fun(const int &n);
  void sum();
  void show();
  ～Array();
};

Array::Array(int* ptr,int n){
  p = new int(*ptr);
  k = n;
  s = new float(0);
}

int Array::fun(const int &n){
  if(n == 2)
    return 1;
  else if(n == 1)
    return 0;
  else{
    for(int i = 2;i<n/2;i++){
      if(n%i == 0)
	return 0;
      else continue
	     }
    return 1;
  }
}

void sum(){
  for(int i = 0;i<k;i++){
    if(p[i].)
  }
  
}

int main(){

  

  return 0;
}
