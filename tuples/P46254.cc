#include <iostream>
#include <cmath>
using namespace std;

struct Punt {
	double x, y;
};

double distancia(const Punt& a, const Punt& b) {
	double x = (b.x - a.x)*(b.x - a.x);
	double y = (b.y - a.y)*(b.y - a.y);
	return sqrt(x + y);
}
