#include<iostream>

using namespace std;

class Point{
private:
  int x,y;
public:
  Point();
  Point(int x,int y); 
  ~Point();
  void move(int newX,int newY);
  int getX()const{return x;}
  int getY()const{return y;}

  static void showCount();
};

Point::Point():x(0),y(0){
  cout<<"Default Constructor called."<<endl;
}

Point::Point(int x,int y):x(x),y(y){
  cout<<"Constructor called."<<endl;
}
Point::~Point(){
  cout<<"Destructor called."<<endl;
}

void Point::move(int newX,int newY){
  cout<<"Moving the Point to("<<newX<<","<<newY<<")"<<endl;
  x = newX;
  y = newY;
}

   
int main(){

  cout<<"Enter main..."<<endl;
  Point a[2];
  for(int i = 0;i<2;i++){
    a[i].move(i+10,i+20);
  }
  cout<<"Exiting main..."<<endl;
 
  return 0;
}
