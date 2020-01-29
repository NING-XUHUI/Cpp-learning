/*
 *用递归法计算从n个人中选选k个人组成一个委员会的不同组合数
 */


#include<iostream>

using namespace std;

int comm(int n,int k){
K if(k > n)
    return 0;
  else if(n == k || k == 0)
    return 1;
  else 
    return comm(n - 1,k) + comm(n - 1,k - 1);
}



int int main(int argc, char const *argv[]) {

  int n,k;
  cout<<"Enter two integers n & k :"<<endl;
  cin>>n>>k;
  cout<<"C(n,k) = "<<comm(n,k)<<endl;

  return 0;
}
