#include <iostream>
using namespace std;

int suma_digits(int num) {
	if (num < 10) return num;
	else return num%10 + suma_digits(num/10);
}

bool es_primer(int num) {
	int d = 2;
	while (d*d <= num) {
		if (num%d == 0) return false; 
		++d;
	}
	if (num <= 1) return false;
	else return true;
}

bool es_primer_perfecte(int n) {
	if (n < 10) {
		if (es_primer(n)) return true;
		else return false;
	}
	else {
		if(not es_primer(n)) return false;
		else return es_primer_perfecte(suma_digits(n));
	}
}

int main() {
	int num;
	while (cin >> num) cout << es_primer_perfecte(num) << endl;
}
