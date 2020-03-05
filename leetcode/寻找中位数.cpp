/*
设计一个数据结构，该数据结构动态维护一组数据，且支持如下操作：
1.添加元素，将整型添加至数据结构中
2.返回数据的中位数，返回器维护的数据的中位数
中位数定义：
1.若数据个数为奇数，中位数是该组数排序后的中间的数
2.若数据个数为偶数，中位数是改组数据排序后中间两个数字的平均值
*/

#include<queue>
#include<stdio.h>

class Data{
private:
  std::priority_queue<double,std::vector<double>,std::less<double>> big_heap;
  std::priority_queue<double,std::vector<double>,std::greater<double>> small_heap;
public:
  void addNum(int num){
    if(big_heap.empty()){
      big_heap.push(num);
      return;
    }
    if(big_heap.size() == small_heap.size()){
      if(num < big_heap.top()){
        big_heap.push(num);
      }
      else{
        small_heap.push(num);
      }
    }
    else if(big_heap.size() > small_heap.size()){
      if(num > big_heap.top()){
        small_heap.push(num);
        return;
      }else{
        small_heap.push(big_heap.top());
        big_heap.pop();
        big_heap.push(num);
        return;
      }
    }
    else if(big_heap.size() < small_heap.size()){
      if(num < small_heap.top()){
        big_heap.push(num);
        return;
      }else{
        big_heap.push(small_heap.top());
        small_heap.pop();
        small_heap.push(num);
        return;
      }
    }
  }
  double getMeddian(){
    if(big_heap.size() == small_heap.size()){
      return (big_heap.top() + small_heap.top())/2;
    }else if(big_heap.size() > small_heap.size()){
      return big_heap.top();
    }
    return small_heap.top();
  }
};

int main(){
  Data d;
  //  d.addNum(3);
  d.addNum(4);
  d.addNum(5);
  d.addNum(6);

  printf("%f",d.getMeddian());

  return 0;
}
