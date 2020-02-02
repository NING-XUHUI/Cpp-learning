#include<iostream>

using namespace std;

int addTwoNum(int x = 5,int y = 6){
  return x + y;
}

int main(){
  addTwoNum(10,20);//10+20
  addTwoNum(10);//10+6
  addTwoNum();//5+6
  
  return 0;
}

/*默认参数值的说明次序
 *1.有默认参数的形参必须列在形参列表的最右
 *2.调用时实参和形参的结合次序是从左向右
 *例如：
 *int addtwonum(int x,int y = 5,int z = 6);正确
 *int addtwonum(int x = 1,int y = 5,int z);错误
 *int add(int x = 1,int y,int z- 6);错误
 */
