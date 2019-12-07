//
//  main.cpp
//  纯虚函数
//
//  Created by 宁旭晖 on 2019/12/7.
//  Copyright © 2019 宁旭晖. All rights reserved.
//

#include <iostream>
using namespace std;

class point{
protected:
    int x0,y0;
public:
    point(int i=0,int j=0){
        x0 = i;
        y0 = j;
    }
    virtual void set() = 0;
    virtual void draw() = 0;
};
class line:public point{
protected:
    int x1,y1;
public:
    line(int i=0,int j=0,int m=0,int n=0):point(i,j){
        x1 = m;
        y1 = n;
    }
    void set(){
        cout<<"line::set()called.\n"<<endl;
    }
    void draw(){
        cout<<"line::draw()called.\n"<<endl;
    }
};

class ellipse: public point{
protected:
    int x2,y2;
public:
    ellipse(int i=0,int j=0,int p=0,int q=0):point(i,j){
        x2 = p;
        y2 = q;
    }
    void set(){
         cout<<"ellipse::set()called.\n"<<endl;
    }
    void draw(){
        cout<<"ellipse::draw()called.\n"<<endl;
    }
};


void drwaobj(point *p){
    p->draw();
}

void setobj(point *p){
    p->set();
}


int main(int argc, const char * argv[]) {
    // insert code here...

    line *lineobj = new line;
    ellipse *elli = new ellipse;
    drwaobj(lineobj);
    drwaobj(elli);
    
    cout<<endl;
    
    setobj(lineobj);
    setobj(elli);
    
    cout<<"redraw"<<endl;
    drwaobj(lineobj);
    drwaobj(elli);
    
    
    
    return 0;
}
