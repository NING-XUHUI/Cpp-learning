//
//  main.cpp
//  重载运算符特点
//
//  Created by 宁旭晖 on 2019/12/7.
//  Copyright © 2019 宁旭晖. All rights reserved.
//

#include <iostream>
using namespace std;

class CAdd{
public:
    int m;
    CAdd(){
        m = 0;
    }
    CAdd(int value){
        m = value;
    }
};

CAdd operator+(CAdd a,int b){
    CAdd sum;
    sum.m = a.m + b;
    return sum;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    CAdd a(5),b;
    b = a + 8;
    cout<<b.m<<endl;

    return 0;
}
