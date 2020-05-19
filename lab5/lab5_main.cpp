#include <iostream>
#include <vector>
#include "lab5.h"
using std::cout;

int main() {
	std::vector <std::vector <int>> v = { {1, 2}, {3, 4} };
	Matrix <int> M1(v);
	Matrix <double> M2(5, 10);
	std::vector <int> m0 = M1(0);
	cout << ArrayMax(M1(0)) << "\n";
}