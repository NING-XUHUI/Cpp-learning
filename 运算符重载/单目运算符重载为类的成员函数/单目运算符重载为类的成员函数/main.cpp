//
//  main.cpp
//  单目运算符重载为类的成员函数
//
//  Created by 宁旭晖 on 2019/12/7.
//  Copyright © 2019 宁旭晖. All rights reserved.
//
//单目运算符成员运算时没有参数
#include <iostream>
using namespace std;

class point{
private:
    int x,y;
public:
    point(int xx=0,int yy=0){
        x = xx;
        y = yy;
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    point operator++();
};

point point::operator++(){
    ++x;
    ++y;
    return *this;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    point ob(3,4);
    
    ob.operator++();
    cout<<ob.getX()<<"   "<<ob.getY()<<endl;
    
    return 0;
}
