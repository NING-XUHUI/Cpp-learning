//
//  main.cpp
//  特殊运算符重载
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
    point operator++();//前置
    point operator--(int);//后置,后置必须带形参，一般为0.
};
point point::operator++(){
    ++x;
    ++y;
    return *this;
}
point point::operator--(int){
    x--;
    y--;
    return *this;
}

int main(int argc, const char * argv[]) {
    // insert code here...

    point ob(3,4);
    
    ++ob;
    cout<<ob.getX()<<"   "<<ob.getY()<<endl;
    ob--;
    cout<<ob.getX()<<"   "<<ob.getY()<<endl;


    return 0;
}
