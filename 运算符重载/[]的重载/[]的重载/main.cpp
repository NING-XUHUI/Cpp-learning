//
//  main.cpp
//  []的重载
//
//  Created by 宁旭晖 on 2019/12/7.
//  Copyright © 2019 宁旭晖. All rights reserved.
//

#include <iostream>
using namespace std;

class aniteger{
    int *a;
    int sz;
public:
    aniteger(int size){
        sz = size;
        a =new int[size];
    }
    int &operator[](int i){
        if (i<0||i>=sz) {
            cout<<"error"<<endl;
        }
        return a[i];
    }
    ~aniteger(){
        delete [] a;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...

    aniteger a(5);
    a[3] = 0;
    a.operator[](3)=0;//不越界
    a.operator[](6);//越界
    return 0;
}
