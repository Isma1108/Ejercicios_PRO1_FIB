#include <iostream>
#include <vector>
using namespace std;

string sortida(int p, vector<int>& v) {
	int n = v.size();
	int aux;
	while (v[p] != 0 and 0 <= p+v[p] and p+v[p] < n) {
		aux = p;
		p = p+v[p];
		v[aux] = 0;
	}
	if (v[p] == 0) return "mai";
	else if (p+v[p] < 0) return "esquerra";
	else return "dreta";
}
