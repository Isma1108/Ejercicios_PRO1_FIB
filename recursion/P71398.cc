#include <iostream>
using namespace std;

void digit_maxim_i_minim(int n, int& maxim, int& minim) {
	if (n < 10) {
		maxim = n;
		minim = n;
	}
	else {
		digit_maxim_i_minim(n/10, maxim, minim);
		if (n%10 > maxim) maxim = n%10;
		if (n%10 < minim) minim = n%10;
	}
}

int main() {
	int num, max, min;
	cin >> num;
	digit_maxim_i_minim(num, max, min);
	cout << max << ' ' << min << endl;
}
