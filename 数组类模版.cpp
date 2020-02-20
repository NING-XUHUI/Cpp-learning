/*
直接访问的线性群体——数组类

 静态数组是具有固定元素个数的群体，其中的元素可以通过下标直接访问。
 缺点：大小在编译时就已经缺点，在运行时无法修改。

 动态数组由一系列位置连续的，任意数量相同类型的元素组成。
 优点：其元素个数可在程序运行是改变。
 */


#include<iostream>
#include<iomanip>
using namespace std;

template<class T>//数组类模版定义
class Array{
private:
  T* list;//用于存放动态分配的数组内存首地址
  int size;//数组大小(元素个数)
public:
  Array(int sz = 50);//构造函数
  Array(const Array<T> &a);//复制构造 
  ~Array();//析构
  Array<T>& operator = (const Array<T> &rhs);//重载‘=’ 
  T & operator[](int n);//重载‘[]’
  const T& operator[](int n)const;//重载‘[]‘常函数,用于储存常对象
  operator T*();//重载T*类型的转换
  operator const T* ()const;
  int getSize()const;//取数组大小
  void resize(int sz);//修改数组的大小
};

template<class T>
Array<T>::Array(int sz){//构造函数
  assert(sz >= 0);//sz为数组大小（元素个数），应当为非负
  size = sz;
  list = new T[size];//动态分配size个T类型的元素空间
}

template<class T>
Array<T>::~Array(){//析构函数
  delete[]list;//释放
}

template<class T>
Array<T>::Array(const Array<T> &a){//复制构造函数,深层复制，new
  size = a.size;//从对象x取得数组大小，并赋值给当前对象的成员
  list = new T[size];//动态分配n个T类型的元素空间
  for(int i = 0;i < size;i++){//复制x中的元素到本对象
    list[i] = a.list[i];
  }
}
//重载“=”运算符，将对象rhs复制给本对象，实现对象之间的整体赋值
template<class T>
Array<T> &Array<T>::operator = (const Array<T>& rhs){
  if(&rhs != this){//避免无谓的自身赋值
    //如果本对象中数组大小与rhs不同，则删除数组原有内存，然后重新分配
    if(size != rhs.size){
      delete[]list;//删除原有内存
      size = rhs.size;//设置本对象的数组大小
      list = new T[size];//重新分配内存
    }
    //从对象x复制元素到本对象
    for(int i = 0;i < size;i++)
      list = rhs.list[i];
  }

  return *this;//返回当前对象的引用
}
//重载下标运算符，实现与普通数组一样通过下标访问元素，具有越界检查功能
template<class T>
T& Array<T>::operator [](int n){
  assert(n >= 0 && n < size);//检查下标是否越界
  return list[n];//返回下标为n的数组元素
}

template<class T>
const T& Array<T>::operator [](int n)const{
  assert(n >= 0 && a < size);
  return list[n];
}

//重载指针转换运算符，将Array类的对象名转换为T类型的指针
template<class T>
Array::operator T*(){
  return list;//返回当前对象中私有数组的首地址
}

//取当前数组的大小
template<class T>
int Array<T>::getSize()const{
  return size;
}

//修改数组大小
template<class T>
void Array<T>::resize(int sz){
  assert(sz >= 0);///检查是否为非负
  if(sz == size)
    return;
  T* newList = new T[sz];//申请新的数组内存
  int n = (sz < size)?sz : size;//将sz与size中较小的值复制给n
  //将原有数组中的前n个元素复制到新数组中
  for(int i = 0;i < n;i++)
    newList[i] = list[i];
  delete[list];//删除原数组
  list = newList;//使list指向新数组/
  size = sz;//更新size
}


int main(){

  Array<int>a(10);
  int n,count = 0;
  cout<<"Enter a value >= 2 as upper limit for prime numbers:";
  cin>>n;

  for(int i = 2;i <= n;i++){
    bool isPrime = true;
    for(int j = 0;j < count;j++)
      //若i被a[j]整除，说明i不是质数
      if(i % a[j] == 0){
        isPrime = false;break;
      }
    if(isPrime){
      if(count == a.getSize())
        a.resize(count*2);
      a[count++] = i;
    }
  }
  for(int i = 0;i < count;i++)
    cout<<setw(8)<<a[i];
  cout<<endl;
  return 0;
} 
