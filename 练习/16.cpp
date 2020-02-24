#include<iostream>
using namespace std;

class Array{
public:
  int *p;
  int n;

  Array(){
    p = nullptr;
    n =0;
  }
  Array(Array& a){
    this->n = a.n;
    p = new int[n];
    for(int i = 0;i < n;i++)
      p[i] = a.p[i];
  }
  Array& operator = (const Array &t){
    if(this->p){
      delete[]p;
    }
    this->n = t.n;
    p = new int[t.n];
    for(int i = 0;i < n;i++)
      p[i] = t.p[i];

    return *this;
  }

};

int main(){

  return 0;
}

