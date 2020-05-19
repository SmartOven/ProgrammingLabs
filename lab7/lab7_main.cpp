#include <iostream>
#include "lab7.h"
using std::cin;
using std::cout;

int main() {
	CircleBuffer <int> v = { 1, 2, 3, 4 };
	CircleBuffer <int>::iterator it = v.begin();
	for (; it != v.end(); ++it) {
		cout << *it << ' ';
	}
    return 0;
}