#include <iostream>
using namespace std;

int nombre_digits(int n) {
	if (n < 10) return 1;
	return 1 + nombre_digits(n/10);
}

void escriu(int n, int i) {
	cout << n;
	for (int m = 0; m < i - 1; ++m) cout << '-' << n;
}

int main() {
	int n, f;
	cin >> n >> f;
	int d = nombre_digits(n);
	int fila = 2*f*d + 2*f - 1;
	for (int i = 1; i <= f; ++i) {
		int mig = fila - 2*(i*d + i -1);
		escriu(n, i);
		for (int m = 0; m < mig; ++m) cout << '.';
		escriu(n, i);
		cout << endl;
	}
}
