#include <iostream>
#include <vector>
using namespace std;

const int ALFABET = 'z'-'a'+1;

int main() {
	char c;
	while (cin >> c) {	
		vector<int> v(ALFABET, 0); 
		while (c != '.') {
			if (c != ',') {
				if (c >= 'a' and c <= 'z') ++v[c - 'a'];
				else if (c >= 'A' and c <= 'Z') ++v[c -'A'];
			}
			cin >> c;
		}
		bool pangrama = true;
		int i = 0;
		while (pangrama and i < ALFABET) {
			if (v[i] == 0) pangrama = false;
			++i;
		}
		if (pangrama) cout << "SI" << endl;
		else cout << "NO" << endl;
	}
}
