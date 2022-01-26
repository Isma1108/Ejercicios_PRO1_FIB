#include <iostream>
#include <vector>
using namespace std;

struct Parell {
	int valor;
	int pos;
};

typedef vector<Parell> Vec_Com;

Vec_Com suma(const Vec_Com& v1, const Vec_Com& v2) {
	int n1 = v1.size();
	int n2 = v2.size();
	vector<Parell> v3(n1 + n2);
	int i, j, k;
	i = j = k = 0;
	while (i < n1 and j < n2) {
		if (v1[i].pos < v2[j].pos) {
			v3[k] = v1[i];
			++i; ++k;
		}
		else if (v1[i].pos > v2[j].pos) {
			v3[k] = v2[j];
			++j; ++k;
		}
		else if (v1[i].valor + v2[j].valor != 0) {
			v3[k].pos = v1[i].pos;
			v3[k].valor = v1[i].valor + v2[j].valor;
			++i; ++j; ++k;
		}
		else {
			++i; ++j;
		}
	}
	while (i < n1) {
		v3[k] = v1[i];
		++i; ++k;
	}
	while (j < n2) {
		v3[k] = v2[j];
		++j; ++k;
	}
	vector<Parell> resultat(k);
	for (int m = 0; m < k; ++m) resultat[m] = v3[m];
	return resultat;
}

void llegeix(Vec_Com& v) {
	int n;
	cin >> n;
	v = Vec_Com(n);
	char c;
	for (int i = 0; i < n; ++i) cin >> v[i].valor >> c >> v[i].pos;
}

void escriu(const Vec_Com& v) {
	int n = v.size();
	cout << n;
	for (int i = 0; i < n; ++i) cout << ' ' << v[i].valor << ';' << v[i].pos;
	cout << endl;
}

int main() {
	int k;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		Vec_Com v1, v2;
		llegeix(v1);
		llegeix(v2);
		Vec_Com v3 = suma(v1, v2);
		escriu(v3);
	}
}
