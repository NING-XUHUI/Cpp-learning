#include<iostream> 
using namespace std;

class A{};
class B{char m_data;};
class C{
  char m_data[100];
};
class D{
  char* m_data;
  D():m_data(new char[100]){}
  ~D(){delete[]m_data;}
};

static void testsizeof(){
  cout<<"bool sizeof "<<sizeof(bool)<<endl;//64位机器1字节
  cout<<"char sizeof "<<sizeof(char)<<endl;//默认值1字节
  cout<<"int sizeof "<<sizeof(int)<<endl;//4字节
  char data[10];
  char* pData = data;
  cout<<"char data[10] sizeof "<<sizeof(data)<<endl;//10
  cout<<"char* sizeof "<<sizeof(pData)<<endl;//8
  cout<<"A sizeof "<<sizeof(A)<<endl;//1 C++11中不允许类的size为0，会自动插入一个char
  cout<<"B sizeof "<<sizeof(B)<<endl;//1
  cout<<"C sizeof "<<sizeof(C)<<endl;//100
  cout<<"D sizeof "<<sizeof(D)<<endl;//8
  cout<<"size_t sizeof "<<sizeof(size_t)<<endl;//8
}

int main(int argc,char* argv[]){

  size_t a = 10;
  int b =-1;
  if(b<a){
    cout<<"right\n";
  }else
    cout<<"bad\n";

  testsizeof();
  return 0;
}

