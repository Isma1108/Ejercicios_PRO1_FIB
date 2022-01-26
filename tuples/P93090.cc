#include <iostream>
using namespace std;

int mcd(int a, int b) {
	if (b == 0) return a;
	else return mcd(b, a%b);
}

struct Fraccio {
	int num, den;
};

Fraccio suma(const Fraccio& x, const Fraccio& y) {
	Fraccio res;
	res.den = x.den*y.den;
	res.num = (res.den/x.den)*x.num + (res.den/y.den)*y.num;
	int d = mcd(res.num, res.den);
	res.num /= d;
	res.den /= d;
	return res;
}

int main() {
	Fraccio primera, res;
	res.num = 0;
	res.den = 1;
	char c;
	bool continua = true;
	while (continua) {
		cin >> primera.num >> c >> primera.den >> c;
		if (c == '=') continua = false;
		res = suma(primera, res);
	}
	cout << res.num << "/" << res.den << endl;
}
