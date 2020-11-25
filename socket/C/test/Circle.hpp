#ifndef __CIRCLE_HPP__
#define __CIRCLE_HPP__

#define PI 3.14
class Circle {
	public:
		float radius;
		Circle(float r):radius(r){}
		float Calculate();
};

#endif
