#include<iostream>

using namespace std;

class Employee{
  char* name;
  char* address;
  char* city;
  char* code;
public:
  Employee(char* n = "",char* add = "",char* ct = "",char* cd = ""):name(n),address(add),city(ct),code(cd){}

  void display(){
    cout<<"name:"<<name<<endl;
    cout<<"address:"<<address<<endl;
    cout<<"city:"<<city<<endl;
    cout<<"code:"<<code<<endl;
  }

  void change_name(char* nm){
    name = nm;
  }
};

int main(){
  Employee e("Wang","Haidian","Beijing","100084");
  e.display();
  e.change_name("LiSan");
  e.display();
  
  return 0;
}
