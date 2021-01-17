#ifndef __COMPLEX__
#define __COMPLEX__
#include <iostream>
using namespace std;
class Complex {
	public:
		Complex(double r, double i)
			:re(r), im(i) {}

		inline Complex&
			__doapl(Complex* ths, const Complex& r) {
				ths->re += r.getRe();
				ths->im += r.getIm();

				return *ths;
			}

		inline Complex&
			operator += (const Complex& r) {
				return __doapl(this, r);
			}

		inline Complex
			operator + (Complex& r) {
				return Complex(this->re + r.getRe(),
							   this->im + r.getIm());
			}

		double getRe () const {
			return this->re;
		}

		double getIm() const {
			return this->im;
		}

		friend
		ostream& operator << (ostream& os, const Complex& x);

	private:
		double re;
		double im;
};

ostream&
operator << (ostream& os, const Complex& x) {
	return os << '(' << x.re << ',' << x.im << ')';
}

#endif
