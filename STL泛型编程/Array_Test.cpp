#include<array>
#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

// 需要传入qsort的比较大小函数
int compareLongs(const void* a,const void* b)
{
    return (*(long*)a - *(long*)b);
}

// 获取一个你想要查找的long类型数据，在规定范围内
long get_a_target_long(){
    long target = 0;
    cout << "target (0~" << RAND_MAX << "):";
    cin >> target;
    return target;
}


// 容器array的出入，排序与搜索性能简单测试
void test_array(){
  srand(time(0));
  cout<<"test_array()....."<<endl;

  const long ASIZE = 50000;                             // 将要放入array的数据量
  array<long,ASIZE> c;                                  // 创建array

  clock_t timeStart = clock();          
  for(long i = 0;i <ASIZE;++i){                         // 放入随机数据
    c[i] = rand();
  }

  cout<<"milli-seconds:"<<(clock() - timeStart)<<endl;  // 放入数据所花费时间
  cout<<"array,size()="<<c.size()<<endl;                // array的size
  cout<<"array.front()="<<c.front()<<endl;              // array的第一个元素
  cout<<"array.back()="<<c.back()<<endl;                // array的最后一个元素
  cout<<"array.data()="<<c.data()<<endl;                // array的内存地址头部

  long target = get_a_target_long();                    // 获取想要查询的数据
  timeStart = clock();
  qsort(c.data(),ASIZE,sizeof(long),compareLongs);      // 使用qsort对array进行排序

  long* pItem = (long*)bsearch(&target,(c.data()),ASIZE,sizeof(long),compareLongs); // 使用bsearch进行搜索查找
  cout << "qsort() + bsearch(),milli-seconds:" << (clock() - timeStart) << endl;    // 排序以及搜索共花费的时间
  if(pItem != NULL){
      cout << "found!" << *pItem << endl;
  }else{
      cout << "not found!" << endl;
  }
}

int main(){
    test_array();

    return 0;
}
