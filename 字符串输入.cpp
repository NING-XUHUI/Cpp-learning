#include<iostream>
#include <fstream>
#include <istream>
#include <string>
#include <sstream>//istringstream
using namespace std;

template<class T>
inline T fromString(const string &str){
	istringstream is(str);//创建字符串输入流
	T v;
	is>>v;
	return v;
}

int main(){

	int v1 = fromString<int>("5");
	cout<<v1<<endl;
	double v2 = fromString<double>("2.1");
	cout<<v2<<endl;



	return 0;
}