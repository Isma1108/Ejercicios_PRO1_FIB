#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<int> vect(n);
		for (int i = 0; i < n; ++i) cin >> vect[i];
		sort(vect.begin(), vect.end());
		bool first = true;
		for (int i = n - 1; i >= 0; --i) {
			if (not first) cout << ' ';
			cout << vect[i];
			first = false;
		}
		cout << endl;
	}
}
