#include <iostream>
using namespace std;

void barres(int n) {
	if (n == 1) cout << '*' << endl;
	else {
		barres(n - 1);
		barres(n - 1);
		for (int i = 0; i < n; ++i) cout << '*';
		cout << endl;
	}
}

int main() {
	int num;
	cin >> num;
	barres(num);
}
