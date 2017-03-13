#include <windows.h>
#include <sstream>
#include <iomanip>
#include "Header.h"

int main()
{

	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);

	RenderWindow window(sf::VideoMode(800, 550), "Lab 11");

	IsoscelesTrapezoid Trapeze(150, 150, 130, 250, 100);
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

		window.clear(Color::White);
		Trapeze.draw(window);
		Trapeze.move();
		window.draw(text);
		window.display();
	}

	return 0;
}