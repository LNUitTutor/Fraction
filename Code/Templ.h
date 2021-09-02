#ifndef TEMPL_GUARD
#define TEMPL_GUARD

// Раціональне число реалізовано шаблоном класу Frac<TNum>, де 
// TNum - тип цілого числа. Для того, щоб запобігти конкретизаціям
// невідповідним типом, використано класи характеристик.

template<typename TNum> class NumTraits;
template<> class NumTraits<short>
{
public:
	const int NumTag = 2;
	static const short numerator = 0;
	static const short denominator = 1;
};
template<> class NumTraits<int>
{
public:
	const int NumTag = 4;
	static const int numerator = 0;
	static const int denominator = 1;
};
template<> class NumTraits<long long>
{
public:
	const int NumTag = 8;
	static const long long numerator = 0LL;
	static const long long denominator = 1LL;
};

template<typename TNum>
TNum GCD(TNum a, TNum b)
{
	a = a < 0 ? -a : a;
	while (a != b)
		if (a > b) a -= b;
		else b -= a;
		return b;
}

template<typename TNum, typename Traits = NumTraits<TNum>>
struct Frac
{
	TNum num;
	TNum den;
	Frac() : num(Traits::numerator), den(Traits::denominator) {}
	Frac(TNum n, TNum d)
	{
		d = (d == Traits::numerator) ? Traits::denominator : d;
		if (n == Traits::numerator)
		{
			num = n;
			den = Traits::denominator;
		}
		else
		{
			TNum gcd = GCD(n, d);
			num = n / gcd;
			den = d / gcd;
		}
	}
	static int FracSize() { return NumTraits<TNum>::NumTag * 2; }
};

template<typename TNum> Frac<TNum> operator+(Frac<TNum> a, Frac<TNum> b)
{
	return Frac<TNum>(a.num*b.den + b.num*a.den, a.den*b.den);
}

template<typename TNum> Frac<TNum> operator*(Frac<TNum> a, Frac<TNum> b)
{
	return Frac<TNum>(a.num*b.num, a.den*b.den);
}

template<typename TNum> ostream& operator<<(ostream& os, const Frac<TNum>& f)
{
	os << f.num << '/' << f.den;
	return os;
}
template<typename TNum> istream& operator>>(istream& is, Frac<TNum>& f)
{
	is >> f.num >> f.den;
	return is;
}

#endif