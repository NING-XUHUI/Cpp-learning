#include <iostream>

using namespace std;

class Point{
public:
  Point():x(0),y(0){
    cout<<"Default constructor called."<<endl;
  }
  Point(int x,int y):x(x),y(y){
    cout<<"Constructor called."<<endl;
  }
  ~Point(){cout<<"Destructor called."<<endl;}
  int getX()const{return x;}
  int getY()const{return y;}
  void move(int newX,int newY){
    x = newX;
    x = newY;
  }
private:
  int x,y;
};

int main(){

  cout<<"Step one:"<<endl;

  Point *p1 = new Point;
  delete p1;

  cout<<"Step two:"<<endl;
  p1 = new Point(1,2);
  delete p1;
  
  return 0;
}
