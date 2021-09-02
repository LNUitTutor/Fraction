#include "Struct.h"

unsigned GCD(int a, unsigned b)
{
	a = a < 0 ? -a : a;
	while (a != b)
		if (a > b) a -= b;
		else b -= a;
	return b;
}

Fraction operator+(Fraction a, Fraction b)
{
	return Fraction(a.num*b.den + b.num*a.den, a.den*b.den);
}

Fraction operator*(Fraction a, Fraction b)
{
	return Fraction(a.num*b.num, a.den*b.den);
}

ostream& operator<<(ostream& os, const Fraction& f)
{
	os << f.num << '/' << f.den;
	return os;
}
istream& operator>>(istream& is, Fraction& f)
{
	is >> f.num >> f.den;
	return is;
}
