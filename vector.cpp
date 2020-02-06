#include<iostream>
#include<vector>

using namespace std;

double average(const vector<double>&n){
  double sum = 0;
  for(unsigned i = 0;i<n.size();i++)
    sum += n[i];

  return sum/n.size();
}

int main(){
  unsigned n;
  cout<<"n = "<<endl;
  cin>>n;

  vector<double>arr(n);
  cout<<"Please input "<<n<<"real numbers:"<<endl;

  for(unsigned i = 0;i<n;i++){
    cin>>arr[i];
  }
  cout<<"Average = "<<average(arr);
  
  return 0;
}
