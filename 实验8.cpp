#include<iostream>
using namespace std;

class Point{
  int _x,_y;
public:
  Point(int x = 0,int y = 0):_x(x),_y(y){}
  Point& operator++();//前
  Point operator++(int);//后
  Point& operator--();//前
  Point operator--(int);//后
  friend ostream& operator << (ostream& o,Point& p);
};

Point& Point::operator++(){
  _x++;
  _y++;
  return *this;
}

Point Point::operator++(int){
  Point old = *this;
  ++(*this);

  return old;
}

Point& Point::operator--(){
  _x--;
  _y--;
  return *this;
}

Point Point::operator--(int){
  Point old = *this;
  --(*this);
  return old;
}

ostream& operator << (ostream& o,Point& p){
  o<<"("<<p._x<<","<<p._y<<")";
  return o;
}

int main(){

  return 0;
} 
