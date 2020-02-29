/*
声明一个整型数组，使用C++标准模版库中的查找算法find进行数据的查找，然后应用排序算法sort，并配合使用标准函数对象greater<T>对数据进行升序和降序排序
*/

#include<iostream>
#include<algorithm>
#include<functional>

using namespace std;
int main(){
  int a[8] = {3,2,5,6,4,1,9,8};
  cout<<"元素9的索引是:"<<find(a,a+8,9) - a<<endl;//减a是为了得到相对位置
  cout<<"升序排序:"<<endl;
  sort(a,a+8);
  for(int i = 0;i<8;i++)
    cout<<a[i]<<" ";
  cout<<endl;
  cout<<"降序排列:"<<endl;
  sort(a,a+8,greater<int>());
  for(int i = 0;i<8;i++)
    cout<<a[i]<<" ";

  cout<<endl;
      
  return 0;
}
