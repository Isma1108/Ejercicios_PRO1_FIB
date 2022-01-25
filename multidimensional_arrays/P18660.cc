   
#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector< vector<char> > Matriu;

void escribir_matriz(Matriu& m) {
	int f = m.size();
	int c = m[0].size();
	for (int i = 0; i < f; ++i) {
		cout << m[i][0];
		for (int j = 1; j < c; ++j) cout << ' ' << m[i][j];
		cout << endl;
	}
}

void leer_matriz(Matriu& m) {
	int f = m.size();
	int c = m[0].size();
	for (int i = 0; i < f; ++i) {
		for (int j = 0; j < c; ++j) cin >> m[i][j];
	}
}

bool esta(const Matriu& m, string s, int i, int j, int x, int y) {
	//(x,y) indica si hay que buscar por fila (1,0), por columna (0,1)
	//o por diagonal (1,1)
	
	int f = m.size();
	int c = m[0].size();
	int l = s.length();
	for (int k = 0; k < l; ++k) {
		if (i < f and j < c) {
			if (m[i][j] != s[k] and char(m[i][j] - 'A' + 'a') != s[k]) return false;
			i += x;
			j += y;
		}
		else return false;
	}
	return true;
}

void mayuscula(Matriu& m, string s, int i, int j, int x, int y) {
	int f = m.size();
	int c = m[0].size();
	int l = s.length();
	for (int k = 0; k < l; ++k) {
		if (i < f and j < c) {
			if (m[i][j] >= 'a' and m[i][j] <= 'z') m[i][j] = char(m[i][j] + 'A' - 'a');
			i += x;
			j += y;
		}
	}
}

int main() {
	bool es_primero = true;
	int numpal, f, c;
	while (cin >> numpal >> f >> c) {
		vector<string> pal(numpal);
		for (int i = 0; i < numpal; ++i) cin >> pal[i];
		Matriu m(f, vector<char> (c));
		leer_matriz(m);

		for (int i = 0; i < f; ++i) {
			for (int j = 0; j < c; ++j) {
				for (int k = 0; k < numpal; ++k) {
					if (esta(m, pal[k], i, j, 0, 1)) mayuscula(m, pal[k], i, j, 0, 1);
					if (esta(m, pal[k], i, j, 1, 0)) mayuscula(m, pal[k], i, j, 1, 0);
					if (esta(m, pal[k], i, j, 1, 1)) mayuscula(m, pal[k], i, j, 1, 1);
				}
			}
		}
		if (es_primero) es_primero = false;
		else cout << endl;
		escribir_matriz(m);
	}
}
