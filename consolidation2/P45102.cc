#include <iostream>
using namespace std;

int operacio() {
	char n;
	cin >> n;
	if (n >= '0' and n <= '9') return n -'0';
	int op1 = operacio();
	char operador;
	cin >> operador;
	int op2 = operacio();
	cin >> n;
	if (operador == '+') return op1 + op2;
	else if (operador == '-') return op1 - op2;
	else return op1*op2;
}

int main() {
	cout << operacio() << endl;
}
