//
//  main.cpp
//  抽象类
//
//  Created by 宁旭晖 on 2019/12/7.
//  Copyright © 2019 宁旭晖. All rights reserved.
//

#include <iostream>
using namespace std;

class Vehicle{
public:
    Vehicle(float speed,int total){
        Vehicle::speed = speed;
        Vehicle::total = total;
    }
    virtual void showMember()=0;
protected:
    float speed;
    int total;
};

class Car:public Vehicle{
public:
    Car(float speed,int total,int arid):Vehicle(speed,total){
        Car::arid = arid;
    }
    void showMember(){
        cout<<"speed is "<<speed<<endl;
        cout<<"total is "<<total<<endl;
        cout<<"arid is "<<arid<<endl;
    }
protected:
    int arid;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
//    Vehicle a(100,4);
    
    Car b(250,150,4);
    b.showMember();

    return 0;
}
