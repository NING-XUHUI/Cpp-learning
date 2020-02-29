#include <iostream>
using namespace std;

class Foo {
public:
  int _id;
  long _data;
  string _str;

public:
  Foo() : _id(0) {
    cout << "default ctor.this = " << this << "id= " << _id << endl;
  }
  Foo(int i) : _id(i) { cout << "ctor.this=" << this << "id= " << _id << endl; }

  // virtual
  ~Foo() { cout << "dtor.this=" << this << "id= " << _id << endl; }
  static void *operator new(size_t size);
  static void operator delete(void *pdead);
  static void *operator new[](size_t size);
  static void operator delete[](void *pdead);
};

void *Foo::operator new(size_t size) {
  Foo *p = (Foo *)malloc(size);
  return p;
}

void Foo::operator delete(void *pdead) { free(pdead); }

void *Foo::operator new[](size_t size) {
  Foo *p = (Foo *)malloc(size);
  return p;
}

void Foo::operator delete[](void *pdead) { free(pdead); }

int main(){

  Foo* p = new Foo(7);
  delete p;

  Foo* pArray = new Foo[5];
  delete[]pArray;

  return 0;
}
