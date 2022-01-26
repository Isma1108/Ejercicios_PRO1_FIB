#include <iostream>
using namespace std;

struct Rectangle {
	int x_esq, x_dre, y_baix, y_dalt;
};

void llegeix(Rectangle& r) {
	cin >> r.x_esq >> r.x_dre >> r.y_baix >> r.y_dalt;
}

int relacio(const Rectangle& r1, const Rectangle& r2) {
	if (r1.x_esq == r2.x_esq && r1.x_dre == r2.x_dre && r1.y_baix == r2.y_baix && r1.y_dalt == r2.y_dalt) return 4;
	if (r2.x_esq <= r1.x_esq && r2.x_dre >= r1.x_dre && r2.y_baix <= r1.y_baix && r2.y_dalt >= r1.y_dalt) return 1;
	if (r1.x_esq <= r2.x_esq && r1.x_dre >= r2.x_dre && r1.y_baix <= r2.y_baix && r1.y_dalt >= r2.y_dalt) return 2;
	if (r1.y_baix >= r2.y_dalt or r2.y_baix >= r1.y_dalt or r1.x_esq >= r2.x_dre or r2.x_esq >= r1.x_dre) return 0;
	else return 3;
}

int main() {
	int n;
	while (cin >> n && n != 0) {
		Rectangle r1, r2;
		llegeix(r2);
		--n;
		bool intersec = true;
		while (intersec && n != 0) {
			r1.x_esq = r2.x_esq;
			r1.x_dre = r2.x_dre;
			r1.y_baix = r2.y_baix;
			r1.y_dalt = r2.y_dalt;
			llegeix(r2);
			if (relacio(r1, r2) == 0) intersec = false;
			else if (relacio(r1, r2) == 1) {
				r2.x_esq = r1.x_esq;
				r2.x_dre = r1.x_dre;
				r2.y_dalt = r1.y_dalt;
				r2.y_baix = r1.y_baix;
			} else if (relacio(r1, r2) == 3)   {
				if (r1.x_esq > r2.x_esq) r2.x_esq = r1.x_esq;
				if (r1.x_dre < r2.x_dre) r2.x_dre = r1.x_dre;
				if (r1.y_baix > r2.y_baix) r2.y_baix = r1.y_baix;
				if (r1.y_dalt < r2.y_dalt) r2.y_dalt = r1.y_dalt;
			}
			--n;
		}
		if (not intersec) {
			cout << "interseccio buida" << endl;
			while (n != 0) {
				llegeix(r2);
				--n;
			}
		} else   {
			cout << "punt inferior esquerre = (" << r2.x_esq << ", " << r2.y_baix << ");";
			cout << " punt superior dret = (" << r2.x_dre << ", " << r2.y_dalt << ")" << endl;
		}
	}
}
