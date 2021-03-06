//分数运算器

#include<iostream>

using namespace std;


class Frac{
private:
  int num,den;
public:
  Frac(int x = 0,int y = 1):num(x),den(y){}
  int ged(int m,int n);
  Frac add(Frac f);
  void show();
  
};

int Frac::ged(int m,int n){
  int a = ((m < n)?m:n);
  for(int i = a;i > 0;i--){
    if(m % i == 0 && n % i == 0)
      return i;
  }
}

Frac Frac::add(Frac f){
  int newNum,newDen;
  newNum = num*f.den + f.num*den;
  newDen = den*f.den;
  int p = Frac::ged(newNum,newDen);
  newNum /= p;
  newDen /= p;
  
  Frac newFrac(newNum,newDen);
  return newFrac;
}

void Frac::show(){
  if(num == den)
    cout<<"1"<<endl;
  else if(num == 0)
    cout<<"0"<<endl;
  else
    cout<<num<<"/"<<den<<endl;
}
int main(){

  Frac f1(1,5);
  Frac f2(7,20);
  Frac f3 = f1.add(f2);

  f3.show();
  

  return 0;
}
