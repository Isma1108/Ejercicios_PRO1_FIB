#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Punt {
	int x, y;
};

int abs(int num) {
	if (num < 0) return -num;
	else return num;
}

int distancia(const Punt& p) {
	return abs(p.x) + abs(p.y);
}

bool comparacio(const Punt& a, const Punt& b) {
	int d1 = distancia(a);
	int d2 = distancia(b);
	if (d1 != d2) return d1 < d2;
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

int main() {
	int x, y, n;
	cin >> x >> y >> n;
	vector<Punt> v(n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		v[i].x = a - x;
		v[i].y = b - y;
	}
	sort(v.begin(), v.end(), comparacio);
	int d_ant = -1;
	for (int i = 0; i < n; ++i) {
		int d = distancia(v[i]);
		if (d > d_ant) {
			cout << "punts a distancia " << d << endl;
			d_ant = d;
		}
		cout << v[i].x + x << ' ' << v[i].y + y << endl;
	}
}
