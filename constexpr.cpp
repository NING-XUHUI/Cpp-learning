#include <iostream>
#include <ctime>
using namespace std;
class Circle {
	public:
	constexpr Circle(int x, int y, int radius):_x(x), _y(y), _radius(radius){}
	constexpr double getArea() const {
		return _radius * _radius * 3.1415926;
	}
	private:
		int _x;
		int _y;
		int _radius;
};

class MyCircle {
	public:
	MyCircle(int x, int y, int radius):_x(x), _y(y), _radius(radius) {}
	double getArea() const {
		return _radius * _radius * 3.1415926;
	}
	private:
		int _x;
		int _y;
		int _radius;
};

	clock_t start1 = clock();
	constexpr Circle c(0, 0, 10);
	constexpr double area = c.getArea();
	clock_t stop1 = clock();

int main() {
	clock_t start2 = clock();
	MyCircle mc(0, 0, 10);
	double marea = c.getArea();
	clock_t stop2 = clock();

	cout << (double)(start1 -stop1) / CLOCKS_PER_SEC << endl;
	cout << (double)(start2 - stop2) / CLOCKS_PER_SEC << endl;
	return 0;
}
