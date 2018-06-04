#pragma once

#include <vector>

#include "../engine/kimo.h"

namespace labyrinth
{

    class Cell
    {
    public:

        Cell() { }
        Cell(float x, float y);
        void update(const aiko::TimeStamp& delta);
        void render(sf::RenderWindow&);

        sf::RectangleShape rect;

        sf::Vertex line[2];

        bool side;

    };

    class Lab : public aiko::Kimo
    {

    public:

        Lab();

        virtual void update(const aiko::TimeStamp& delta) final override;
        virtual void render(sf::RenderWindow&) final override;

        std::vector< std::vector<Cell> > cells;

    };

}