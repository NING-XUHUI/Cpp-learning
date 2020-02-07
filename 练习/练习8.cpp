/*
对于一个有正数和负数的数组，将其中所有小于零的元素放到所有大于零的元素前面。使用的算法是：从左有两个方向扫描数组，从左向右找到大于零的元素，从右向左找到小于零的元素，将两者交换，以此类推。知道扫描完为止。建立ARR类。
*/

#include<iostream>

using namespace std;

class ARR{
private:
  int n;
  int a[100];
public:
  ARR(int x[],int size);
  void change();
  void show();
};

ARR::ARR(int x[],int size){
  for(int i = 0;i<size;i++){
    a[i] = x[i];
  }

  n = size;
}

void ARR::change(){
  for(int i = 0,j = n - 1;i<(n/2),j>(n/2);i++,j--){
    if(a[i] > 0 && a[j] < 0){
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }
  }
}

void ARR::show(){
  for(int i = 0;i<n;i++){
    cout<<a[i]<<" ";
  }
}



int main(){
  int b[10] = {1,-3,-1,3,2,4,-4,5,-5,-2};
  ARR a(b,10);
  a.change();
  a.show();
  
  return 0;
}
