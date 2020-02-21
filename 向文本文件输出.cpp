/*操纵符(manipulator)
插入运算符与操作符一起工作
  控制输出格式
很多操纵符都定义在
  ios_base类中(如hex())、<iomanip>头文件(如setprecision())。
控制输出宽度
  在流中房屋setw操纵符或调用width成员函数为每个项指定输出宽度。
setw和width仅影响紧随其后的输出项，但其他格式操纵符保持有效直到发生改变
dec、oct和hex操纵符设置输入和输出的默认进制
 */

/*setiosflags操纵符
  在这个程序中，通过使用带参数的setiosflags操纵符设置左对齐，setiosflags定义在iomanip
  参数ios_base::left是ios_base的静态常量。因此引用是必须包括前缀。
  这里需要用resetiosflags操纵符关闭左对齐标志。setiosflags不同于width和setw，他的影响是持久的，直到用re重新恢复默认值为止。
  setiosflags的参数是该流的格式标志值，可用按位或（｜）运算符进行组合
 */

/*精度
 如果不指定fixed或scientfic，精度值表示有效数字位数。
 如果设置ios::base::fixed或ios_base::scientific精度值表示小数点之后的位数*/
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int main(){
  double value[] = {1.23,35.36,653.7,4358.24};
  string names[] = {"Zoot","Jimmy","AI","Stan"};
  //cout<<setiosflags(ios_base::fixed);//指定以定点方式输出
  cout<<setiosflags(ios_base::scientific);//以科学计数输出
  for(int i = 0;i<4;i++)
    cout<<setiosflags(ios_base::left)//左对齐
        <<setw(6)<<names[i]
        <<resetiosflags(ios_base::left)//取消左对齐
        <<setw(10)<<setprecision(1)<<valuep[i]<<endl;
  return 0;
}
