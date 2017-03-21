#pragma once
#define _HEADER_H_

#include <cmath>
using namespace std;

const double PI = atan(1.0) * 4;

double degree(const double radian)
{
	return ((180 / PI)*radian);
}

double radian(const double degree)
{
	return ((PI / 180)*degree);
}

template<typename T>
class Polygon
{
protected:
	int sides;
	T radius;
public:
	Polygon() : sides(3), radius(0) {};
	Polygon(const int sides, const T radius) : sides(sides), radius(radius) {};
	double angle() { return (360.0 / sides); }
	double length();
	double apofema();
	double perimeter();
	double area();
	double diagonal();
};

template<typename T>
class Prism : protected Polygon<T>
{
private:
	T hight;
public:
	Prism() :  hight(0) {}
	Prism(const int sides, const T radius, const T hight) : Polygon<T>(sides, radius), hight(hight) {};
	double area();
	double volume();
	double diagonal();
};

template<typename T>
inline double Polygon<T>::length()
{
	return (radius * 2 * sin(radian(180.0 / sides)));
}

template<typename T>
inline double Polygon<T>::apofema()
{
	return (sqrt(pow(radius, 2) - pow((length() / 2), 2)));
}

template<typename T>
inline double Polygon<T>::perimeter()
{
	return (sides * length());
}

template<typename T>
inline double Polygon<T>::area()
{
	return ((perimeter() / 2) * apofema());
}

template<typename T>
inline double Polygon<T>::diagonal()
{
	return (sqrt(2 * pow(length(), 2) - 4 * length() * cos(radian(angle()))));
}

template<typename T>
inline double Prism<T>::area()
{
	return (2 * Polygon<T>::area() + Polygon<T>::perimeter() * hight);
}

template<typename T>
inline double Prism<T>::volume()
{
	return (Polygon<T>::area() * hight);
}

template<typename T>
inline double Prism<T>::diagonal()
{
	return (sqrt(pow(Polygon<T>::diagonal(), 2) + pow(hight, 2)));
}

#if !defined(_HEADER_H_)
#include "Header.h"
#endif