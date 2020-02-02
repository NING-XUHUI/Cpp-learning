#include <iostream>

#define PI 3.1415926

inline double getArea(float radius){
  return PI * radius *radius;
}

int main(){

  float radius = 4;

  float area = getArea(radius);

  std::cout<<"area is :"<<area<<std::endl;

  return 0;
}
