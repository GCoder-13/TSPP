#include "Header.h"

int main()
{
	RenderWindow window(VideoMode(700, 400), "Lab 9");

	Triangl tr(250,10,30,350,600,250, "Khomutovskiy Andriy");

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear(Color::Cyan);
		window.draw(tr.TrGet());
		tr.NaText(window);
		window.display();
	}

	return 0;
}