#include <iostream>
#include <vector>
using namespace std;

bool es_palindrom(const string& s) {
	int n = s.size();
	for (int i = 0; i < n/2; ++i) {
		if (s[i] != s[n - 1 - i]) return false;
	}
	return true;
}
