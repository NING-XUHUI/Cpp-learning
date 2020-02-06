#include<iostream>

using namespace std;

class IntNum{
public:
  IntNum(int x= 0):xptr(new int(x)){
    cout<<"Calling constructor..."<<endl;
  }

  //使用复制构造
  /*
  IntNum(const IntNum& n):xptr(new int(*n.xptr)){
    cout<<"Calling copy constructor..."<<endl;
  }
  */


  //使用移动构造

  IntNum(IntNum && n):xptr(n.xptr){
    n.xptr = nullptr;
    cout<<"Calling move constructor..."<<endl;
  }
  ~IntNum(){
    delete xptr;
    cout<<"Destructing ..."<<endl;
  }
  
  int getInt(){return *xptr;}
private:
  int *xptr;
};

IntNum getNum(){
  IntNum a;
  return a;
}


int main(){

  cout<<getNum().getInt()<<endl;
 
  return 0;
}
