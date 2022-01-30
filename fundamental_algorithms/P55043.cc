#include <iostream>
using namespace std;

int suma_digits(int n) {
	if (n < 10) return n;
	else return n%10 + suma_digits(n/10);
}

int trobada_de_rius(int n) {
	int riu1 = 1;
	int riu3 = 3;
	int riu9 = 9;
	while (n != riu1 and n != riu3 and n != riu9) {
		if (riu1 < n) riu1 += suma_digits(riu1);
		else if (riu3 < n) riu3 += suma_digits(riu3);
		else if (riu9 < n) riu9 += suma_digits(riu9);
		else n += suma_digits(n);
	}
	return n;
}
