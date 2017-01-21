#pragma once

#ifndef _HEADER_H_
#define _HEADER_H_

#include <SFML/Graphics.hpp>

using namespace sf;

class Point
{
private:
	int x, y;
public:
	Point();
	Point(int _x, int _y);
	Vector2f Coord() const;
};

class Triangl : public Point
{
private:
	Point b, c;
public:
	Triangl(int xa, int ya, int xb, int yb, int xc, int yc);
	ConvexShape TrGet() const;
};

#endif // !_HEADER_H_

