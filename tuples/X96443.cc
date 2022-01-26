#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Coord {
	int x, y;
};

typedef vector <vector <char> >Matriu;
void omple_matriu(Matriu& mat) {
	int n = mat.size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> mat[i][j];
		}
	}
}
Coord seguentD(const Coord& p, int n) {
	Coord p1;

	if (p.x-1 < 0 and p.y+1 > n-1) {
		p1.x = n-1;
		p1.y = p.x+1;
	} else if (p.x == n-1 and p.y == n-1)   {
		p1.x = 0;
		p1.y = 0;
	} else if (p.x-1 < 0)   {
		p1.y = 0;
		p1.x = p.y+1;
	} else if (p.y+1 > n-1)   {
		p1.y = p.x+1;
		p1.x = n-1;
	} else   {
		p1.x = p.x-1;
		p1.y = p.y+1;
	}
	return p1;
}

int main() {
	int n, d, l;
	Coord p;
	while (cin >> n >> d >> l >> p.x >> p.y) {
		Matriu mat(n, vector <char>(n));
		vector <char>holi(l);
		omple_matriu(mat);
		int i = 0;
		holi[i] = mat[p.x][p.y];
		++i;
		--l;
		while (l > 0) {
			for (int j = 0; j < d+1; ++j) {
				p = seguentD(p, n);
			}
			holi[i] = mat[p.x][p.y];
			++i;
			--l;
		}
		for (int j = 0; j < holi.size()-1; ++j) {
			if (holi[j] == 'X' and holi[j+1] == 'X') {
				cout << ' ';
				++j;
			} else cout << holi[j];
		}
		cout << holi[holi.size()-1];
		cout << endl;
	}
}
