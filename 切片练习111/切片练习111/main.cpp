//
//  main.cpp
//  切片练习111
//
//  Created by 宁旭晖 on 2020/2/20.
//  Copyright © 2020 宁旭晖. All rights reserved.
//

#include<iterator>
#include<iostream>
#include<list>
#include<string>
using namespace std;

int main(){

    char w1[] = {'A','P','P','L','E'};
    char w2[] = {'P','E','A','R'};
    
    list<char>c1(w1,w1+5);
    list<char>c2(w2,w2+4);
    
    list<char>::iterator iter1 = c1.begin();
    list<char>::iterator iter2 = c1.end();
    
    c2.splice(c2.end(), c1, iter1, iter2);
    sort(c2.begin(), c2.end(),lower<char>());
    
    copy(c2.begin(), c2.end(), ostream_iterator<char>(cout,""));
    cout<<endl;
  return 0;
}
