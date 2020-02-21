/*统计一句话中每个字母出现的次数*/
#include<iostream>
#include<map>
#include<cctype>
using namespace std;
int main(){

  map<char,int>s;
  char c;
  do{
    cin>>c;
    if(isalpha(c)){//判断是否为字母
      c = tolower(c);//转换小写
      s[c]++;//该字母的出现频率加一
    }
  }while(c!='.');//碰到"."结束输入
  for(map<char,int>::iterator iter = s.begin();iter != s.end();++iter)
    cout<<iter->first<<" "<<iter->second<<" ";
  cout<<endl;

  return 0;
} 
