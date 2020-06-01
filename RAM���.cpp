/*
拓展练习：
    声明RAM类、CDROM类。
    提示：
    1.RAM类的主要参数包括：容量、类型和主频；类型建议用枚举类型（DDR4/DDR3/DDR2...）。
    2.CD-ROM类的主要参数包括：接口类型、缓存容量、安装方式；接口类型建议用枚举类型（SATA、USB...），安装方式建议用枚举类型（external/built-in)。
*/

#include<iostream>

enum RAM_Rank{DDR4,DDR3,DDR2,DDR1};
enum CD-ROM_Type{SATA,USB};
enum CD-ROM_Install{externl,built-in};

class RAM{
private:
  RAM_Rank rank;
  int capicity;
  float main_frequncy;
public:
  RAM(RAM_Rank r,int c,float f){
    rank = r;
    capicity = c;
    main_frequncy = f;
  }
};



using namespace std;

int main(){

  return 0;
}
