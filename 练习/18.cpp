#include <iostream>
#include <string>
using namespace std;

class Modistr {
private:
  char *str;

public:
  Modistr(char *s);
  void print();
  void Modify(char *wordp);
  ~Modistr();
};

Modistr::Modistr(char *s) {
  str = new char[strlen(s) + 1];
  strcpy(str, s);
}
void Modistr::print(){
  cout<<str<<endl;
}

void Modistr::Modify(char *wordp) {
  char p1[100], p2[20];
  strcpy(p1, str);
  strcpy(p2, wordp);
  int i = 0, n;
  for (; p1[i++];) {
    for (int j = i, k = 0; p1[j] == p2[k] && p2[k] != '\0'; k++, j++)
    if (p2[k] == '\0') {
      n = j;
      while (p1[n++])
      for (int m = n;m >= j; m--)
        p1[m + 1] = p1[m];
      p1[j] = 's';
      i = j;
    }
  }
  str = new char[i];
  strcpy(str, p1);
}
Modistr::~Modistr() { delete[] str; }

int main() {
  char *s = "We are student  ,you are student  ,too.";
  char *p = "student";
  Modistr mys(s);
  mys.print();
  mys.Modify(p);
  mys.print();

  return 0;
}
