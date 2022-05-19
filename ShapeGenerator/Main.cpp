#include "SFML/Graphics.hpp"
#include <math.h>
#include "MiddleAverageFilter.h"
#include "Menu.h"
#include "ShapeGenerator.h"


constexpr int WINDOW_X = 1100;
constexpr int WINDOW_Y = 800;
constexpr int MAX_BALLS = 300;
constexpr int MIN_BALLS = 100;

Math::MiddleAverageFilter<float, 100> fpscounter;

void draw_fps(sf::RenderWindow& window, float fps)
{
    char c[32];
    snprintf(c, 32, "FPS: %f", fps);
    std::string string(c);
    sf::String str(c);
    window.setTitle(str);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "ball collision demo");
	srand(time(NULL));

	window.setFramerateLimit(60);

    ShapeGenerator Gen;
    Menu menu;

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            auto MenuOutput = menu.MenuInteract(window);
            if (MenuOutput == 1)
            {
                Gen.GenTriangle();
            }
            else if (MenuOutput == 2)
            {
                Gen.GenBall();
            }
            else if (MenuOutput == 3)
            {
                Gen.GenRectangle();
            }


        }

        window.clear(Color::White);

        menu.MenuDraw(window);



        
        Gen.moveShapes();
        Gen.drawTriangle(window);
        Gen.drawBall(window);
        Gen.drawRectangle(window);

        draw_fps(window, fpscounter.getAverage());
        window.display();
    }





	return 0;
}