#include<iostream>

using namespace std;

class Rectangle{
  int len,wid;
public:
  Rectangle(int l,int w):len(l),wid(w){}
  void show();
  friend int Area(const Rectangle &r);
  friend int Round(const Rectangle &r);
};


int Area(const Rectangle& r){
  return (r.len*r.wid);
}

int Round(const Rectangle& r){
  return 2*(r.len+r.wid);
}

void Rectangle::show(){
  cout<<"zc:"<<Round(*this)<<endl;
  cout<<"mj:"<<Area(*this)<<endl;
}

int main(){

  Rectangle a(10,20);
  Rectangle b(100,200);

  a.show();
  b.show();
  

  return 0;
}
