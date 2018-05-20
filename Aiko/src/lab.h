#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "engine/kimo.h"

class Cell
{
public:

    Cell() { }
    Cell(float x, float y);
    void update(const TimeStamp& delta);
    void render(sf::RenderWindow&);

    sf::RectangleShape rect;

    sf::Vertex line[2];

    bool side;


};

class Lab : public Kimo
{

public:

    Lab();

    virtual void update(const TimeStamp& delta) final override;
    virtual void render(sf::RenderWindow&) final override;

    std::vector< std::vector<Cell> > cells;

};