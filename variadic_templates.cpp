#include <iostream>
//数量不定的模版参数
void print() {}

template <typename T, typename... Types>
//                   first                   pack
void print(const T &firstArg, const Types &... args) {
  std::cout << firstArg << std::endl;
  print(args...);
}

int main() {

  print(7.5, "hello", std::bitset<16>(337), 42);

  return 0;
}
