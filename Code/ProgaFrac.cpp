#include <iostream>
#include "TemplFrac.h"

using namespace std;

int main()
{
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