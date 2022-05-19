#pragma once
#include "SFML/Graphics.hpp"
#include <list>

class ShapeGenerator
{
private:

    struct Ball
    {
        sf::Vector2f p;
        sf::Vector2f dir;
        float r = 0;
        float speed = 0;
        sf::Color color;
    };

    struct Triangle
    {
        sf::Vector2f p1;
        sf::Vector2f dir;
        float h = 0;
        float speed = 0;
        sf::Color color;
    };

    struct Rectangle
    {
        sf::Vector2f p1;
        sf::Vector2f p2;
        sf::Vector2f dir;
        float speed = 0;
        sf::Color color;
    };



public:

    float getRandomNumber(float min, float max);
    sf::Color GetRandomColor();


    void GenBall();
    void drawBall(sf::RenderWindow&);

    void moveShapes();

    void GenTriangle();
    void drawTriangle(sf::RenderWindow&);

    void GenRectangle();
    void drawRectangle(sf::RenderWindow&);

private:

    std::list<Ball> balls;
    std::list<Triangle> triangles;
    std::list<Rectangle> rectangles;


};

