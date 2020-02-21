#include<iterator>
#include<iostream>
#include<list>
#include<string>
using namespace std;

int main(){

  string word1 = "apple";
  string word2 = "pear";

  char* w1 = &word1;
  char* w2 = &word2;

  list<char>l1(*w1,*(w1+5));
  list<char>l2(*w2,*(w2+4));




  return 0;
}
