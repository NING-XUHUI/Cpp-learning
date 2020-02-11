#include<iostream>
#include<map>
using namespace std;

int main(){
  int num;
  cin>>num;
  unordered_map<int,int> result;
  for(int i = 0;i < num/2 ; i++){
    for(int j = 0;j < num/2;j++)
      if(i*i + j*j == num)
	if(result.find(j)){
	  continue;
	}
	result[i] = j;
	cout<<i<<" "<<j<<endl;
  }
  cout<<"No Solution";
  
  return 0;
}
