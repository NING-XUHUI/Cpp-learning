#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

namespace jj02 {
using namespace std;
void test_vector(long &value) {
  cout << "test_vector...." << endl;

  vector<string> c;
  char buf[10];

  clock_t timeStart = clock();
  for (long i = 0; i < value; ++i) {
    try {
      snprintf(buf, 10, "%d", rand());
      c.push_back(string(buf));
    } catch (exception &p) {
      cout << "i = " << i << " " << p.what() << endl;
      abort();
    }
  }
  cout << "time"
       << " " << (clock() - timeStart) << endl;
  cout << "size " << c.size() << endl;
  cout << "front " << c.front() << endl;
  cout << "back " << c.back() << endl;
  cout << "data " << c.data() << endl;
  cout << "capocity " << c.capacity() << endl;
}
} // namespace jj02

int main(int argc, char *argv[]) {
  long number = 1000000;
  jj02::test_vector(number);

  return 0;
}
