#include <iostream>
#include <vector>
using namespace std;

double producte_escalar(const vector<double>& u, const vector<double>& v) {
	double suma = 0;
	for (int i = 0; i < u.size(); ++i) suma += u[i]*v[i];
	return suma;
}
