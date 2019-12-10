//
//  main.cpp
//  双目运算符重载为友元函数
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
    
    friend point operator+(point a,point b);
};
point operator+(point a,point b){
    point temp;
    temp.x = a.x + b.x;
    temp.y = a.y +b.y;
    return temp;
}
int main(int argc, const char * argv[]) {
    // insert code here...

    point ob1(1,2),ob2(3,4),ob3,ob4;
    ob3 = ob1 + ob2;
    ob4 = operator+(ob1,ob2);
    
    cout<<ob4.getX()<<"   "<<ob4.getY()<<endl;
    return 0;
}
