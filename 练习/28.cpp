#include <iostream>
#include <string>
using namespace std;
class strin{
protected:
	int Length;
	char *sp;
public:
	strin(){sp=0;Length=0;}
	strin(const strin &);
	strin(const char *s)
	{
		Length=strlen(s);
		sp=new char[Length+1];
		strcpy(sp,s);
	}
	~strin(){if(sp)delete []sp;}

	void show()
	{cout<<sp<<'\n';}

  strin operator =(strin &);
  strin operator +(strin &);
};
strin::strin(const strin &s)
{
	Length=s.Length;
	if(s.sp){
		sp=new char[Length+1];
		strcpy(sp,s.sp);
	}
	else sp=0;
}


strin strin::operator +(strin &s)
{
	strin t;
	t.Length=Length+s.Length;
	t.sp=new char[t.Length+1];
	strcpy(t.sp,sp);
	strcat(t.sp,s.sp);
	Length=t.Length;
	return t;
}

strin strin::operator =(strin &s)
{
	if(sp)delete []sp;
	Length=s.Length;
	if(s.sp)
    {
      sp=new char[Length+1];
      strcpy(sp,s.sp);
		}
  else
    sp=0;
  return *this;
}

int  main()
{
	strin s1("C++程序设计"),s2,s3("学生学习");
	strin s;
	s1.show();
	s2=s1;
	s2.show();
  strin S(s1 + s3);
  s = S;
  s.show();
  return 0;
}
