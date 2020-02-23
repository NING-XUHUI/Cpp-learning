#include<iostream>
#include<string>
using namespace std;
int main(){

  char ch;
  while((ch=cin.get())!=EOF)//EOF文件结束符C-d
    cout.put(ch);
  /*******************************************/
  string line;
  cout<<"Type a line terminated by 't'"<<endl;
  getline(cin,line,'t');
  cout<<line<<endl;

  return 0;
} 
