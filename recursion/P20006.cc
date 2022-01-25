#include <iostream>
using namespace std;

int operacio() {
	char c;
	cin >> c;
	if (c >= '0' and c <= '9') return c - '0';
	else {
		if (c == '+') return (operacio() + operacio());
		else if (c == '-') return (operacio() - operacio());
		else return (operacio()*operacio());
	}
}

int main() {
	cout << operacio() << endl;
}
