#include<iostream>

class Fraction{
public:
	explicit Fraction(int num,int den = 1):m_numerator(num),m_denominator(den){}
	//explicit Fraction(int num):m_numerator(num),m_denominator(1){}
	operator double()const{
		return ((double)(m_numerator)/m_denominator);
	}

	Fraction operator+(const Fraction& f){
		return Fraction(m_numerator*f.m_denominator+m_denominator*f.m_numerator,
			m_denominator*f.m_denominator);
	}
private:
	int m_numerator;
	int m_denominator;

};

int main(int argc, char const *argv[])
{
	Fraction f(3,5);
	Fraction d = f+4;

	return 0;
}