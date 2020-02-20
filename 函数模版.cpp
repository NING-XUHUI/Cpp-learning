/*
函数模版定义语法:
  语法形式:
    template<模版参数表>
  函数定义
模版参数表的内容:
  类型参数：class(或 typename)标识符
  常量参数：类型说明符 标识符
  模版参数：template<参数表>class 标识符

注意：
  一个函数模版并非自动可以处理所有类型的数据
  只有能够进行函数模版中运算的类型，可以作为类型实参
  自定义的类，需要重载模版中的运算符，才能作为类型实参
 */


#include<iostream>
using namespace std;

template<typename T>//将自行推导类型
T abs(T x){
  return x < 0 ? -x : x;
}

template<class T>//定义函数模版
void outputArray(const T *array,int count){
  for(int i = 0;i < count;i++)
    cout<<array[i]<<" ";//如果数组元素是类的对象，需要该对象所属类重载了流插入运算符"<<"
  cout<<endl;
}

int main(){
  int n = -5;
  double d = -5.5;
  cout<<abs(a)<<endl;
  cout<<abs(d)<<endl;

  return 0;
} 
7
