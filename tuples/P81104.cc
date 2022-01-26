#include <iostream>
#include <vector>
using namespace std;

struct Assignatura {
	string nom;
	double nota;
};

struct Alumne {
	string nom;
	int dni;
	vector<Assignatura> ass;
};

double nota(const vector<Alumne>& alums, int dni, string nom) {
	int n1 = alums.size();
	for (int i = 0; i < n1; ++i) {
		if (alums[i].dni == dni) {
			int n2 = alums[i].ass.size();
			for (int j = 0; j < n2; ++j) {
				if (alums[i].ass[j].nom == nom and alums[i].ass[j].nota != -1) {
					return alums[i].ass[j].nota;
				}
			}
		}		
	}
	return -1.0;
}

double mitjana(const vector<Assignatura>& ass) {
	int n = ass.size();
	double mitjana = 0;
	int x = 0;
	bool trobat = false;
	for (int i = 0; i < n; ++i) {
		if (ass[i].nota != -1) {
			mitjana += ass[i].nota;
			++x;
			trobat = true;
		}
	}
	if (trobat) return mitjana/double(x);
	else return -1;
}

void compta(const vector<Alumne>& alums, int dni, string nom, int& com) {
	int n = alums.size();
	double nota_alum = nota(alums, dni, nom);
	for (int i = 0; i < n; ++i) {
		double mid = mitjana(alums[i].ass);
		if (mid > nota_alum) ++com;
	}
}

int main() {
	int n;
	cin >> n;
	vector<Alumne> alumnes(n);
	for (int i = 0; i < n; ++i) {
		cin >> alumnes[i].nom;
		cin >> alumnes[i].dni;
		int x;
		cin >> x;
		alumnes[i].ass = vector<Assignatura> (x);
		for (int j = 0; j < x; ++j) {
			cin >> alumnes[i].ass[j].nom;
			cin >> alumnes[i].ass[j].nota;
		}
	}
	int dni;
	string assig;
	while (cin >> dni >> assig) {
		int com = 0;
		compta(alumnes, dni, assig, com);
		cout << com << endl;
	}
}
