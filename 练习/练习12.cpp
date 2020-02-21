#include<iostream>
using namespace std;

class SET{
private:
	int *a;
	int len;
public:
	SET(int *p,int n);
	int operator == (int m);//重载函数，判断m是否属于当前对象所属的集合
	friend int operator == (SET &s1,SET &s2);//判断s1和s2所属的集合是否相同
	void print();///输出集合
	~SET();//释放动态内存
};

SET::SET(int *p,int n){
	a = new int[n];
	len = n;
	for (int i = 0; i < len; ++i)
	{
		a[i] = p[i];
	}
}

int SET::operator == (int m){
	for (int i = 0; i < len; ++i)
	{
		if (a[i] == m)
		{
			return 1;
		}
	}
	return 0;
}

void SET::print(){
	for (int i = 0; i < len; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

SET::~SET(){
	if (a)
		delete[]a;
}

int operator == (SET &s1,SET &s2){
	if (s1.len == s2.len)
	{
		for (int i = 0; i < s1.len; ++i)
		{
			if (s1.a[i] == s2.a[i])
			{
				continue;
			}else
				return 0;
		}
		return 1;
	}
	else
		return 0;
}

int main(int argc, char const *argv[])
{
	int a[]={1,2,3,4,5},b[]={1,2,3,4,5},c[]={1,2,3,4,5,6},d[]={1,3,5,7,9};
	SET s1(a,5),s2(b,5),s3(c,6),s4(d,5);
	cout<<"a:\t";s1.print();
	cout<<"b:\t";s2.print();
	cout<<"c:\t";s3.print();
	cout<<"d:\t";s4.print();
	if(s1==s2)cout<<"a==b\n";
	else cout<<"a!=b\n";
	if(s1==s3)cout<<"a==c\n";
	else cout<<"a!=c\n";
	if(s1==s4)cout<<"a==d\n";
	else cout<<"a!=d\n";





	return 0;
}