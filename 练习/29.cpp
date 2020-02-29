#include <iostream>
#include <map>
#include <string>
using namespace std;

class Str {
private:
  char *str;
  char *s;
  int maxlen;

public:
  Str(const char *p);
  ~Str();
  void process();
  void show() const;
};

Str::Str(const char *p) {
  str = new char[strlen(p) + 1];
  strcpy(str, p);
}

Str::~Str() {
  delete[] str;
  delete[] s;
}

void Str::process() {
  map<char, int> m;
  string ss = str;
  int max = 0;
  char ch;
  for (auto c : ss) {
    if (m.count(c) == 0) {
      m.insert(pair<char, int>(c, 1));
    } else
      m[c]++;
    if (max < m[c]) {
      max = m[c];
      ch = c;
    }
  }
  maxlen = max;
  s = new char[max + 1];
  for (int i = 0; i < max; i++)
    s[i] = ch;
}

void Str::show() const {
  cout << maxlen << endl;
  cout << str << endl;
  cout << s << endl;
}

int main(int argc, char *argv[]) {

  char *p = new char[15];
  strcpy(p, "asdzxcvsdddddd");
  Str s(p);

  s.process();
  s.show();

  delete[] p;

  return 0;
}
