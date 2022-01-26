#include <iostream>
#include <vector>
using namespace std;

struct Estudiant {
	int dni;
	string nom;
	double nota;
	bool repetidor;
};

void informacio(const vector<Estudiant>& es, double& min, double& max, double& mitj) {
	int n = es.size();
	min = -1.0;
	max = -1.0;
	mitj = 0.0;
	int total = 0;
	bool first = true;
	for (int i = 0; i < n; ++i) {
		if (not es[i].repetidor and es[i].nota != -1.0) {
			if (es[i].nota > max) max = es[i].nota;
			mitj += es[i].nota;
			if (first) {
				min = es[i].nota;
				first = false;
			}
			else {
				if (es[i].nota < min) min = es[i].nota;
			}
			++total;
		}
	}
	if (first) mitj = -1;
	else mitj /= total;
}
