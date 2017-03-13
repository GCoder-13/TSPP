#pragma once
#define _HEADER_H_

#include <SFML/Graphics.hpp>
using namespace sf;

class Point
{
protected:
	int x, y;
public:
	Point() : x(0), y(0) {};
	Point(const int _x, const int _y) : x(_x), y(_y) {};
	operator Vector2f() const;
	virtual void draw(RenderWindow &w) const = 0;
	virtual void move() = 0;
	virtual double area() = 0;
};

class Rectangle
{
protected:
	double width, hight;
public:
	Rectangle() : width(0.f), hight(0.f) {};
	Rectangle(const double _width, const double _hight) :  width(_width), hight(_hight) {};
	double area();
};

class RectangularTriangle
{
protected:
	double leg1, leg2;
public:
	RectangularTriangle() : leg1(0.f), leg2(0.f) {};
	RectangularTriangle(const double _leg1, const double _leg2) : leg1(_leg1), leg2(_leg2) {};
	double area();
};

class IsoscelesTrapezoid : public Point, public Rectangle, public RectangularTriangle
{
protected:
	double baseDown;
public:
	IsoscelesTrapezoid() : baseDown(0.f) {};
	IsoscelesTrapezoid(const int x, const int y, const double baseTop, const double baseDown, const double hight) :
		Point(x, y), Rectangle(baseTop, hight), RectangularTriangle(hight, ((baseDown - baseTop) / 2)), baseDown(baseDown) {};
	virtual void draw(RenderWindow &w) const;
	virtual void move();
	virtual double area();
};

#if !defined(_HEADER_H_)
#include "Header.h"
#endif // !defined(_HEADER_H_)
