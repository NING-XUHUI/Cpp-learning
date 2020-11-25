/*************************************************************************
    > File Name: main.cpp
    > Author: Leoning
    > Mail: 1998ok4nxh@gmail.com 
    > Created Time: 2020年11月20日 星期五 14时13分29秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include"Cube.hpp"
#include"Circle.hpp"
using namespace std;

int main() {
	Cube cube(2.5);
	Circle circle(1.1);
	Cube cube1 = new Cube(1,1);	
	cout << "Cube :" << cube.Calculate() << endl;
	cout << "Circle :" << circle.Calculate() << endl;
	delete cube1;
	return 0;
}
