#include <iostream>
#include <string>
using namespace std;

class String {
protected:
  int Length; //字符串的长度
  char *s;    //指向字符串的指针public:
  String();
  String(String &S);
  String(const char *a);
  ~String();
  String operator+(String &);
  String &operator=(String &);
};

String::~String(){
  if(s)
    delete[]s;
}

String::String() {
  Length = 0;
  s = 0;
}
String::String(String &S) {
  Length = S.Length;
  if (S.s) {
    s = new char[Length + 1];
    strcpy(s, S.s);
  } else
    s = 0;
}

String::String(const char *a) {
  Length = strlen(a);
  s = new char[Length + 1];
  strcpy(s, a);
}

String String::operator+(String &S) {
  // strcat尾部追加
}

int main(int argc, char *argv[]) { return 0; }
