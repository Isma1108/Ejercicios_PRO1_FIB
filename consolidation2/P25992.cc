#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n; 
	while (cin >> n) {
		vector<int> parells;
		vector<int> senars;
		while(n != 0) {
			if (n%2 == 0) parells.push_back(n);
			else senars.push_back(n);
			cin >> n;
		}
		sort(parells.begin(), parells.end());
		sort(senars.begin(), senars.end());
		bool first = true;
		for (int i = 0; i < parells.size(); ++i){
			if (not first) cout << ' ';
			cout << parells[i];
			first = false;
		}
		cout << endl;
		first = true;
		for (int i = senars.size()-1; i >= 0; --i) {
			if (not first) cout << ' ';
			cout << senars[i];
			first = false;
		}
		cout << endl;
	}
}
