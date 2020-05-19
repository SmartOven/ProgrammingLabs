#pragma once
#include <vector>

template <class T>
T ArrayMax(std::vector<T> arr);

template <class T>
class Matrix {
public:
	Matrix(int n, int m);
	Matrix(std::vector <std:: vector <T>> v);
	T operator() (T i, T j);
	std::vector <T> operator() (T i);
private:
	std::vector <std::vector <T>> data_;
};