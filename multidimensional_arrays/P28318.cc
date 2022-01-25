#include <iostream>
#include <vector>
using namespace std;

int main() {
	typedef vector< vector<int> > Matriu;
	int n, m;
	cin >> n >> m; //n = f, m = c;
	Matriu mat(n, vector<int>(m));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) cin >> mat[i][j];
	}

	string paraula;
	while (cin >> paraula) {
		int n1;
		if (paraula == "fila") {
			cin >> n1;
			cout << "fila " << n1 << ':';
			for (int j = 0; j < m; ++j) cout << ' ' << mat[n1-1][j];
		}
		else if (paraula == "columna") {
			cin >> n1;
			cout << "columna " << n1 << ':';
			for (int i = 0; i < n; ++i) cout << ' ' << mat[i][n1-1];
		}
		else {
			int n2;
			cin >> n1 >> n2;
			cout << "element " << n1 << ' ' << n2 << ": ";
			cout << mat[n1-1][n2-1];
		}
		cout << endl;
	}
}
