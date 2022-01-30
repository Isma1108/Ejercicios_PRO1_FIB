#include <iostream>
#include <vector>
using namespace std;

vector<bool> garbell(int m) {
	vector<bool> v(m + 1, true);
	v[0] = v[1] = false;
	for (int i = 2; i*i <= m; ++i) {
		if (v[i]) {
			for (int j = i*i; j <= m; j += i) v[j] = false;
		}
	}
	return v;
}

int main() {
	int m = 1000000;
	vector<bool> v = garbell(m);
	int n;
	while (cin >> n) {
		if (v[n]) cout << n << " es primer" << endl;
		else cout << n << " no es primer" << endl;
	}
}
