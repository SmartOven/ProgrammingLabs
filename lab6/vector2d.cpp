#include "vector2d.h"
#include <cmath>
#include <iostream>

// class Vector2D
// ======================================================================================
Vector2D::Vector2D(double x, double y) {
	this->x = x;
	this->y = y;
};
Vector2D::Vector2D() = default;
Vector2D::Vector2D(double x) {
	this->x = x;
	this->y = x;
};
double Vector2D::len() const {
	return sqrt(this->x * this->x + this->y * this->y);
};
void Vector2D::print() const {
	std::cout << this->x << ' ' << this->y << "\n";
};
Vector2D Vector2D::operator- (Vector2D & v) const {
	const Vector2D result(v.x - this->x, v.y - this->y);
	return result;
};
Vector2D Vector2D::operator+(Vector2D & v) const {
	const Vector2D result(v.x + this->x, v.y + this->y);
	return result;
};
Vector2D Vector2D::operator+=(Vector2D & v) const {
	const Vector2D result(v.x + this->x, v.y + this->y);
	return result;
};
Vector2D Vector2D::operator/=(double v) const {
	const Vector2D result(this->x / v, this->y / v);
	return result;
};
Vector2D Vector2D::operator/(double v) const {
	const Vector2D result(this->x / v, this->y / v);
	return result;
};
Vector2D Vector2D::operator*(double v) const {
	const Vector2D result(this->x * v, this->y * v);
	return result;
};
bool Vector2D::operator==(Vector2D v2) const {
	return (this->x == v2.x && this->y == v2.y);
};
bool Vector2D::operator<(int x) const {
	return (this->len() < x);
};
bool Vector2D::operator>(int x) const {
	return (this->len() > x);
};