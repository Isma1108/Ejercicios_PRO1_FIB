#include <iostream>
using namespace std;

void convergeix(int n, int& k, int& lluny) {
	while (n != 1) {
		if (n%2 == 0) n /= 2;
		else n = n*3 + 1;
		if (n > lluny) lluny = n;
		++k;
	}
}

int main() {
	int n, p;
	cin >> n >> p;
	int lluny = n;
	for (int i = 1; i <= n; ++i) {
		int k = 0;
		convergeix(i, k, lluny);
		if (k >= p) cout << i << endl;
	}
	cout << "S'arriba a " << lluny << '.' << endl;
}
