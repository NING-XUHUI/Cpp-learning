#include<iostream>
#include<string>
using namespace std;
class STR{
	char *s;
public:
	STR(char *p=0);
	STR& operator =(STR &str);
	friend STR& operator+=(STR &str1,STR &str2);
	void print();
	~STR();
};
STR::STR(char *p){
	if(p==0)s=0;
	else{
		s=new char[strlen(p)+1];
		strcpy(s,p);
	}
}
STR& STR::operator =(STR &str){
	if(s)delete[]s;
	s=new char[strlen(str.s)+1];
	strcpy(s,str.s);
	return *this;
}
STR& operator+=(STR &str1,STR &str2){
	char *p=new char[strlen(str1.s)+strlen(str2.s)+1];
	strcpy(p,str1.s);
	strcat(p,str2.s);
	if(str1.s)delete []str1.s;
	str1.s=new char[strlen(p)+1];
	strcpy(str1.s,p);
	if(p)delete []p;
	return str1;
}
void STR::print(){
	cout<<s<<'\n';
}
STR::~STR(){if(s)delete []s;}
int main(){
	STR str1("abcd"),str2("12345"),str3;
	str1.print();
	str2.print();
	str3=str1+=str2;
	str3.print();

  return 0;
}

