#include<iostream>

using namespace std;

class ID{
private:
  char s[19],x[12];//s身份证号，x校验码{1,0,X,9,8,7,6,5,4,3,2}
  int w[17];//前17位权值{7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2}
public:
  ID(const char *str);//构造函数，给定15位旧身份证号，初始化x和w
  void fun();//将s中的15位拓展为18位
  void print();//打印完整身份证号
};


ID::ID(const char* str){
  //char temp[12] = "10X98765432";
  
  strcpy(x,"10X98765432");
  
  int t[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
  
  for(int j = 0;j<17;j++)
    w[j] = t[j];
  
  for(int i = 0;i<15;i++)
    s[i] = str[i];
}

void ID::fun(){

  for(int i = 17;i>5;i--){
    s[i] = s[i-2];
    }

  s[6] = '2';
  s[7] = '0';

  int num[17];
  for(int j = 0;j<17;j++)
    num[j] = static_cast<int>(s[j])-48;

  int sum = 0;
  for(int k = 0;k<17;k++){
    sum += num[k]*w[k];
  }

  int last = sum%11;

  s[17] = x[last];
  
    
}
void ID::print(){
  cout<<"拓展后身份证号："<<s<<endl;
}


int main(){
  const char *pre = "522423000620002";
  cout<<"原身份证号："<<pre<<endl;
  ID id(pre);
  id.fun();
  id.print();
  
  return 0;
}
