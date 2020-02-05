#include<iostream>

using namespace std;

int main(){
  int a[10],*pa;
  pa = &a[0];//或pa = a;
  //等效形式：*pa就是a[0],*(pa+1)就是a[1],...,*(pa+i)就是a[i].

  int line1[] = {1,0,0};
  int line2[] = {0,1,0};
  int line3[] = {0,0,1};

  int *pline[3] = {line1,line2,line3};

  cout<<"Matrix test:"<<endl;
  //输出矩阵

  for(int i = 0;i<3;i++){
    for(int j = 0;j<3;j++)
      cout<<pline[i][j]<<" ";
    
    cout<<endl;
  }
  
  return 0;
}


