#ifndef STRUCT_GUARD
#define STRUCT_GUARD

#include <iostream>
using namespace std;

unsigned GCD(int a, unsigned b);

struct Fraction
{
	int num;
	unsigned den;
	Fraction() : num(0), den(1) {}
	Fraction(int n, unsigned d)
	{
		d = (d == 0) ? 1 : d;
		if (n == 0)
		{
			num = n;
			den = d;
		}
		else
		{
			unsigned gcd = GCD(n, d);
			num = n / gcd;
			den = d / gcd;
		}
	}
};

Fraction operator+(Fraction a, Fraction b);
Fraction operator*(Fraction a, Fraction b);

ostream& operator<<(ostream& os, const Fraction& f);
istream& operator>>(istream& os, Fraction& f);

#endif