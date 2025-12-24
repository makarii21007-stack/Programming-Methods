#include <iostream>
#include <locale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, l, d;

	cin >> n;

	l = n % 10;
	d = (n % 100) / 10;
	if (n == 0)
		cout << "Мы не собрали грибов в лесу";
	else
	{
		if ((l == 1 && d == 0) || (l == 1 && d != 1))
			cout << "Мы собрали " << n << " гриб";

		if ((l >= 2 && l <= 4 && d == 0) || (l >= 2 && l <= 4 && d != 1))
			cout << "Мы собрали " << n << " гриба";

		if ((d == 0 && l >= 5) || (d == 1) || (d > 1 && l >= 5))
			cout << "Мы собрали " << n << " грибов";
	}
}
