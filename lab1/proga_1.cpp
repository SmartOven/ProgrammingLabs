#include <iostream>
#include "proga_1.h"

int main() {
	double a = 3.14;
	float b = 2.71;
	_reverse(a);
	std::cout << "Done: " << a << "\n";
	_reverse(&a);
	std::cout << "Done: " << a << "\n";
	_reverse(b);
	std::cout << "Done: " << b << "\n";
	_reverse(&b);
	std::cout << "Done: " << b << "\n";

	a = 3.14;
	b = 2.71;
	float_int(a);
	std::cout << "Done: " << a << "\n";
	float_int(&a);
	std::cout << "Done: " << a << "\n";
	float_int(b);
	std::cout << "Done: " << b << "\n";
	float_int(&b);
	std::cout << "Done: " << b << "\n";
	return 0;
}