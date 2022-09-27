#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Kolorowe kolo");
	sf::CircleShape shape(300.f);
	shape.setFillColor(sf::Color::Green);
	string input;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		if (input == "niebieski")
		{
			shape.setFillColor(sf::Color::Blue);
		}
		if (input == "zielony")
		{
			shape.setFillColor(sf::Color::Green);
		}
		if (input == "czerwony")
		{
			shape.setFillColor(sf::Color::Red);
		}
		if (input == "rorzowy")
		{
			shape.setFillColor(sf::Color::Magenta);
		}

		window.clear();
		window.draw(shape);
		window.display();
		cin >> input;
	}
	return 0;
}