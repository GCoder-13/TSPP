#include "Header.h"

int main()
{
	RenderWindow window(VideoMode(200, 200), "SFML works!");

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(/*...*/);
		window.display();
	}

	return 0;
}