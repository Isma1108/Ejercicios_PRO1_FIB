#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, total = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	for (int i = 0; i < n - 1; ++i) {
		if (v[i] == v[n - 1]) ++total;
	}
	cout << total << endl;
}
