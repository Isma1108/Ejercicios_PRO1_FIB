#include <iostream>
#include <vector>
using namespace std;

vector<int> concatenacio(const vector<int>& v1, const vector<int>& v2) {
	int n1 = v1.size();
	int n2 = v2.size();
	vector<int> res(n1 + n2);
	for (int i = 0; i < n1; ++i) res[i] = v1[i];
	for (int i = 0; i < n2; ++i) res[i + n1] = v2[i];
	return res;
}
