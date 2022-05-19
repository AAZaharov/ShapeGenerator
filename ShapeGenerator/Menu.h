#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class Menu
{
public:

	Menu();

	short MenuInteract(RenderWindow&);

	void MenuDraw(RenderWindow&);

private:

	Font font;
	
	Text Button1, Button2, Button3;
	


};

//Text text(s, font, 40);
//text.setFillColor(Color::Black);
//
//text.setStyle(sf::Text::Bold);
//text.setPosition(f.p1);
//text.move(20, 20);
//
//app.draw(text);