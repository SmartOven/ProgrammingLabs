#include <iostream>
#include "proga_2.h"

int main() {
	Polinom p(1, 2, 1);
	p.print();
	p.howmuch();
	p.solve();
	p.dydx();
	p.fx(15.0);
	return 0;
}