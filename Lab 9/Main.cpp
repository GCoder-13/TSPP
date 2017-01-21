#include "Header.h"

int main()
{
	RenderWindow window(VideoMode(700, 400), "Lab 9");
	RectangleShape Rt;
	Rt.setSize(Vector2f(700, 400));
	Rt.setFillColor(Color::Cyan);

	const Triangl tr(250,10,30,350,600,250);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(Rt);
		window.draw(tr.TrGet());
		window.display();
	}

	return 0;
}