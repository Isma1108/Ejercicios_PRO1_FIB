#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matriu;

void transposa(Matriu& m) {
	int n = m.size(); //Matriu quadrada
	Matriu transposta(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) transposta[i][j] = m[j][i];
	}
	m = transposta;
}
