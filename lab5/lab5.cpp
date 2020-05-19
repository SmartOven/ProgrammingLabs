#include "lab5.h"
#include "lab5_exep.h"
#include <iostream>
#include <vector>

// function ArrayMax
// =====================================================
template <class T>
T ArrayMax(std::vector <T> arr) {
	try {
		if (arr.empty())
			throw "Array is empty: ";
		T max = arr[0];
		for (auto& i : arr)
			if (i > max)
				max = i;
		return max;
	}
	catch (const char* e) {
		std::cout << e;
		return static_cast<T>(0);
	}
};
// class Matrix
// =====================================================
template <class T>
Matrix<T>::Matrix(int n, int m) {
	this->data_.assign(n, std::vector <T>(m));
};
template <class T>
Matrix<T>::Matrix(std::vector <std::vector <T>> v) {
	this->data_ = v;
};
template <class T>
T Matrix<T>::operator()(T i, T j) {
	if (i < 0 || i > this->data_.size())
		throw ExistExeption();
	if (j < 0 || j > this->data_[i].size())
		throw ExistExeption();
	return this->data_[i][j];
};
template <class T>
std::vector <T> Matrix<T>::operator()(T i) {
	if (i < 0 || i > this->data_.size())
		throw ExistExeption();
	return this->data_[i];
};
