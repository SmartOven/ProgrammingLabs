#include <vector>
#include <list>
#include "vector2d.h"
#include "lab6.h"

#include <iostream>
using std::cout;

template <class T>
bool predicate(T x) {
	return (x > 0 && x < 1234);
}

int32_t main() {
	// Создаем переменные пользовательского типа данных
	const Vector2D vec1(1, 1); // len = sqrt(2)
	const Vector2D vec2(3, 4); // len = 5
	const Vector2D vec3(2); // len = 4
	const Vector2D vec4; // len = 0

	// Создаем контейнеры
	std::vector <int> v1 = {1, 2, 3, 4, 5};
	std::vector <double> v2 = {1.6, 2.0, 3.8, 4.4, 5.7}; // can you guess the cars with the same engine volume?
	std::list <float> l1 = { 0.0, -1.0, 3.0, 1234.0, 1235.0 };
	std::list <Vector2D> l2 = { vec1, vec2, vec3, vec4 };

	// Пробуем вызвать пользовательские функции
	// all_of
	cout << all_of(v1.begin(), v1.end(), predicate <int>) << "\n"; // [](int x) {return (0 < x && x < 1234);}
	cout << all_of(v2.begin(), v2.end(), predicate <double>) << "\n";
	cout << all_of(l1.begin(), l1.end(), predicate <float>) << "\n";
	cout << all_of(l2.begin(), l2.end(), predicate <Vector2D>) << "\n";

	// one_of
	cout << one_of(v1.begin(), v1.end(), predicate <int>) << "\n";
	cout << one_of(v2.begin(), v2.end(), predicate <double>) << "\n";
	cout << one_of(l1.begin(), l1.end(), predicate <float>) << "\n";
	cout << one_of(l2.begin(), l2.end(), predicate <Vector2D>) << "\n";

	// find_backward
	const auto ind1 = find_backward(v1.rbegin(), v1.rend(), 2);
	cout << (*ind1 == 2 ? "True" : "False") << "\n";
	
	const auto ind2 = find_backward(v2.rbegin(), v2.rend(), 2.0);
	cout << (*ind2 == 2.0 ? "True" : "False") << "\n";
	
	const auto ind3 = find_backward(l1.rbegin(), l1.rend(), 2.2);
	cout << (*ind3 == 2.2 ? "True" : "False") << "\n";

	const auto ind4 = find_backward(l2.rbegin(), l2.rend(), vec2);
	cout << (*ind4 == vec2 ? "True" : "False") << "\n";
	return 0;
}