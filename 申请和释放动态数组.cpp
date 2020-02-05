#include <iostream>

using namespace std;

class Point{
public:
  Point():x(0),y(0){cout<<"Default constructor called."<<endl;}
  Point(int x,int y):x(x),y(y){cout<<"Constructor called."<<endl;}
  ~Point(){cout<<"Destructor called."<<endl;}
  void move(int newX,int newY){
    x = newX;
    y = newY;
  }
  int getX(){return x;}
  int getY(){return y;}
private:
  int x,y;
};

int main(){
  Point *ptr = new Point[2];
  ptr[0].move(5,10);
  ptr[1].move(2,3);
  cout<<"Deleting..."<<endl;
 
  delete[] ptr;
  
  
  return 0;
}
