#include <iostream>
#include <vector>
using namespace std;

int avalua(const vector<int>& p, int x) {
	int n = p.size() - 1;
	vector<int> aux(p.size());
	aux[n] = p[n];
	for (int i = n - 1; i >= 0; --i) {
		aux[i] = p[i] + aux[i + 1]*x;
	}
	return aux[0];
}
