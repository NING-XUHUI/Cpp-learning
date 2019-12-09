//
//  main.cpp
//  练习
//
//  Created by 宁旭晖 on 2019/12/7.
//  Copyright © 2019 宁旭晖. All rights reserved.
//

#include <iostream>
#define PI 3.14
using namespace std;

class Shape{
public:
    virtual double getArea()=0;
    virtual double getPerim()=0;
};

class circle:public Shape{
public:
    circle(float r){
        radius = r;
    }
    double getArea(){
        return radius*radius*PI;
    }
    double getPerim(){
        return 2*radius*PI;
    }
protected:
    float radius;
};

class Rectangle :public Shape{
protected:
    int width,height;
public:
    Rectangle(int w,int h){
        width = w;
        height = h;
    }
    double getArea(){
        return width*height;
    }
    double getPerim(){
        return 2*(width + height);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    circle c(3.0);
    cout<<c.getArea()<<endl;
    cout<<c.getPerim()<<endl;
    
    Rectangle r(3,4);
    cout<<r.getArea()<<endl;
    cout<<r.getPerim()<<endl;
    
    

    return 0;
}
