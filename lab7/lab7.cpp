#include "lab7.h"

// ������ ������ CircleBuffer<T>::iterator
template <class T> // ������� ����������� ��� �������� ��������� � ������ �������
CircleBuffer<T>::iterator::iterator(T* start) {
    _data = start;
}
template <class T> // ����������� ��� �������� �����������
CircleBuffer<T>::iterator::iterator(const iterator& src) {
    _data = src._data;
}
template <class T> // ��������������� ���������
T& CircleBuffer<T>::iterator::operator*() {
    return *(_data);
}
template <class T> // ��������� ������ �� ���������
T* CircleBuffer<T>::iterator::operator->() {
    return _data;
}

// ��������� �������� � ���������
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
// end ��������� �������� � ���������

// ��������� ���������
template <class T>
bool CircleBuffer<T>::iterator::operator==(const iterator& other) const {
    return _data == other._data;
}
template <class T> // �����
bool CircleBuffer<T>::iterator::operator!=(const iterator& other) const {
    return _data != other._data;
}
// end ��������� ���������