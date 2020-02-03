//使用联合体保存成绩信息，并且输出

#include <iostream>
#include <string>
using namespace std;

class ExamInfo{
private:
  string name;
  enum {GRADE,PASS,PECENTAGE} mode;
  union {
    char grade;
    bool pass;
    int percent;
  };
public:
  ExamInfo(string name,char grade):name(name),mode(GRADE),grade(grade){}

  ExamInfo(string name,bool pass):name(name),mode(PASS),pass(pass){}

  ExamInfo(string name,int percent):name(name),mode(PECENTAGE),percent(percent){}

  void show();
  
};

void ExamInfo::show(){
  cout<<name<<":";
  switch(mode){
  case GRADE :
    cout<<grade;
    break;
  case PASS:
    cout<<(pass ? "PASS":"FAILED");
    break;
  case PECENTAGE:
    cout<<percent;
    break;
  }
  cout<<endl;
}

  

int main(){
  
  ExamInfo course1("English",'B');

  ExamInfo course2("Calculus",true);

  ExamInfo course3("C++Programming",85);

  course1.show();
  course2.show();
  course3.show();
  
  
    
  return 0;
}
