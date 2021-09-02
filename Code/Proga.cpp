#include <fstream>
#include <string>
#include <sstream>
#include "Struct.h"
#include "Templ.h"

// Удосконалена функція введення числового масиву
size_t readMas(int * a, size_t n)
{
	size_t loaded = 0;
	cout << "Input up to " << n << " numbers (not digit to break)\n";
	while (loaded < n && cin >> a[loaded]) ++loaded;
	if (loaded < n)
	{
		cin.clear();
		while (cin.get() != '\n') continue;
	}
	return loaded;
}

int main()
{
	// коефіцієнти полінома оголошені статично
	const int n = 3;
	Fraction P[n] = { Fraction(1, 1), Fraction(-2, 3), Fraction(4, 2) };

	// файл для накопичення результатів
	ofstream f("result.txt");

	// рядок для накопичення результатів
	ostringstream str;

	// виведення вхідних даних
	for (int i = 0; i < n; ++i)
	{
		cout << "   " << P[i];
		f << "   " << P[i];
		str << "   " << P[i];
	}
	cout << endl;
	f << endl;
	str << endl;

	// обчислення значення полінома в точці за схемю Горнера
	Fraction x(2, 3);
	Fraction S;
	for (int i = 0; i < n; ++i)
	{
		S = S*x + P[i];
	}
	cout << "P = " << S << endl;
	f << "P = " << S << endl;
	str << "P = " << S << endl;
	f.close(); // завершено формування файла
	system("pause");

	// отримання даних, записаних до рядкового потоку
	cout << "stream=" << str.str() << endl;
	// створення рядкового потоку і читання з нього
	string line("3 4");
	istringstream g(line);
	g >> S;
	cout << "Fraction from string = " << S << endl;
	system("pause");

	// випробування функції введення "не всіх" чисел
	//int a[n], b[n], c[n];
	//cout << " a loaded " << readMas(a, n) << endl;
	//cout << " b loaded " << readMas(b, n) << endl;
	//cout << " c loaded " << readMas(c, n) << endl;
	//system("pause");

	// шаблон раціональних чисел
	Frac<short> fd;
	cout << fd << '\n';
	Frac<short> fs(1, 2);
	Frac<short> rs(-1, 3);
	cout << fs << " + " << rs << " = " << fs + rs << '\n';
	Frac<long long> fll(123456, 339966);
	//Frac<char> fc;   // raise error of compilation
	cout << fll << '\n';
	system("pause");
	return 0;
}