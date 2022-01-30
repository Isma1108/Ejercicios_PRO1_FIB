#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<char> > Matriu;

int num_bac(const Matriu& joc, int i, int j) {
        int n = joc.size();
        int m = joc[0].size();
        int i1 = i + 1, i2 = i - 1;
        int j1 = j + 1, j2 = j - 1;
        bool paddi = i1 < n;
        bool psubi = i2 >= 0;
        bool paddj = j1 < m;
        bool psubj = j2 >= 0;
	int bact = 0;
        if (paddi and psubj and joc[i1][j2] == 'B') ++bact;
        if (paddi and joc[i1][j] == 'B') ++bact;
        if (paddi and paddj and joc[i1][j1] == 'B') ++bact;
        if (paddj and joc[i][j1] == 'B') ++bact;
        if (psubi and joc[i2][j] == 'B') ++bact;
        if (psubj and joc[i][j2] == 'B') ++bact;
        if (psubi and psubj and joc[i2][j2] == 'B') ++bact;
        if (psubi and paddj and joc[i2][j1] == 'B') ++bact;
        return bact;
}

Matriu tracta_joc(const Matriu& joc) {
        int n = joc.size();
        int m = joc[0].size();
        Matriu pjoc = joc;
        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                        int k = num_bac(joc, i, j);
                        if (joc[i][j] == '.') {
                                if (k == 3) pjoc[i][j] = 'B';
                        }
                        else {
                                if (k != 2 and k != 3) pjoc[i][j] = '.';
                        }
                }
        }
        return pjoc;
}

int main() {
        int n, m;
        bool primer = true;
	cin >> n >> m;
        while (n != 0 and m != 0) {
                Matriu joc(n, vector<char>(m));
                for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < m; ++j) cin >> joc[i][j];
                }
                joc = tracta_joc(joc);
                if (primer) primer = false;
                else cout << endl;
                for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < m; ++j) cout << joc[i][j];
                        cout << endl;
                }
		cin >> n >> m;
        }
}
