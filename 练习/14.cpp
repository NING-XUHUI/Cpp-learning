#include<iostream>
using namespace std;
#define PI 3.1415

class Container{
protected:
  double radius;
public:
  Container(double r);
  virtual double area() = 0;
  virtual double volume() = 0;
};

Container::Container(double r){
  Container::radius = r;
}

class Cube:public Container{
public:
  Cube(double r):Container(r){}
  double area();
  double volume();
};

double Cube::area(){
  return 6*(radius * radius);
}

double Cube::volume(){
  return radius *radius * radius;
}

class Sphere:public Container{
public:
  Sphere(double r):Container(r){}
  double area();
  double volume();
};

double Sphere::area(){
  return radius*radius*PI*4;
}

double Sphere::volume(){
  return radius*radius*radius*PI*4/3;
}
int main(){

  Container *p;
  Cube obj1(10);
  Sphere obj2(6);

  p=&obj1;
  cout<<p->area()<<" "<<p->volume()<<endl;
  p=&obj2;
  cout<<p->area()<<" "<<p->volume()<<endl;

  return 0;
} 
