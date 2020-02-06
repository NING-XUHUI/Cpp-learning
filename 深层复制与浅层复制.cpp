#include<iostream>
using namespace std;
class Point{
  
};

class ArrayOfPoints{
  ArrayOfPoints(const ArrayOfPoints& pointsArray);
};

//深层复制
ArrayOfPoints::ArrayOfPoints(const ArrayOfPoints& pointsArray){
  size = pointsArray.size;
  points = new Point[size];
  for(int i = 0;i<size;i++){
    points[i] = pointsArray[i];
  }
}

int main(){

  int count;
  cout<<"Please enter the count of points:";
  cin>>count;
  ArrayOfPoints pointsArray1(count);
  pointsArray1.element(0).move(5,10);
  pointsArray1.element(1).move(15.20);
  //浅层复制
  ArrayOfPoints pointsArray2(pointsArray1);

  cout<<"Copy of pointsarray1:"<<endl;
  cout<<"Point_0 of array2:"<<pointsArray2.element(0).getX();<<","<<pointsArray2.element(0).getY()<<endl;

   cout<<"Point_1 of array2:"<<pointsArray2.element(1).getX();<<","<<pointsArray2.element(1).getY()<<endl;
   //5,10
   //15,20
   //数组一移动之后，数组二跟着移动
   //且程序结束时会析构产生错误

   
   



   
  return 0;
}
