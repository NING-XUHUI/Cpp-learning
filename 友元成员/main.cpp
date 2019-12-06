
#include<iostream>
#include <string.h>
using namespace std;

class boy;//提前声明，因为girl类中用到了boy,具体定义在后方

class girl{
private:
    char *name;
    int age;
public:
    girl(char *n,int a){
        name = new char(strlen(n)+1);
        strcpy(name, n);
        age = a;
    }
    void prt(boy &b);
    ~girl(){
        delete name;
    }
};

class boy{
private:
    char *name;
    int age;
public:
    boy(char *n,int a){
        name = new char(strlen(n)+1);
        strcpy(name, n);
        age = a;
    }
    friend void girl::prt(boy &b);
    ~boy(){
        delete name;
    }
};

void girl::prt(boy &b){
    cout<<"girl's name:"<<name<<"      age:"<<age<<endl;
    cout<<"boy's name:"<<b.name<<"     age"<<b.age<<endl;
}


int main(){
    
    girl g("lucy", 15);
    boy b("jack", 20);
    g.prt(b);
    
}


