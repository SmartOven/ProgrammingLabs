#include <iostream>
#include "proga_1.h"
using namespace std;

int main() {
	int a = 5, b = 7;
	p_sum(&a, &b); // ¹2
	cout << "Done: " << a << endl;

	a = 5, b = 7;
	l_sum(a, b);
	cout << "Done: " << a << endl;

	float c = 3.14;
	p_func(&c);
	cout << "Done: " << c << endl; // ¹5

	c = 3.14;
	l_func(c);
	cout << "Done: " << c << endl;
	return 0;
}