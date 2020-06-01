#include<iostream>
#include<thread>

void some_function();
void some_other_function();

int main(){

  std::thread t1(some_function);//启动新线程与t1关联
  std::thread t2 = std::move(t1);//t2构建完成所有权被转移给t2
  t1 = std::thread(some_other_function);//启动新线程并与临时对象相关联，所有权转移至t1
  std::thread t3;//默认构造
  t3 = std::move(t2);//所有权转移到t3
  t1 = std::move(t3);//所有权转回给t1

  return 0;
}
