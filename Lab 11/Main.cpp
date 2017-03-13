#include "Header.h"
#include <sstream>
#include <iomanip>

int main()
{
	RenderWindow window(sf::VideoMode(800, 550), "Lab 11");

	IsoscelesTrapezoid Trapeze(150, 150, 100, 180, 100);
	Font font;
	font.loadFromFile("impact.ttf");
	
	std::stringstream res;
	res << std::fixed << std::setprecision(2) << Trapeze.area();
	std::string area = "S = " + res.str();

	Text text(area, font, 20);
	text.setFillColor(Color::Black);
	text.setPosition(Vector2f(650, 10));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear(Color(200, 200, 200, 255));
		Trapeze.draw(window);
		window.draw(text);
		window.display();
	}

	return 0;
}