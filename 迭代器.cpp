#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
  string s("some string");
  /*
  if(s.begin() != s.end()){
    auto it = s.begin();
    *it = toupper(*it);
  }
  */
  for(auto it = s.begin();it != s.end() && !isspace(*it);it++){
    *it = toupper(*it);
  }
  cout<<s<<endl;

  constexpr size_t sz = 5;
  int arr[sz] = {1,2,3,4,5};
  int *ip = arr;
  int *ip2 = ip + 4;

  
}
