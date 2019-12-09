//
//  main.cpp
//  多态的引入
//
//  Created by 宁旭晖 on 2019/12/7.
//  Copyright © 2019 宁旭晖. All rights reserved.
//





#include <iostream>
using namespace std;

class animal{
public:
    void sleep(){
        cout<<"animal sleep"<<endl;
    }
    void breath(){
        cout<<"animal breath"<<endl;
    }
};

class fish:public animal{
public:
    void breath(){
        cout<<"fish bubble"<<endl;
    }
};
int main(int argc, const char * argv[]) {
    
    fish fh;
    fh.breath();
    
    animal *pan = &fh;
    pan->breath();
}
