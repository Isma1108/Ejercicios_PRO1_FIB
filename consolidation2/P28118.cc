#include <iostream>
#include <cmath>
using namespace std;

double distancia(double x1, double y1, double x2, double y2) {
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main() {
	cout.setf(ios::fixed);
	cout.precision(4);
	string trajecte;
	while (cin >> trajecte) {
		double total = 0;
		double x1, y1, x2, y2, xb, yb;
		cin >> xb >> yb >> x2 >> y2;
		x1 = xb; 
		y1 = yb;
		while (x2 != xb or y2 != yb) {
			total += distancia(x1,y1,x2,y2);
			x1 = x2;
			y1 = y2;
			cin >> x2 >> y2;
		}
		total += distancia (x1, y1, x2, y2);
		cout << "Trajecte " << trajecte << ": " << total << endl;
	}
}
