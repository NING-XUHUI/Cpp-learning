//
//  main.cpp
//  单目运算符重载为友元函数
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
    friend point operator++(point &p);
};
point operator++(point &p){
    ++p.x;
    ++p.y;
    return p;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    point ob(3,4);
    operator++(ob);
    
    cout<<ob.getX()<<"   "<<ob.getY()<<endl;
    
    return 0;
}
