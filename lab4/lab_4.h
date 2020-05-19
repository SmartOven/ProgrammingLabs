#pragma once

class BaseCObject {
public:
	virtual const char* classname() = 0;
	virtual unsigned int size() = 0;
}; // класс любого объекта

class GeoFig {
public:
	virtual double square() = 0;
	virtual double perimeter() = 0;
}; // класс геом фигуры

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
}; // адекватно сделанный класс двумерного вектора

class PhysObject {
public:
	virtual double mass() = 0;
	virtual Vector2D massCenter() = 0;
	virtual Vector2D position() = 0;
	// Сравнение по массе
	virtual bool operator== (PhysObject& ob) = 0;
	virtual bool operator< (PhysObject& ob) = 0;
}; // класс физ объекта

class Printable {
public:
	virtual void draw() const = 0;
};

class DialogInitiable {
public:
	virtual void initFromDialog() = 0;
};

class Figure : public BaseCObject, public GeoFig, public PhysObject, public Printable, public DialogInitiable, public Vector2D {
public:
};

class Hexagon : public Figure {
public:
	Hexagon();
	const char* classname() override;
	unsigned int size() override;
	void initFromDialog() override;
	double square() override;
	double perimeter() override;
	double mass() override;
	Vector2D massCenter() override;
	Vector2D position() override;
	bool operator== (PhysObject& ob) override;
	bool operator< (PhysObject& ob) override;
	void draw() const override;
private:
	const char* _classname = "Hexagon";
	Vector2D v[6];
	Vector2D pos;
	Vector2D mass_center;
	double Si[6] = {};
	double S = 0, P = 0;
	double _mass = 0;
	unsigned int _size = 0;
};

class Ellipse : public Figure {
public:
	Ellipse();
	const char* classname() override;
	unsigned int size() override;
	void initFromDialog() override;
	double square() override;
	double perimeter() override;
	double mass() override;
	Vector2D massCenter() override;
	Vector2D position() override;
	bool operator== (PhysObject& ob) override;
	bool operator< (PhysObject& ob) override;
	void draw() const override;
private:
	const char* _classname = "Ellipse";
	Vector2D v[6];
	Vector2D pos;
	Vector2D mass_center;
	double l_a = 0, l_b = 0;
	double S = 0, P = 0;
	double _mass = 0;
	unsigned int _size = 0;
};