#include <iostream>
#include <vector>
using namespace std;

int main() {
	char c;
	while (cin >> c) {
		int pos_isbn = 10;
		int total = 0;
		if (c != '?') total += 10*(c-'0');
		for (int i = 1; i < 10; ++i) {
			cin >> c;
			if(c == '?') pos_isbn = 10-i;
			else if (c >= '0' and c <= '9') total += (c-'0')*(10-i);
			else total += 10;
		}
		int n = 0;
		bool trobat = false;
		while (n <= 10 and not trobat) {
			if ((total + n*(pos_isbn))%11 == 0) trobat = true;
			else ++n;
		}
		if (n == 10) cout << 'X' << endl;
		else cout << n << endl;
	}
}
