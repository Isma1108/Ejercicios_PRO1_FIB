#include <iostream>
#include <vector>
using namespace std;

bool es_primer(int num) {
	int div = 2;
	while (div*div <= num) {
		if (num%div == 0) return false;
		++div;
	}
	if (num != 1) return true;
	else return false;
}

int main() {
	int n;
	while (cin >> n) {
		vector<int> vect(n);
		for (int i = 0; i < vect.size(); ++i) cin >> vect[i];
		int i = 0;
		bool trobat = false;
		while (not trobat and i < n) {
			int j = 0;
			while (not trobat and j < n) {
				if (i != j) {
					if (es_primer(vect[i] + vect[j])) trobat = true;
				}
			++j;	
			}
		++i;	
		}
		if (trobat) cout << "si" << endl;
		else cout << "no" << endl;
	}
}
