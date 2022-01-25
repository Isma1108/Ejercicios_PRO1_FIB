#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, a;
	cin >> n;
	vector<int> A(1001);

	for (int i = 0; i < n; ++i) {
		cin >> a;
		a -= 1000000000;
		++A[a];
	}
	for (int i = 0; i < A.size(); ++i) {
		if (A[i] != 0) cout << 1000000000 + i << " : " << A[i] << endl;
	}
}
