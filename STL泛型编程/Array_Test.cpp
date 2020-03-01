#include<array>
#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

void test_array(){
  cout<<"test_array()....."<<endl;

  const long ASIZE = 50000;
  array<long,ASIZE> c;

  clock_t timeStart = clock();
  for(long i = 0;i <ASIZE;++i){
    c[i] = rand();
  }

  cout<<"milli-seconds:"<<(clock() - timeStart)<<endl;
  cout<<"array,size()="<<c.size()<<endl;
  cout<<"array.front()="<<c.front()<<endl;
  cout<<"array.back()="<<c.back()<<endl;
  cout<<"array.data()="<<c.data()<<endl;

  long target = get_a_target_long();
  timeStart = clock();
  qsort(c.data(),ASIZE,sizeof(long),compareLongs);

  long* pItem = (long*)bsearch(&target,(c.data()),ASIZE,sizeof(long),compareLongs);
}
