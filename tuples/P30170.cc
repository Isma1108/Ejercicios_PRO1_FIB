#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<int> vcontcar(n, 0);
		vector<string> v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		sort(v.begin(), v.end());
		string ant = v[0];
		int npig = 1;
		for (int i = 1; i < n; ++i) {
			if (v[i] == ant) ++npig;
			else {
				vcontcar[npig - 1] = vcontcar[npig - 1] + ant.length();
				ant = v[i];
				npig = 1;
			}
		}
		vcontcar[npig - 1] = vcontcar[npig - 1] + ant.length();

		for (int i = 0; i < n; ++i) {
			if (vcontcar[i] != 0) cout << i + 1 << " : " << vcontcar[i] << endl;
		}
		cout << endl;
	}
}
