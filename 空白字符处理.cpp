#include<iostream>
#include<string>

using namespace std;

int main(){

	string word,line;
	cout<<"choose the way you read string:1.by word  2.by line"<<endl;

	char ch;
	cin>>ch;
	if (ch == '1')
	{
		cout<<"enter the string : Welcome to C++ family !"<<endl;
		cin>>word;
		cout<<"the valid string are :"<<endl;
		cout<<word<<endl;

		return 0;
	}
	//清空输入缓冲区
	cin.clear();
	cin.sync();
	if (ch == '2')
	{
		cout<<"enter the string : Welcome to C++ family !"<<endl;
		getline(cin,line);
		cout<<"the valid string are :"<<endl;
		cout<<line<<endl;

		return 0;
	}
	cout<<"invalid input !"<<endl;

	return -1;
}