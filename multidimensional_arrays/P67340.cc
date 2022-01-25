#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<char> > Matriu;

void diagonal(const Matriu& mat, int i, int j, int x, int y) {
	int pi = i + x;
	int pj = j + y;
	int f = mat.size();
	int c = mat[0].size();
	while (pi >= 0 and pi < f and pj >= 0 and pj < c and mat[pi][pj] == '.')  {
		pi += x;
		pj += y;
	}
	if (pi >= 0 and pi < f and pj >= 0 and pj < c) {
		if (mat[pi][pj] == 'X') {
			cout << '(' << i+1 << ',' << j+1 << ")<->(" << pi+1 << ',' << pj+1 << ')' << endl;
	
		}
	}
}

int main() {
	int f, c;
	cin >> f >> c;
	Matriu mat(f, vector<char> (c));
	for (int i = 0; i < f; ++i) {
		for (int j = 0; j < c; ++j) cin >> mat[i][j];
	}

	for (int i = 0; i < f; ++i) {
		for (int j = 0; j < c; ++j) {
			if (mat[i][j] == 'X') {
				diagonal(mat, i, j, 1, 1);
				diagonal(mat, i, j, 1, -1);
				diagonal(mat, i, j, -1, 1);
				diagonal(mat, i, j, -1, -1);
			}
		}
	}
}
