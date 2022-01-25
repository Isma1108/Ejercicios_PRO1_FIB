#include <iostream>
using namespace std;

void girar() {
	string name;
	cin >> name;
	if (name != "fi") {
		girar();
		cout << name << endl;
	}
}

int main() {
	girar();
}
