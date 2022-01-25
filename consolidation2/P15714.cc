#include <iostream>
using namespace std;

int main() {
	char c = '-';
	int curtes = 0, mitjanes = 0, llargues = 0, longitud = 0;
	while (c!= '.') {
		cin >> c;
		if (c >= 'a' and c <= 'z') ++longitud;
		else {
			if (longitud > 9) ++llargues;
			else if (longitud > 4) ++mitjanes;
			else if (longitud > 0) ++curtes;
			longitud = 0;
		}
	}	
	cout << curtes << ',' << mitjanes << ',' << llargues << endl;
}
