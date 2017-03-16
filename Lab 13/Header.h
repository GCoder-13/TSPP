#pragma once
#define _HEADER_H_

#include <cmath>

template<typename T>
class Polygon
{
protected:
	int nSides;
	T length;
	T apofema;
public:
	Polygon() : nSides(3), length(0), apofema(0) {};
	Polygon(const int nSides, const T length, const T apofema) : nSides(nSides), length(length), apofema(apofema) {};
	T perimeter();
	T area();
	T diagonal();
};

template<typename T>
class Prism : protected Polygon<T>
{
private:
	T hight;
public:
	Prism() :  hight(0) {}
	Prism(const int nSides, const T length, const T apofema, const T hight) : Polygon<T>(nSides, length, apofema), hight(hight) {};
	T area();
	T volume();
	T diagonal();
};

template<typename T>
inline T Polygon<T>::perimeter()
{
	return T(nSides * length);
}

template<typename T>
inline T Polygon<T>::area()
{
	return T((perimeter() / 2) * apofema);
}

template<typename T>
inline T Polygon<T>::diagonal()
{
	return T(sqrt(pow((length / 2), 2) + pow(apofema, 2)));
}

template<typename T>
inline T Prism<T>::area()
{
	return T(2 * Polygon<T>::area() + Polygon<T>::perimeter() * hight);
}

template<typename T>
inline T Prism<T>::volume()
{
	return T(Polygon<T>::area() * hight);
}

template<typename T>
inline T Prism<T>::diagonal()
{
	return T(sqrt(pow(Polygon<T>::diagonal(), 2) + pow(hight, 2)));
}

#if !defined(_HEADER_H_)
#include "Header.h"
#endif