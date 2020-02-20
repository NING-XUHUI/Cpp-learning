/*
类模版声明
 类模版
 template<模版参数表>
 class 类名
 {类成员声明}

如果需要在类模版以外定义其成员函数，则要采用以下形式：
  template<模版参数表>
  类型名 类名<模版参数标识符列表>::函数名(参数表)
 */



#include<iostream>
#include<cstdlib>
using namespace std;

struct Student{
  int id;
  float gpa;
};

template <class T>
class Store{
private:
  T item;//item用于存放任意类型的数据
  bool haveValue;//haveValue标记item是否被存入数据
public:
  Store();
  T& getElem();//提取
  void putElem(const T &x);//存入
};

template<class T>
Store<T>::Store():haveValue(false){}

template<class T>
T& Store<T>::getElem(){
  if(!haveValue){
    cout<<"No item present!"<<endl;
    exit(1);
  }
  return item;
}

template<class T>
void Store<T>::putElem(const T &x){
  //将haveValue置为true，表示item中已存入数值
  haveValue = true;
  item = x;
}

int main(){

  Store<T> s1,s2;
  s1.putElem(3);
  s2.putElem(-7);

  Student g = {1000,23};
  Store<Student> s3;
  s3.putElem(g);

  Store<double> d;
  cout<<"Retrievinf object D...";
  cout<<d.getElem()<<endl;
  //d未进行初始化，执行上面函数时导致程序终止

  return 0;
} 
