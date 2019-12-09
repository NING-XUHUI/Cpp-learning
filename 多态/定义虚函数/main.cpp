//
//  main.cpp
//  定义虚函数
//
//  Created by 宁旭晖 on 2019/12/7.
//  Copyright © 2019 宁旭晖. All rights reserved.
//

#include <iostream>
using namespace std;

class animal{
public:
    void sleep(){
        cout<<"animal sleeo"<<endl;
    }
    virtual void breath(){//定义虚函数
        cout<<"animal breath"<<endl;
    }
};

class fish:public animal{
public:
    void sleep(){
        cout<<"fish bubble"<<endl;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    fish fh;
    animal *pan = &fh;
    pan->breath();

    return 0;
}
