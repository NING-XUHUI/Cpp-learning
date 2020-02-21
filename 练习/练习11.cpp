#include<iostream.h>
#include<string.h>
class String_Integer{
	char *s;
public:
	String_Integer(char *str)
	{
		s=new char[strlen(str)+1];
		strcpy(s,str);
	}
	operator int()//重载
	{
		int num=0;
		for(char *p=s;*p;p++)
			if(*p>='0'&&*p<='9')
				num=num*10+*p-'0';
		return num;
	}
	void show()
	{
		cout<<"字符串为："<<s<<endl;
	}
	~String_Integer()
	{
		delete []s;
	}
};
void main()
{
	char str[50];
	cout<<"请输入字符串ab12  3c00d45ef ：";
	cin.getline(str,50);
	String_Integer test(str);
	test.show();
	int n=test;
	cout<<"转换得到的整数为："<<n<<endl;
}
