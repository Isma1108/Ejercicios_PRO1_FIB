#include <iostream>
using namespace std;

struct Rellotge {
	int h;
	int m;
	int s;
};

Rellotge mitja_nit() {
	Rellotge ini;
	ini.h = ini.m = ini.s = 0;
	return ini;
}

void incrementa(Rellotge& r) {
	++r.s;
	if (r.s > 59) {
		r.s -= 60;
		++r.m;
	}
	if (r.m > 59) {
		r.m -= 60;
		++r.h;
	}
	if (r.h == 24) r.h = 0;
}

void escriu (const Rellotge& r) {
	if (r.h < 10) cout << '0';
	cout << r.h << ':';
	if (r.m < 10) cout << '0';
	cout << r.m << ':';
	if (r.s < 10) cout << '0';
	cout << r.s << endl; 
}
