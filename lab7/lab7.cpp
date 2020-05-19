#include "lab7.h"

// Методы класса CircleBuffer<T>::iterator
template <class T> // Скрытый конструктор для создания итератора в классе буффера
CircleBuffer<T>::iterator::iterator(T* start) {
    _data = start;
}
template <class T> // Конструктор для неявного копирования
CircleBuffer<T>::iterator::iterator(const iterator& src) {
    _data = src._data;
}
template <class T> // Разыменовывание указателя
T& CircleBuffer<T>::iterator::operator*() {
    return *(_data);
}
template <class T> // Получение данных по указателю
T* CircleBuffer<T>::iterator::operator->() {
    return _data;
}

// Операторы сложения и вычитания
template <class T>
typename CircleBuffer<T>::iterator CircleBuffer<T>::iterator::operator++() {
    ++_data;
    return *this;
}
template <class T>
typename CircleBuffer<T>::iterator CircleBuffer<T>::iterator::operator++(int) {
    ++_data;
    return *this;
}
template <class T>
T* CircleBuffer<T>::iterator::operator--() {
    --_data;
    return *this;
}
template <class T>
typename CircleBuffer<T>::iterator CircleBuffer<T>::iterator::operator+(int x) {
    _data = _data + x;
    return *this;
}
template <class T>
typename CircleBuffer<T>::iterator CircleBuffer<T>::iterator::operator-(int x) const {
    _data = _data - x;
    return *this;
}
// end Операторы сложения и вычитания

// Операторы сравнения
template <class T>
bool CircleBuffer<T>::iterator::operator==(const iterator& other) const {
    return _data == other._data;
}
template <class T> // готов
bool CircleBuffer<T>::iterator::operator!=(const iterator& other) const {
    return _data != other._data;
}
// end Операторы сравнения