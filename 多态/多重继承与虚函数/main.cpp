//
//  main.cpp
//  多重继承与虚函数
//
//  Created by 宁旭晖 on 2019/12/7.
//  Copyright © 2019 宁旭晖. All rights reserved.
//

#include <iostream>
using namespace std;

class base{
public:
    virtual void func() const{
        cout<<"base output"<<endl;
    }
};

class derived1:public base{
public:
    void func() const{
        cout<<"derived1 output"<<endl;
    }
};

class derived2 :public derived1{
public:
    void func() const{
        cout<<"derived2 output"<<endl;
    }
};

void test(const base &rBase){
    rBase.func();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    base bObj;
    derived1 d1Obj;
    derived2 d2Obj;
    test(bObj);
    test(d1Obj);
    test(d2Obj);



    return 0;
}
