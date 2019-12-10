//
//  main.cpp
//  =的重载
//
//  Created by 宁旭晖 on 2019/12/7.
//  Copyright © 2019 宁旭晖. All rights reserved.
//

#include <iostream>
using namespace std;

class Internet{
public:
    char *name,*url;
    Internet(char *name,char *url){
        Internet::name = new char(strlen(name) + 1);
        Internet::url = new char(strlen(url) + 1);
        if (name) {
            strcpy(Internet::name, name);
        }
        if (url) {
            strcpy(Internet::url, url);
        }
    }
    Internet(Internet &temp){
        Internet::name = new char(strlen(temp.name) + 1);
        Internet::url = new char(strlen(temp.url) + 1);
        if (name) {
            strcpy(Internet::name, temp.name);
        }
        if (url) {
            strcpy(Internet::url, temp.url);
        }
    }
    ~Internet(){
        delete[] name;
        delete[] url;
        //释放空间
    }
    Internet operator=(Internet &temp){
        delete[] name;
        delete[] url;
        this->name = new char(strlen(temp.name) + 1);
        this->url  = new char(strlen(temp.url) + 1);
        if (name) {
            strcpy(this->name, temp.name);
        }
        if (url) {
            strcpy(this->url, temp.url);
        }
        return *this;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    Internet a("Education","www.edu.com");
    Internet b=a;
    cout<<b.name<<"   "<<b.url<<endl;
    Internet c("Tsinghua","www.Wsinghua.edu.cn");
    b=c;
    cout<<b.name<<"   "<<b.url<<endl;

    
    return 0;
}
