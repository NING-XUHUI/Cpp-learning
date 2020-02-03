#include <iostream>

using namespace std;

enum class Side{Right,Left};

enum class Thing{Wrong,Right};

int main(){

  Side s = Side::Right;

  Thing w = Thing::Right;

  cout<<(s == w)<<endl;//编译错误，不能直接比较不同枚举类
  
  return 0;
}
