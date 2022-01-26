#include <iostream>
#include <vector>
using namespace std;

struct Punt {
	double x, y;
};
bool prop1(const vector <Punt>&v) {
	int count = 0;
	for (int i = 0; i < v.size()-1; ++i) {
		if (v[i].x != v[i+1].x or v[i].y != v[i+1].y) ++count;
	}
	if (count > 1) return true;
	else return false;
}
bool prop2(const vector <Punt>&v) {
	Punt p;
	p.x = 0;
	p.y = 0;
	for (int i = 0; i < v.size(); ++i) {
		p.x = p.x+v[i].x;
		p.y = p.y+v[i].y;
	}
	if (p.x == p.y) return true;
	else return false;
}
bool baricentre(const vector <Punt>& v, Punt& b) {
	int n = v.size();
	for (int i = 0; i < n; ++i) {
		if (v[i].x == b.x and v[i].y == b.y) return false;
	}
	return true;
}
int main() {
	cout.setf(ios::fixed);
	cout.precision(2);
	int n;
	while (cin >> n) {
		vector <Punt>v(n);
		Punt b;
		b.x = 0;
		b.y = 0;
		for (int i = 0; i < n; ++i) {
			cin >> v[i].x >> v[i].y;
			b.x = b.x+v[i].x;
			b.y = b.y+v[i].y;
		}
		Punt bar;
		bar.x = b.x / n;
		bar.y = b.y / n;
		cout << "baricentre: (" << bar.x << "," << bar.y << ")" << endl;
		if (not prop1(v)) cout << "el vector no compleix la propietat 1" << endl;
		else {
			if (not prop2(v)) cout << "el vector no compleix la propietat 2" << endl;
			else {
				if (not baricentre(v, bar)) cout << "el vector no compleix la propietat 3" << endl;
				else {
					cout << "vector normalitzat" << endl;
				}
			}
		}
	}
}
