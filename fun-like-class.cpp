#include <algorithm>
using namespace std;
template <class T1, class T2> struct pair {
  T1 first;
  T2 second;
  pair() : first(T1()), second(T2()) {}
  pair(const T1 &a, const T2 &b) : first(a), second(b) {}
};

template <class T> struct identity {
  const T &operator()(const T &x) const { return x; }
};

template <class Pair>
struct select1st : public unary_function<Pair, typename Pair::first_type> {
  const typename Pair::first_type &operator()(const Pair &x) const {
    return x.first;
  }
};

template <class Pair>
struct select2nd : public unary_function<Pair, typename Pair::first_type> {
  const typename Pair::second_type &operator()(const Pair &x) const {
    return x.second;
  }
};

int main(int argc, char const *argv[]) {
  int a = 1;
  int b = 2;

  return 0;
}
