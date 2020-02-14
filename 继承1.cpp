#include<iostream>

using namespace std;

class Point{
public:
  void initPoint(float x = 0,float y = 0){this->x = x;this->y = y;}
  void move(float offX,float offY){x += offX;y += offY;}
  float getX()const{return x;}
  float getY()const{return y;}
private:
  float x,y;
};

class Rectangle:public Point{
public:
  void initRectangle(float x,float y,float w,float h){
    initPoint(x,y);
    this->w = w;
    this->h = h;
  }
  float getH()const{return h;}
  float getW()const{return w;}
private:
  float w,h;
  
};



int main(){
  Rectangle r;
  r.initRectangle(2,3,5,6);
  r.move(3,2);
  cout<<r.getX()<<","<<r.getY()<<","<<r.getH()<<" "<<r.getW();
  
  return 0;
}
