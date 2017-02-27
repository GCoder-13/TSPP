#include "Header.h"

Point::Point(): x(0), y(0) {}

Point::Point(int _x, int _y) : x(_x), y(_y) {}

Vector2f Point::Coord() const
{
	return Vector2f(x,y);
}

Triangl::Triangl(int xa, int ya, int xb, int yb, int xc, int yc, std::string name) : Point(xa, ya), b(xb, yb), c(xc, yc), Name_autor(name) {}

ConvexShape Triangl::TrGet() const
{
	ConvexShape Tr(3);
	Tr.setPoint(0, Coord());
	Tr.setPoint(1, b.Coord());
	Tr.setPoint(2, c.Coord());
	Tr.setFillColor(Color::Red);
	return Tr;
}

Name_autor::Name_autor(const std::string name) : Name(name) {}

void Name_autor::NaText(RenderWindow& w)
{
	Font font;
	font.loadFromFile("impact.ttf");
	Text autor(Name, font, 20);
	autor.setFillColor(Color::Black);
	autor.setPosition(Vector2f(500, 5));
	w.draw(autor);
}
