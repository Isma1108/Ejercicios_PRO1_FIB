#include <iostream>
#include <vector>
using namespace std;

bool quadrat_magic(const vector< vector<int> >& t) {
	int n = t.size();
	bool first = true;
	int d1 = 0, d2 = 0;
	for (int i = 0; i < n; ++i) {
		int x = 0, y = 0, z1 = 0, z2 = n - 1;
		for (int j = 0; j < n; ++j) {
			if (t[i][j] < 1 or t[i][j] > n*n) return false;
			x += t[i][j];
			y += t[j][i];
			if (first) {
				d1 += t[j][z1];
				d2 += t[j][z2];
				++z1;
				--z2;
			}
		}
		if (first and d1 != d2) return false;
		first = false;
		if (x != d1 or y != d1) return false;
	}
	return true;
}
/*
int main() {
	int n;
	while (cin >> n) {
		vector< vector<int> > m(n, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) cin >> m[i][j];
		}
		cout << quadrat_magic(m) << endl;
	}
}
*/
