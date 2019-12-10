//
//  main.cpp
//  重载为类的成员函数
//
//  Created by 宁旭晖 on 2019/12/7.
//  Copyright © 2019 宁旭晖. All rights reserved.
//

#include <iostream>
using namespace std;

class point{
private:
    int x,y;
public:
    point(int xx = 0,int yy = 0){
        x = xx;
        y = yy;
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    point operator+(point p);
};

point point::operator+(point p){
    point temp;
    temp.x = x+p.x;
    temp.y = y+p.y;
    return temp;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    point ob1(1,2),ob2(3,4),ob3,ob4;
    ob3 = ob1+ob2;
    ob4 = ob1.operator+(ob2);
    
    cout<<ob3.getX()<<"   "<<ob3.getY()<<endl;
    cout<<ob4.getX()<<"   "<<ob4.getY()<<endl;
    
    
    return 0;
}
