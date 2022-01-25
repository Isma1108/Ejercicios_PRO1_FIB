#include <iostream>
#include <vector>
using namespace std;

bool existeix_parell(const vector<int>& v) {
	int n = v.size();
	bool parell = false, senar = false;
	for (int i = 0; i < n; ++i) {
		if (v[i]%2 == 0) parell = true;
		else if (v[i]%2 != 0) senar = true;
	}
	if (parell and senar) return true;
	else return false;

}

int main() {
	int num;
	while (cin >> num) {
		vector<int> v(num);
		for (int i = 0; i < num; ++i) cin >> v[i];
		if (existeix_parell(v)) cout << "si" << endl;
		else cout << "no" << endl;
	}
}
