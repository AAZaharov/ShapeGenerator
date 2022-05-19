#include "Menu.h"

Menu::Menu()
{
	
	font.loadFromFile("CyrilicOld.ttf");

	Button1 = Text("Triange", font, 40);
	Button1.setPosition(900, 200);
	Button2 = Text("Circle", font, 40);
	Button2.setPosition(900, 300);
	Button3 = Text("Convex", font, 40);
	Button3.setPosition(900, 400);
}


short Menu::MenuInteract(RenderWindow&app)
{
	Button1.setFillColor(Color::Black);
	Button2.setFillColor(Color::Black);
	Button3.setFillColor(Color::Black);
	int MenuIvent = 0;

	if (IntRect(900, 200, 140, 50).contains(Mouse::getPosition(app))) {
		Button1.setFillColor(Color::Blue); 
		MenuIvent = 1;
	}
	if (IntRect(900, 300, 140, 50).contains(Mouse::getPosition(app))) {
		Button2.setFillColor(Color::Blue); 
		MenuIvent = 2;
	}
	if (IntRect(900, 400, 140, 50).contains(Mouse::getPosition(app))) {
		Button3.setFillColor(Color::Blue); 
		MenuIvent = 3;
	}

	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (MenuIvent == 1) { return 1; }
		else if (MenuIvent == 2) { return 2; }
		else if (MenuIvent == 3) { return 3; }
	}

	return 0;
}

void Menu::MenuDraw(RenderWindow&app)
{
	app.draw(Button1);
	app.draw(Button2);
	app.draw(Button3);

}
