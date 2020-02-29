#include <string>

template <class T1, class T2> struct pair {
  T1 first;
  T2 second;
  pair() : first(T1()), second(T2()) {}
  pair(const T1 &a, const T2 &b) : first(a), second(b) {}

  template <class U1, class U2>
  pair(const pair<U1, U2> &p) : first(p.first), second(p.second) {}
};

//模版特化
template <class Key> struct hash {};

template <> struct hash<char> {
  size_t operator()(char x) const { return x; }
};

template <> struct hash<int> {
  size_t operator()(int x) const { return x; }
};

template <> struct hash<long> {
  size_t operator()(int x) const { return x; }
};

//局部(偏)特化--个数
template <typename T, typename Alloc = ...> class vector {
  //...
};

template <typename Alloc = ...> class vector<bool, Alloc> {
  //...
};

//--范围
template <typename T> class C {
  //...
};

template <typename T> class C<T *> {
  //...
};

//也可这样写
/*
template <typename U>
class C<U*>
{
  //...
};
*/
//模版模版参数
template <typename T, template <typename T> class Container> class XCls {
private:
  Container<T> c;
public:
  //...
};



int main() {
  C<std::string> obj1;
  C<std::string *> obj2;

  return 0;
}
