#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int x, y, anty, shx, shy, c;
	ifstream odczyt("prog.cfg");
	odczyt >> x >> y >> anty >>shx >>shy>>c;
	cout << "cfg=" << endl << "window.x=" << x<<endl << "window.y=" << y <<
	endl<< "antialiasingLevel=" << anty<<endl<<"shape.x="<<shx<<endl<<"shape.y="<<shy<<endl<<"color="<<c<<endl;
	sf::RenderWindow window(sf::VideoMode(x, y), "wolking shape by GRATHRRAM");
	sf::RectangleShape player1(sf::Vector2f(shx, shy));
	if (c == 0)
	{
		player1.setFillColor(sf::Color::Green);
	}
	if (c == 1)
	{
		player1.setFillColor(sf::Color::Blue);
	}
	if (c == 2)
	{
		player1.setFillColor(sf::Color::Red);
	}
	if (c == 3)
	{
		player1.setFillColor(sf::Color::Magenta);
	}
	sf::ContextSettings set;
	set.antialiasingLevel = anty;
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			// left key is pressed: move our character
			player1.move(-1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			// Right key is pressed: move our character
			player1.move(1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			// Up key is pressed: move our character
			player1.move(0.f, -1.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			//down key is pressed: move our character
			player1.move(0.f, 1.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
		
			player1.rotate(-0.5f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			
			player1.rotate(0.5f);
		}
	
		
		window.clear();
		window.draw(player1);
		window.display();
	}
	return 0;
}

