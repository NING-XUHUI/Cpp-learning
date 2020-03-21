#include<iostream>
using namespace std;

class aallocator{
private:
  struct obj{
    struct obj* next;//embedded pointer
  };
public:
  void* allocate(size_t);
  void deallocate(void*,size_t);
private:
  obj* freeStore = nullptr;
  const int CHUNK = 5;
};

void* aallocator::allocate(size_t size){
  obj* p;
  if(!freeStore){
    size_t chunk = CHUNK * size;
    freeStore = p = (obj*)malloc(chunk);

    for(int i = 0;i<(CHUNK - 1);++i){
      p->next = (obj*)((char*)p + size);
      p = p->next;
    }
    p->next = nullptr;
  }
  p = freeStore;
  freeStore = freeStore->next;
  return p;
}

void aallocator::deallocate(void* p,size_t){
  ((obj*)p)->next = freeStore;
  freeStore = (obj*)p;
}

class Foo{
public:
  long L;
  string str;
  static aallocator myAlloc;
public:
  Foo(long l):L(l){ }
  static void* operator new(size_t size){ return myAlloc.allocate(size);}
  static void operator delete(void* pdead,size_t size){
    return myAlloc.deallocate(pdead,size);
  }
};

aallocator Foo::myAlloc;

int main(){
  Foo* p[100];

  cout<<"sizeof(Foo):"<<sizeof(Foo)<<endl;
  for(int i = 0;i < 23;i++){
    p[i] = new Foo(i);
    cout<<p[i]<<' '<<p[i]->L<<endl;
  }

  for(int i = 0;i < 23;i++){
    delete p[i];
  }

  return 0;
}

