#include <iostream>
using namespace std;

void conversio(int num, int base) {
	if (num < base) {
		if(base != 16) cout << num;
		else if (num%base > 9) cout << char('A' + (num%base - 10));
		else cout << num%base;
	}
	else {
		conversio(num/base, base);
		if (base != 16) cout << num%base;
		else if (num%base > 9) cout << char('A' + (num%base - 10));
		else cout << num%base;
	}
}
int main() {
	int n;
	while (cin >> n) {	
		cout << n << " = " ;
		conversio(n, 2);
		cout << ", ";
		conversio(n, 8);	
		cout << ", ";
		conversio(n, 16); 
		cout << endl;
	}
}
