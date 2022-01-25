#include <iostream>
#include <vector>
using namespace std;

bool suma_demes(const vector<int>& v) {
	int suma = 0;
	for (int i = 0; i < v.size(); ++i) suma += v[i];
	for (int i = 0; i < v.size(); ++i) if (v[i] == suma - v[i]) return true;
	return false;
}

int main() {
	int n;
	while (cin >> n) {
		vector<int> vect(n);
		for (int i = 0; i < n; ++i) cin >> vect[i];
		if (suma_demes(vect)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
