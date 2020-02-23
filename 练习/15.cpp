#include<iostream>
#include<cmath>
using namespace std;

class Point{
protected:
  int x1,y1;
public:
  Point(int a,int b):x1(a),y1(b){}
};

class Line:public Point{
protected:
  int x2,y2;
public:
  Line(int a,int b,int c,int d):Point(a,b),x2(c),y2(d){}
};

class Triangle:public Line{
private:
  int x3,y3;
  double area;
public:
  Triangle(int a,int b,int c,int d,int e,int f):Line(a,b,c,d),x3(e),y3(f){
    area = 0;
  }
  void f();
  void print();
};

void Triangle::f(){
  double s1 = static_cast<double>(sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)));
  double s2 = static_cast<double>(sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3)));
  double s3 = static_cast<double>(sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3)));

  double s = (s1 + s2 + s3)/2;
  this->area = sqrt(s*(s-s1)*(s-s2)*(s-s3));
}

void Triangle::print(){
  cout<<"三角形面积是："<<this->area<<endl;
}

int main(){
  
  Triangle tri(4,1,4,5,1,1);
  tri.f();
  tri.print();

  return 0;
} 
