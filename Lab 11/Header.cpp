#include "Header.h"

Point::operator Vector2f() const
{
	return Vector2f(x, y);
}

double Rectangle::area()
{
	return (width * hight);
}

double RectangularTriangle::area()
{
	return ((leg1*leg2) / 2);
}

void IsoscelesTrapezoid::draw(RenderWindow & w) const
{
	ConvexShape tr;
	tr.setFillColor(Color::Red);
	tr.setPointCount(4);
	tr.setPoint(0, Vector2f(x - leg2, y + hight));
	tr.setPoint(1, Vector2f(x, y));
	tr.setPoint(2, Vector2f(x + width, y));
	tr.setPoint(3, Vector2f(x + baseDown - leg2, y + hight));
	w.draw(tr);
}

double IsoscelesTrapezoid::area()
{
	return (Rectangle::area() + (2 * RectangularTriangle::area()));
}
