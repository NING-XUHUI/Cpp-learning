//
//  main.cpp
//  使用虚函数
//
//  Created by 宁旭晖 on 2019/12/7.
//  Copyright © 2019 宁旭晖. All rights reserved.
//

#include <iostream>
using namespace std;

class base{
private:
    int x,y;
public:
    base(int xx=0,int yy=0){
        x=xx;
        y=yy;
    }
    virtual void disp(){
        cout<<"base:"<<x<<"   "<<y<<endl;
    }
};

class base1:public base{
private:
    int z;
public:
    base1(int xx,int yy,int zz):base(xx,yy){
        z = zz;
    }
    void disp(){
        cout<<"base1:"<<z<<endl;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    base obj(3,4),*objp;
    base1 obj1(1, 2, 5);
    objp = &obj;
    objp->disp();
    objp= &obj1;
    objp->disp();

    return 0;
}
