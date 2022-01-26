#include <iostream>
using namespace std;

struct Racional {
	int num, den;
};

int mcd(int n1, int n2) {
	while (n2 != 0) {
		int r = n1%n2;
		n1 = n2;
		n2 = r;
	}
	return n1;
}

Racional racional(int n, int d) {
	if (n == 0) d = 1;
	else {
		int divisor = mcd(n, d);
		n /= divisor;
		d /= divisor;
		if (d < 0) {
			d = -d;
			n = -n;
		}
	}
	Racional fraccio;
	fraccio.num = n;
	fraccio.den = d;
	return fraccio;
}
