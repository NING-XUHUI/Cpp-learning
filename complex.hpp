#ifndef _COMPLEX_
#define _COMPLEX_

#include <iostream>
class complex {
public:
  complex(double r = 0, double i = 0) : re(r), im(i) {}
  complex &operator+=(const complex &);
  double real() const { return this->re; }
  double imag() const { return this->im; }

private:
  double re, im;

  friend complex &_doap1(complex *, const complex &);
};

complex &_doap1(complex *ths, const complex &r) {
  ths->re += r.re;
  ths->im += r.im;
  return *ths;
}

inline complex &complex::operator+=(const complex &r) {
  return _doap1(this, r);
}

inline complex operator+(const complex &x, const complex &y) {
  return complex(x.real() + y.real(), x.imag() + y.imag());
}

inline complex operator+(const complex &x, double y) {
  return complex(x.real() + y, x.imag());
}

inline complex operator+(double x, const complex &y) {
  return complex(x + y.real(), y.imag());
}

std::ostream &operator<<(std::ostream &os, const complex &x) {
  os << '(' << x.real() << ',' << x.imag() << "i" << ')';
  return os;
}

#endif
