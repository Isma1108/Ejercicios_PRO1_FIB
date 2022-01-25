#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matriu;

Matriu producte(const Matriu& a, const Matriu& b) {
	int n = a.size();
	int p = b.size();
	int q = b[0].size();
	Matriu c(n, vector<int>(q, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < q; ++j) {
			for (int k = 0; k < p; ++k) c[i][j] += a[i][k] * b[k][j];
		}
	}
	return c;
}
