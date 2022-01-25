#include <iostream>
#include <vector>
using namespace std;

vector<bool> pos_rampas(const vector<int>& V) {
	vector<bool> rampes(V.size(), false);
	int n = V.size() - 2;
	for (int i = 0; i < n; ++i) {
		if (V[i] > V[i+1] and V[i+1] > V[i+2]) rampes[i] = true;
		else if (V[i] < V[i+1] and V[i+1] < V[i+2]) rampes[i] = true;
	}
	return rampes;
}

int pos_conflictives(const vector<bool>& B) {
	int total = 0;
	for (int i = 0; i < B.size() - 3; ++i) {
		if (B[i] and B[i+1]) ++total;
		if (B[i] and B[i+2]) ++total;
	}
	return total;
}

int main() {
	int n;
	while (cin >> n) {
		vector<int> vect(n);
		vector<bool> rampes(n);
		for (int i = 0; i < n; ++i) cin >> vect[i];
		rampes = pos_rampas(vect);
		cout << "posicions amb rampa:";
		for (int i = 0; i < n; ++i) {
			if (rampes[i]) cout << ' ' << i;
		}
		cout << endl << "potencialment conflictives: " << pos_conflictives(rampes);
		cout << endl << "---" << endl;
	}
}
