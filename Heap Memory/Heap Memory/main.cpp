#include <iostream>
using  namespace std;
int main() {
    int *numPtr = new int;

    cout<<"numPtr:"<<*numPtr<<endl;
    cout<<"numPtr:"<<numPtr<<endl;
    cout<<"&numPtr:"<<&numPtr<<endl;

    *numPtr = 42;
    cout<<"numPtr:"<<*numPtr<<endl;
    cout<<"numPtr:"<<numPtr<<endl;
    cout<<"&numPtr:"<<&numPtr<<endl;

    *numPtr = 54;
    cout<<"numPtr:"<<*numPtr<<endl;
    cout<<"numPtr:"<<numPtr<<endl;
    cout<<"&numPtr:"<<&numPtr<<endl;

    delete numPtr;
    cout<<"numPtr:"<<*numPtr<<endl;
    return 0;
}
