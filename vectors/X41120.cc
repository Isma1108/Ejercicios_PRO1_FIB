#include <iostream>
#include <vector>
using namespace std;

vector<int> calcula_cims(const vector<int>& v) {
	vector<int> cims;
	//Para hacerlo mas eficiente, cuando encuentre un pico,
	//voy a hacer dos saltos en la iteracion (el elemento contiguo al pico no es un pico)
	int i = 1;
	while (i < v.size()-1) {
		if (v[i] > v[i-1] and v[i] > v[i+1]) {
			cims.push_back(v[i]);
			i += 2;
		}
		else ++i;
	}
	return cims;
}

int main() {
	int n;
	cin >> n;
	vector<int> vect(n);
	for (int i = 0; i < n; ++i) cin >> vect[i];
	vector<int> cims = calcula_cims(vect);
	cout << cims.size() << ':';
	for (int i = 0; i < cims.size(); ++i) cout << ' ' << cims[i];
	cout << endl;
	bool mes_alt = false;
	for (int i = 0; i < cims.size(); ++i) {
		if (cims[i] > cims[cims.size() - 1]) {
			if(not mes_alt) cout << cims[i];
			else cout << ' ' << cims[i];
			mes_alt = true;
		}
	}
	if (not mes_alt) cout << '-';
	cout << endl;
}
