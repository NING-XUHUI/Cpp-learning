//
//  main.cpp
//  Memory&Pointer
//
//  Created by 宁旭晖 on 2019/12/23.
//  Copyright © 2019 宁旭晖. All rights reserved.
//

#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    // insert code here...
    int num = 7;
    cout<<num<<endl;
    cout<<&num<<endl;
    
    int *p = &num;
    cout<<p<<endl;
    cout<<&p<<endl;
    cout<<"asd dmk awr"<<endl;

    *p = 42;
    cout<<num<<endl;

    return 0;
}
