//
//  main.cpp
//  函数重载
//
//  Created by 宁旭晖 on 2019/12/7.
//  Copyright © 2019 宁旭晖. All rights reserved.
//

#include <iostream>
using namespace std;

class point{
    int x,y;
public:
    point(int xx,int yy){
        x = xx;
        y = yy;
    }
    double area(){
        return 0.0;
    }
};

class circle:public point{
    int r;
public:
    circle(int xx,int yy,int rr):point(xx,yy){
        r = rr;
    }
    double area(){
        return 3.1415*r*r;
    }
};


int main(int argc, const char * argv[]) {

    point pob(15, 15);
    circle cob(20, 20, 10);
    cout<<"pob.area="<<pob.area()<<endl;
    cout<<"con.area="<<cob.area()<<endl;
    cout<<"cob.point::area()="<<cob.point::area()<<endl;
    
}
