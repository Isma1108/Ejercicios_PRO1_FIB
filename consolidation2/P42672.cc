#include <iostream>
#include <vector>
using namespace std;

vector<int> base2(int n) {
	vector<int> res;
	while (n != 0) {
		res.push_back(n%2);
		n /= 2;
	}
	return res;
}

int main() {
	int n1, n2;
	while (cin >> n1 >> n2) {
		vector<int> v1;
		vector <int> v2;
		v1 = base2(n1);
		v2 = base2(n2);
		for (int i = v1.size() - 1; i >= 0; --i) {
			cout << v1[i] << v2[i];
		}
		cout << endl;
	}
}
