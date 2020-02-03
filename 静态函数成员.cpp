#include<iostream>

using namespace std;

class Point{
private:
  int x,y;
  static int count;
public:
  Point(int x = 0,int y = 0):x(x),y(y){count++;}

  Point(Point &p){
    x = p.x;
    y = p.y;

    count++;
  }
  ~Point(){
    count--;
  }

  int getX(){return x;}
  int getY(){return y;}

  static void showCount(){
    cout<<"Object count = "<<count<<endl;//静态函数只能在类内部进行定义
  }
  
};

int Point::count = 0;

int main(){
  Point::showCount();
  
  Point a(4,5);

  Point::showCount();

  Point b(a);

  Point::showCount();
  
  return 0;
}
