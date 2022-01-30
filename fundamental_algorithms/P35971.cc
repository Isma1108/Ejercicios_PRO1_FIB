#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matriu;

int suma_linia(const Matriu& mat, int of, int oc, int df, int dc) {
	int total = 0;
	if (of == df) {
		if (oc < dc) { 
			for (int i = oc + 1; i <= dc; ++i) total += mat[of][i];
		}
		else {
			for (int i = oc - 1; i >= dc; --i) total += mat[of][i];
		}
	}

	else {
		if (of < df) {
			for (int i = of + 1; i <= df; ++i) total += mat[i][oc];
		}
		else {
			for (int i = of - 1; i >= df; --i) total += mat[i][oc];
		}
	}
	return total;
}

int main() {
	int f, c;
	cin >> f >> c;
	Matriu mat(f, vector<int>(c));
	for (int i = 0; i < f; ++i) {
		for (int j = 0; j < c; ++j) cin >> mat[i][j];
	}
	int total = 0;
	int of, oc, df, dc;
	cin >> of >> oc;
	total += suma_linia(mat, of - 1, oc, of, oc);
	while (cin >> df >> dc) {
		total += suma_linia(mat, of, oc, df, dc);
		of = df;
		oc = dc;
	}
	cout << "suma = " << total << endl;
}
