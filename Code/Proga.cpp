#include <fstream>
#include <string>
#include <sstream>
#include "Struct.h"
#include "Templ.h"

// ������������ ������� �������� ��������� ������
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
	// ����������� ������� �������� ��������
	const int n = 3;
	Fraction P[n] = { Fraction(1, 1), Fraction(-2, 3), Fraction(4, 2) };

	// ���� ��� ����������� ����������
	ofstream f("result.txt");

	// ����� ��� ����������� ����������
	ostringstream str;

	// ��������� ������� �����
	for (int i = 0; i < n; ++i)
	{
		cout << "   " << P[i];
		f << "   " << P[i];
		str << "   " << P[i];
	}
	cout << endl;
	f << endl;
	str << endl;

	// ���������� �������� ������� � ����� �� ����� �������
	Fraction x(2, 3);
	Fraction S;
	for (int i = 0; i < n; ++i)
	{
		S = S*x + P[i];
	}
	cout << "P = " << S << endl;
	f << "P = " << S << endl;
	str << "P = " << S << endl;
	f.close(); // ��������� ���������� �����
	system("pause");

	// ��������� �����, ��������� �� ��������� ������
	cout << "stream=" << str.str() << endl;
	// ��������� ��������� ������ � ������� � �����
	string line("3 4");
	istringstream g(line);
	g >> S;
	cout << "Fraction from string = " << S << endl;
	system("pause");

	// ������������ ������� �������� "�� ���" �����
	//int a[n], b[n], c[n];
	//cout << " a loaded " << readMas(a, n) << endl;
	//cout << " b loaded " << readMas(b, n) << endl;
	//cout << " c loaded " << readMas(c, n) << endl;
	//system("pause");

	// ������ ������������ �����
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