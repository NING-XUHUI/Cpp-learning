#include<iostream>
using namespace std;

class Array{
  int ar[3];
public:
  Array(){}
  Array(int *a){
    for(int i = 0;i < 3;i++)
      ar[i] = a[i];
  }
  void show(){
    for(int i = 0;i<3;i++)
      cout<<ar[i]<<" ";
    cout<<endl;
  }
  Array operator^(const Array &a);
};

Array Array::operator^(const Array &a){
  int t;
  for(int i=0;i<3;i++){
    t = ar[i];
    if(a.ar[i] == 0)ar[i] = 1;
    else for(int j = 1;j<a.ar[i];j++)
           ar[i] *= t;
  }
  return *this;
}

int main(){

  int a[3]={2,2,2},b[3]={3,4,2};
	Array ar1(a),ar2(b),ar3;
	ar1.show();	ar2.show();
	ar3=ar1^ar2;	ar3.show();

  return 0;
} 
