/*
设计评选优秀教师和优秀学生候选人的程序。如果学生的分数大于90，则可评为优秀学生；如果教师发表的论文数大于3，则可以评委优秀教师。
*/

#include<iostream>
#include<string>
class Test{
pravite:
  string name;
  enum {STUDENT,TEACHER}mode;
  union{
    char grade;
    int numberOfPaper;
  };
public:
  Test(string name,char grade):name(name),mode(STUDENT),grade(grade){}
  Test(string name,int numberOfPaper):name(name),mode(TEACHER),numberOfPaper(numberOfPaper){}
  void show();
  int ifGood();
};

int Test::ifGood(){
  switch(mode){
  case STUDENT:
    if(grade>90)
      return 1;
    else
      return 0;
    break;
  case TEACHER:
    if(numberOfPaper>3)
      return 1;
    else
      return 0;
    break;
  }
}

void Test::show(){
  cout<<name<<":";
  if(this->ifGood)
    cout<<"可以评优";
  else
    cout<<"不能评优";
}

using namespace std;

int main(){
  Test

  return 0;
}
