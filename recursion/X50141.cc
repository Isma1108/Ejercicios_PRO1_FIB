#include <iostream>
using namespace std;

int engreixa(int x) {
	if (x < 9) return x;
	else return engreixa(x/10)*10 + max(engreixa(x/10)%10, x%10);
}

int main() {
	int num;
	while(cin >> num) cout << engreixa(num) << endl;
}
