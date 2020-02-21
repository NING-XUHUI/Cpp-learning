/*
绑定适配器:bind1st bind2nd
  将n元函数对象的直到参数绑定为一个常数，得到n-1元函数对象

组合适配器:not1 not2
  将指定谓词取反

函数指针适配器:ptr_fun
  将一般函数指针转换为函数对象，使之能够作为其他函数适配器的输入
  在进行参数棒的或其他转换的时候，通常需要函数对象的类型信息，例如bind1st和bind2nd要求函数对象必须继承于binary_function类型，但如果传入的是函数指针形式的函数对象，则无法获得函数对象的类型信息。

成员函数适配器:ptr_fun ptr_fun_ref
  对成员函数指针使用，把n元成员函数适配为n+1函数对象，该函数对象的第一个参数为调用该成员函数时的目的对象
  也就是需要将"object->method()"转为"method(object)"形式。将"object->method(arg1)"转为二元函数"method(object,arg1)"
*/

/*查找第一个大于40的数*/

#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;

bool g(int x,int y){
  return x>y;
}

int main(){
  //绑定适配器
  int intArr[] = {30,90,10,40,70,50,20,80};
  const int N = sizeof(intArr)/sizeof(int);
  vector<int>a(intArr,intArr+N);
  vector<int>::iterator p = find_if(a.begin(),a.end(),bind2nd(greater<int>(),40));
  if(p == a.end())
    cout<<"no elements greater than 40"<<endl;
  else
    cout<<"first element greater than 40 is :"<<*p<<endl;

  //组合适配器
  vector<int>::iterator P;
  P = find_if(a.begin(),a.end(),bind2nd(ptr_fun(g),40));
  if(p == a.end())
    cout<<"no elements greater than 40"<<endl;
  else
    cout<<"first element greater than 40 is:"<<*P<<endl;

  P = find_if(a.begin(),a.end(),not1(bind2nd(greater<int>(),15)));
  if(p == a.end())
    cout<<"no element is not greater than 15"<<endl;
  else
    cout<<"first element is not greater 15 is:"<<*P<<endl;

  P = find_if(a.begin(),a.end(),bind2nd(not2(greater<int>()),15));
  if(p == a.end())
    cout<<"no element is not greater than 15"<<endl;
  else
    cout<<"first element is not greater 15 is:"<<*P<<endl;







  return 0;
} 
