#include "ShapeGenerator.h"

float ShapeGenerator::getRandomNumber(float min, float max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

    return static_cast<float>(rand() * fraction * (max - min + 1) + min);
}

sf::Color ShapeGenerator::GetRandomColor()
{
    return sf::Color(rand() % 255, rand() % 255, rand() % 255, 200);
}

void ShapeGenerator::GenBall()
{
    Ball newBall;
    
    do
    {
        newBall.dir.x = (-5.0f + (rand() % 10)) / 3.0f;
        newBall.dir.y = (-5.0f + (rand() % 10)) / 3.0f;
    } while (newBall.dir.x == 0 || newBall.dir.y == 0);

    newBall.r = 5 + rand() % 5;
    
    newBall.p.x = getRandomNumber(newBall.r, 850 - newBall.r);
    newBall.p.y = getRandomNumber(newBall.r, 800 - newBall.r);
    newBall.speed = 30 + rand() % 30;
    newBall.color = GetRandomColor();
    balls.push_back(newBall);

}

void ShapeGenerator::drawBall(sf::RenderWindow& app)
{
    for (auto ball : balls)
    {
        sf::CircleShape gball;
        gball.setRadius(ball.r);
        gball.setPosition(ball.p.x, ball.p.y);
        gball.setFillColor(ball.color);
        gball.setOrigin(ball.r, ball.r);
        app.draw(gball);
    }
}

void ShapeGenerator::moveShapes()
{
    for (auto& ball : balls)
    {
        float dx = ball.dir.x * ball.speed * 0.01;
        float dy = ball.dir.y * ball.speed * 0.01;
        ball.p.x += dx;
        ball.p.y += dy;
    }
    for (auto& tri : triangles)
    {
        float dx = tri.dir.x * tri.speed * 0.01;
        float dy = tri.dir.y * tri.speed * 0.01;
        tri.p1.x += dx;
        tri.p1.y += dy;
    }
    for (auto& rec : rectangles)
    {
        float dx = rec.dir.x * rec.speed * 0.01;
        float dy = rec.dir.y * rec.speed * 0.01;
        rec.p1.x += dx;
        rec.p1.y += dy;
    }
}

void ShapeGenerator::GenTriangle()
{
    
    Triangle newTriangle;

    do
    {
        newTriangle.dir.x = (-5.0f + (rand() % 10)) / 3.0f;
        newTriangle.dir.y = (-5.0f + (rand() % 10)) / 3.0f;
    } while (newTriangle.dir.x == 0 || newTriangle.dir.y == 0);

    newTriangle.h = getRandomNumber(5, 40);

    newTriangle.p1.x = getRandomNumber(newTriangle.h, 850);
    newTriangle.p1.y = getRandomNumber(newTriangle.h, 800);
    newTriangle.color = GetRandomColor();

    newTriangle.speed = 30 + rand() % 30;
    triangles.push_back(newTriangle);



}

void ShapeGenerator::drawTriangle(sf::RenderWindow& app)
{
    for (auto& T : triangles)
    {
        sf::CircleShape gtriangle(T.h, 3);
        gtriangle.setPosition(T.p1.x, T.p1.y);       
        gtriangle.setFillColor(T.color);
        
        app.draw(gtriangle);
    }
}

void ShapeGenerator::GenRectangle()
{

    Rectangle newrec;

    do
    {
        newrec.dir.x = (-5.0f + (rand() % 10)) / 3.0f;
        newrec.dir.y = (-5.0f + (rand() % 10)) / 3.0f;
    } while (newrec.dir.x == 0 || newrec.dir.y == 0);

    newrec.p1.x = getRandomNumber(0, 850);
    newrec.p1.y = getRandomNumber(0, 800);
    newrec.p2.x = getRandomNumber(1, 40);
    newrec.p2.y = getRandomNumber(1, 40);

    newrec.speed = 30 + rand() % 30;
    newrec.color = GetRandomColor();
    rectangles.push_back(newrec);

}

void ShapeGenerator::drawRectangle(sf::RenderWindow& app)
{
    for (auto& R : rectangles)
    {
        sf::RectangleShape grectangle(R.p2);
        grectangle.setPosition(R.p1);
        grectangle.setFillColor(R.color);

        app.draw(grectangle);
    }
}
