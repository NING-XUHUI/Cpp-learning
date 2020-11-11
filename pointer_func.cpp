#include<iostream>

using namespace std;
/*
void splitFloat(float x,int *intPart,float *fracPart){
  *intPart = static_cast<int>(x);
  *fracPart = x - *intPart;
}

int main(){

  cout<<"Enter 3 float point numbers:"<<endl;

  for(int i =0;i<3;i++){
    float x,f;
    int n;
    cin>>x;
    splitFloat(x,&n,&f);
    cout<<"Integer Part:"<<n<<" "<<"Fraction Part"<<f<<endl;
  }
  
  return 0;
}
*/


//指向常量的指针做形参

/*
const int N = 6;
void print(const int* p,int n);

int main(){

  int array[N];
  for(int i = 0;i<N;i++){
    cin>>array[i];
    
  }
  print(array,N);

  return 0;
}

void print(const int* p,int n){
  cout<<"{"<<*p;
  for(int i = 1;i<n;i++){
    cout<<","<<*(p+i);
  }
  cout<<"}"<<endl;
}
*/

//指针类型函数
//返回类型为指针
//不要将非静态的局部地址作为函数的返回值

/*错误例子
int main(){
  int* function();
  int* ptr = function();
  *ptr = 5;//危险访问！

  return 0;
}

int* function(){
  int local = 0;
  return &local;
}//函数结束时，local被释放

*/

int* search(int* a,int num);
int main(){
  int array[10];
  for(int i = 0;i<10;i++)
    cin>>array[i];

  int* zeroptr = search(array,10);
  cout<<zeroptr<<endl;
  return 0;
}

int* search(int* a,int num){
  for(int i = 0;i<num;i++)
    if(a[i]==0)
      return &a[i];
}

