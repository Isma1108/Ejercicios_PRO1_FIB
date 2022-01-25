#include <iostream>
using namespace std;

void girar() {
	string paraula;
	while (cin >> paraula) {
		girar();
		cout << paraula << endl;
	}
}

int main() {
	girar();
}
