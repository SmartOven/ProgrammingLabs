#pragma once

class Vector2D {
public:
	double x = 0, y = 0;
	Vector2D(double x, double y);
	explicit Vector2D(double x);
	Vector2D();
	double len() const;
	void print() const;
	Vector2D operator- (Vector2D& v) const;
	Vector2D operator+ (Vector2D& v) const;
	Vector2D operator+= (Vector2D& v) const;
	Vector2D operator/= (double v) const;
	Vector2D operator/ (double v) const;
	Vector2D operator* (double v) const;
	bool operator== (Vector2D v2) const;
	bool operator< (int x) const;
	bool operator> (int x) const;
}; // адекватно сделанный класс двумерного вектора