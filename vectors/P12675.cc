#include <iostream>
#include <vector>
using namespace std;

int elements_comuns(const vector<int>& X, const vector<int>& Y) {
	int i, j, total;
	i = j = total = 0;

	while (i < X.size() and j < Y.size()) {
		if (X[i] < Y[j]) ++i;
		else if (X[i] > Y[j]) ++j;
		else {
			++i;
			++j;
			++total;
		}
	}
	return total;
}
