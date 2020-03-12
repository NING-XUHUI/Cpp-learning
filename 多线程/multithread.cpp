#include <iostream>
#include <string>
#include <thread>
void function_1() { std::cout << "www.oxox.work" << std::endl; }

class Fctor {
public:
  void operator()(std::string& msg) {
    for (int i = 0; i > -100; i--)
      std::cout << "from t1:" << i <<
        msg<<std::endl;
    msg = " DA SHA BI";
  }
};

int main() {
  // Fctor fct;

  std::string s = "sha bi";
  std::thread t1((Fctor()),s);

  
  try {
    for (int i = 0; i < 100; i++) {
      std::cout << "from main:" << i << std::endl;
    }
  } catch (...) {
    t1.join();
    throw;
  }

  t1.join();

  return 0;
}
