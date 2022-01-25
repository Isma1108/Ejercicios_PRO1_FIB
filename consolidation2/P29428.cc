#include <iostream>
#include <vector>
using namespace std;

bool conte(string s1, string s2) {
	int i = 0, j = 0;
	while (i + s2.size() <= s1.size() and j < s2.size()) {
		if (s2[j] == s1[i + j]) ++j;
		else {
			j = 0;
			++i;
		}
	}
	if (j == s2.size()) return true;
	else return false;
}

int main() {
	int n;
	cin >> n;
	vector<string> paraules(n);
	for (int i = 0; i < n; ++i) cin >> paraules[i];
	for (int i = 0; i < n; ++i) {
		cout << paraules[i] << ':';
		for (int j = 0; j < n; ++j) {
			if (conte(paraules[i], paraules[j])) {
				cout << ' ' << paraules[j];
			}	
		}
		cout << endl;
	}
}
