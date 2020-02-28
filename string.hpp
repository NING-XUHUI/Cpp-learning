#ifndef _STRING_
#define _STRING_
#include <iostream>
#include <string>

// class with pointer member
class String {
public:
  String(const char *cstr = 0);
  String(const String &str);
  String &operator=(const String &str);
  ~String();

  //供类外函数调用
  char *get_c_str() const { return m_data; }
private:
  char *m_data;
};

 inline String::String(const char *cstr) {
  if (cstr) {
    m_data = new char[strlen(cstr) + 1];
    strcpy(m_data, cstr);
  } else {
    m_data = new char[1];
    *m_data = '\0';
  }
}

String::~String() { delete[] m_data; }

String &String::operator=(const String &str) {
  if (this == &str) {
    return *this;
  }
  delete[] m_data;
  m_data = new char[strlen(str.m_data) + 1];
  strcpy(m_data, str.m_data);
  return *this;
}

inline String::String(const String &str) {
  m_data = new char[strlen(str.m_data) + 1];
  strcpy(m_data, str.m_data);
}

#endif
