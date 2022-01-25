#include <iostream>
#include <vector>
using namespace std;

bool es_palindrom(string s) {
	int n = s.size();
	for (int i = 0; i < n/2; ++i) {
		if (s[i] != s[n-1-i]) return false;
	}
	return true;
}

int main() {
	int num;
	cin >> num;
	while (num != 0) {
		vector <string> v(num);
		for (int i = 0; i < num; ++i) cin >> v[i];
		
		int max = 0;
		for (int i = 0; i < num; ++i) {
			if (es_palindrom(v[i]) and v[i].size() > max) max = v[i].size();
		}
		cout << "-----" << endl;
		bool trobat = false;
		for (int i = 0; i < num; ++i) {
			if (es_palindrom(v[i]) and v[i].size() == max) {
				cout << v[i] << endl;
				trobat = true;
			}
		}
		if (not trobat) cout << "cap palindrom" << endl;
		cin >> num;
	}
	cout << "-----" << endl;
}
