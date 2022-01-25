#include <iostream>
using namespace std;

void girar(int& n) {
	string name;
	if (cin >> name) {
		++n;
		girar(n);
		if (n <= 0) cout << name << endl;
		n -= 2;
	}
}

int main() {
	int n = 0;
	girar(n);
}
