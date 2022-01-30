#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int N_ALFABET = 'z'-'a'+ 1;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		vector<int> v(N_ALFABET, 0);
		char c;
		cin >> c;
		while (c != '.') {
			if (c >= 'A' and c <= 'Z') ++v[c - 'A'];
			cin >> c;
		}
		
		cin >> c;
		while (c != '.') {
			if (c >= 'A' and c <= 'Z') --v[c - 'A'];
			cin >> c;
		}

		bool correcte = true;
		int k = 0;
		while (correcte and k < N_ALFABET) {
			if (v[k] != 0) correcte = false;
			++k;
		}
		if (correcte) cout << "SI" << endl;
		else cout << "NO" << endl;
	}
}
