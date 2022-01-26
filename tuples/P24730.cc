#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Profe {
	string name;
	int c, p;
};

typedef vector<Profe> Profes;

Profes llegeix(int m) {
	Profes profes(m);
	for (int i = 0; i < m; ++i) {
		cin >> profes[i].name >> profes[i].c >> profes[i].p;
	}
	return profes;
}

bool cmp(const Profe& a, const Profe& b) {
	if (a.c != b.c) return a.c > b.c;
	if (a.p != b.p) return a.p > b.p;
	if (a.name.size() != b.name.size()) return a.name.size() < b.name.size();
	return a.name < b.name;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int m; 
		cin >> m;
		Profes profes = llegeix(m);
		sort(profes.begin(), profes.end(), cmp);
		for (int j = 0; j < m; ++j) cout << profes[j].name << endl;
		cout << endl;
	}
}
