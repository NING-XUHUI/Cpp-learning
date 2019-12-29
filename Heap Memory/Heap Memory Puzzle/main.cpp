#include <iostream>

using  namespace std;
int *all(){
    int i = 1;
    return &i;
}

void love_you(){
    cout<<"1"<<endl;
}
int main() {
    bool I_am_alive = true;
//    int i = 2, j = 4, k = 8;
//    int *p = &i, *q = &j, *r = &k;
//
//    k = i;
//    cout<<i<<j<<k<<*p<<*q<<*r<<endl;
//
//    p = q;
//    cout<<i<<j<<k<<*p<<*q<<*r<<endl;
//
//    *q = *r;
//    cout<<i<<j<<k<<*p<<*q<<*r<<endl;

//    int *x = new int;
//    int &y = *x;
//    y = 4;

//    cout<<&x<<endl;
//    cout<<x<<endl;
//    cout<<*x<<endl;
//
//    cout<<&y<<endl;
//    cout<<y<<endl;
//    cout<<*y<<endl;

//    int *p,*q;
//    p = new int;
//    q = p;
//    *q = 8;
//    cout<<*p<<endl;
//
//    q = new int;
//    *q = 9;
//    cout<<*p<<endl;
//    cout<<*q<<endl;




while(I_am_alive){
    love_you();
}


















//    int *x;
//    int size = 3;
//    x = new int[size];
//
//    for (int i = 0; i < size ; ++i) {
//        x[i] = i + 3;
//    }
//
//    delete [] x;
//
//    int y = 2;
//    float  z = 3.5;
//    cout<<y + z<<endl;
//    int a = z + y;
//    cout<<a<<endl;

    int *i = new int;
    *i = 0;
    int &j = *i;
    j++;


    return 0;
}
