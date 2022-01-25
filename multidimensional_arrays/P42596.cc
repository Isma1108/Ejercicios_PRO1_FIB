#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matriu;

void min_max(const Matriu& mat, int& minim, int& maxim) {
	int f = mat.size();
	int c = mat[0].size();
	minim = maxim = mat[0][0];
	for (int i = 0; i < f; ++i) {
		for (int j = 0; j < c; ++j) {
			if (mat[i][j] > maxim) maxim = mat[i][j];
			else if (mat[i][j] < minim) minim = mat[i][j];
		}
	}
}

int main() {
	int f, c;
	int dif = -1, iterador = 0, primer = 0;
	while (cin >> f >> c) {
		Matriu mat(f, vector<int>(c));
		for (int i = 0; i < f; ++i) {
			for (int j = 0; j < c; ++j) cin >> mat[i][j];
		}
		int maxim, minim;
		min_max(mat, minim, maxim);
		++iterador;
		
		if ((maxim - minim) > dif) {
			dif = maxim - minim;
			primer = iterador;
		}
	}
	cout << "la diferencia maxima es " << dif << endl;
	cout << "la primera matriu amb aquesta diferencia es la " << primer << endl;
}
