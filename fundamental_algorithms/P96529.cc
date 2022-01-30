#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool es_correcte(const string& p) {
	vector<char> v;
	int n = p.size();
	int i = 0;
	while (i < n) {
		if (p[i] == '[' or p[i] == '(') v.push_back(p[i]);
		else {
			int m = v.size() - 1;
			if (m >= 0) {
				if ((p[i] == ']' and v[m] != '[') or (p[i] == ')' and v[m] != '(')) {
					return false;
				}
				else v.pop_back();
			}
			else return false;
		}
		++i;
	}
	return v.size() == 0;
}

int main() {
	string p;
	while (cin >> p) {
		if (es_correcte(p)) cout << "si" << endl;
		else cout << "no" << endl;
	}
}
