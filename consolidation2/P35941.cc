#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

char torna_lletra(string trad, char c) {
	int i = 0;
	bool trobat = false;
	while (not trobat and i < trad.size()) {
		if(c == trad[i]) trobat = true;
		++i;
	}
	--i;
	return char(i + 'a');
}

int main() {
	string trad;
	while (cin >> trad) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			string word;
			cin >> word;
			for (int j = 0; j < word.size(); ++j) {
				if (word[j] == '_') cout << ' ';
				else cout << torna_lletra(trad, word[j]);
			}
			cout << endl;
		}
		cout << endl;
	}
}
