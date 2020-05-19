#include <iostream>
#include <algorithm>
#include "lab7.h"
using std::cin;
using std::cout;

template <class T>
void print_info(const CircleBuffer<T>& v) {
    static int COUNT = 1;
    cout << "Op. number: " << COUNT << "\n";
    cout << "Capacity: " << v.capacity() << "\n";
    cout << "Size: " << v.size() << "\n";
    cout << "Items: ";
    for (auto it : v) {
        cout << it << ' ';
    }
    cout << "\n";
    cout << "\n";
    COUNT++;
}

int main() {
	CircleBuffer <int> v(3);
	v.push_back(1);
	v.push_back(3);
    print_info(v); // 1

    v.push_back(2);
    print_info(v); // 2

	v.push_back(5);
    print_info(v); // 3

    v.resize(5);
    print_info(v); // 4

    v.insert(1, -1);
    print_info(v); // 5

    v.push_back(-2);
    print_info(v); // 6

    v.remove(2);
    print_info(v); // 7

    v.resize(2);
    print_info(v); // 8

    v.pop_back();
    print_info(v); // 9

    v.push_front(2);
    print_info(v); // 10

    v.push_front(1);
    print_info(v); // 11

    v.pop_front();
    print_info(v); // 12

    v.push_front(3);
    print_info(v); // 13

    v.insert(v.begin(), -10);
    print_info(v); // 14

    v = {1, 2, 4, 5, 3};
    print_info(v); // 15

    std::sort(v.begin(), v.end());
    print_info(v); // 16
    return 0;
}