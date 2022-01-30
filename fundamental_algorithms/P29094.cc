#include <iostream>
#include <vector>
using namespace std;

int posicio_maxim(const vector<double>& v, int m) {
	int pos_max = 0;
	for (int i = 1; i <= m; ++i) {
		if (v[i] > v[pos_max]) pos_max = i;
	}
	return pos_max;
}
