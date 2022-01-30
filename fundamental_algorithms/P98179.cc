#include <iostream>
#include <vector>
using namespace std;

void insereix(vector<double>& v) {
	double x = v[v.size() - 1];
	int j = v.size() - 1;
	while (j > 0 and v[j-1] > x) {
		v[j] = v[j-1];
		--j;
	}
	v[j] = x;
}
