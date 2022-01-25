#include <iostream>
#include <vector>
using namespace std;

bool same_digits(int x, int y, int b) {
	vector <int>v(b, 0);
	int taman = v.size();
	int xy = x * y;
	while (xy != 0) {
		if (x != 0) v[x % b]++;
		if (y != 0) v[y % b]++;
		v[xy % b]--;
		x /= b;
		y /= b;
		xy /= b;
	}
	for (int i = 0; i < taman; ++i) {
		if (v[i] != 0) return false;
	}
	return true;
}

void write(int n, int b) {
	if (n != 0) {
		write(n / b, b);
		int aux = n % b;
		if (aux < 10) cout << aux;
		else cout << char(aux-10+'A');
	}
}

int main() {
	int x, y;
	while (cin >> x >> y) {
		int in = 2;
		bool entra = false;
		cout << "solucions per a " << x << " i " << y;
		while (in <= 16) {
			bool resultat = same_digits(x, y, in);
			if (resultat) {
				if (not entra) cout << endl;
				write(x, in);
				cout << " * ";
				write(y, in);
				cout << " = ";
				int nxy = x * y;
				write(nxy, in);
				cout << " (base " << in << ')' << endl;
				entra = true;
			}
			in++;
		}
		if (not entra) {
			cout << endl;
			cout << "cap" << endl;
		}
		cout << endl;
	}
}
