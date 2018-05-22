#include "labyrinth.h"

#include "../constants.h"

Cell::Cell(float x, float y)
{
    static const auto size = sf::Vector2f(30.f, 30.f);
    rect.setSize(size);
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineColor(sf::Color::Red);
    rect.setOutlineThickness(1);
    rect.setPosition(x * size.x, y * size.y);

    side = random(0, 1) == 0;

    if (side)
    {
        line[0] = sf::Vertex(sf::Vector2f(x * size.x, y * size.y));
        line[1] = sf::Vertex(sf::Vector2f(line[0].position.x + size.x, line[0].position.y + size.y));
    }
    else
    {
        line[0] = sf::Vertex(sf::Vector2f(x * size.x + size.x, y * size.y));
        line[1] = sf::Vertex(sf::Vector2f(x * size.x, line[0].position.y + size.y));
    }

}

void Cell::update(const TimeStamp& delta)
{

}

void Cell::render(sf::RenderWindow& window)
{
    window.draw(line, 2, sf::Lines);

}

// *************************************************************************************

Lab::Lab()
    : cells ( 22, std::vector<Cell>(16) )
{
    for (unsigned int i = 0; i < cells.size(); ++i)
    {
        for (unsigned int j = 0; j < cells[0].size(); ++j)
        {
            cells[i][j] = Cell(static_cast<float>(i), static_cast<float>(j));
        }
    }
}

void Lab::update(const TimeStamp& delta)
{
    for (unsigned int i = 0; i < cells.size(); ++i)
    {
        for (unsigned int j = 0; j < cells[0].size(); ++j)
        {
            cells[i][j].update(delta);
        }
    }
}

void Lab::render(sf::RenderWindow& window)
{
    for (unsigned int i = 0; i < cells.size(); ++i)
    {
        for (unsigned int j = 0; j < cells[0].size(); ++j)
        {
            cells[i][j].render(window);
        }
    }
}