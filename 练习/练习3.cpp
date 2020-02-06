/*
  由一个已知的一位数组派生出另一个一位数组，规则如下：新数组的每一个元素等于原是数组的对应位置元素及其相邻元素的平均值。其中第0个元素的左邻元素约定为最后一个元素，最后一个元素的右邻元素约定为第0个元素。
*/

#include<iostream>

using namespace std;

class ARRAY{
private:
  float a[10],b[10];
public:
  ARRAY(float t[10]){
    for(int i = 0;i<10;i++)
      a[i] = t[i];
  }
  void process();
  void print();
};

void ARRAY::process(){
  b[0] = (a[9]+a[0]+a[1])/3;
  b[9] = (a[8]+a[9]+a[0])/3;
  for(int i = 1;i<9;i++){
    b[i] = (a[i-1]+a[i]+a[i+1])/3;
  }
}

void ARRAY::print(){
  for(int i = 0;i<10;i++)
    cout<<a[i]<<" ";


  cout<<endl;
  for(int j = 0;j<10;j++)
    cout<<b[j]<<" ";
}



int main(){

  float t[10] = {0,3,6,9,12,15,18,21,24,27};

  ARRAY demo(t);

  demo.process();

  demo.print();
  

  return 0;
}
