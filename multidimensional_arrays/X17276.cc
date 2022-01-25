#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matriu;

Matriu llegeix_matriu(int f, int c) {
	Matriu m(f, vector<int> (c));
	for (int i = 0; i < f; ++i) {
		for (int j = 0; j < c; ++j) cin >> m[i][j];
	}
	return m;
}

bool creixent(Matriu mat, int a, int b) {
	int f = mat.size();
	int c = mat[0].size();

	int i = a-1, j = b+1, comp = mat[a][b];
	while (i >= 0 and j < c) {
		if (mat[i][j] > comp) comp = mat[i][j];
		else return false;
		--i;
		++j;
	}

	i = a-1, j = b-1, comp = mat[a][b];
	while (i >= 0 and j >= 0) {
		if (mat[i][j] > comp) comp = mat[i][j];
		else return false;
		--i;
		--j;
	}

	i = a+1, j = b-1, comp = mat[a][b];
	while (i < f and j >= 0) {
		if (mat[i][j] > comp) comp = mat[i][j];
		else return false;
		++i;
		--j;
	}

	i = a+1, j = b+1, comp = mat[a][b];
	while (i < f and j < c) {
		if (mat[i][j] > comp) comp = mat[i][j];
		else return false;
		++i;
		++j;
	}
	return true;
}

int main() {
	int f, c;
	while (cin >> f >> c) {
		Matriu mat = llegeix_matriu(f, c);
		int i, j;
		cin >> i >> j;
		if (creixent(mat, i, j)) cout << "si" << endl;
		else cout << "no" << endl;
	}
}
