#include <iostream>
#include <vector>
using namespace std;

vector<double> diferencia(const vector<double>& v1, const vector<double>& v2) {
	//A l'hora de crear el vector considero el cas extrem:
	int n1 = v1.size();
	int n2 = v2.size();
	vector<double> aux(n1);
	int i, j, k;
	i = j = k = 0;
	while (i < n1 and j < n2) {
		if (v1[i] < v2[j]) {
			if (k == 0 or v1[i] != aux[k-1]) {
				aux[k] = v1[i];
				++k;
			}
			++i;
		}
		else if (v1[i] > v2[j]) ++j;
		else ++i;
	}
	while (i < n1) {
		if (k == 0 or aux[k-1] != v1[i]) {
			aux[k] = v1[i];
			++k;
		}
		++i;
	}
	vector<double> dif(k);
	for (int m = 0; m < k; ++m) dif[m] = aux[m];
	return dif;
}
