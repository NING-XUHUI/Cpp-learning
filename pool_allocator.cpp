#include<iostream>
#include<pool_alloc>
using namespace std;

template<typename Alloc>
void cookie_test(Alloc alloc,size_t n){
  typename Alloc::value_type *p1,*p2,*p3;
  p1 = alloc.allocate(n);
  p2 = alloc.allocate(n);
  p3 = alloc.allocate(n);

  cout<<"p1 "<<p1<<" p2 "<<p2<<" p3 "<<p3<<endl;

  alloc.deallocate(p1,sizeof(typename Alloc::value_type));
  alloc.deallocate(p2,sizeof(typename Alloc::value_type));
  alloc.deallocate(p3,sizeof(typename Alloc::value_type));
}

int main(){

  cookie_test(__gnu_cxx::__pool_alloc<double>(),1);

  return 0;
}
