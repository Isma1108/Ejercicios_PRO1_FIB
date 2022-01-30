#include <iostream>
#include <vector>
using namespace std;

int posicio(double x, const vector<double>& v, int esq, int dre) {
	if (esq > dre) return -1;
	int m = (dre + esq)/2;
	if (v[m] < x) return posicio(x, v, m + 1, dre);
	else if (v[m] > x) return posicio(x, v, esq, m - 1);
	else return m;
}
