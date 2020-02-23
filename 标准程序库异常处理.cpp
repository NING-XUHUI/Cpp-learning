#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

double area(double a,double b, double c)throw(invalid_argument){
	//判断三角形边长是否为正
	if (a <= 0 || b <= 0 || c <= 0)
	{
		throw invalid_argument("the side length should be positive");
	}
	//判断三边长是否满足三角不等式
	if (a + b <= c || b + c <= a || a + c <= b)
	{
		throw invalid_argument("the side length should fit the triangle inequaticon");
	}
	//由Heron公式计算三角形的面积
	double s = (a + b + c)/2;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main(int argc, char const *argv[])
{
	double a,b,c;
	cout<<"Please input the side of a triangle:";
	cin>>a>>b>>c;
	try{
		double s = area(a,b,c);
		cout<<"Area"<<s<<endl;
	}catch(exception &e){
		cout<<"ERROR:"<<e.what()<<endl;
	}


	return 0;
}