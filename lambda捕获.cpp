#include <iostream>
#include <string>
#include <functional>
#include <vector>
using namespace std;

void fcn1() {
  size_t v1 = 42;
  auto f = [v1] { return v1; };
  v1 = 0;
  auto j = f(); // j=42，f保存了我们创建他时的v1拷贝
}

void fcn2() {
  size_t v1 = 42;
  auto f = [&v1] { return v1; };
  v1 = 0;
  auto j = f(); // j为0，f保存v1的引用，而非拷贝
}

bool check_size(const string &s, string::size_type sz) {
  return s.size() >= sz;
}

int main() {
  auto check6 = bind(check_size,placeholders::_1,6);

  string s = "hello";
  bool b1 = check6(s);

  if(b1){
    cout<<"yes"<<endl;
  }else{
    cout<<"no"<<endl;
  }
  vector<string> words{"new","old","happy","sad"};
  auto wc = find_if(words.begin(),words.end(),
                    bind(check_size,placeholders::_1,6));



  return 0;
}
