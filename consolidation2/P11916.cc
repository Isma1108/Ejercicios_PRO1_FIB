#include <iostream>
using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(10);
	int n;
	while (cin >> n) {
		double total = 0, factorial = 1;
		bool first = true;
		for (int i = 0; i < n; ++i) {
			if (not first) factorial *= i;
			total += double(1)/factorial;
			first = false;
		}
		cout << "Amb " << n << " terme(s) s'obte " << total << '.' << endl; 
	}
}
