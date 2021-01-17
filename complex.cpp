#include <iostream>
#include "complex.h"
using namespace std;

int main(int argc, char* argv[]) {
	Complex c1(1.0, 2.0);
	Complex c2(3.0, 4.0);
	c1 += c2;
	Complex c3 = c1 + c2;
	cout << c1 << endl;
	cout << c2 << endl;
	cout << c3 << endl;
	return 0;
}
