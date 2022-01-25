#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		bool first = true;
		vector<int> v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		for (int i = n - 1; i >= 0; --i) { 
			if (not first) cout << ' ';
			first = false;
			cout << v[i];
		}
		cout << endl;
	}
}
