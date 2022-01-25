#include <iostream>
using namespace std;

void girar(int& n) {
	string name;
	if (cin >> name) {
		girar(n);
		if (n != 0) {
			cout << name << endl;
			--n;
		}
	}
}

int main() {
	int num;
	cin >> num;
	girar(num);
}
