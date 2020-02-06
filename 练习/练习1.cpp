/*
  编写一个程序，定义长方形类，构造函数、拷贝构造、赋值构造、获取面积、获取IOU面积、获取交集面积、并集面积、面积大小比较、是否为同一长方形比较、自定义cout << 打印函数。
*/

#include<iostream>

using namespace std;

class Rectangle{
private:
  int *x,*y;
  int *area;
public:
  Rectangle(int xx=0,int yy=0){
    x = new int(xx);
    y = new int(yy);
    area = new int(xx*yy);
  }
  Rectangle(const Rectangle &r){
    x = new int(*r.x);
    cout<<"x copy"<<endl;
    y = new int(*r.y);
    cout<<"y copy"<<endl;
    area = new int(*r.area);
    cout<<"area copy"<<endl;
  }//深层复制
  /*
  Rectangle(const Rectangle &r){
    x = r.x;
    y = r.y;
    area = r.area;
  }浅层复制，将随着复制对象的改变而改变.
*/
  ~Rectangle(){
    delete x;
    cout<<"x done"<<endl;
    delete y;
    cout<<"y done"<<endl;
    delete area;
    cout<<"area done"<<endl;
    
  }
  
  
  int getArea(){return *area;}

  void changePoint(int newX,int newY){
    *x = newX;
    *y = newY;
    *area = newX*newY;
  }
  
  
};


int main(){

  Rectangle a(3,4);
  Rectangle b(a);

  a.changePoint(5,6);

  cout<<a.getArea()<<endl;
  cout<<b.getArea()<<endl;

  

  
  return 0;
}
