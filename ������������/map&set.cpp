#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
using namespace std;

int main() {

  map<string, size_t> word_count;
  set<string> exclude = {"The", "But", "And", "Or", "An", "A",
                         "the", "but", "and", "or", "an", "a"};
  string word;
  while (cin >> word) {
    if (exclude.find(word) == exclude.end()) {
      ++word_count[word];
    }
  }
  for (const auto &w : word_count)
    cout << w.first << " occurs " << w.second
         << ((w.second > 1) ? "times" : "time") << endl;

  auto map_it = word_count.begin();
  cout << map_it->first;
  cout << " " << map_it->second;
  ++map_it->second; // set中只能改变元素值，不能改变关键字值

  set<int> iset = {-1, 1, 2, 3, 4, 5, 6, 7, 8};
  set<int>::iterator set_it = iset.begin();
  if (set_it != iset.end()) {
    // 1*set_it = 42;//错误
    cout << *set_it << endl;
  }

  return 0;
}
