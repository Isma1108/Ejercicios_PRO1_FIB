#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	for (int i = n - 1; i >= 0; --i) {
		for (int j = v[i].size() - 1; j >= 0; --j) cout << v[i][j];
		cout << endl;
	}
}
