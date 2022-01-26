#include <iostream>
using namespace std;

struct Racional {
	int num;
	int den;
};

int Mcd(int a, int b) {
	if (b == 0) return a;
	else return Mcd(b, a % b);
}

Racional Simplifica(Racional& r) {
	int mcd = Mcd(r.num, r.den);
	Racional Res;
	Res.num = r.num / mcd;
	Res.den = r.den / mcd;
	if (Res.den < 0) {
		Res.num = -Res.num;
		Res.den = -Res.den;
	}
	return Res;
}

Racional suma(Racional& r1, Racional& r2) {
	Racional r;
	r.den = r1.den * r2.den;
	r.num = r1.num * r2.den+r2.num * r1.den;
	return Simplifica(r);
}

Racional multiplica(Racional& r1, Racional& r2) {
	Racional r;
	r.num = r1.num * r2.num;
	r.den = r1.den * r2.den;
	return Simplifica(r);
}

void Escriu_racional(Racional& r) {
	if (r.num == 0) cout << 0 << endl;
	else if (r.den == 1) cout << r.num << endl;
	else cout << r.num << "/" << r.den << endl;
}

int main() {
	Racional r1, r2;
	cin >> r1.num >> r1.den;
	r1 = Simplifica(r1);
	string s;
	Escriu_racional(r1);
	while (cin >> s) {
		if (s == "suma") {
			cin >> r2.num >> r2.den;
			r1 = suma(r1, r2);
		} else if (s == "resta")   {
			cin >> r2.num >> r2.den;
			r2.num = -r2.num;
			r1 = suma(r1, r2);
		} else if (s == "multiplica")   {
			cin >> r2.num >> r2.den;
			r1 = multiplica(r1, r2);
		} else if (s == "divideix")   {
			cin >> r2.den >> r2.num;
			r1 = multiplica(r1, r2);
		}
		Escriu_racional(r1);
	}
}
