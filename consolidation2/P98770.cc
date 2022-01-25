#include <iostream>
#include <vector>
using namespace std;

void calcula_posicions(const vector<double>& v, int& p, int& q) {
	p = 1;
	for (int i = 2; i < v.size(); ++i) {
		if (v[i] > v[p]) p = i;
	}
	q = 0;
	for (int i = 1; i < p; ++i) {
		if (v[i] > v[q]) q = i; 
	}
}

int main() {
	cout.setf(ios::fixed);
	cout.precision(6);

	int n;
	while (cin >> n) {
		vector<double> v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		int p, q;
		calcula_posicions(v, p, q);
		double suma = 0;
		for (int i = q; i <= p; ++i) suma += v[i];
		cout << suma/(p - q + 1) << endl;
	}
}
