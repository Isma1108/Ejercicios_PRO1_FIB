#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Enviament {
	string dni;
	string exer;
	int temps;
	string res;
};

struct Alumne {
	string dni;
	int num;
};

struct Resultats {
	Alumne env_verds;
	Alumne ex_verds;
	Alumne ex_verms;
	Alumne ex_in;
	Alumne max_temp;
};

typedef vector <Enviament>Historia;

void llegeix_env(Enviament&e) {
	cin >> e.dni >> e.exer >> e.temps >> e.res;
}

void llegeix_hist(Historia&h) {
	for (int i = 0; i < h.size(); ++i) llegeix_env(h[i]);
}

bool es_mes_petit(const Enviament&a, const Enviament&b) {
	if (a.dni == b.dni) return a.exer < b.exer;
	return a.dni < b.dni;
}

void actualitza_param(int intent, Alumne &actual, const string& alumneint) {
	if (intent > actual.num) {
		actual.dni = alumneint;
		actual.num = intent;
	}
}

void calcula_resultats(const Historia&v, Resultats&r) {
	int i = 0;
	r.max_temp.num = r.env_verds.num = r.ex_verds.num = r.ex_verms.num =
		r.ex_in.num = 0;

	while (i < v.size()) {
		string alum = v[i].dni;
		int auxenv_verds, auxex_in, auxex_verds, auxex_verms;
		auxenv_verds = auxex_in = auxex_verds = auxex_verms = 0;
		while (i < v.size() and v[i].dni == alum) {
			string exer = v[i].exer;
			bool hihaverd, hihagroc, hihavermell;
			hihaverd = hihagroc = hihavermell = false;
			while (i < v.size() and v[i].dni == alum and v[i].exer == exer) {
				if (v[i].res == "groc") hihagroc = true;
				if (v[i].res == "vermell") hihavermell = true;
				if (v[i].res == "verd") {
					++auxenv_verds;
					hihaverd = true;
				}
				actualitza_param(v[i].temps, r.max_temp, alum);
				++i;
			}
			if (hihaverd) ++auxex_verds;
			if (hihavermell and not hihaverd and not hihagroc) ++auxex_verms;
			++auxex_in;
		}
		actualitza_param(auxex_verds, r.ex_verds, alum);
		actualitza_param(auxex_verms, r.ex_verms, alum);
		actualitza_param(auxex_in, r.ex_in, alum);
		actualitza_param(auxenv_verds, r.env_verds, alum);
	}
}

void pinta_al(const Alumne &a, const string &m1, bool pintanum) {
	cout << m1;
	if (a.num != 0) {
		cout << a.dni;
		if (pintanum) cout << " (" << a.num << ')';
		cout << endl;
	} else cout << '-' << endl;
}

void escriu_resultats(const Resultats &r) {
	pinta_al(r.env_verds, "alumne amb mes enviaments verds:     ", true);
	pinta_al(r.ex_verds, "alumne amb mes exercicis verds:      ", true);
	pinta_al(r.ex_verms, "alumne amb mes exercicis vermells:   ", true);
	pinta_al(r.ex_in, "alumne amb mes exercicis intentats:  ", true);
	pinta_al(r.max_temp, "alumne que ha fet l'ultim enviament: ", false);
}

int main() {
	int n;
	cin >> n;
	Historia h(n);
	llegeix_hist(h);

	sort(h.begin(), h.end(), es_mes_petit);
	Resultats r;
	calcula_resultats(h, r);

	escriu_resultats(r);
}
