#include <iostream>

class Foo1{
	public:
		Foo1(int x):_x(x){}
		int getX() {
			return _x;
		}
	private:
		int _x;
};

class Foo2{
	public:
		Foo2(const Foo1& f) :f1(f) {}
		void p() {
			std::cout << f1.getX() << std::endl;
		}
	private:
		Foo1 f1;
};

class Foo3 : Foo1 {
	public:
		Foo3(int x, int y): Foo1(x), _y(y){}
	private:
		int _y;

};

int main(int argc, char* argv[]) {
	Foo1 f1(3);
	Foo2 f2(f1);
	f2.p();

	return 0;
}

