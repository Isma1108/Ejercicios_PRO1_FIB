#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matriu;

Matriu llegeix_sudoku() {
	Matriu sudoku(9, vector<int>(9));
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) cin >> sudoku[i][j];	
	}
	return sudoku;
}

bool es_correcte(const Matriu& sudoku) {
	int f = sudoku.size();
	int c = sudoku[0].size();
	
	//Recorregut horitzontal i vertical alhora:
	for (int i = 0; i < f; ++i) {
		vector<bool> xesta(9, false);
		vector<bool> yesta(9, false);
		for (int j = 0; j < c; ++j) {
			int xnum = sudoku[i][j];
			if (not xesta[xnum-1]) xesta[xnum-1] = true;
			else return false;
			
			int ynum = sudoku[j][i];
			if (not yesta[ynum-1]) yesta[ynum-1] = true;
			else return false;
		}
	}		
	//Recorregut submatrius 3x3
	for (int m = 0; m < 3; ++m) {
		for (int k = 0; k < 3; ++k) {
			vector <bool>esta(9, false);
			for (int i = 3 * m; i < (3 * m+3); ++i) {
				for (int j = 3 * k; j < (3 * k+3); ++j) {
					int num = sudoku[i][j];
					if (not esta[num-1]) esta[num-1] = true;
					else return false;
				}
			}
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		Matriu sudoku = llegeix_sudoku();
		if (es_correcte(sudoku)) cout << "si" << endl;
		else cout << "no" << endl;
	}
}
