#include <iostream>
using namespace std;

int main() {
	char c;
	int total = 0;
	while (cin >> c) {
		if (c == 'a' or c == 'e') ++total;
		else if (c == 'o' or c == 's') total += 2;
		else if (c == 'd' or c == 'i' or c == 'n' or c == 'r') total += 3;
		else if (c == 'c' or c == 'l' or c == 't' or c == 'u') total += 4;
		else if (c == 'm' or c == 'p') total += 5;
		else if (c == 'b' or c == 'f' or c == 'g' or c == 'h' or c == 'j') total += 6;
		else if (c == 'q' or c == 'v' or c == 'x' or c == 'y' or c == 'z') total += 6;
		else if (c == 'k' or c == 'w') total += 7;
	}
	cout << total << endl;
}
