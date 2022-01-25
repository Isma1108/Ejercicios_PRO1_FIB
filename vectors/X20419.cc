#include <iostream>
#include <vector>
using namespace std;

const int LONG_ALFABET = 'z'-'a' + 1;

char lletra_mes_frequent(const string& s) {
	vector<int> alfabet(LONG_ALFABET, 0);
	for (int i = 0; i < s.size(); ++i) {
		++alfabet[s[i] - 'a'];
	}
	int max = 0;
	for (int i = 0; i < alfabet.size(); ++i) {
		if (alfabet[i] > alfabet[max]) max = i;
	}
	return char(max + 'a');
}


int main() {
	cout.setf(ios::fixed);
	cout.precision(2);
	int n, total = 0;
	cin >> n;
	vector<string> paraules(n);
	for (int i = 0; i < n; ++i) cin >> paraules[i];
	for (int i = 0; i < n; ++i) total += paraules[i].size();
	cout << total/double(n) << endl;
	for (int i = 0; i < n; ++i) {
		if (paraules[i].size() >= total/double(n)) {
			cout << paraules[i] << ": " << lletra_mes_frequent(paraules[i]) << endl; 
		}
	}
}
