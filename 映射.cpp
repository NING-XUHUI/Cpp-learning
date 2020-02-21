/*有五门课程，每门都有相应的学分，从中选择三门，输出学分总和*/

#include<iostream>
#include<map>
#include<iterator>
#include<utility>
#include<string>
using namespace std;

int main(){
  map<string,int>courses;
  //将课程信息插入:
  courses.insert(make_pair("CSAPP",3));
  courses.insert(make_pair("C++",2));
  courses.insert(make_pair("CSARCH",4));
  courses.insert(make_pair("COMPILER",4));
  courses.insert(make_pair("OS",5));
  int n = 3;//剩下可选次数
  int sum = 0;//学分总和

  while(n > 0){
    string name;
    cin>>name;//输入课程名称
    map<string,int>::iterator iter = courses.find(name);//查找课程
    if(iter == courses.end()){//判断是否找到
      cout<<name<<"is not available"<<endl;
    }else{
      sum += iter->second;//累加学分
      courses.erase(iter);//删除映射
      n--;
    }
  }
  cout<<"Total credit:"<<sum<<endl;//输出总学分
  return 0;
}
