//
//  main.cpp
//  类类型转换
//
//  Created by 宁旭晖 on 2019/12/7.
//  Copyright © 2019 宁旭晖. All rights reserved.
//

#include <iostream>
using namespace std;

class Test{
public:
    Test(int a = 0){
        cout<<this<<":"<<"载入构造函数"<<a<<endl;
    }
    Test(Test &temp){
        cout<<"载入拷贝构造函数"<<endl;
        Test::a=temp.a;
    }
    ~Test(){
        cout<<this<<":"<<"载入析构函数"<<this->a<<endl;
        cin.get();
    }
    operator int(){
        cout<<this<<":"<<"载入转换运算符函数"<<this->a<<endl;
        return Test::a;
    }
    public:
        int a;
};

int main(int argc, const char * argv[]) {
    // insert code here...
        
        Test b(99);
        
        cout<<"b的内存地址"<<&b<<endl;
        cout<<(int)b<<endl;
        
        
        
        return 0;
}
