#pragma once

#ifndef _HEADER_H_
#define _HEADER_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

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

class Name_autor
{
private:
	std::string Name;
public:
	Name_autor(const std::string name);
	void NaText(RenderWindow& w);
};

class Triangl : public Name_autor, public Point
{
private:
	Point b, c;
public:
	Triangl(int xa, int ya, int xb, int yb, int xc, int yc, std::string name);
	ConvexShape TrGet() const;
};

#endif // !_HEADER_H_

